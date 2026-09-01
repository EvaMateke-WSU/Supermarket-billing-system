#include "Inventory.hpp"
#include <iostream>

void Inventory::addStock(const Product& p) {
    stock.push_back(p);
}

void Inventory::displayStock() const {
    std::cout << "\n=== INVENTORY ===\n";
    for (const auto& item : stock) {
        item.display();
    }
}

Product Inventory::findProduct(int id) const {
    for (const auto& item : stock) {
        if (item.getId() == id) return item;
    }
    return Product(-1, "Not Found", 0, 0);
}
