#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[2][2];

public:

    Matrix() {
        for (int i = 0; i <2; ++i){
            for (int  j= 0; j < 2; ++j)
            {
                mat[i][j] = 0;
            }
            
        }
    }

void setValues(int r, int c, int value) {
    mat[r][c] = value;
}

Matrix operator+(const Matrix& other){
    Matrix result;
    for (int i = 0; i < 2; ++i)
    {
        for ( int j = 0; j < 2; ++j)
        {
            result.mat[i][j] = mat[i][j] + other.mat[i][j];
        }
        
    }
    return result;
}

Matrix operator-(const Matrix& other){
    Matrix result;
    for (int i = 0; i < 2; ++i)
    {
        for ( int j = 0; j < 2; ++j)
        {
            result.mat[i][j] = mat[i][j] - other.mat[i][j];
        }
        
    }
    return result;
}

Matrix operator*(const Matrix& other){
    Matrix result;
    for (int i = 0; i < 2; ++i)
    {
        for ( int j = 0; j < 2; ++j)
        {
            result.mat[i][j] = mat[i][j] * other.mat[i][j];
        }
        
    }
    return result;
}



void display() const { 
    for (int i = 0; i < 2; ++i) { 
        for (int j = 0; j < 2; ++j) {
             cout << mat[i][j] << " "; 
     } 
        cout << endl; 
    } 
}
};


int main() {
    Matrix mat1, mat2, mat3;

    mat1.setValues(0, 0, 1);
    mat1.setValues(0,1,2);
    mat1.setValues( 1, 0 ,3);
    mat1.setValues(1 , 1 ,4 );


    mat2.setValues(0, 0, 5);
    mat2.setValues(0,1,6);
    mat2.setValues(1,0,7);
    mat2.setValues(1,1,8);

    mat3.setValues(0,0,10);
    mat3.setValues(0,1, 11);
    mat3.setValues(1,0,12);
    mat3.setValues(1,1,13);


    Matrix resultAdd = mat1 + mat2;
    cout << "Addition of Two Matrices: " << endl;
    resultAdd.display();

    Matrix resultSub = mat1 - mat2;
    cout << "Subtraction of Two Matrices: " << endl;
    resultSub.display();

     Matrix resultMul = mat1 * mat2;
    cout << "Multiplication of Two Matrices: " << endl;
    resultMul.display();
}