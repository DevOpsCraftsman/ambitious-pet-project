#include <iostream>
#include <fstream>

using namespace std;

bool match(string actualLine, string prevLine, string option);

string uniq_u(ifstream &file) {
    string currentLine;
    string previousLine;
    bool firstLine = true;
    bool previousLineIsDuplicate = false;
    string result;
    while (getline(file, currentLine)) {
        bool currentLineIsDuplicate = (currentLine == previousLine);
        if (!previousLineIsDuplicate) {
            if (!currentLineIsDuplicate) {
                if (!firstLine) {
                    result.append("\n");
                }
                result.append(currentLine);
                firstLine = false;
            }
        }
        previousLineIsDuplicate = currentLineIsDuplicate;
        previousLine = currentLine;

        firstLine = false;
    }
    return result;
}

void test_uniq_l() {

    const int row = 3;
    const int col = 2;
    string test_data[row][col] = {
            {"file1.txt", "line1"},
            {"file2.txt", "line1\nline2"},
            {"file3.txt", "line1"},
    };

    for (int i = 0; i < row; i++) {
        string path = "./test_data/" + test_data[i][0];
        string expected = test_data[i][1];
        ifstream file(path);
        string result = uniq_u(file);
        cout << "testing: " + path << endl;
        if (result == expected) {
            cout << "passed." << endl;
        } else {
            cerr << "failed: " + result << endl;
            cerr << "expected: " + expected << endl;
        }
    }

}

int main() {
    test_uniq_l();
    // Add more test functions here as needed.
    return 0;
}
//int main(int argc, char *argv[]) {
//
//    ifstream file(argv[1]);
//    string option;
//    if (argc == 3) {
//        option = argv[2];
//    }
//
//    if (!file) {
//        cerr << "Error opening file." << endl;
//        return 1;
//    }
//
//    if (option == "-u") {
//
//        uniq_u(file);
//
//    } else {
//
//        string actualLine;
//        string previousLine;
//
//        while (getline(file, actualLine)) {
//            if (match(actualLine, previousLine, option)) {
//                cout << actualLine << endl;
//            }
//            previousLine = actualLine;
//        }
//
//    }
//
//
//    file.close();
//
//    return 0;
//}

bool match(string actualLine, string prevLine, string option) {
    if (option == "-d" && actualLine == prevLine) {
        return true;
    } else if (option.empty() && actualLine != prevLine) {
        return true;
    }
    return false;
}
