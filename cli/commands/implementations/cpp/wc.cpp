#include <iostream>
#include <fstream>

using namespace std;

void displayArgs(int argc, char *const *argv);


void countLines(ifstream &file);

int main(int argc, char *argv[]) {

    displayArgs(argc, argv);

    ifstream file(argv[1]);

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    countLines(file);

    return 0;
}

void countLines(ifstream &file) {
    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        lineCount++;
    }
    file.close();

    cout << lineCount << endl;
}

void displayArgs(int argc, char *const *argv) {
    cout << argc << endl;
    for (int i(1); i < argc; i++) {
        cout << argv[i] << endl;
    }
}
