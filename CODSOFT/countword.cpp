#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int countWords(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int wordCount = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string word;

            while (iss >> word) {
                // Increment word count for each word encountered
                wordCount++;
            }
        }
        file.close();
    } else {
        std::cout << "Error: Unable to open file." << std::endl;
    }

    return wordCount;
}

int main() {
    // Get the file name from the user
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;

    // Count the number of words in the file
    int wordCount = countWords(filename);

    // Display the result
    if (wordCount > 0) {
        std::cout << "Total number of words in the file: " << wordCount << std::endl;
    }

    return 0;
}
