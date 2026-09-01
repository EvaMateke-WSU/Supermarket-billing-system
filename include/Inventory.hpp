#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Product.hpp"
#include <vector>

class Inventory {
private:
    std::vector<Product> stock;

public:
    void addStock(const Product& p);
    void displayStock() const;
    Product findProduct(int id) const;
};

#endif
endig