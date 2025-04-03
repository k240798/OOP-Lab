#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    Number(int v) : value(v) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;  
        value /= 4;
        return temp;  
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(16);  

    cout << "Initial value: ";
    num.display();

    --num;
    cout << "After prefix decrement (--num): ";
    num.display();

    num--;
    cout << "After postfix decrement (num--): ";
    num.display();

    return 0;
}
