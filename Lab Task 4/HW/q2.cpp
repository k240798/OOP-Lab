#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            cerr << "Initial balance cannot be negative." << endl;
            balance = 0; 
        }
    }

    void credit(double amount) {
        if (amount < 0) {
            cerr << "Amount to credit cannot be negative." << endl;
            return;
        }
        balance += amount;
    }

    void debit(double amount) {
        if (amount < 0) {
            cerr << "Amount to debit cannot be negative." << endl;
            return;
        }
        if (amount > balance) {
            cerr << "Insufficient funds for this withdrawal." << endl;
            return;
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: <initial_balance>" << endl;
        return 1;
    }

    double initialBalance = stod(argv[1]);

    Account myAccount(initialBalance);

    cout << "Initial Account Balance: $" << myAccount.getBalance() << endl;

    myAccount.credit(100.50); 
    cout << "Balance after credit: $" << myAccount.getBalance() << endl;

    myAccount.debit(50.00); 
    cout << "Balance after debit: $" << myAccount.getBalance() << endl;

    myAccount.debit(200.00); 

    return 0;
}
