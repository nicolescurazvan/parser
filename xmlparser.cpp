#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Read the file as string vector
std::string readFile(const char *path) {
    std::ifstream f(path);
    std::string line, text;
    while (getline(f, line)) {
        text += line + "\n";
    }
    return text;
}

// Define lexemes
enum XMLType {
    TAG,
    ATTRIBUTE,
    VALUE,
    CONTENT,
    END,
    COMMENT
};
struct XMLLexeme {
    std::string value;
    XMLType type;
};

bool lexer(std::vector<XMLLexeme> &tokens, std::string text);

int main() {
    std::string text = readFile("test.xml");
    std::cout << text;
    return 0;
}
