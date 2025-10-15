#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <old_word> <new_word>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return 1;
    }
    
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();

    inputFile.close();

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Could not create output file: " << outputFilename << std::endl;
        return 1;
    }

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        break;
    }

    std::string result;
    size_t start = 0;

    while ((pos = content.find(s1, start)) != std::string::npos) {
        result.append(content, start, pos - start);
        result.append(s2);
        start = pos + s1.length();
    }

    result.append(content, start, std::string::npos);

    outputFile << result;

    std::cout << "Replacement done successfully. Output written to " << outputFilename << std::endl;

    return 0;
}
