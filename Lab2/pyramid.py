space = " "
star = "*"
row = int(input("Enter row num: "))
column = 1 + (row - 1) * 2
starCount = 1

for a in range(column // 2, -1, -1):
    for b in range(a):
        print(space, end="")
    for c in range(starCount):
        print(star, end="")
    starCount += 2
    print()
