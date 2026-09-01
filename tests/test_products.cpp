#include "Product.hpp"
#include <cassert>

int main() {
    Product p(1, "Test", 10.0, 2);
    assert(p.getPrice() == 10.0);
    assert(p.getQuantity() == 2);
    return 0;
}
