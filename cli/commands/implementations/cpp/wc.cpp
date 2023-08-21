#include <iostream>
#include <fstream>

using namespace std;

void displayArgs(int argc, char *const *argv);

void countLines(ifstream &file);
void countChars(ifstream &file);
void countWords(ifstream &file);

bool isBlank(char character);

int main(int argc, char *argv[]) {

//    displayArgs(argc, argv);

    ifstream file(argv[1]);

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

//    countChars(file);
//    file.seekg(0, ios::beg);
//    countLines(file);
    countWords(file);
    file.close();

    return 0;
}

void countChars(ifstream &file) {
    char character;
    int charCount = 0;
    while (file.get(character)) {
        charCount++;
    }
    cout << charCount << endl;
}

void countWords(ifstream &file) {
    char character;
    int wordsCount = 0;
    bool lastCharWasBlank = false;
    while (file.get(character)) {
        if (isspace(character)) {
            if (!lastCharWasBlank) {
                wordsCount++;
            }
            lastCharWasBlank = true;
        } else {
            lastCharWasBlank = false;
        }
    }
    cout << wordsCount << endl;
}

void countLines(ifstream &file) {
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
    }
    cout << lineCount << endl;
}

void displayArgs(int argc, char *const *argv) {
    cout << argc << endl;
    for (int i(1); i < argc; i++) {
        cout << argv[i] << endl;
    }
}
