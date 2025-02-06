#include <iostream>
#include <string>
using namespace std;

void resize(int*& arr, int& capacity, int newCapacity, int size) {
    int* newArr = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

int main() {
    int initialSize = 5;
    int capacity = initialSize;
    int size = 0;
    int* arr = new int[capacity];

    for (int i = 1; i <= 15; i++) {
        if (size >= 2 * capacity) {
            resize(arr, capacity, 2 * capacity, size);
        }
        arr[size++] = i;
    }

    cout << "Before final resize:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nCapacity: " << capacity << "\n";

    resize(arr, capacity, size, size);

    cout << "After final resize:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nCapacity: " << capacity << "\n";

    delete[] arr;
    return 0;
}
