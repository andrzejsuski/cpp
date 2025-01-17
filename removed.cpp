#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    // Process input line by line
    while (getline(cin, line)) {
        // Check if the line starts with a dot
        if (!line.empty() && line[0] == '.') {
            // Remove the first dot and print the result
            cout << line.substr(1) << endl;
        } else {
            // If no dot at the beginning, print the line as is
            cout << line << endl;
        }
    }

    return 0;
}
