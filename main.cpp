#include "Commons.h"

int main(){
    string input;
    getline(cin, input);
    
    cout << "String: " << input << endl;
    cout << "Binary representation:" << endl;
    
    // Iterate over each character in the string
    for (char c : input) {
        // Convert the character to its ASCII value and then to binary using bitset
        bitset<8> binary(static_cast<unsigned char>(c));
        cout << c << " : " << binary << endl;
    }


}