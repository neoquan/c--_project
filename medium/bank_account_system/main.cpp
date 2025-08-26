#include <iostream>
#include <string>
#include <vector>

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
    // check the account balance of user
    void checkBalance() const
    {
        cout << "Account " << accountNumber << " (" << owner << ") balance: " << balance << endl;
    }

    // get the account number of user
    int getAccountNumber() const {return accountNumber; }

};

int main()
{
    vector<Account> accounts;

    // Create accounts.
    // push_back → constructs a temporary Account, then moves it into the vector.
    // emplace_back → constructs the Account in place inside the vector.
    accounts.emplace_back(1001, "Alice", 500.0);
    accounts.emplace_back(1002, "Bob", 1000.0);

    accounts[1].checkBalance();

    int searchAcc = 1002;

    for (auto &i : accounts) {
        if (i.getAccountNumber() == searchAcc) {
            i.deposit(500);
            i.checkBalance();
        }
    }
}