#pragma once
#include <iostream>

using namespace std;

class Matrix{
    public:
        friend ostream &operator<<(ostream &os, const Matrix &aMatrix);
        Matrix(int n = 0, int m = 0);               //Matrix init
        ~Matrix();                                  //Matrix delete
        Matrix(const Matrix &c);                    //Matrix copy
        Matrix &operator=(const Matrix &matrix);    //Matrix =

        void matrixInit();
        double matrixDeterminant();
        Matrix matrixMinor(int line_n, int line_m);
    private:
        int size_n;
        int size_m;
        double **matrix;
};