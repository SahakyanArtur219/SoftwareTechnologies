#include <iostream>
#include <vector>
#include <algorithm>

bool isGraphical(std::vector<int> degrees) {

    std::sort(degrees.rbegin(), degrees.rend());

    while (!degrees.empty()) {

        int d = degrees[0];
        degrees.erase(degrees.begin());

        if (d > degrees.size()) {

            return false;
        }

        for (int i = 0; i < d; ++i) {
            if (--degrees[i] < 0) {
                return false;
            }
        }


        std::sort(degrees.rbegin(), degrees.rend());
    }

    return true;
}

int main() {

    std::vector<int> degrees = { 5,5,5,5,5,5,
                                3,3,3,3,4,1};


    if (isGraphical(degrees)) {
        std::cout << "Yes, the degree sequence is graphical.\n";
    }
    else {
        std::cout << "No, the degree sequence is not graphical.\n";
    }

    return 0;
}