#include "../headers/matrix_class.h"
#include "../headers/errors.h"

Matrix::Matrix(int n, int m)
{
    if(n < 1) n = 1;
    if(m < 1) m = 1;
    size_n = n;
    size_m = m;
    matrix = new double*[size_n];
    for(int i = 0; i < size_n; ++i) matrix[i] = new double[size_m];
}

Matrix::~Matrix(){
    for(int i = 0; i < size_n; ++i) delete matrix[i]; //TROUBLES
    delete []matrix;
}

Matrix::Matrix(const Matrix &cMatrix){
    size_n = cMatrix.size_n;
    size_m = cMatrix.size_m;
    matrix = new double*[size_n];
    for(int i = 0; i < size_n; ++i) matrix[i] = new double[size_m];
}

Matrix &Matrix::operator=(const Matrix &cMatrix){
    if(this != &cMatrix){
        for(int i = 0; i < size_n; ++i) delete matrix[i];
        delete []matrix;
        size_m = cMatrix.size_m;
        size_n = cMatrix.size_n;

        matrix = new double*[size_n];
        for(int i = 0; i < size_n; ++i) matrix[i] = new double[size_m];

        for(int i = 0; i < size_n; ++i){
            for(int j = 0; j < size_m; ++j){
                matrix[i][j] = cMatrix.matrix[i][j];
            }
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &aMatrix){
    for(int i = 0; i < aMatrix.size_n; ++i){
        for(int j = 0; j < aMatrix.size_m; ++j){
            os << aMatrix.matrix[i][j];
            if(j < aMatrix.size_m - 1){
                os << " ";
            }
        }
        if(i < aMatrix.size_n - 1){
            os << endl;
        }
    }
    return os;
}

void Matrix::matrixInit(){
    for(int i = 0; i < size_n; ++i){
            for(int j = 0; j < size_m; ++j){
                cin >> matrix[i][j];
            }
        }
}

double Matrix::matrixDeterminant(){
    double result = 0;
    if(size_n != size_m) exit(SIZE_ERROR);
    if(size_n == 1) result = matrix[0][0];
    else if(size_n == 2){
        result += matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    } else if(size_n > 2){
        for(int j = 0; j < size_n; ++j){
            Matrix tempMatrix = matrixMinor(0, j);
            cout << endl << tempMatrix << endl;
            result += pow(-1, j) * matrix[0][j] * tempMatrix.matrixDeterminant();
        }
    }
    return result;
}

Matrix Matrix::matrixMinor(int line_n, int line_m){
    Matrix newMatrix(size_n - 1, size_m - 1);
    for(int i = 0, n_i = 0; i < size_n; ++i, ++n_i){
        if(i == line_n) ++i;
        for(int j = 0, n_j = 0; j < size_m; ++j, ++n_j){
            if(j == line_m) ++j;
            newMatrix.matrix[n_i][n_j] = matrix[i][j];
        }
    }
    return newMatrix;
}