import sys
from pyfiglet import Figlet
import random

figlet = Figlet()

#list of fonts
font_list = [figlet.getFonts()]






#output text in font, s is text as str
#print(figlet.renderText(s))


# Prints a command-line argument
len = len(sys.argv)
if len == 1:
    #random font selection
    font = random.choice(font_list[0])

    #set fonts, f is font name as str
    setFont = figlet.setFont(font=font)
    print('argv = 0, random font = ' + str(font))

elif len == 3:

    try:
        print(f"argv1 = " + str(sys.argv[1]))
        print(f"argv2 = " + str(sys.argv[2]))
    except IndexError:
        print("error")

    # check if first is -f or --font
    if sys.argv[1] == '-f' or sys.argv[1] == '--font':
        print('yes it is -f or --f')
        # and second is found in font_list
        if sys.argv[2] in font_list[0]:
            print("yes font in font list")

            try:
                if sys.argv[2] in font_list[0]:
                    #font = sys.argv[2]
                    print (f"font =" + str(sys.argv[2]))
                    figlet.setFont(font=sys.argv[2])
                    #print(f"setFont = " + str(setFont))
            except IndexError:
                    print("error")
        # if font is not in font_list
        elif not (sys.argv[2] in font_list[0]):
            print("Invalid usage")
            sys.exit(1)
    # if not -f or --font
    elif sys.argv[1] != '-f' or sys.argv[1] != '--font':
        print("Invalid usage")
        sys.exit(1)

#if not first or second use sys.exit with error msg
elif len == 2 or len > 3:
    print("Invalid usage")
    sys.exit(1)

# Printing command-line arguments, indexing into argv
input = input("Input: ")
print(figlet.renderText(input))
