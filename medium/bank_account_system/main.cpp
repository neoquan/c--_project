#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Account
{
    private:
        int accountNumber;
        string owner;
        double balance;
    
    // This is called a member initializer list.
    // It assigns values to private variables before the constructor body runs.
    // Account(int accNo, string name, double initialBalance = 0.0) {
    //     accountNumber = accNo;
    //      owner = name;
    //      balance = initialBalance;
    // }

    public:
        Account (int accNo, string name, double initialBal = 0.0)
            : accountNumber(accNo), owner(name), balance(initialBal) {}

    void deposit (double amount) 
    {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw (double amount) 
    {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withraw " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }

    // const in functions => This function will NOT modify the object’s data members
    void checkBalance() const
    {
        cout << "Account " << accountNumber << " (" << owner << ") balance: " << balance << endl;
    }

    int getAccountNumber() const {return accountNumber; }

};