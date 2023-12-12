#ifndef FEISTELCIPHER_H
#define FEISTELCIPHER_H

#include <cstdint>

class FeistelCipher {
public:
    static uint32_t roundFunction(uint32_t right, uint64_t key);
    static uint64_t feistelEncryption(uint64_t block, uint64_t key);
    static uint64_t feistelDecryption(uint64_t block, uint64_t key);
};

#endif
