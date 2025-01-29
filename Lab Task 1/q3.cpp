#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int customerID, units;
    string customerName;
    double amount = 0.0, surcharge = 0.0, netAmount = 0.0;


    cout << "Enter Customer ID: ";
    cin >> customerID;
    cin.ignore(); 
    cout << "Enter Customer Name: ";
    getline(cin, customerName);
    cout << "Enter Units Consumed: ";
    cin >> units;

    if (units <= 199) {
        amount = units * 16.20;
    } else if (units >= 200 && units < 300) {
        amount = units * 20.10;
    } else if (units >= 300 && units < 500) {
        amount = units * 27.10;
    } else {
        amount = units * 35.90;
    }

    if (amount > 18000) {
        surcharge = 0.15 * amount;
    }

    netAmount = amount + surcharge;

    cout << "\nElectricity Bill\n";
    cout << "Customer ID: " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Units Consumed: " << units << endl;
    cout << fixed << setprecision(2);
    cout << "Amount Charges @Rs. " << (units >= 500 ? 35.90 : (units >= 300 ? 27.10 : (units >= 200 ? 20.10 : 16.20)))
         << " per unit: " << amount << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << netAmount << endl;

    return 0;
}
