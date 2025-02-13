#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    string isbnNumber;
    string authorName;
    string publisher;

public:
    Book(string bookName, string isbnNumber, string authorName, string publisher) {
        this->bookName = bookName;
        this->isbnNumber = isbnNumber;
        this->authorName = authorName;
        this->publisher = publisher;
    }

    string getBookName() const {
        return bookName;
    }

    string getIsbnNumber() const {
        return isbnNumber;
    }

    string getAuthorName() const {
        return authorName;
    }

    string getPublisher() const {
        return publisher;
    }

    string getBookInfo() const {
        return "Book Name: " + bookName + "\nISBN Number: " + isbnNumber + "\nAuthor: " + authorName + "\nPublisher: " + publisher;
    }
};

int main() {
    Book books[5] = {
        Book("The Catcher in the Rye", "978-0-316-76948-0", "J.D. Salinger", "Little, Brown and Company"),
        Book("1984", "978-0-452-28423-4", "George Orwell", "Secker & Warburg"),
        Book("To Kill a Mockingbird", "978-0-06-112008-4", "Harper Lee", "J.B. Lippincott & Co."),
        Book("The Great Gatsby", "978-0-7432-7356-5", "F. Scott Fitzgerald", "Scribner"),
        Book("Moby-Dick", "978-0-14-243724-7", "Herman Melville", "Harper & Brothers")
    };

    for (int i = 0; i < 5; ++i) {
        cout << "Book " << i + 1 << " Information:\n";
        cout << books[i].getBookInfo() << "\n\n";
    }

    return 0;
}
