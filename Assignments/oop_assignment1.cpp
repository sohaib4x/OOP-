#include <iostream>
using namespace std;

// Structure to represent the Engine of a vehicle
struct Engine {
    int horse_power = 0;  // Horsepower of the engine
    int cylinders = 0;    // Number of cylinders in the engine
    string fuel_type = "N/A"; // Type of fuel used by the engine
};

// Structure to represent a Wheel
struct Wheel {
    int size = 0;        // Size of the wheel
    string type = "N/A"; // Type of the wheel (e.g., alloy, steel)
};

// Structure to represent the Body of a vehicle
struct Body {
    string color = "N/A";      // Color of the vehicle
    string material = "N/A";   // Material of the vehicle body
    int doors = 0;             // Number of doors in the vehicle body
};

// Structure to represent a Vehicle, which contains nested structures
struct Vehicle {
    string brand = "N/A"; // Brand of the vehicle
    Engine engine;        // Nested structure for engine details
    Wheel wheels[4];      // Array of 4 wheels (nested structure)
    Body body;            // Nested structure for body details
};

// Function to display a welcome message
void welcome() {
    cout << "\t\tWelcome to My Garage\t" << endl;
    cout << "************<<<<<<<<<<<<<<<<<<>>>>>>>>>>>*************\n\n";
}

// Function to build a vehicle from scratch
void build_vehicle(Vehicle &vehicle) {
    cout << "Enter brand of your vehicle: ";
    cin >> vehicle.brand; // Accessing brand of the vehicle

    cout << "\n\t\tDetails for Engine " << endl;
    cout << "Enter HP of your Engine (12 to 1000) : ";
    cin >> vehicle.engine.horse_power; // Accessing and modifying engine horsepower
    cout << "Enter Number of cylinders in Engine (2 to 16): ";
    cin >> vehicle.engine.cylinders; // Accessing and modifying number of cylinders
    cout << "Enter the type of fuel of your Engine (gasoline, diesel etc): ";
    cin >> vehicle.engine.fuel_type; // Accessing and modifying fuel type

    cout << "\n\n\t\tWheels details" << endl;

    int wheel_size;
    string wheel_type;

    cout << "Enter size for all 4 wheels (15 to 26): ";
    cin >> wheel_size; // Input for wheel size

    cout << "Enter type for all 4 wheels (e.g., alloy, steel): ";
    cin >> wheel_type; // Input for wheel type

    // Assign the same size and type to all wheels in the array
    for (int i = 0; i < 4; i++) {
        vehicle.wheels[i].size = wheel_size; // Accessing and modifying size of each wheel
        vehicle.wheels[i].type = wheel_type; // Accessing and modifying type of each wheel
    }

    cout << "\n\n\t\tBody details" << endl;
    cout << "Enter color of your vehicle: ";
    cin >> vehicle.body.color; // Accessing and modifying body color
    cout << "Enter the Body material: ";
    cin >> vehicle.body.material; // Accessing and modifying body material
    cout << "Enter number of doors: ";
    cin >> vehicle.body.doors; // Accessing and modifying number of doors
}

// Function to upgrade the engine
void upgrade_engine(Engine &engine) {
    cout << "\n\n\t\tEngine Upgradation";
    int choice;

    do {
        cout << "\nPress 1 to increase HP" << endl;
        cout << "Press 2 to add cylinders" << endl;
        cout << "Press 3 to enter new type of Engine" << endl;
        cout << "Press 0 to exit the function" << endl;
        cin >> choice; // User choice for engine upgrade

        switch (choice) {
            case 1: {
                int increase;
                cout << "Enter how much you wanna increase HP: ";
                cin >> increase;
                engine.horse_power += increase; // Modifying engine horsepower
                cout << "Engine is upgraded to " << engine.horse_power << endl;
                break;
            }
            case 2: {
                int add;
                cout << "Enter how many cylinders you wanna add more: ";
                cin >> add;
                engine.cylinders += add; // Modifying number of cylinders
                cout << "New number of cylinders are: " << engine.cylinders << endl;
                break;
            }
            case 3:
                cout << "Enter new type of Engine (gasoline, diesel etc): ";
                cin >> engine.fuel_type; // Modifying fuel type
                cout << "Fuel type is changed to " << engine.fuel_type << endl;
                break;
            case 0:
                cout << "\nExiting the function..." << endl;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    } while (choice != 0);
}

// Function to upgrade a single wheel
void upgrade_wheel(Wheel &wheel) {
    cout << "\n\n\t\tUpgrading Wheel" << endl;

    int choice;
    cout << "Press 1 to change wheel size" << endl;
    cout << "Press 2 to change wheel type" << endl;
    cout << "Press 0 to exit the function" << endl;
    cin >> choice; // User choice for wheel upgrade

    switch (choice) {
        case 1:
            cout << "Enter new size of wheels: ";
            cin >> wheel.size; // Modifying size of the wheel
            cout << "Size of new wheels is " << wheel.size << endl;
            break;
        case 2:
            cout << "Enter new type of wheels: ";
            cin >> wheel.type; // Modifying type of the wheel
            cout << "Type of new wheels is " << wheel.type << endl;
            break;
        case 0:
            cout << "Exiting the function..." << endl;
            break;
        default:
            cout << "Invalid option, try again" << endl;
    }
}

// Function to customize the body of the vehicle
void customize_body(Body &body) {
    cout << "\n\n\t\tCustomizing Body" << endl;
    int choice;

    do {
        cout << "Press 1 to paint the vehicle" << endl;
        cout << "Press 2 to change the material" << endl;
        cout << "Press 3 to change number of doors" << endl;
        cout << "Press 0 to exit the function" << endl;
        cin >> choice; // User choice for body customization

        switch (choice) {
            case 1:
                cout << "Enter new color of vehicle: ";
                cin >> body.color; // Modifying body color
                cout << "Color is changed to: " << body.color << endl << endl;
                break;
            case 2:
                cout << "Enter new material of vehicle: ";
                cin >> body.material; // Modifying body material
                cout << "Material is changed to: " << body.material << endl << endl;
                break;
            case 3:
                cout << "Enter new number of doors: ";
                cin >> body.doors; // Modifying number of doors
                cout << "Number of doors is changed to: " << body.doors << endl << endl;
                break;
            case 0:
                cout << "Exiting the function..." << endl;
                break;
            default:
                cout << "Invalid option, try again." << endl;
        }
    } while (choice != 0);
}

// Function to display vehicle details
void display_vehicle(const Vehicle &vehicle) {
    cout << "\n\n\t\tVehicle Details:" << endl;
    cout << "Brand: " << vehicle.brand << endl;

    // Display engine details
    cout << "\n\t\tEngine Details:" << endl;
    cout << "Horse Power: " << vehicle.engine.horse_power << endl; // Accessing engine horsepower
    cout << "Cylinders: " << vehicle.engine.cylinders << endl; // Accessing number of cylinders
    cout << "Fuel Type: " << vehicle.engine.fuel_type << endl; // Accessing fuel type

    // Display wheels details
    cout << "\n\t\tWheels Details:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Wheel " << i + 1 << ":" << endl;
        cout << "  Size: " << vehicle.wheels[i].size << endl; // Accessing size of each wheel
        cout << "  Type: " << vehicle.wheels[i].type << endl; // Accessing type of each wheel
    }

    // Display body details
    cout << "\n\t\tBody Details:" << endl;
    cout << "Color: " << vehicle.body.color << endl; // Accessing body color
    cout << "Material: " << vehicle.body.material << endl; // Accessing body material
    cout << "Number of Doors: " << vehicle.body.doors << endl; // Accessing number of doors
}

// Menu function for vehicle management
void menu(Vehicle &vehicle) {
    int choice;
    do {
        cout << "\n\n\t\tVehicle Management Menu" << endl;
        cout << "1. Build Vehicle" << endl;
        cout << "2. Upgrade Engine" << endl;
        cout << "3. Upgrade Wheels" << endl;
        cout << "4. Customize Body" << endl;
        cout << "5. Show Vehicle Details" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice; // User choice for menu options

        switch (choice) {
            case 1:
                build_vehicle(vehicle); // Build a new vehicle
                break;
            case 2:
                upgrade_engine(vehicle.engine); // Upgrade engine details
                break;
            case 3:
                for(int i = 0; i < 4; i++) {
                    upgrade_wheel(vehicle.wheels[i]); // Upgrade each wheel
                }
                break;
            case 4:
                customize_body(vehicle.body); // Customize body details
                break;
            case 5:
                display_vehicle(vehicle); // Show all vehicle details
                break;
            case 0:
                cout << "Exiting the menu..." << endl; // Exit option
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 0);
}

// Main function
int main() {
    Vehicle my_car; // Create a Vehicle object

    welcome(); // Display welcome message
    menu(my_car); // Start the vehicle management menu

    return 0;  
}
