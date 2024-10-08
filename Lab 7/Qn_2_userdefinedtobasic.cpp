// User defined to basic type

#include <iostream>
using namespace std;

class Matrix
{
private:
    int row, col;
    int **matrix;

public:
    Matrix(int row = 0, int col = 0) : row(row), col(col)
    {
        matrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
        }
    }

    void read()
    {
        cout << "Enter the elements of the matrix: " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void show() const
    {
        cout << "Matrix: " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &m) const
    {
        Matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return temp;
    }

    Matrix operator*(const Matrix &m) const
    {
        Matrix temp(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp.matrix[i][j] = matrix[i][j] * m.matrix[i][j];
            }
        }
        return temp;
    }

    operator int() const
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    Matrix m1(2, 2), m2(2, 2);
    m1.read();
    m2.read();
    cout << "Matrix 1: " << endl;
    m1.show();
    cout << "Matrix 2: " << endl;
    m2.show();
    cout << "Sum of elements of Matrix 1: " << int(m1) << endl;
    cout << "Sum of elements of Matrix 2: " << int(m2) << endl;
    return 0;
}
