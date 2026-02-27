import math

x1 = int(input("enter x1: "))
y1 = int(input("enter y1: "))
x2 = int(input("enter x2: "))
y2 = int(input("enter y2: "))

distance = math.sqrt(math.pow(x1-x2, 2) + math.pow(y1-y2, 2))
print(f"Distance: {distance}")