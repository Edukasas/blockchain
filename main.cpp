#include "MD5.h"
#include "Commons.h"
#include "functions.h" 

int main() {
    const std::string filename = "./test_files/randomPairs/file.txt";
    const int maxLines = 100000;
    std::vector<double> hashTimes(5, 0.0), md5Times(5, 0.0);

    for (int j = 0; j < 5; j++) {
        std::string inputData = readLinesFromFile(filename, maxLines);

        auto start = std::chrono::high_resolution_clock::now();
        std::string hashValue = Hash(inputData);
        auto end = std::chrono::high_resolution_clock::now();
        hashTimes[j] = std::chrono::duration<double>(end - start).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        std::string md5HashValue = MD5(inputData);
        auto end2 = std::chrono::high_resolution_clock::now();
        md5Times[j] = std::chrono::duration<double>(end2 - start2).count();
    }

    std::cout << "Average Time Taken for Hash Function: " << std::fixed << std::setprecision(6)
              << std::accumulate(hashTimes.begin(), hashTimes.end(), 0.0) / hashTimes.size() << " seconds" << std::endl;

    std::cout << "Average Time Taken for MD5 Function: " << std::fixed << std::setprecision(6)
              << std::accumulate(md5Times.begin(), md5Times.end(), 0.0) / md5Times.size() << " seconds" << std::endl;

    return 0;
}
