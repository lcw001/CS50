from cs50 import get_int

# Prompt user for pyramid height
height = 0

while height < 1 or height > 8:
    height = get_int("Height? ")

# Print pyramid
# Rows

for i in range(height):

    # print spaces
    spaces = height - (i+1)
    for j in range(spaces):
        print(" ", end="")

    # print '#'
    for k in range(i + 1):
        print("#", end="")

    print()

