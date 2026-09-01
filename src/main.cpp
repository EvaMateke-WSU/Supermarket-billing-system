#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

struct Item {
    std::string name;
    double price;
    int quantity;

    double getSubtotal() const {
        return price * quantity;
    }
};

class SupermarketBillingSystem {
private:
    std::vector<Item> cart;
    const double discountRate = 0.10; // 10% discount threshold
    const std::string filename = "inventory.txt";

    int getIntInput(const std::string& prompt) {
        int val;
        while (true) {
            std::cout << prompt;
            if (std::cin >> val) return val;
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    double getDoubleInput(const std::string& prompt) {
        double val;
        while (true) {
            std::cout << prompt;
            if (std::cin >> val) return val;
            std::cout << "Invalid input. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void pauseForUser() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

public:
    SupermarketBillingSystem() {
        loadFromFile();
    }

    // Save inventory data to a text file
    void saveToFile() const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "[!] Error opening file for writing.\n";
            return;
        }

        for (const auto& item : cart) {
            // Using '|' as a delimiter to handle product names with spaces
            outFile << item.name << "|" << item.price << "|" << item.quantity << "\n";
        }
        outFile.close();
    }

    // Load inventory data from a text file on startup
    void loadFromFile() {
        std::ifstream inFile(filename);
        if (!inFile) {
            // If file doesn't exist, seed default items
            seedDefaultData();
            saveToFile();
            return;
        }

        cart.clear();
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.empty()) continue;

            std::stringstream ss(line);
            std::string name, priceStr, qtyStr;

            if (std::getline(ss, name, '|') &&
                std::getline(ss, priceStr, '|') &&
                std::getline(ss, qtyStr, '|')) {
                Item item;
                item.name = name;
                item.price = std::stod(priceStr);
                item.quantity = std::stoi(qtyStr);
                cart.push_back(item);
            }
        }
        inFile.close();
    }

    void addProductToInventory() {
        Item newItem;
        std::cout << "\nEnter Item Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newItem.name);

        newItem.price = getDoubleInput("Enter Price: R");
        newItem.quantity = getIntInput("Enter Quantity: ");

        cart.push_back(newItem);
        saveToFile(); // Persist newly added product immediately

        std::cout << "\n[+] Item successfully added and saved to database.\n";
        pauseForUser();
    }

    void calculateBill() {
        if (cart.empty()) {
            std::cout << "\n[!] Cart is empty.\n";
            pauseForUser();
            return;
        }

        double total = 0.0;
        for (const auto& item : cart) {
            total += item.getSubtotal();
        }

        double discount = (total >= 1000.0) ? (total * discountRate) : 0.0;
        double finalAmount = total - discount;

        std::cout << "\n==========================================\n";
        std::cout << "              BILL SUMMARY                \n";
        std::cout << "==========================================\n";
        std::cout << std::left << std::setw(20) << "Total Bill" << ": R" << std::fixed << std::setprecision(2) << total << "\n";
        std::cout << std::left << std::setw(20) << "Discount Applied" << ": R" << discount << "\n";
        std::cout << std::left << std::setw(20) << "Final Amount" << ": R" << finalAmount << "\n";
        std::cout << "==========================================\n";

        pauseForUser();
    }

    void printReceipt() {
        if (cart.empty()) {
            std::cout << "\n[!] No items available to print receipt.\n";
            pauseForUser();
            return;
        }

        std::cout << "\n==========================================\n";
        std::cout << "         GROUP6 SUPERMARKET RECEIPT       \n";
        std::cout << "==========================================\n";
        std::cout << std::left << std::setw(18) << "Item"
                  << std::setw(8)  << "Price"
                  << std::setw(6)  << "Qty"
                  << std::right << std::setw(10) << "Subtotal" << "\n";
        std::cout << "------------------------------------------\n";

        double total = 0.0;
        for (const auto& item : cart) {
            double subtotal = item.getSubtotal();
            total += subtotal;

            std::cout << std::left << std::setw(18) << item.name
                      << std::setw(8)  << std::fixed << std::setprecision(2) << item.price
                      << std::setw(6)  << item.quantity
                      << std::right << std::setw(10) << std::fixed << std::setprecision(2) << subtotal << "\n";
        }

        double discount = (total >= 1000.0) ? (total * discountRate) : 0.0;
        double finalAmount = total - discount;

        std::cout << "------------------------------------------\n";
        std::cout << std::left << std::setw(18) << "Total Bill" << ": R" << std::fixed << std::setprecision(2) << total << "\n";
        std::cout << std::left << std::setw(18) << "Discount Applied" << ": R" << discount << "\n";
        std::cout << std::left << std::setw(18) << "Final Amount" << ": R" << finalAmount << "\n";
        std::cout << "==========================================\n";
        std::cout << "        THANK YOU FOR SHOPPING.           \n";
        std::cout << "==========================================\n";

        pauseForUser();
    }

    void viewInventory() {
        if (cart.empty()) {
            std::cout << "\n[!] Inventory is empty.\n";
        } else {
            std::cout << "\n==========================================\n";
            std::cout << "            CURRENT INVENTORY             \n";
            std::cout << "==========================================\n";
            for (size_t i = 0; i < cart.size(); ++i) {
                std::cout << i + 1 << ". " << cart[i].name 
                          << " - R" << cart[i].price 
                          << " (Stock: " << cart[i].quantity << ")\n";
            }
        }
        pauseForUser();
    }

    void seedDefaultData() {
        cart = {
            {"Chicken Breast(5kg)", 450.00, 2},
            {"LOW FAT MILK (1L)", 60.00, 5},
            {"Bread", 40.00, 3},
            {"Pre Workout", 320.00, 2},
            {"Sweet Potato", 150.00, 1},
            {"Eggs (60)", 180.00, 2}
        };
    }
};

int main() {
    SupermarketBillingSystem system;

    while (true) {
        std::cout << "\n==========================================\n";
        std::cout << "     SUPERMARKET BILLING SYSTEM MENU      \n";
        std::cout << "==========================================\n";
        std::cout << "1. Add Product to Inventory\n";
        std::cout << "2. Calculate Bill\n";
        std::cout << "3. Print Receipt\n";
        std::cout << "4. View Inventory\n";
        std::cout << "5. Exit Program\n";
        std::cout << "------------------------------------------\n";
        std::cout << "Enter your choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                system.addProductToInventory();
                break;
            case 2:
                system.calculateBill();
                break;
            case 3:
                system.printReceipt();
                break;
            case 4:
                system.viewInventory();
                break;
            case 5:
                std::cout << "\nExiting program...\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Select between 1 and 5.\n";
                break;
        }
    }
}