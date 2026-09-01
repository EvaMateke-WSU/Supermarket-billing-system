#include "Validator.hpp"
#include <cassert>

int main() {
    assert(Validator::isValidPrice(10.0) == true);
    assert(Validator::isValidPrice(-5.0) == false);

    assert(Validator::isValidQuantity(3) == true);
    assert(Validator::isValidQuantity(0) == false);

    return 0;
}
