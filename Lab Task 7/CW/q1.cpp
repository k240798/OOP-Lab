#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, double initialBalance, const string& holderName, const string& type = "")
        : accountNumber(accNum), balance(initialBalance), accountHolderName(holderName), accountType(type) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    virtual double calculateInterest() const {
        return 0.0;  
    }

    virtual void printStatement() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
    }

    void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        if (!accountType.empty()) {
            cout << "Account Type: " << accountType << endl;
        }
    }
};

class SavingsAccount : public Account {
private:
    double interestRate; 

public:
    SavingsAccount(int accNum, double initialBalance, const string& holderName, double rate)
        : Account(accNum, initialBalance, holderName, "Savings"), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Interest: " << calculateInterest() << endl;
    }
};

class CheckingAccount : public Account {
private:
    double minimumBalance;  

public:
    CheckingAccount(int accNum, double initialBalance, const string& holderName, double minBalance)
        : Account(accNum, initialBalance, holderName, "Checking"), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && (balance - amount) >= minimumBalance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient funds or below minimum balance." << endl;
        }
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;  
    string maturityDate;      

public:
    FixedDepositAccount(int accNum, double initialBalance, const string& holderName, double rate, const string& maturity)
        : Account(accNum, initialBalance, holderName, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() const override {
        return balance * fixedInterestRate / 100;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Interest: " << calculateInterest() << endl;
    }
};

int main() {
    SavingsAccount savingsAcc(101, 10000, "John Doe", 5.0);
    CheckingAccount checkingAcc(102, 5000, "Jane Smith", 1000);
    FixedDepositAccount fdAcc(103, 20000, "Robert Brown", 6.0, "2025-12-31");

    savingsAcc.deposit(2000);
    checkingAcc.withdraw(1500);
    fdAcc.deposit(5000);

    savingsAcc.printStatement();
    checkingAcc.printStatement();
    fdAcc.printStatement();

    savingsAcc.getAccountInfo();
    checkingAcc.getAccountInfo();
    fdAcc.getAccountInfo();

    return 0;
}
