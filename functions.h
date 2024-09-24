#include "Commons.h"
string intToHex(unsigned int byte);
unsigned int bitsetToInt(bitset<8> bitset);
bitset<8> swap4Bits(const std::bitset<8> &bits);
string Hash(const string& input);
string readFromFile(const string &filename);
string readLinesFromFile(const string &filename, int numLines);
void generateRandomStringPairs(int stringLength, int numPairs, const string& filename);
void compareStringPairs(const string& filename);