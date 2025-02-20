#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;    
    string partDescription; 
    int quantity;         
    double pricePerItem; 

public:
    Invoice(string partNum, string partDesc, int qty, double price) {
        partNumber = partNum;
        partDescription = partDesc;

        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }

        if (price > 0) {
            pricePerItem = price;
        } else {
            pricePerItem = 0.0;
        }
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    string getPartNumber() const {
        return partNumber;
    }

    string getPartDescription() const {
        return partDescription;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: <partNumber> <partDescription> <quantity> <pricePerItem>" << endl;
        return 1;
    }

    string partNumber = argv[1];
    string partDescription = argv[2];
    int quantity = stoi(argv[3]);  
    double pricePerItem = stod(argv[4]); 

    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);

    cout << "Invoice Details:" << endl;
    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price per Item: $" << invoice.getPricePerItem() << endl;
    cout << "Total Invoice Amount: $" << invoice.getInvoiceAmount() << endl;

    return 0;
}
