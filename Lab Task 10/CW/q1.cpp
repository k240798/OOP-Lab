#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encryptText(const string& input) {
    string encryptedText = "";
    for (int i = 0; i < input.length(); ++i) {
        char encryptedChar = input[i] + (i + 1); 
        encryptedText += encryptedChar;
    }
    return encryptedText;
}

string decryptText(const string& encryptedText) {
    string decryptedText = "";
    for (int i = 0; i < encryptedText.length(); ++i) {
        char decryptedChar = encryptedText[i] - (i + 1); 
        decryptedText += decryptedChar;
    }
    return decryptedText;
}

int main() {
    string input;
    cout << "Enter String: ";
    getline(cin, input);  

    cout << "Normal Text: " << input << endl;

    string encryptedText = encryptText(input);

    ofstream outFile("encrypted.txt");
    if (outFile.is_open()) {
        outFile << encryptedText;
        cout << "Encrypted text inserted in file" << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for writing!" << endl;
        return 1;
    }

    ifstream inFile("encrypted.txt");
    string fileContent;
    if (inFile.is_open()) {
        getline(inFile, fileContent);
        inFile.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
        return 1;
    }

    cout << "Encrypted text from file: " << fileContent << endl;

    string decryptedText = decryptText(fileContent);

    cout << "Decrypted text read then decoded from file: " << decryptedText << endl;

    return 0;
}
