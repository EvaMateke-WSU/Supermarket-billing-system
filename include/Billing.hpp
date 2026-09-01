#ifndef BILLING_HPP
#define BILLING_HPP

#include "Product.hpp"
#include <vector>

class Billing {
private:
    std::vector<Product> cart;

public:
    void addProduct(const Product& p);
    double calculateTotal() const;
    double applyDiscount(double total) const;
    std::vector<Product> getCart() const;
};

#endif
end iff