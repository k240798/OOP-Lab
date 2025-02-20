#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;      
    string author;     
    double price;      
    string publisher;  
    int stock;         

public:
    Book(string t, string a, double p, string pub, int s) 
        : title(t), author(a), price(p), publisher(pub), stock(s) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }

    string getPublisher() const {
        return publisher;
    }

    int getStock() const {
        return stock;
    }

    void updateStock(int soldCopies) {
        stock -= soldCopies;
    }

    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }

    bool isAvailable(int requestedCopies) const {
        return stock >= requestedCopies;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 1) {
        cerr << "Usage: ./bookshop" << endl;
        return 1;
    }

    vector<Book> inventory = {
        Book("The Catcher in the Rye", "J.D. Salinger", 10.99, "Little, Brown and Company", 5),
        Book("To Kill a Mockingbird", "Harper Lee", 7.99, "J.B. Lippincott & Co.", 3),
        Book("1984", "George Orwell", 8.99, "Secker & Warburg", 4),
        Book("Pride and Prejudice", "Jane Austen", 5.99, "T. Egerton", 2)
    };

    string searchTitle, searchAuthor;
    cout << "Enter the book title: ";
    getline(cin, searchTitle);
    cout << "Enter the book author: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (Book& book : inventory) {  
        if (book.getTitle() == searchTitle && book.getAuthor() == searchAuthor) {
            found = true;
            cout << "Book found!" << endl;
            book.displayBookDetails();

            int requestedCopies;
            cout << "Enter the number of copies required: ";
            cin >> requestedCopies;

            if (book.isAvailable(requestedCopies)) {
                double totalCost = requestedCopies * book.getPrice();
                cout << "Total cost for " << requestedCopies << " copies: $" << totalCost << endl;
                book.updateStock(requestedCopies);
            } else {
                cout << "Required copies not in stock." << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "The book is not available in the inventory." << endl;
    }

    return 0;
}
