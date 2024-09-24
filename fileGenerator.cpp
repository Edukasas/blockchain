#include "Commons.h"
#include "functions.h"

void generateRandomStringPairs(int stringLength, int numPairs, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, charset.size() - 1);

    for (int i = 0; i < numPairs; ++i) {
        std::string str1;
        for (int j = 0; j < stringLength-1; ++j) {
            str1 += charset[dist(rng)];
        }
        std::string str2 = str1 + 'b';  // First string with 'b'
        str1 += 'a';  

        outFile << str1 << " " << str2 << "\n";
    }

    outFile.close();
}