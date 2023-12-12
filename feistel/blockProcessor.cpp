#include "blockProcessor.hpp"

std::vector<uint64_t> BlockProcessor::textToBlocks(const std::string& txt) {
    std::string paddedText = txt;
    while (paddedText.size() % 8 != 0) {
        paddedText.push_back('\0');
    }

    std::vector<uint64_t> blocks;

    for (size_t i = 0; i < paddedText.size(); i += 8) {
        uint64_t block = 0;
        for (int j = 0; j < 8; ++j) {
            block |= static_cast<uint64_t>(paddedText[i + j]) << (8 * j);
        }
        blocks.push_back(block);
    }

    return blocks;
}

std::string BlockProcessor::blocksToText(const std::vector<uint64_t>& blocks) {
    std::string processedText;
    for (uint64_t block : blocks) {
        for (int j = 0; j < 8; ++j) {
            processedText.push_back(static_cast<char>(block >> (8 * j)));
        }
    }

    return processedText;
}
