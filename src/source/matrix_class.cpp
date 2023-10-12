#include "../headers/matrix_class.h"

using namespace std;

Matrix::Matrix(int n, int m):
size_n(n),
size_m(m)
{
    matrix = new double*[n];
    for(int i = 0; i < size_n; ++i) matrix[i] = new double[size_m];
}

Matrix::~Matrix(){
    for(int i = 0; i < size_n; ++i) delete matrix[i];
    delete []matrix;
}

Matrix::Matrix(const Matrix &c){
    
}