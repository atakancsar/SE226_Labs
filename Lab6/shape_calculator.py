import geometry_utils

print("Available shapes: circle, rectangle, triangle")
print("Available calculations: _area, _perimeter (e.g., circle_area)")

operation = input("Enter the operation you want to perform: ")

try:
    if operation == "circle_area":
        radius = float(input("Enter radius: "))
        result = geometry_utils.circle_area(radius)
        print(f"Result: {result:.2f}")
        
    elif operation == "circle_perimeter":
        radius = float(input("Enter radius: "))
        result = geometry_utils.circle_perimeter(radius)
        print(f"Result: {result:.2f}")
        
    elif operation == "rectangle_area":
        width = float(input("Enter width: "))
        height = float(input("Enter height: "))
        result = geometry_utils.rectangle_area(width, height)
        print(f"Result: {result:.2f}")
        
    elif operation == "rectangle_perimeter":
        width = float(input("Enter width: "))
        height = float(input("Enter height: "))
        result = geometry_utils.rectangle_perimeter(width, height)
        print(f"Result: {result:.2f}")
        
    elif operation == "triangle_area":
        base = float(input("Enter base: "))
        height = float(input("Enter height: "))
        result = geometry_utils.triangle_area(base, height)
        print(f"Result: {result:.2f}")
        
    else:
        print("Invalid operation!")

except ValueError as e:
    print("Input Error: Dimensions must be strictly positive.")