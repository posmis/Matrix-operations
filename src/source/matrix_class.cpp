#include "../headers/matrix_class.h"

#include "../headers/errors.h"

Matrix::Matrix(int rows, int cols) {
    if (rows < 1) rows = 1;
    if (cols < 1) cols = 1;
    mRows = rows;
    mCols = cols;

    matrix = (double **)malloc(mRows * mCols * sizeof(double) + mRows * sizeof(double *));
    double *pMatrix = (double *)(matrix + mRows);
    if (matrix == NULL) exit(ALLOC_ERROR);
    for (int i = 0; i < mRows; ++i) matrix[i] = pMatrix + i * mCols;
}

Matrix::~Matrix() {
    if (matrix != NULL) free(matrix);
}

Matrix::Matrix(const Matrix &cMatrix) {
    mRows = cMatrix.mRows;
    mCols = cMatrix.mCols;

    matrix = (double **)malloc(mRows * mCols * sizeof(double) + mRows * sizeof(double *));
    double *pMatrix = (double *)(matrix + mRows);
    if (matrix == NULL) exit(ALLOC_ERROR);
    for (int i = 0; i < mRows; ++i) matrix[i] = pMatrix + i * mCols;

    for (int row = 0; row < mRows; ++row) {
        for (int col = 0; col < mCols; ++col) matrix[row][col] = cMatrix.matrix[row][col];
    }
}

Matrix &Matrix::operator=(const Matrix &cMatrix){
    if(this != &cMatrix){
        if (matrix != NULL) free(matrix);
        mRows = cMatrix.mRows;
        mCols = cMatrix.mCols;

        matrix = (double **)malloc(mRows * mCols * sizeof(double) + mRows * sizeof(double *));
        double *pMatrix = (double *)(matrix + mRows);
        if (matrix == NULL) exit(ALLOC_ERROR);
        for (int i = 0; i < mRows; ++i) matrix[i] = pMatrix + i * mCols;

        for (int row = 0; row < mRows; ++row) {
            for (int col = 0; col < mCols; ++col) matrix[row][col] = cMatrix.matrix[row][col];
        }
    }
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &aMatrix) {
    for (int row = 0; row < aMatrix.mRows; ++row) {
        for (int col = 0; col < aMatrix.mCols; ++col) {
            os << aMatrix.matrix[row][col];
            if (col < aMatrix.mCols - 1) os << " ";
        }
        if (row < aMatrix.mRows - 1) os << endl;
    }
    return os;
}

void Matrix::mInit() {
    for (int row = 0; row < mRows; ++row) {
        for (int col = 0; col < mCols; ++col) cin >> matrix[row][col];
    }
}

Matrix Matrix::mMinor(int line_n, int line_m) {
    Matrix newMatrix(mRows - 1, mCols - 1);
    for (int row = 0, i = 0; i < mRows; ++i, ++row) {
        if (i == line_n) ++i;
        for (int col = 0, j = 0; j < mCols; ++j, ++col) {
            if (j == line_m) ++j;
            newMatrix.matrix[row][col] = matrix[i][j];
        }
    }
    return newMatrix;
}

double Matrix::mDeterminant() {
    double result = 0;
    if (mRows == 2) {
        result += matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else if (mRows > 2) {
        for (int j = 0; j < mCols; j++) {
            result += pow(-1, j) * matrix[0][j] * mMinor(0, j).mDeterminant();
        }
    }
    return result;
}