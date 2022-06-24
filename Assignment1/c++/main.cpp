#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter in a sentence" << endl;
    string sentenceInput;
    getline(cin, sentenceInput);
    cout << "Enter in a word to search for" << endl;
    string wordInput;
    cin >> wordInput;
    cout << "Searching " << sentenceInput << " for " << wordInput << endl;
    if (sentenceInput.find(wordInput) != string::npos) {
        cout << "FOUND" << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
    return 0;
}
