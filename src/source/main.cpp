#include <iostream>
#include "../headers/matrix_class.h"

using namespace std;

int main(){

    int n, m;
    cout << "Enter matrix size: ";
    cin >> n >> m;
    Matrix newMatrix(n, m);

    newMatrix.matrixInit();
    //cout << "\n\n" << newMatrix.matrixMinor(0, 1) << endl;
    cout << newMatrix.matrixDeterminant() << endl;
    
    return 0;
}