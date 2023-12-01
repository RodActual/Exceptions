// Anthony Rodriguez
// CIS 1202 101
// 11/30/2023
 
#include <iostream>
#include <stdexcept>

using namespace std;

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalid_argument("Invalid start character");
    }

    if (!isalpha(start + offset) || (islower(start) && isupper(start + offset)) || (isupper(start) && islower(start + offset))) {
        throw out_of_range("Invalid character offset");
    }

    return start + offset;
}

int main() {
    try {
        char start;
        int offset;

        cout << "Enter a letter (A-Z, a-z): ";
        cin >> start;

        cout << "Enter an integer offset: ";
        cin >> offset;

        char result = character(start, offset);
        cout << "Result: " << result << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
