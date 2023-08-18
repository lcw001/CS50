import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd
import datetime
import math


# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    # Display html table summazing user portfolio
    # Get user data from user and transaction tables
    user_id = session["user_id"]
    portfolio = db.execute(
        "SELECT symbol, name, shares, SUM(shares) AS sum FROM transactions WHERE user_id=? GROUP BY symbol", user_id)

    # Iterate through portfolio to get current symbol price
    portfolio_total = 0
    for row in portfolio:
        current_price = lookup(row["symbol"])["price"]
        total = current_price * int(row["sum"])
        row["current_price"] = usd(current_price)
        row["total"] = usd(total)
        portfolio_total += total

    user_cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)
    available_user_cash = user_cash[0]["cash"]

    grand_total = available_user_cash + portfolio_total

    return render_template("index.html", portfolio=portfolio, available_user_cash=usd(available_user_cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        return render_template("buy.html")

    else:
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Assign a variable and call lookup fxn
        stock_info = lookup(symbol.upper())

        # Checks to see if symbol is valid
        if stock_info == None:
            return apology("Symbol not found", 400)

        name = stock_info["name"]
        price = stock_info["price"]

        # Makes sure number of shares is a positive number
        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError
        except ValueError:
            return apology("Please enter a number > 0", 400)

        # Create variable for cost of transaction
        transaction_cost = shares * stock_info["price"]
        user_id = session["user_id"]

        # Gets available user cash
        user_cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)
        available_user_cash = user_cash[0]["cash"]

        # Make sure available user cash can cover transaction cost
        if available_user_cash < transaction_cost:
            return apology("Insufficient funds for transaction", 400)

        # Calculate new amount of user cash
        new_user_cash = available_user_cash - transaction_cost

        # Update user cash in the user table
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_user_cash, user_id)

        # Update transaction table
        date = datetime.datetime.now()

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date, name) VALUES(?,?,?,?,?,?)",
                    user_id, stock_info["symbol"], shares, stock_info["price"], date, name)

        # display message that purchase was successful via flashed message
        flash("Purchase successful")

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    portfolio = db.execute("SELECT symbol, shares, price, date FROM transactions WHERE user_id=?", user_id)

    return render_template("history.html", portfolio=portfolio)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/login")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")

        # Checks for empty symbol box
        if not symbol:
            return apology("Enter Symbol", 400)

        # Assign a variable and call lookup fxn
        stock_info = lookup(symbol.upper())

        # Checks to see if symbol is valid
        if stock_info == None:
            return apology("Symbol not found", 400)

        # return render_template("stockinfo.html", name, price, symbol)
        price = usd(stock_info["price"])
        return render_template("stockinfo.html", name=stock_info["name"], price=price, symbol=stock_info["symbol"])


@app.route("/register", methods=["GET", "POST"])
def register():
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    if request.method == "GET":
        return render_template("register.html")

    else:
        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        # No password confirmation on form
        if not confirmation:
            return apology("Please enter password confirmation", 400)

        # Password and confirmation do not match
        if password != confirmation:
            return apology("Passord and confirmation do not match", 400)

        # Generate a hash of password
        hash = generate_password_hash(password)

        try:
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        except:
            return apology("Username already registered", 400)

        session["user_id"] = new_user

        return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        user_id = session["user_id"]
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        sell_symbols = db.execute("SELECT symbol FROM transactions WHERE user_id=? GROUP BY symbol HAVING SUM(shares) > 0", user_id)
        return render_template("sell.html", symbols=[row["symbol"] for row in sell_symbols])

    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Checks for empty symbol box
        if not symbol:
            return apology("Enter Symbol", 400)

        # Assign a variable and call lookup fxn
        stock_info = lookup(symbol.upper())
        name = stock_info["name"]
        price = stock_info["price"]

        # Checks to see if symbol is valid
        if stock_info == None:
            return apology("Symbol not found", 400)

        # Makes sure number of shares is a positive number
        if shares < 0:
            return apology("Please enter a number > 0", 400)

        # Create variable for cost of transaction
        transaction_cost = shares * stock_info["price"]

        # Gets available user cash
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id=?", user_id)
        available_user_cash = user_cash[0]["cash"]

        # Get user shares
        user_shares = db.execute("SELECT SUM(shares) AS sum FROM transactions WHERE user_id=? AND symbol = ?", user_id, symbol)
        current_user_shares = user_shares[0]["sum"]

        if current_user_shares < shares:
            return apology("selling more shares than you hold", 400)

        # Calculate new amount of user cash
        new_user_cash = available_user_cash + transaction_cost

        # Update user cash in the user table
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_user_cash, user_id)

        # Update transaction table
        date = datetime.datetime.now()

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date, name) VALUES(?,?,?,?,?,?)",
                   user_id, stock_info["symbol"], (-1)*shares, stock_info["price"], date, name)

        # display message that purchase was successful via flashed message
        flash("Sell successful")

        return redirect("/")


@app.route("/addcash", methods=["GET", "POST"])
@login_required
def addcash():
    """Add cash to the account."""

    # else if user reached route via GET (as by clicking a link or via redirect)
    if request.method == "GET":
        return render_template("addcash.html")

    else:
        # check cash amout was entered
        if not request.form.get("addcash"):
            return apology("please enter cash amount between $1 and $50,000", 400)

        # check for numeric and >0 and lesser then $50,000
        elif not str.isdigit(request.form.get("addcash")) or float(request.form.get("addcash")) < 0.01 or float(request.form.get("addcash")) > 50000:
            return apology("please enter cash amount between $1 and $50,000", 400)

        # query database for username current cash
        user_id = session["user_id"]
        available_user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # update cash in users table for the user

        cash = available_user_cash[0]["cash"] + float(request.form.get("addcash"))
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)

        return redirect("/")
