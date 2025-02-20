#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int currentSize;

    void allocateMemory(int size) {
        data = new int[size] {};
        currentSize = size;
    }

    void deallocateMemory() {
        delete[] data;
    }

public:
    DynamicArray() : data(nullptr), currentSize(0) {}

    DynamicArray(int n) : data(nullptr), currentSize(0) {
        if (n > 0) {
            allocateMemory(n);
        }
    }

    DynamicArray(const DynamicArray& other) : data(nullptr), currentSize(0) {
        if (other.currentSize > 0) {
            allocateMemory(other.currentSize);
            for (int i = 0; i < other.currentSize; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    ~DynamicArray() {
        if (data != nullptr) {
            deallocateMemory();
        }
    }

    int size() const {
        return currentSize;
    }

    int& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize == currentSize) return;
        int* newData = new int[newSize] {};
        int elementsToCopy = (newSize < currentSize) ? newSize : currentSize;
        for (int i = 0; i < elementsToCopy; ++i) {
            newData[i] = data[i];
        }

        deallocateMemory();
        data = newData;
        currentSize = newSize;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: <size> <elements...>" << endl;
        return 1;
    }

    int size = stoi(argv[1]);
    DynamicArray arr(size);

    for (int i = 0; i < size; ++i) {
        arr.at(i) = stoi(argv[i + 2]);
    }

    cout << "Dynamic Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    return 0;
}
