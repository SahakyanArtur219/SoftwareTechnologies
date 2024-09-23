
#include <iostream>
#include <cstdlib> 
#include <ctime>


using namespace std;

int main()
{
    cout << " Find Indexes " << endl << endl;

    int arr[1000];
    int n;
    int m;
    cout << " n = "; cin >> n; cout << endl;
    cout << " m = "; cin >> m; cout << endl;

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101; 
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((arr[i] + arr[j]) == m) {
                cout << '[' << i << ',' << j << ']' <<"  " << arr[i] << " " << arr[j] << endl;
                i = n;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " ;
    }
}

