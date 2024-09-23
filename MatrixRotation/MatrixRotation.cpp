#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;



void print(int matr[][100], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n";
}



int main() {

    cout << " Matrix Routation " << endl << endl;

    int matrix[100][100];
    int n;
    int temp;
    cout << " n = "; cin >> n; cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 101;
        }
    }

    print(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = temp;
        }
    }

    print(matrix, n);

}
