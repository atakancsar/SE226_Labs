def factorial(x):
    if x <= 1:
        return 1
    return x * factorial(x - 1)


abs_val = lambda x, i: (x ** (2 * i)) / factorial(2 * i)


def exp_x(x, n):
    total = 0
    for i in range(n):
        sign = (-1) ** i
        total += sign * abs_val(x, i)
    return total


total_q3 = 0

def series(n, r):
    global total_q3
    
    if n == 0:
        total_q3 += 1
        return
        
    total_q3 += r ** n
    series(n - 1, r)


x_input = int(input("Enter x: "))
n_input = int(input("Enter n: "))
print(exp_x(x_input, n_input))

n3_input = int(input("Enter n for task 3: "))
r3_input = int(input("Enter r for task 3: "))
series(n3_input, r3_input)
print(total_q3)
