#include <iostream>
#include "../headers/matrix_class.h"

using namespace std;

int main(){

    Matrix newMatrix(3, 3);
    newMatrix.matrixInit();
    Matrix newMatrix2 = newMatrix.matrixMinor(1, 1);
    //cout << newMatrix.matrixDeterminant();
    cout << "\n\n";

    cout << newMatrix;
    cout << endl << endl << newMatrix2 << endl;
    return 0;
}