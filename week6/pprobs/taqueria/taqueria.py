import re
import sys

CURSOR_UP = '\033[1A'
CLEAR = '\x1b[2K'
CLEAR_LINE = CURSOR_UP + CLEAR

menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

total = 0

while True:
    try:
        # Get item
        item = input("Item: ").title()
        # Check to see if item on memu
        # If yes, add price to total
        # If no, prompt for item
        if item in menu:
            total += menu[item]
            print(f"Total: ${total:.2f}")
        elif not (item in menu):
            print("try again, item not on menu")

    except EOFError:
        #print(CURSOR_UP)
        #print()
        #print("Item: ")
        break

print()
