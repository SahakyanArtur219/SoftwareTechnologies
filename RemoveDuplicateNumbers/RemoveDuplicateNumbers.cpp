#include <iostream>
#include <algorithm>
#include <cassert>

class ArrayProcessor {
public:
    int removeDuplicates(int arr[], int& size) {
        std::sort(arr, arr + size);
        int uniqueCount = 0;

        for (int i = 0; i < size; ++i) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                arr[uniqueCount++] = arr[i];
            }
        }

        size = uniqueCount;

        return size;
    }
};

int main() {

    ArrayProcessor processor;

    int myArray[100];
    int expectedArray[100];
    int n;
    int m;
    std::cout << "input size of array n = ";
    std::cin >> n;
    std::cout << "\n";
    for (int i = 0; i < n; i++) {
        std::cin >> myArray[i];
    }

    std::cout << "input size of expected array n = ";
    std::cin >> m;
    std::cout << "\n";
    for (int i = 0; i < m; i++) {
        std::cin >> expectedArray[i];
    }


    int myArraySize = n;
    int expectedArraySize = m;

    int k = processor.removeDuplicates(myArray, myArraySize);

    assert(k == expectedArraySize);

    for (int i = 0; i < k; i++) {
        assert(myArray[i] == expectedArray[i]);
    }

    std::cout << "Arrays are equal to each other, Artur write great C++ code :))))" << std::endl;

    return 0;
}
