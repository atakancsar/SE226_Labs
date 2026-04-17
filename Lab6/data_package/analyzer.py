def calculate_mean(num_list):
    total = 0
    for num in num_list:
        total = total + num
    return total / len(num_list)

def find_maximum(num_list):
    maximum = num_list[0]
    for num in num_list:
        if num > maximum:
            maximum = num
    return maximum

def find_minimum(num_list):
    minimum = num_list[0]
    for num in num_list:
        if num < minimum:
            minimum = num
    return minimum