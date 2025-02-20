#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

class Matrix {
private:
    double** data;
    int rows, cols;

    void allocateMemory(int r, int c) {
        data = new double*[r];
        for (int i = 0; i < r; ++i) {
            data[i] = new double[c] {};
        }
        rows = r;
        cols = c;
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    Matrix() : data(nullptr), rows(0), cols(0) {}

    Matrix(int r, int c) : data(nullptr), rows(0), cols(0) {
        allocateMemory(r, c);
    }

    Matrix(const Matrix& other) : data(nullptr), rows(0), cols(0) {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < other.rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        if (data != nullptr) {
            deallocateMemory();
        }
    }

    void fill(double value) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = value;
            }
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    double& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[r][c];
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: <rows> <cols> [elements...]" << endl;
        return 1;
    }

    int rows = stoi(argv[1]);
    int cols = stoi(argv[2]);

    if (argc != (3 + rows * cols)) {
        cerr << "Error: Number of elements does not match matrix size." << endl;
        return 1;
    }

    Matrix mat(rows, cols);

    int idx = 3;  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat.at(i, j) = stod(argv[idx++]);
        }
    }

    mat.print();

    return 0;
}
