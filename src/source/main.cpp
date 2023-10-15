#include <iostream>

#include "../headers/matrix_class.h"

using namespace std;

int main() {
    int n, m;
    cout << "Enter matrix size: ";
    cin >> n >> m;
    Matrix newMatrix(n, m);

    newMatrix.mInit();
    // cout << "\n\n" << newMatrix.mMinor(0, 1) << endl << endl;
    // cout << newMatrix << endl;
    cout << newMatrix.mDeterminant() << endl;

    return 0;
}