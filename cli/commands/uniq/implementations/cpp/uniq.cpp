#include <iostream>
#include <fstream>

using namespace std;

bool match(string actualLine, string prevLine, string option);

int main(int argc, char *argv[]) {

    ifstream file(argv[1]);
    string option;
    if (argc == 3) {
        option = argv[2];
    }

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    if (option == "-u") {

        string actualLine;
        string nextLine;
        bool noDuplicate = true;

        while (getline(file, nextLine)) {
            if (actualLine == nextLine) {
                noDuplicate = false;
            } else if (noDuplicate) {
                cout << actualLine << endl;
            } else {
                noDuplicate = true;
            }
            actualLine = nextLine;
        }
        if (nextLine != actualLine) {
            cout << actualLine << endl;
        }

    } else {

        string actualLine;
        string previousLine;

        while (getline(file, actualLine)) {
            if (match(actualLine, previousLine, option)) {
                cout << actualLine << endl;
            }
            previousLine = actualLine;
        }

    }


    file.close();

    return 0;
}

bool match(string actualLine, string prevLine, string option) {
    if (option == "-d" && actualLine == prevLine) {
        return true;
    } else if (option.empty() && actualLine != prevLine) {
        return true;
    }
    return false;
}
