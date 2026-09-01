#include "Product.hpp"
#include <iostream>

Product::Product(int id, const std::string& name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }
void Product::setQuantity(int q) { quantity = q; }

void Product::display() const {
    std::cout << id << " - " << name << " | R" << price << " x " << quantity << std::endl;
}
