#include "Commons.h"
string intToHex(unsigned int byte);
unsigned int bitsetToInt(bitset<8> bitset);
bitset<8> swap4Bits(const std::bitset<8> &bits);
unsigned int Hash(const string& input);

int main()
{
    string input, hexInputString;
    int decimal;

    getline(cin, input);
    unsigned int hashValue = Hash(input);
    cout << "Hash: " << intToHex(hashValue) << endl;
}
string intToHex(unsigned int byte)
{
    stringstream hexStream;
    hexStream << hex << setw(2) << setfill('0') << byte;
    return hexStream.str();
}
bitset<8> swap4Bits(const std::bitset<8> &bits)
{
    bitset<4> first4(bits.to_ulong() >> 4);
    bitset<4> last4(bits.to_ullong() & 0x0F);
    bitset<8> result((last4.to_ulong() << 4) | first4.to_ulong());
    return result;
}
unsigned int bitsetToInt(bitset<8> bitset)
{
    return bitset.to_ulong();
}
unsigned int Hash(const string& input)
{
    unsigned int hash = 0xFAFAFAFA; // Initial hash value
    for (char c : input)
    {
        bitset<8> binary(static_cast<unsigned char>(c));
        binary = swap4Bits(binary);
        hash ^= bitsetToInt(binary) * 0x1000193;
        hash = (hash << 5) | (hash >> (32 - 5));
    }
    return hash;
}