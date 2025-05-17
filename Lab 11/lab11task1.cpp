#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(const string& mess) : message(mess) {}
    const char* what() const noexcept{
        return message.c_str();
    }
};


template <class T, int ROWS, int COLS>
class Matrix {
    int rows;
    int columns;
    T array[ROWS][COLS]; 

public:
    
    Matrix(int r, int c) : rows(r), columns(c) {
    
    }
    void input(){
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < columns; ++j) {
                cin >> array[i][j];
            }
        }
    }   
    
    Matrix addition(const Matrix& other) {
        if (rows != other.rows || columns != other.columns) {
            throw DimensionMismatchException("DimensionMismatchException: (" + to_string(rows) + "x" + to_string(columns) + ") and (" + to_string(other.rows) + "x" + to_string(other.columns) + ")");
        }
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.array[i][j] = array[i][j] + other.array[i][j];
            }
        }
        return result;
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    const int ROWS = 10; 
    const int COLS = 10; 

    try {
    
        Matrix<int, ROWS, COLS> m1(2,2);
        m1.input();


        Matrix<int, ROWS, COLS> m2(2,2);
        m2.input();

        Matrix<int, ROWS, COLS> result = m1.addition(m2);
        cout << "Resultant Matrix:" << endl;
        result.display();
    } catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;
}
}