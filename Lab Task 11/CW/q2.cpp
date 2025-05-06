#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match.";
    }
};

template<typename T>
class Matrix {
private:
    size_t rows, cols;
    vector<vector<T>> data;

public:
    Matrix(size_t rows, size_t cols, const T& initial = T()) :
        rows(rows), cols(cols), data(rows, vector<T>(cols, initial)) {}

    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }

    T& at(size_t row, size_t col) {
        if (row >= rows || col >= cols)
            throw out_of_range("Matrix access out of bounds");
        return data[row][col];
    }

    const T& at(size_t row, size_t col) const {
        if (row >= rows || col >= cols)
            throw out_of_range("Matrix access out of bounds");
        return data[row][col];
    }

    // Operator () overload
    T& operator()(size_t row, size_t col) { return at(row, col); }
    const T& operator()(size_t row, size_t col) const { return at(row, col); }

    // Addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other(i, j);

        return result;
    }

    // Multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();

        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other(k, j);
                }
            }
        }
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row)
                cout << elem << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix<int> A(2, 2, 1);
    Matrix<int> B(2, 2, 2);
    Matrix<int> C = A + B;
    C.print();
    return 0;
}
