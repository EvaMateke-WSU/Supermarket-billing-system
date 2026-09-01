#include "Receipt.hpp"
#include <iostream>

void Receipt::printReceipt(const Billing& bill) {
    auto cart = bill.getCart();
    std::cout << "\n=== RECEIPT ===\n";
    for (const auto& item : cart) {
        item.display();
    }
    double total = bill.calculateTotal();
    double discounted = bill.applyDiscount(total);
    std::cout << "Total: R" << total << std::endl;
    if (discounted < total) {
        std::cout << "Discounted Total: R" << discounted << std::endl;
    }
    std::cout << "================\n";
}
