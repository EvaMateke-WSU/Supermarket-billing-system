#include "Billing.hpp"

void Billing::addProduct(const Product& p) {
    cart.push_back(p);
}

double Billing::calculateTotal() const {
    double total = 0;
    for (const auto& item : cart) {
        total += item.getPrice() * item.getQuantity();
    }
    return total;
}

double Billing::applyDiscount(double total) const {
    if (total > 500) return total * 0.9; // 10% discount
    return total;
}

std::vector<Product> Billing::getCart() const {
    return cart;
}
