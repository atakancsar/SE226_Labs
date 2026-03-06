## Task 1
num = int(input("Please enter a positive integer greater than 9: "))
step = 0

print(num, end="")
while num >= 10:
    temp_sum = 0
    temp_num = num
    while temp_num > 0:
        temp_sum += temp_num % 10
        temp_num //= 10
    num = temp_sum
    print(f" -> {num}", end="")
    step += 1
print(f"\nFinal value: {num}")
print(f"Total steps: {step}")

## Task 2
n = int(input("Please enter a number between 10 and 100: "))
while n < 10 or n > 100:
    n = int(input("Invalid input. Please enter a number between 10 and 100: "))

fizz_count = 0
buzz_count = 0
fizzbuzz_count = 0

for i in range(1, n + 1):
    if i % 7 == 0:
        print(f"({i} is skipped)")
        continue
    
    if i % 15 == 0:
        print("FizzBuzz")
        fizzbuzz_count += 1
    elif i % 3 == 0:
        print("Fizz")
        fizz_count += 1
    elif i % 5 == 0:
        print("Buzz")
        buzz_count += 1
    else:
        print(i)

print("--- Summary ---")
print(f"Fizz count : {fizz_count}")
print(f"Buzz count : {buzz_count}")
print(f"FizzBuzz count: {fizzbuzz_count}")

## Task 3
n3 = int(input("Please enter a number between 3 and 9: "))

for i in range(1, 2 * n3):
    k = n3 - abs(n3 - i)
    for j in range(1, k + 1):
        print(j, end="")
    print()
