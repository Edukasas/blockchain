#include "Commons.h"

string BinToHex(bitset<8> bitset);

int main(){
    string input, HexInputString;
    getline(cin, input);
    

    for (char c : input) {
        bitset<8> binary(static_cast<unsigned char>(c));
        HexInputString += BinToHex(binary);
    }
}
    string BinToHex(bitset<8> bitset){
            unsigned int bit = bitset.to_ulong();
            stringstream hexStream;
            hexStream << hex << setw(2) << setfill('0') << bit;
            return hexStream.str();
    }