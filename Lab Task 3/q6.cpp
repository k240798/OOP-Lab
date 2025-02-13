#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        mat.resize(rows, vector<int>(cols, 0)); 
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return mat[i][j];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1; 
        }
    }

    Matrix add(const Matrix& other) {
        if (this->rows != other.rows || this->cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0); 
        }

        Matrix result(this->rows, this->cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, this->getElement(i, j) + other.getElement(i, j));
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) {
        if (this->cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0); 
        }

        Matrix result(this->rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += this->getElement(i, k) * other.getElement(k, j);
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix matrix1(2, 3);
    Matrix matrix2(2, 3);

    matrix1.setElement(0, 0, 1);
    matrix1.setElement(0, 1, 2);
    matrix1.setElement(0, 2, 3);
    matrix1.setElement(1, 0, 4);
    matrix1.setElement(1, 1, 5);
    matrix1.setElement(1, 2, 6);

    matrix2.setElement(0, 0, 7);
    matrix2.setElement(0, 1, 8);
    matrix2.setElement(0, 2, 9);
    matrix2.setElement(1, 0, 10);
    matrix2.setElement(1, 1, 11);
    matrix2.setElement(1, 2, 12);

    cout << "Matrix 1:" << endl;
    matrix1.display();

    cout << "Matrix 2:" << endl;
    matrix2.display();

    Matrix sum = matrix1.add(matrix2);
    cout << "\nSum of Matrix 1 and Matrix 2:" << endl;
    sum.display();

    Matrix matrix3(3, 2);
    Matrix matrix4(2, 3);

    matrix3.setElement(0, 0, 1);
    matrix3.setElement(0, 1, 2);
    matrix3.setElement(1, 0, 3);
    matrix3.setElement(1, 1, 4);
    matrix3.setElement(2, 0, 5);
    matrix3.setElement(2, 1, 6);

    matrix4.setElement(0, 0, 7);
    matrix4.setElement(0, 1, 8);
    matrix4.setElement(0, 2, 9);
    matrix4.setElement(1, 0, 10);
    matrix4.setElement(1, 1, 11);
    matrix4.setElement(1, 2, 12);

    Matrix product = matrix3.multiply(matrix4);
    cout << "\nProduct of Matrix 3 and Matrix 4:" << endl;
    product.display();

    return 0;
}
