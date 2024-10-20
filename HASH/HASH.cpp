#include <iostream>
#include <fstream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class app {
public:


    std::string sha256(const std::string& str) {
        std::stringstream ss;
        for (char c : str) {
            double sineValue = std::sin(static_cast<double>(c));
            ss << std::setprecision(2) << sineValue;
        }
        std::string hash = ss.str();
        return hash.substr(0, 256);
    }



    void signUp(const std::string& username, const std::string& password) {
        std::ofstream file("users.txt");
        file << username << ":" << sha256(password) << std::endl;
        file.close();
        std::cout << "Sign-up successful! You can now log in." << std::endl;
    }




    bool login(const std::string& username, const std::string& password) {
        std::ifstream file("users.txt");
        std::string line;
        std::string user = username + ":" + sha256(password);

        while (std::getline(file, line)) {
            if (line == user) {
                return true;
            }
        }

        return false;
    }

};


int main() {
    app site;
    string choice;
    std::string username, password;

    while (true) {

        std::cout << "1. Sign Up\n2. Log In\nEnter choice: ";
        std::cin >> choice;
       

        if (choice == "1") {

            std::cout << "Enter username: ";
            std::cin.ignore();
            std::getline(cin, username);

            std::cout << "Enter password: ";
            std::cin.ignore();
            std::getline(cin, password);

            site.signUp(username, password);
        }
        else if (choice == "2") {
            std::cout << "Enter username: ";
            
            std::cin.ignore();
            std::getline(cin, username);

            std::cout << "Enter password: ";
            std::cin.ignore();
            std::getline(cin, password);

            if (site.login(username, password)) {
                std::cout << "Login successful!" << std::endl;
            }
            else {
                std::cout << "Invalid username or password." << std::endl;
            }
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
    return 0;
}
