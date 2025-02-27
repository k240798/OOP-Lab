#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Book {
public:
    Book(const std::string &title, const std::string &author, const std::string &isbn)
        : title(title), author(author), isbn(isbn) {
        std::cout << "Book \"" << title << "\" by " << author << " with ISBN " << isbn << " created." << std::endl;
    }

    std::string getISBN() const {
        return isbn;
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
    }

private:
    std::string title;
    std::string author;
    std::string isbn;
};

class Catalog {
public:
    void addBook(Book *book) {
        catalog[book->getISBN()] = book;
    }

    Book* findBook(const std::string &isbn) {
        if (catalog.find(isbn) != catalog.end()) {
            return catalog[isbn];
        }
        return nullptr; 
    }

private:
    std::unordered_map<std::string, Book*> catalog; 
};

class Library {
public:
    Library(const std::string &name, const std::string &address)
        : name(name), address(address), catalog() {
        std::cout << "Library \"" << name << "\" at " << address << " created." << std::endl;
    }

    void addBook(std::shared_ptr<Book> book) {
        books.push_back(book);
        catalog.addBook(book.get());  
    }

    void removeBook(const std::string &isbn) {
        auto it = std::remove_if(books.begin(), books.end(), [&isbn](const std::shared_ptr<Book> &book) {
            return book->getISBN() == isbn;
        });
        books.erase(it, books.end());  
    }

    void findBookInCatalog(const std::string &isbn) {
        Book* book = catalog.findBook(isbn);
        if (book) {
            book->display();  
        } else {
            std::cout << "Book with ISBN " << isbn << " not found in catalog." << std::endl;
        }
    }

private:
    std::string name;
    std::string address;
    Catalog catalog;  
    std::vector<std::shared_ptr<Book>> books;  
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Usage: " << argv[0] << " <library_name> <library_address> <book1_isbn> <book1_title> <book1_author> ..." << std::endl;
        return 1;
    }

    std::string libraryName = argv[1];
    std::string libraryAddress = argv[2];

    Library library(libraryName, libraryAddress);

    for (int i = 3; i < argc; i += 3) {
        std::string isbn = argv[i];
        std::string title = argv[i + 1];
        std::string author = argv[i + 2];
        
        auto book = std::make_shared<Book>(title, author, isbn);
        library.addBook(book);
    }

    if (argc > 3) {
        std::cout << "Searching for a book with ISBN: " << argv[3] << std::endl;
        library.findBookInCatalog(argv[3]);
    }

    return 0;
}
