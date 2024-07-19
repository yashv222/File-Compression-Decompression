#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // Opening input file in read-only mode
    std::ifstream inputFile("sample.txt", std::ios::in);
    if (!inputFile) {
        std::cerr << "Open Failed For Input File:\n";
        std::exit(1);
    }

    // Creating output file in write mode
    std::ofstream outputFile("sample - compressed.txt", std::ios::out);
    if (!outputFile) {
        std::cerr << "Open Failed For Output File:\n";
        std::exit(1);
    }

    // Your file processing code here

    inputFile.close();
    outputFile.close();

    return 0;
}

