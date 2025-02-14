#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string bookName;
    string ISBN;
    string authorName;
    string publisher;

public:
    // Constructor that initializes the Book instance with provided data
    Book(string bName, string isbn, string aName, string pub) {
        this->bookName = bName;
        this->ISBN = isbn;
        this->authorName = aName;
        this->publisher = pub;
    }

    // Query Methods for each attribute
    string getBookName() const {
        return bookName;
    }

    string getISBN() const {
        return ISBN;
    }

    string getAuthorName() const {
        return authorName;
    }

    string getPublisher() const {
        return publisher;
    }

    // Method to return the book's description as a string
    string getBookInfo() const {
        return "Book Name: " + bookName + "\n" +
               "ISBN: " + ISBN + "\n" +
               "Author: " + authorName + "\n" +
               "Publisher: " + publisher;
    }
};

int main(int argc, char* argv[]) {
    // Ensure the program is provided with exactly 20 arguments (5 books * 4 details per book)
    if (argc != 21) {
        cout << "Usage: BookTest <BookName1> <ISBN1> <Author1> <Publisher1> "
             << "<BookName2> <ISBN2> <Author2> <Publisher2> "
             << "<BookName3> <ISBN3> <Author3> <Publisher3> "
             << "<BookName4> <ISBN4> <Author4> <Publisher4> "
             << "<BookName5> <ISBN5> <Author5> <Publisher5>" << endl;
        return 1;
    }

    // Create an array of 5 Book objects using command-line arguments
    Book books[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    // Display the information of each book
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << (i + 1) << " Information:\n";
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}
