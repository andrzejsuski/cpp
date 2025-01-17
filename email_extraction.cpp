/* email_extraction filein.txt fileout.txt */ 

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << 
endl;
        return 1;
    }

    ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        cerr << "Error: Could not open input file " << argv[1] << endl;
        return 1;
    }

    ofstream output_file(argv[2]);
    if (!output_file.is_open()) {
        cerr << "Error: Could not open output file " << argv[2] << endl;
        return 1;
    }

    string line;
    regex email_regex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    smatch match;

    // Process input line by line
    while (getline(input_file, line)) {
        // Search for email addresses in the line
        while (regex_search(line, match, email_regex)) {
            // Write the matched email address to the output file
            output_file << match[0] << endl;
            // Proceed to the next match
            line = match.suffix().str();
        }
    }

    input_file.close();
    output_file.close();
    return 0;
}
