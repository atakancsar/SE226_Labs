numOfUsers = int(input("Enter number of users: "))
print()

users_data = {}          
all_items_list = []      
unique_items_set = set() 

for i in range(numOfUsers):
    username = input("Enter username : ")
    numOfItems = int(input("How many items? "))
    
    user_items = []
    
    for j in range(1, numOfItems + 1):
        item = input(f"Item {j}: ")
        user_items.append(item)
        all_items_list.append(item) 
        unique_items_set.add(item)  
        
    users_data[username] = user_items
    print()

print("USER DATA:")
for username, items in users_data.items():
    print(f"{username} -> {items}")
print()

item_user_counts = {}

for item in unique_items_set:
    item_user_counts[item] = 0

for username, items in users_data.items():
    
    user_unique_items = []
    for item in items:
        if item not in user_unique_items:
            user_unique_items.append(item)
              
    for item in user_unique_items:
        item_user_counts[item] = item_user_counts[item] + 1

ordered_items = []
for items in users_data.values():
    for item in items:
        if item not in ordered_items:
            ordered_items.append(item)

print("COMMON ITEMS:")
for item in ordered_items:
    if item_user_counts[item] > 1:
        print(item)
print()

print("UNIQUE ITEMS:")
for item in ordered_items:
    if item_user_counts[item] == 1:
        print(item)
print()

total_counts = {}
for item in unique_items_set:
    total_counts[item] = 0

for item in all_items_list:
    total_counts[item] = total_counts[item] + 1

max_count = 0
for count in total_counts.values():
    if count > max_count:
        max_count = count

print("MOST POPULAR ITEM:")
for item in ordered_items:
    if total_counts[item] == max_count:
        print(item)
