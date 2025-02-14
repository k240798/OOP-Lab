#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> matrixData;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        matrixData.resize(rows, vector<int>(cols, 0));  
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            matrixData[i][j] = value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }

    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return matrixData[i][j];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1; // Error value
        }
    }

    Matrix add(const Matrix& other) {
        if (rows != other.getRows() || cols != other.getCols()) {
            cout << "Matrices cannot be added." << endl;
            return Matrix(0, 0);  // Return an empty matrix
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, matrixData[i][j] + other.matrixData[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) {
        if (cols != other.getRows()) {
            cout << "Matrices cannot be multiplied." << endl;
            return Matrix(0, 0);  // Return an empty matrix
        }

        Matrix result(rows, other.getCols());
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.getCols(); ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += matrixData[i][k] * other.matrixData[k][j];
                }
                result.setElement(i, j, sum);
            }
        }
        return result;
    }

    // Method to print the matrix
    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrixData[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 10) {
        cout << "Usage: MatrixTest <rows1> <cols1> <element11> <element12> ... <rows2> <cols2> <element21> <element22> ..." << endl;
        return 1;
    }

    int rows1 = stoi(argv[1]);
    int cols1 = stoi(argv[2]);
    Matrix matrix1(rows1, cols1);

    int index = 3;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            matrix1.setElement(i, j, stoi(argv[index++]));
        }
    }

    int rows2 = stoi(argv[index++]);
    int cols2 = stoi(argv[index++]);
    Matrix matrix2(rows2, cols2);

    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            matrix2.setElement(i, j, stoi(argv[index++]));
        }
    }

    cout << "Matrix 1:" << endl;
    matrix1.printMatrix();

    cout << "Matrix 2:" << endl;
    matrix2.printMatrix();

    Matrix sumMatrix = matrix1.add(matrix2);
    if (sumMatrix.getRows() > 0 && sumMatrix.getCols() > 0) {
        cout << "\nSum of Matrices:" << endl;
        sumMatrix.printMatrix();
    }

    Matrix productMatrix = matrix1.multiply(matrix2);
    if (productMatrix.getRows() > 0 && productMatrix.getCols() > 0) {
        cout << "\nProduct of Matrices:" << endl;
        productMatrix.printMatrix();
    }

    return 0;
}
