#include <iostream>
#include <exception>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds!";
    }
};

template <typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    SafeArray(int size) {
        if (size <= 0) throw invalid_argument("Size must be positive.");
        this->size = size;
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

int main() {
    try {
        SafeArray<int> myArray(5);
        for (int i = 0; i < myArray.getSize(); ++i) {
            myArray[i] = i * 10;
        }

        cout << "Array contents:\n";
        for (int i = 0; i < myArray.getSize(); ++i) {
            cout << myArray[i] << " ";
        }
        cout << endl;

        // Accessing invalid index to trigger exception
        cout << "Trying to access index 10...\n";
        cout << myArray[10] << endl; // Should throw
    }
    catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Other exception: " << e.what() << endl;
    }

    return 0;
}
