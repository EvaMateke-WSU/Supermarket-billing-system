#include <iostream>
#include "Product.hpp"
#include "Billing.hpp"
#include "Receipt.hpp"
#include "Validator.hpp"
#include "Inventory.hpp"

int main() {
    Inventory inv;
    inv.addStock(Product(1, "Milk", 20.0, 50));
    inv.addStock(Product(2, "Bread", 15.0, 30));
    inv.addStock(Product(3, "Eggs", 40.0, 100));

    std::cout << "=== Supermarket Billing System ===\n";
    inv.displayStock();

    Billing bill;
    bill.addProduct(Product(1, "Milk", 20.0, 2));
    bill.addProduct(Product(2, "Bread", 15.0, 1));

    Receipt receipt;
    receipt.printReceipt(bill);

    return 0;
}
