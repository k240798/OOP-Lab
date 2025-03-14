#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string genre;  

public:
    Book(const string& genre) : genre(genre) {}

    virtual void displayDetails() = 0;

    virtual ~Book() = default;
};

class Novel : public Book {
private:
    string title;  
    string author; 

public:
    Novel(const string& title, const string& author)
        : Book("Novel"), title(title), author(author) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

class Mystery : public Book {
private:
    string title;  
    string author; 

public:
    Mystery(const string& title, const string& author)
        : Book("Mystery"), title(title), author(author) {}

    void displayDetails() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int main() {
    Novel novel("The Great Gatsby", "F. Scott Fitzgerald");
    Mystery mystery("The Hound of the Baskervilles", "Arthur Conan Doyle");

    cout << "Novel Book Details: " << endl;
    novel.displayDetails();
    cout << endl;

    cout << "Mystery Book Details: " << endl;
    mystery.displayDetails();

    return 0;
}
