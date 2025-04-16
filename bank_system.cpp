#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Account
{
protected:
    string accountHolder;
    double balance;

public:
    Account(string name, double initialBalance)
    {
        accountHolder = name;
        balance = initialBalance;
    }

    string getAccountHolder()
    {
        return accountHolder;
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double amount)
    {
        balance = amount;
    }

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void display() = 0;
};

// SavingsAccount class
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(string name, double initialBalance, double rate)
        : Account(name, initialBalance)
    {
        interestRate = rate;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " into Savings Account.\n";
    }

    void withdraw(double amount) override
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrew " << amount << " from Savings Account.\n";
        }
        else
        {
            cout << "Insufficient funds in Savings Account.\n";
        }
    }

    void display() override
    {
        cout << "Savings Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// CheckingAccount class
class CheckingAccount : public Account
{
private:
    double transactionFee;

public:
    CheckingAccount(string name, double initialBalance, double fee)
        : Account(name, initialBalance)
    {
        transactionFee = fee;
    }

    void deposit(double amount) override
    {
        balance += amount;
        cout << "Deposited " << amount << " into Checking Account.\n";
    }

    void withdraw(double amount) override
    {
        double totalAmount = amount + transactionFee;
        if (balance >= totalAmount)
        {
            balance -= totalAmount;
            cout << "Withdrew " << amount << " with a fee of " << transactionFee << " from Checking Account.\n";
        }
        else
        {
            cout << "Insufficient funds in Checking Account.\n";
        }
    }

    void display() override
    {
        cout << "Checking Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction Fee: " << transactionFee << endl;
    }
};

int main()
{
    Account *account1 = new SavingsAccount("Alice", 1000.0, 2.5);
    Account *account2 = new CheckingAccount("Bob", 2000.0, 5.0);

    account1->deposit(500);
    account1->withdraw(200);
    account1->display();

    cout << "---------------------------\n";

    account2->deposit(1000);
    account2->withdraw(500);
    account2->display();

    delete account1;
    delete account2;

    return 0;
}
