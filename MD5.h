#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <vector>

// Constants for MD5 transformation
const uint32_t S[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

// Precomputed table of sine values
const uint32_t K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

// Left rotate function
uint32_t leftRotate(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32 - c));
}

// MD5 function
std::string MD5(const std::string &input) {
    uint32_t state[4] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
    uint64_t bitLength = input.size() * 8;
    std::string buffer = input;
    buffer += static_cast<char>(0x80);  // Append a single '1' bit

    // Pad with zeros until the buffer is 56 bytes
    while (buffer.size() % 64 != 56) {
        buffer += static_cast<char>(0x00);
    }

    // Append the bit length
    for (int i = 0; i < 8; ++i) {
        buffer += static_cast<char>((bitLength >> (8 * i)) & 0xFF);
    }

    // Process each 64-byte block
    for (size_t i = 0; i < buffer.size(); i += 64) {
        uint32_t A = state[0];
        uint32_t B = state[1];
        uint32_t C = state[2];
        uint32_t D = state[3];
        uint32_t M[16];

        // Break chunk into sixteen 32-bit words
        for (int j = 0; j < 16; ++j) {
            M[j] = (buffer[i + j * 4]) | 
                   (buffer[i + j * 4 + 1] << 8) | 
                   (buffer[i + j * 4 + 2] << 16) | 
                   (buffer[i + j * 4 + 3] << 24);
        }

        // Main MD5 transformation loop
        for (int j = 0; j < 64; ++j) {
            uint32_t F, g;
            if (j < 16) {
                F = (B & C) | (~B & D);
                g = j;
            } else if (j < 32) {
                F = (D & B) | (~D & C);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                F = B ^ C ^ D;
                g = (3 * j + 5) % 16;
            } else {
                F = C ^ (B | ~D);
                g = (7 * j) % 16;
            }

            F = F + A + K[j] + M[g];
            A = D;
            D = C;
            C = B;
            B = B + leftRotate(F, S[j]);
        }

        // Add this chunk's hash to result so far
        state[0] += A;
        state[1] += B;
        state[2] += C;
        state[3] += D;
    }

    // Convert the final state to a hex string
    std::stringstream ss;
    for (int i = 0; i < 4; ++i) {
        ss << std::hex << std::setw(8) << std::setfill('0') << state[i];
    }

    return ss.str();
}
