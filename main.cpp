#include "header.hpp"

struct BankAccount
{
    int balance = 0;

    BankAccount() {}
    explicit BankAccount(const int balance) : balance(balance) {}
    void deposit(int amount)
    {
        balance += amount;
    }
    bool withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
};
