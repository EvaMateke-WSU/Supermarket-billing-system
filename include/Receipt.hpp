#ifndef RECEIPT_HPP
#define RECEIPT_HPP

#include "Billing.hpp"

class Receipt {
public:
    void printReceipt(const Billing& bill);
};

#endif
