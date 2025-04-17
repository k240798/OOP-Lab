#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDeposited;
    double dailyWithdrawn;
    
    const double MAX_DAILY_DEPOSIT = 10000.0;
    const double MAX_DAILY_WITHDRAWAL = 5000.0;

public:
    Wallet() : balance(0.0), dailyDeposited(0.0), dailyWithdrawn(0.0) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive\n";
            return false;
        }

        if (dailyDeposited + amount > MAX_DAILY_DEPOSIT) {
            cout << "Error: Exceeds daily deposit limit\n";
            return false;
        }

        balance += amount;
        dailyDeposited += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive\n";
            return false;
        }

        if (amount > balance) {
            cout << "Error: Insufficient funds\n";
            return false;
        }

        if (dailyWithdrawn + amount > MAX_DAILY_WITHDRAWAL) {
            cout << "Error: Exceeds daily withdrawal limit\n";
            return false;
        }

        balance -= amount;
        dailyWithdrawn += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyCounters() {
        dailyDeposited = 0.0;
        dailyWithdrawn = 0.0;
    }
};

class User {
private:
    string userId;
    string name;
    Wallet wallet;

public:
    User(const string& id, const string& userName) 
        : userId(id), name(userName) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }

    string getUserId() const {
        return userId;
    }

    string getName() const {
        return name;
    }

    void resetDailyCounters() {
        wallet.resetDailyCounters();
    }

    void printDailyStats() const {
        cout << "Balance: " << wallet.getBalance() << "\n";
    }
};

int main() {
    User umer("B3864", "Umer");
    User usman("B123", "Usman");

    cout << "Umer deposits $500: ";
    if (umer.deposit(500)) {
        cout << "Success! New balance: " << umer.checkBalance() << "\n";
    }

    cout << "Usman deposits $1000: ";
    if (usman.deposit(1000)) {
        cout << "Success! New balance: " << usman.checkBalance() << "\n";
    }

    cout << "Umer withdraws $200: ";
    if (umer.withdraw(200)) {
        cout << "Success! New balance: " << umer.checkBalance() << "\n";
    }

    cout << "Umer tries to withdraw $1000: ";
    umer.withdraw(1000); 

    cout << "Usman tries to deposit $-100: ";
    usman.deposit(-100); 

    cout << "\nTesting daily deposit limit:\n";
    for (int i = 1; i <= 11; i++) {
        cout << "Umer deposits $1000 (attempt " << i << "): ";
        if (!umer.deposit(1000)) {
            break; 
        }
        cout << "Success! New balance: " << umer.checkBalance() << "\n";
    }

    cout << "\nResetting daily counters...\n";
    umer.resetDailyCounters();
    cout << "Umer deposits $500: ";
    if (umer.deposit(500)) {
        cout << "Success! New balance: " << umer.checkBalance() << "\n";
    }

    return 0;
}