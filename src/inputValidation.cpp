#include "inputValidation.h"

// minSize: minimum size of the input
// maxSize: maximum size of the input
// mode: "numbers", "letters", or "all" (default)
// allCaps: if true, convert the input to uppercase
// prompt: the prompt to display to the user

string getValidatedInput(int minSize, int maxSize, const string &mode,
                         bool allCaps, string prompt) {
    string input;
    while (true) {
        cout << prompt << ": ";
        if (!getline(cin, input)) {
            cin.clear();
            continue;
        }

        if (input.find(',') != string::npos) {
            cout << "  ✗ Error: commas are not allowed.\n";
            continue;
        }
        if (static_cast<int>(input.size()) < minSize) {
            cout << "  ✗ Error: input must be at least " << minSize
                 << " characters.\n";
            continue;
        }
        if (static_cast<int>(input.size()) > maxSize) {
            cout << "  ✗ Error: input exceeds " << maxSize << " characters.\n";
            continue;
        }

        if (mode == "numbers") {
            bool allDigits = true;
            for (char c : input) {
                if (!isdigit(static_cast<unsigned char>(c))) {
                    allDigits = false;
                    break;
                }
            }
            if (!allDigits) {
                cout << "  ✗ Error: only digits are allowed.\n";
                continue;
            }
        } else if (mode == "letters") {
            bool allLetters = true;
            for (char c : input) {
                if (!isalpha(static_cast<unsigned char>(c))) {
                    allLetters = false;
                    break;
                }
            }
            if (!allLetters) {
                cout << "  ✗ Error: only letters are allowed.\n";
                continue;
            }
        } else if (mode != "all") {
            cout << "  ✗ Error: invalid mode \"" << mode << "\".\n";
            continue;
        }

        break;
    }

    if (allCaps) {
        for (char &c : input) {
            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
        }
    } else if (!input.empty()) {
        input[0] =
            static_cast<char>(toupper(static_cast<unsigned char>(input[0])));
        for (size_t i = 1; i < input.size(); ++i) {
            input[i] = static_cast<char>(
                tolower(static_cast<unsigned char>(input[i])));
        }
    }

    return input;
}

// Read an integer between minValue and maxValue (inclusive)
int getValidatedInt(int minValue, int maxValue, const string &prompt) {
    int value;
    while (true) {
        cout << prompt << ": ";
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  ✗ Error: invalid number.\n";
            continue;
        }
        if (value < minValue || value > maxValue) {
            cout << "  ✗ Error: please enter a number between " << minValue
                 << " and " << maxValue << ".\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
    return value;
}