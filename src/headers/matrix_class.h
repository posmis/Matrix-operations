#pragma once
#include <iostream>

class Matrix{
    public:
        Matrix(int n = 0, int m = 0);
        ~Matrix();
        Matrix(const Matrix &c);
        Matrix &operator=(const Matrix &matrix);
        Matrix &operator<<(const Matrix &matrix);
    private:
        int size_n;
        int size_m;
        double **matrix;
};