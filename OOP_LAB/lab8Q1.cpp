#include <iostream>
#include <cstdlib>/*Contains functions for general utilities, including rand() and srand()*/
#include <ctime>//used for date and time, often for random number
#include <string>//Allows the use of the string class for handling strings more easily

using namespace std;

class Inventory {
private:
    int* stockLevels;
    int* salesData;
    string* productNames; // Array to hold product names
    int size;

public:
    // Constructor
    Inventory() {
        stockLevels = NULL; //same as nullptr
        salesData = NULL;     
        productNames = NULL; 
        size = 0;
    }

    //Function to input inventory size and product names
    void inputInventory() {
        cout << "Enter the number of products in the inventory: ";
        cin >> size;
        stockLevels = new int[size];
        salesData = new int[size];
        productNames = new string[size]; //Allocate memory for product names

        for (int i = 0; i < size; ++i) {
            cout << "Enter name for product " << (i + 1) << ": ";
            cin >> productNames[i]; //Get product name from user
            stockLevels[i] = 0;     //Initialize stock levels to 0
            salesData[i] = 0;       //Initialize sales data to 0
        }
    }

    //Function to generate random stock levels and sales data
    void generateRandomStockLevels() {
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < size; ++i) {
            stockLevels[i] = rand() % 100;  //Random stock level between 0 and 99
            salesData[i] = rand() % 50;      //Random sales volume between 0 and 49
            //Ensure sales do not exceed stock levels
            if (salesData[i] > stockLevels[i]) {
                salesData[i] = stockLevels[i]; //Adjust sales to not exceed stock
            }
        }
    }

    //Function to calculate average stock level
    double calculateAverageStockLevel() {
        int totalStock = 0;
        for (int i = 0; i < size; ++i) {
            totalStock += stockLevels[i];
        }
        return static_cast<double>(totalStock) / size;
    }

    //Function to get names of critical products
    void getCriticalProducts() {
        double average = calculateAverageStockLevel();
        cout << "Critical Products (Stock below average):\n";
        for (int i = 0; i < size; ++i) {
            if (stockLevels[i] < average) {
                cout << productNames[i] << " (Stock: " << stockLevels[i] << ")\n";
            }
        }
    }

    //Function to find the top-selling product
    string findTopSellingProduct() {
        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (salesData[i] > salesData[maxIndex]) {
                maxIndex = i;
            }
        }
        return productNames[maxIndex];
    }

    //Function to find the second best-selling product
    string findSecondBestSeller() {
        int first = findTopSellingProductIndex();
        int second = (first == 0) ? 1 : 0; //Initialize to a different product
        for (int i = 0; i < size; ++i) {
            if (i != first && salesData[i] > salesData[second]) {
                second = i;
            }
        }
        return productNames[second];
    }

    //Helper function to get the index of the top-selling product
    int findTopSellingProductIndex() {
        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (salesData[i] > salesData[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    //Function to sort products by popularity using bubble sort
    void sortByPopularity() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (salesData[j] < salesData[j + 1]) {
                    // Swap sales data
                    swap(salesData[j], salesData[j + 1]);
                    // Swap stock levels accordingly
                    swap(stockLevels[j], stockLevels[j + 1]);
                    // Swap product names accordingly
                    swap(productNames[j], productNames[j + 1]);
                }
            }
        }
        displaySortedProducts(); //Display sorted products after sorting
    }

    //Function to display inventory
    void displayInventory() {
        cout << "Product Stock Levels and Sales Data:\n";
        for (int i = 0; i < size; ++i) {
            cout << "Product: " << productNames[i] << ", Stock = " 
                 << stockLevels[i] << ", Sales = " << salesData[i] << "\n";
        }
    }

    //Function to display sorted products by popularity
    void displaySortedProducts() {
        cout << "Products Sorted by Popularity (Sales Data):\n";
        for (int i = 0; i < size; ++i) {
            cout << "Product: " << productNames[i] << ", Sales = " << salesData[i] << "\n";
        }
    }

    //Destructor
    ~Inventory() {
        delete[] stockLevels;
        delete[] salesData;
        delete[] productNames; // Free the product names array
    }
};

int main() {
    Inventory inventory; //Create an instance of the Inventory class
    int choice;         //Variable to store user menu choice

    do {
        //Display the inventory management menu options
        cout << "\nInventory Management Menu:\n";
        cout << "1. Input Inventory\n";
        cout << "2. Generate Random Stock Levels and Sales Data\n";
        cout << "3. Display Inventory\n";
        cout << "4. Calculate Average Stock Level\n";
        cout << "5. Count Critical Products\n";
        cout << "6. Find Top Selling Product\n";
        cout << "7. Find Second Best Selling Product\n";
        cout << "8. Sort Products by Popularity\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: "; //Prompt user for input
        cin >> choice; //Read user input

        //Handle user choice using a switch statement
        switch (choice) {
            case 1:
                inventory.inputInventory(); //Input product details into inventory
                break;
            case 2:
                inventory.generateRandomStockLevels(); //Generate random stock levels and sales data
                cout << "Random stock levels and sales data generated.\n";
                break;
            case 3:
                inventory.displayInventory(); //Display current inventory details
                break;
            case 4:
                cout << "Average Stock Level: " << inventory.calculateAverageStockLevel() << "\n"; //Show average stock level
                break;
            case 5:
                inventory.getCriticalProducts(); //List products with stock below average
                break;
            case 6:
                cout << "Top Selling Product: " << inventory.findTopSellingProduct() << "\n"; //Display the name of the top-selling product
                break;
            case 7:
                cout << "Second Best Selling Product: " << inventory.findSecondBestSeller() << "\n"; // Display the second best-selling product
                break;
            case 8:
                inventory.sortByPopularity(); //Sort products based on sales data
                break;
            case 9:
                cout << "Exiting program.\n"; //Exit message
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Handle invalid input
        }
    } while (choice != 9); //Continue until the user chooses to exit

    return 0;
}
