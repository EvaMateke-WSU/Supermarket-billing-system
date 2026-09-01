#include "Validator.hpp"

bool Validator::isValidPrice(double price) {
    return price >= 0;
}

bool Validator::isValidQuantity(int quantity) {
    return quantity > 0;
}
