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

    int myArray[] = { 1, 2, 2, 3, 4, 4, 5, 6, 6, 6 };
    int expectedArray[] = { 1, 2, 3, 4, 5, 6 };
    int myArraySize = sizeof(myArray) / sizeof(myArray[0]);
    int expectedArraySize = sizeof(expectedArray) / sizeof(expectedArray[0]);

    int k = processor.removeDuplicates(myArray, myArraySize);

    assert(k == expectedArraySize);

    for (int i = 0; i < k; i++) {
        assert(myArray[i] == expectedArray[i]);
    }

    std::cout << "Arrays are equal to each other, Artur write great C++ code :))))" << std::endl;

    return 0;
}
