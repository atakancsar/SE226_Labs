from data_package import remove_duplicates, strip_whitespaces, calculate_mean, find_maximum, find_minimum

try:
    user_input = input("Enter a comma-separated list of numbers (e.g., 12, 5, 12, 8 , 21): ")
    
    string_list = user_input.split(",")
    cleaned_strings = strip_whitespaces(string_list)
    
    number_list = []
    for item in cleaned_strings:
        if item != "":
            number_list.append(float(item))
    
    unique_numbers = remove_duplicates(number_list)
    
    print(f"Cleaned and unique data: {unique_numbers}")
    print("-" * 20)
    
    mean = calculate_mean(unique_numbers)
    maximum = find_maximum(unique_numbers)
    minimum = find_minimum(unique_numbers)
    
    print(f"Mean: {mean:.2f}")
    print(f"Maximum: {maximum}")
    print(f"Minimum: {minimum}")
    
except ValueError:
    print("Data Error: Please make sure you only enter numbers separated by commas.")