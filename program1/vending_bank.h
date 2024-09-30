#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include<string>

class VendingBank {
    public:
        // Constructors
        VendingBank();
        VendingBank(int id);

        // getters-setters
        int id() const;

    private:
        int _id;

};

#endif