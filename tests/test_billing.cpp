#include "Billing.hpp"
#include "Product.hpp"
#include <cassert>

int main() {
    Billing bill;
    bill.addProduct(Product(1, "Milk", 20.0, 2));
    bill.addProduct(Product(2, "Bread", 15.0, 1));

    double total = bill.calculateTotal();
    assert(total == 55.0); // 20*2 + 15*1

    double discounted = bill.applyDiscount(total);
    assert(discounted == 55.0); // No discount since < 500

    return 0;
}
