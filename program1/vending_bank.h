#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include <string>

// Do the banking part
/*
- how many coins (nickels, dimes, etc)
- do you have change for this amount
- insert coins
*/

struct Wallet {
    int dollars;
    int quarters;
    int dimes;
    int nickels;
    int pennies;
};

class VendingBank {
    public:
        // Constructors
        VendingBank();
        VendingBank(int id);

        // getters-setters
        int id() const;
        float total() const; // how much money is in the machine added up
        const Wallet* coins() const; // More descriptive representation of what is in the machine. const pointer to the internal wallet is returned 

        // Method takes in the item id, such as "A4", and a wallet struct. Wallet struct contains the amount of money a person puts into the machine.
        // This method will check if the item is still in stock. If it is, it will call the CanBuy() method. If the method is successful, it it will call TakeMoney()
        // Returns boolean if buying was successful or not.
        // If purchase is successful, the reference to the buyer's wallet is modified with the change owed back to them.
        bool BuyItem(const std::string &item_id, Wallet &wallet);

    private:
        int id_;

        // keep track of money saved in the machine
        Wallet money_;

        // Takes in a string of the item id and a struct of how much money the person has put in.
        // This method calls CalculateChange().
        // This method will modify:
        // 1. The Vending Bank's money inside of the machine. Adds how much money put in and subtracts money owed.
        // 2. Modifies the wallet reference with money owed back to the person.
        bool TakeMoney(const std::string &item_id, Wallet &wallet);

        // Takes in a string of the item id and a struct of hwo much money the person has put in.
        // Modifies nothing.
        // Returns a Wallet struct of how much change is owed by the machine back to the person.
        // This method will take into account what is inside of the VendingBank and give back the appropriate combination of coins.
        Wallet CalculateChange(const std::string &item_id, const Wallet &wallet);

        // This method takes in the item id and wallet struct containing money inserted into the machine.
        // Responsible for checking if the money put in is enough to:
        // 1. buy the item
        // 2. the machine has a way to give back amount of change owed.
        bool CanBuy(const std::string &item_id, const Wallet &wallet);
};

#endif