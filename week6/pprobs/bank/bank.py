
greeting = input("Greeting: ")
greeting = greeting.lower()

if 'hello' in greeting:
    money = 0
elif greeting.startswith("h"):
    money = 20
else:
    money = 100

print (f"$" + str(money))


