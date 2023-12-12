#include <iostream>
#include "feistelCipher.hpp"
#include "blockProcessor.hpp"

int main() {
    std::string plaintext {"London is the capital of Great Britain"};
    uint64_t key {0xaff0f0f0faf0f0fd};

    auto blocks = BlockProcessor::textToBlocks(plaintext);

    for (auto& block : blocks) {
        block = FeistelCipher::feistelDecryption(block, key);
    }

    std::string encoded = BlockProcessor::blocksToText(blocks);

    for (auto& block : blocks) {
        block = FeistelCipher::feistelDecryption(block, key);
    }

    std::string decoded = BlockProcessor::blocksToText(blocks);

    std::cout << "\nOriginal Text: " << plaintext
              << "\nEncoded Text: " << encoded
              << "\nDecoded Text: " << decoded << std::endl;

    return 0;
}
