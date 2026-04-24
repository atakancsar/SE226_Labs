class Vehicle:
    def __init__(self, vid, model, year):
        self.vid = vid
        self.model = model
        self.year = int(year)
 
    def __str__(self):
        return f"VID: {self.vid} | {self.model} ({self.year})"
        
    def __eq__(self, other):
        if self.vid == other.vid:
            return True
        else:
            return False
            
    def is_new(self, n):
        
        if (2026 - self.year) <= n:
            return True
        else:
            return False

class Car(Vehicle):
    def __init__(self, vid, model, year, fuel_type, doors):
        super().__init__(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = int(doors)
        
    def __str__(self):
        model_str = self.model.ljust(15)
        fuel_str = self.fuel_type.ljust(8)
        return f"[Car]        VID: {self.vid} | {model_str} ({self.year}) | Fuel: {fuel_str} | {self.doors} Doors"

class Truck(Vehicle):
    def __init__(self, vid, model, year, max_load, axles):
        super().__init__(vid, model, year)
        self.max_load = int(max_load)
        self.axles = int(axles)
        
    def __str__(self):
        model_str = self.model.ljust(15)
        load_str = str(self.max_load) + "kg"
        load_str = load_str.ljust(8)
        return f"[Truck]      VID: {self.vid} | {model_str} ({self.year}) | Load: {load_str} | {self.axles} Axles"

class Motorcycle(Vehicle):
    def __init__(self, vid, model, year, engine_cc, vehicle_type):
        super().__init__(vid, model, year)
        self.engine_cc = int(engine_cc)
        self.type = vehicle_type
        
    def __str__(self):
        model_str = self.model.ljust(15)
        eng_str = str(self.engine_cc) + "cc"
        eng_str = eng_str.ljust(8)
        return f"[Motorcycle] VID: {self.vid} | {model_str} ({self.year}) | Eng: {eng_str} | Type: {self.type}"

def save_fleet_to_file(vehicles, filename):
    file = open(filename, "w")
    for vehicle in vehicles:
        if type(vehicle) == Car:
            file.write(f"Car,{vehicle.vid},{vehicle.model},{vehicle.year},{vehicle.fuel_type},{vehicle.doors}\n")
        elif type(vehicle) == Truck:
            file.write(f"Truck,{vehicle.vid},{vehicle.model},{vehicle.year},{vehicle.max_load},{vehicle.axles}\n")
        elif type(vehicle) == Motorcycle:
            file.write(f"Motorcycle,{vehicle.vid},{vehicle.model},{vehicle.year},{vehicle.engine_cc},{vehicle.type}\n")
    file.close()

def load_fleet_from_file(filename):
    print(f"Loading fleet data from '{filename}'...")
    file = open(filename, "r")
    lines = file.readlines()
    file.close()
    
    vehicles = []
    for line in lines:
        line = line.strip()
        parts = line.split(",")
        vehicle_type = parts[0]
        
        if vehicle_type == "Car":
            car = Car(parts[1], parts[2], parts[3], parts[4], parts[5])
            vehicles.append(car)
        elif vehicle_type == "Truck":
            truck = Truck(parts[1], parts[2], parts[3], parts[4], parts[5])
            vehicles.append(truck)
        elif vehicle_type == "Motorcycle":
            motor = Motorcycle(parts[1], parts[2], parts[3], parts[4], parts[5])
            vehicles.append(motor)
            
    print(f"  {len(vehicles)} vehicles loaded successfully.\n")
    return vehicles



v1 = Car("V001", "Tesla Model 3", 2023, "Electric", 4)
v2 = Truck("T101", "Volvo FH16", 2019, 25000, 6)
v3 = Motorcycle("M301", "Yamaha R1", 2024, 998, "Sport")
v4 = Car("V002", "Toyota Corolla", 2018, "Petrol", 4)
v5 = Truck("T102", "Mercedes Actros", 2021, 18000, 4)
v6 = Motorcycle("M302", "Harley Davidson", 2015, 1200, "Cruiser")

fleet = [v1, v2, v3, v4, v5, v6]


save_fleet_to_file(fleet, "fleet.txt")


loaded_vehicles = load_fleet_from_file("fleet.txt")


print("All Vehicles")
for v in loaded_vehicles:
    print("  " + str(v))

print("")


print("Recent Vehicles Last 4 Years")
for v in loaded_vehicles:
    if v.is_new(4) == True:
        print("  " + str(v))

print("")


print("Electric Cars Only")
for v in loaded_vehicles:
    if type(v) == Car:
        if v.fuel_type == "Electric":
            print("  " + str(v))
