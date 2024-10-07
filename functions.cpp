#include "Commons.h"
#include "functions.h"
#include "MD5.h"
string intToHex(unsigned int byte)
{
    stringstream hexStream;
    hexStream << hex << setw(2) << setfill('0') << byte;
    return hexStream.str();
}
bitset<8> swap4Bits(const bitset<8> &bits)
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
string generateSalt(int len = 16) {
    const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";
    string salt;
    srand((time(nullptr)));
    for (int i = 0; i < len; ++i) {
        salt += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return salt;
}
string Hash(const string &input) {
    const int hash_parts = 3;
    unsigned long long hashes[hash_parts] = {
        0xFA153BE9AB2842EAULL,
        0xBABABABA01032587ULL,
        0xC0DE15500DAFFAE7ULL
    };

    const unsigned long long prime = 0x10E93214ULL;
    
    string salt = generateSalt();
    string saltedInput = salt + input;
    for (size_t pos = 0; pos < saltedInput.size(); ++pos) {
        char c = saltedInput[pos];
        bitset<8> binary(static_cast<unsigned char>(c));
        binary = swap4Bits(binary);
        unsigned long long value = static_cast<unsigned long long>(bitsetToInt(binary));

        for (int i = 0; i < hash_parts; ++i) {
            hashes[i] ^= value * prime;
            hashes[i] = (hashes[i] * 0x5BD1E995) ^ (hashes[i] >> (i + 1));
            hashes[i] = (hashes[i] << (5 + i)) | (hashes[i] >> (64 - (5 + i)));
        }
    }

    for (int i = 0; i < hash_parts; ++i) {
        hashes[i] ^= (hashes[(i + 1) % hash_parts] * prime) ^ (hashes[i] >> 31);
        hashes[i] = (hashes[i] * 0x5BD1E995) ^ (hashes[i] >> 33);
    }

    ostringstream result;
    for (int i = 0; i < hash_parts; ++i) {
        result << hex << setw(16) << setfill('0') << hashes[i];
    }

    return salt + result.str();
}
string readFromFile(const string &filename)
{
    ifstream file(filename);
    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
string readLinesFromFile(const string &filename, int numLines)
{
    ifstream file(filename);
    stringstream buffer;
    string line;
    int linesRead = 0;

    if (!file.is_open())
    {
        cerr << "Error: File cannot be opened or does not exist." << endl;
        return "";
    }

    while (linesRead < numLines && getline(file, line))
    {
        buffer << line << "\n";
        linesRead++;
    }

    file.close();
    return buffer.str();
}
void compareStringPairs(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    string str1, str2;
    int matchCount = 0;

    while (inFile >> str1 >> str2)
    {
        if (Hash(str1) == Hash(str2))
        {
            matchCount++;
        }
    }

    inFile.close();

    cout << "Total matches found between pairs: " << matchCount << endl;
}
void compareStringPairsBitLevel(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    string str1, str2;
    vector<double> percentages;
    double minPercentage = 100.0;
    double maxPercentage = 0.0;
    double totalPercentage = 0.0;
    int count = 0;

    while (inFile >> str1 >> str2)
    {
        int matchCount = 0;
        str1 = Hash(str1);
        str2 = Hash(str2);
        int totalBits = str1.length() * 8;

        for (size_t i = 0; i < str1.length(); ++i)
        {
            bitset<8> bits1(str1[i]);
            bitset<8> bits2(str2[i]);

            for (size_t bit = 0; bit < 8; ++bit)
            {
                if (bits1[bit] == bits2[bit])
                {
                    matchCount++;
                }
            }
        }

        double percentage = (static_cast<double>(matchCount) / totalBits) * 100.0;

        minPercentage = min(minPercentage, percentage);
        maxPercentage = max(maxPercentage, percentage);
        totalPercentage += percentage;
        count++;
    }

    inFile.close();

    double averagePercentage = (count > 0) ? (totalPercentage / count) : 0.0;

    cout << fixed << setprecision(2);
    cout << "Lowest matching percentage: " << minPercentage << "%" << endl;
    cout << "Highest matching percentage: " << maxPercentage << "%" << endl;
    cout << "Average matching percentage: " << averagePercentage << "%" << endl;
}
void compareStringPairsHexLevel(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    string str1, str2;
    vector<double> percentages;
    double minPercentage = 100.0;
    double maxPercentage = 0.0;
    double totalPercentage = 0.0;
    int count = 0;

    while (inFile >> str1 >> str2)
    {
        str1 = Hash(str1);
        str2 = Hash(str2);
        int matchCount = 0;
        int totalHexDigits = str1.length() * 2;

        for (size_t i = 0; i < str1.length(); ++i)
        {
            string hex1 = intToHex(str1[i]);
            string hex2 = intToHex(str2[i]);

            for (size_t j = 0; j < max(hex1.length(), hex2.length()); ++j)
            {
                if (j < hex1.length() && j < hex2.length() && hex1[j] == hex2[j])
                {
                    matchCount++;
                }
            }
        }

        double percentage = (static_cast<double>(matchCount) / totalHexDigits) * 100.0;

        minPercentage = min(minPercentage, percentage);
        maxPercentage = max(maxPercentage, percentage);
        totalPercentage += percentage;
        count++;
    }

    inFile.close();

    double averagePercentage = (count > 0) ? (totalPercentage / count) : 0.0;

    cout << fixed << setprecision(2);
    cout << "Lowest matching percentage: " << minPercentage << "%" << endl;
    cout << "Highest matching percentage: " << maxPercentage << "%" << endl;
    cout << "Average matching percentage: " << averagePercentage << "%" << endl;
}