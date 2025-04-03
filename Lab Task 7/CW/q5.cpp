#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Checked Out: " << (isCheckedOut ? "Yes" : "No") << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }
    static void searchByTitle(const vector<Media*>& mediaList, const string& searchTitle) {
        for (const auto& media : mediaList) {
            if (media->title == searchTitle) {
                media->displayInfo();
                return;
            }
        }
        cout << "No media found with the title: " << searchTitle << endl;
    }

    static void searchByPublicationYear(const vector<Media*>& mediaList, const string& year) {
        bool found = false;
        for (const auto& media : mediaList) {
            if (media->publicationDate.substr(0, 4) == year) {
                media->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No media found for the year: " << year << endl;
        }
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration; 
    float rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, float rat)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << " / 5" << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    string issue;
    string genre;

public:
    Magazine(string t, string pubDate, string id, string pub, string iss, string gen)
        : Media(t, pubDate, id, pub), issue(iss), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue: " << issue << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Book book1("C++ Programming", "2022-05-01", "B001", "Tech Press", "John Doe", "978-1234567890", 350);
    DVD dvd1("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, 4.8);
    CD cd1("Thriller", "1982-11-30", "C001", "Epic", "Michael Jackson", 9, "Pop");
    Magazine mag1("Tech Weekly", "2023-03-01", "M001", "Tech Magazines", "March 2023", "Technology");

    vector<Media*> mediaList = { &book1, &dvd1, &cd1, &mag1 };

    cout << "---- All Media Info ----" << endl;
    for (const auto& media : mediaList) {
        media->displayInfo();
        cout << endl;
    }

    cout << "---- Search for Book by Title ----" << endl;
    Media::searchByTitle(mediaList, "C++ Programming");
    cout << endl;

    cout << "---- Search for Media by Publication Year ----" << endl;
    Media::searchByPublicationYear(mediaList, "2023");
    cout << endl;

    cout << "---- Check Out and Return Items ----" << endl;
    book1.checkOut();
    dvd1.checkOut();
    book1.returnItem();
    dvd1.returnItem();
    cout << endl;

    return 0;
}
