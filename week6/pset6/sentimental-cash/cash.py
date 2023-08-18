from cs50 import get_float

# Set coins to 0
coins = 0

# Input change; until valid (> 0)
while True:
    input_change = get_float("Change owed: ")
    if input_change > 0:
        break
# Convert input_change to cents and round
change = round(int(input_change * 100))

# Sort coins, increment counter
while change > 0:
    # Quarter
    while change >= 25:
        coins += 1
        change -= 25
    # Dime
    while change >= 10:
        coins += 1
        change -= 10
    # Nickel
    while change >= 5:
        coins += 1
        change -= 5
    # Penny
    while change >= 1:
        change -= 1
        coins += 1
print(coins)