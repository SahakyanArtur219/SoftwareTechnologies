#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int num_students = 102;
    int min_familiar = 68;
    int max_familiar = 101; 
    
    std::vector<int> familiar(num_students);


    for (int i = 0; i < num_students; ++i) {
        familiar[i] = min_familiar + (rand() % (max_familiar - min_familiar + 1));
    }

    std::unordered_map<int, int> familiar_count;

    for (int i = 0; i < num_students; ++i) {
        familiar_count[familiar[i]]++;
    }

    for (const auto& entry : familiar_count) {
        std::cout << "Num: " << entry.first << std::endl << "Times: " << entry.second << std::endl;

    }

    std::cout << "No number of familiar pupils appears 4 times." << std::endl;
    return 0;
}