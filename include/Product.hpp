#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int id, const std::string& name, double price, int quantity);
    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setQuantity(int q);
    void display() const;
};

#endif
