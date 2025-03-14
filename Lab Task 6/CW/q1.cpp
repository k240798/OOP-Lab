#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class BankAccount {
public:
    BankAccount(string accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    virtual void printAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}

protected:
    string accountNumber;
    double balance;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accountNumber, double balance, double interestRate)
        : BankAccount(accountNumber, balance), interestRate(interestRate) {}

    void applyInterest() {
        balance += balance * (interestRate / 100);
    }

    void printAccountDetails() const override {
        BankAccount::printAccountDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

private:
    double interestRate;
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(string accountNumber, double balance, double overdraftLimit)
        : BankAccount(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void printAccountDetails() const override {
        BankAccount::printAccountDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }

private:
    double overdraftLimit;
};

class BusinessAccount : public BankAccount {
public:
    BusinessAccount(string accountNumber, double balance, double corporateTaxRate)
        : BankAccount(accountNumber, balance), corporateTaxRate(corporateTaxRate) {}

    void deposit(double amount) override {
        double tax = amount * (corporateTaxRate / 100);
        balance += (amount - tax);
    }

    void printAccountDetails() const override {
        BankAccount::printAccountDetails();
        cout << "Corporate Tax Rate: " << corporateTaxRate << "%" << endl;
    }

private:
    double corporateTaxRate;
};

class User {
public:
    virtual void performOperations(BankAccount &account) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    void performOperations(BankAccount &account) override {
        int choice;
        double amount;

        cout << "Customer Operations: " << endl;
        cout << "1. Deposit\n2. Withdraw\nChoose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            account.withdraw(amount);
        }

        account.printAccountDetails();
    }
};

class Employee : public User {
protected:
    string name;
    string role;

public:
    Employee(string name, string role)
        : name(name), role(role) {}

    virtual void performOperations(BankAccount &account) = 0;
};

class Teller : public Employee {
public:
    Teller(string name) : Employee(name, "Teller") {}

    void performOperations(BankAccount &account) override {
        int choice;
        double amount;

        cout << "Teller Operations: " << endl;
        cout << "1. Deposit\n2. Withdraw\n3. Freeze Account\nChoose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            cout << "Account frozen. No further operations possible." << endl;
        }

        account.printAccountDetails();
    }
};

class Manager : public Employee {
public:
    Manager(string name) : Employee(name, "Manager") {}

    void performOperations(BankAccount &account) override {
        int choice;
        double amount;

        cout << "Manager Operations: " << endl;
        cout << "1. Deposit\n2. Withdraw\n3. Freeze Account\n4. Override Account Limit\nChoose operation: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            cout << "Account frozen. No further operations possible." << endl;
        } else if (choice == 4) {
            cout << "Override account limit (if any) or adjust parameters." << endl;
        }

        account.printAccountDetails();
    }
};

int main() {
    SavingsAccount savings("SA001", 5000, 3.5);
    CheckingAccount checking("CA001", 2000, 500);
    BusinessAccount business("BA001", 10000, 5.0);

    Customer customer;
    Teller teller("John Doe");
    Manager manager("Jane Smith");

    vector<unique_ptr<User>> users;
    users.push_back(make_unique<Customer>());
    users.push_back(make_unique<Teller>("Alice"));
    users.push_back(make_unique<Manager>("Bob"));

    vector<unique_ptr<BankAccount>> accounts;
    accounts.push_back(make_unique<SavingsAccount>(savings));
    accounts.push_back(make_unique<CheckingAccount>(checking));
    accounts.push_back(make_unique<BusinessAccount>(business));

    for (auto& user : users) {
        for (auto& account : accounts) {
            user->performOperations(*account);
        }
    }

    return 0;
}
