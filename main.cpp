#include "Commons.h"
string intToHex(unsigned int byte);
unsigned int bitsetToInt(bitset<8> bitset);
bitset<8> swap4Bits(const std::bitset<8> &bits);
string Hash(const string& input);

int main()
{
    string input, hexInputString;
    int decimal;

    getline(cin, input);
    string hashValue = Hash(input);
    cout << "Hash: " << hashValue << endl;
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
string Hash(const string& input)
{
    const int hash_parts = 4;
    unsigned long long hashes[hash_parts]  = {
        0xFA153BE9AB2842EAULL,
        0xBABABABA01032587ULL,
        0xC0DE15500DAFFAE7ULL,
        0x1234567812345678ULL
    };

    for (char c : input)
    {
        bitset<8> binary(static_cast<unsigned char>(c));
        binary = swap4Bits(binary);
        for (int i = 0; i < hash_parts; ++i) {
            hashes[i] ^= static_cast<unsigned long long>(bitsetToInt(binary)) * 0x10E93214ULL;
            hashes[i] = (hashes[i] << 5) | (hashes[i] >> (64-i));
        }
    }

    ostringstream result;
    for (int i = 0; i < hash_parts; ++i) {
        result << hex << setw(16) << setfill('0') << hashes[i];
    }
    return result.str();
}