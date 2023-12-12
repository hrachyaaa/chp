#include "feistelCipher.hpp"

uint32_t FeistelCipher::roundFunction(uint32_t right, uint64_t key) {
    return right ^ static_cast<uint32_t>(key);
}

uint64_t FeistelCipher::feistelEncryption(uint64_t block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);
    const int rounds {16};

    for (int round = 0; round < rounds; ++round) {
        uint32_t temp = left;
        left = right;
        right = temp ^ roundFunction(right, key);
    }

    return (static_cast<uint64_t>(right) << 32) | left;
}

uint64_t FeistelCipher::feistelDecryption(uint64_t block, uint64_t key) {
    uint32_t left = block >> 32;
    uint32_t right = static_cast<uint32_t>(block);
    const int rounds {16};

    for (int round = 0; round < rounds; ++round) {
        uint32_t temp = left;
        left = right;
        right = temp ^ roundFunction(right, key);
    }

    return (static_cast<uint64_t>(right) << 32) | left;
}
