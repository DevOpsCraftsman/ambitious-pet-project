#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    // std::cout << "Hello, World!" << std::endl;
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}