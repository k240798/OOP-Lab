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

    string getBookInfo() const {
        return "Book Name: " + bookName + "\n" +
               "ISBN: " + ISBN + "\n" +
               "Author: " + authorName + "\n" +
               "Publisher: " + publisher;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 21) {
        cout << "Usage: BookTest <BookName1> <ISBN1> <Author1> <Publisher1> "
             << "<BookName2> <ISBN2> <Author2> <Publisher2> "
             << "<BookName3> <ISBN3> <Author3> <Publisher3> "
             << "<BookName4> <ISBN4> <Author4> <Publisher4> "
             << "<BookName5> <ISBN5> <Author5> <Publisher5>" << endl;
        return 1;
    }

    Book books[5] = {
        Book(argv[1], argv[2], argv[3], argv[4]),
        Book(argv[5], argv[6], argv[7], argv[8]),
        Book(argv[9], argv[10], argv[11], argv[12]),
        Book(argv[13], argv[14], argv[15], argv[16]),
        Book(argv[17], argv[18], argv[19], argv[20])
    };

    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << (i + 1) << " Information:\n";
        cout << books[i].getBookInfo() << endl;
    }

    return 0;
}
