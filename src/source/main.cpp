#include <iostream>

#include "../headers/matrix_class.h"

using namespace std;

int main() {
    int n, m;
    cout << "Enter matrix size: ";
    cin >> n >> m;
    Matrix newMatrix1(n, m);
    newMatrix1.mInit();
    Matrix result = newMatrix1.mTranspose();
    cout << "\n" << result;


    // cout << "\n\nEnter matrix size: ";
    // cin >> n >> m;
    // Matrix newMatrix2(n, m);
    // newMatrix2.mInit();
    
    // Matrix result = mMult(newMatrix1, newMatrix2);
    // cout << "\n\n";
    // cout << result;

    return 0;
}