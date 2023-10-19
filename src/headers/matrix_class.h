#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class Matrix{
    public:
        friend ostream &operator<<(ostream &os, const Matrix &aMatrix);
        Matrix(int rows = 1, int cols = 1);         //Matrix init
        ~Matrix();                                  //Matrix delete
        Matrix(const Matrix &c);                    //Matrix copy
        Matrix &operator=(const Matrix &matrix);    //Matrix =

        void mInit();
        double mDeterminant();
        Matrix mMinor(int line_n, int line_m);
        Matrix mTranspose();

        friend Matrix mSum(const Matrix &mFirst, const Matrix &mSecond);
        friend Matrix mMult(const Matrix &mFirst, const Matrix &mSecond);

    private:
        int mRows;
        int mCols;
        double **matrix;
};