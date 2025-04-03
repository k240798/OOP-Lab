#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRateToBase;  

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRateToBase(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRateToBase;
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        double baseAmount = this->convertToBase();
        return baseAmount / targetCurrency.getExchangeRateToBase();
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << " " << amount << " " << currencyCode << endl;
    }

    double getExchangeRateToBase() const {
        return exchangeRateToBase;
    }

    double getAmount() const {
        return amount;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt)
        : Currency(amt, "USD", "$", 1.0) {} 

    void displayCurrency() const override {
        cout << currencySymbol << fixed << setprecision(2) << amount << " " << currencyCode << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt)
        : Currency(amt, "EUR", "€", 0.85) {}  

    void displayCurrency() const override {
        cout << currencySymbol << fixed << setprecision(2) << amount << " " << currencyCode << endl;
    }
};

class PKR : public Currency {
public:
    PKR(double amt)
        : Currency(amt, "PKR", "₨", 0.0036) {}  

    void displayCurrency() const override {
        cout << currencySymbol << fixed << setprecision(2) << amount << " " << currencyCode << endl;
    }
};

int main() {
    Dollar dollarAmount(100);     
    Euro euroAmount(100);         
    PKR pkrAmount(10000);         

    cout << "Original Currency Values:" << endl;
    dollarAmount.displayCurrency();
    euroAmount.displayCurrency();
    pkrAmount.displayCurrency();

    double convertedToDollar = euroAmount.convertTo(dollarAmount);
    cout << "\n100 EUR in USD: " << fixed << setprecision(2) << convertedToDollar << " USD" << endl;

    double convertedToEuro = pkrAmount.convertTo(euroAmount);
    cout << "10000 PKR in EUR: " << fixed << setprecision(2) << convertedToEuro << " EUR" << endl;

    double convertedToPKR = dollarAmount.convertTo(pkrAmount);
    cout << "100 USD in PKR: " << fixed << setprecision(2) << convertedToPKR << " PKR" << endl;

    return 0;
}
