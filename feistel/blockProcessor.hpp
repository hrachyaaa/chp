#ifndef BLOCKPROCESSOR_H
#define BLOCKPROCESSOR_H

#include <vector>
#include <string>
#include <cstdint>

class BlockProcessor {
public:
    static std::vector<uint64_t> textToBlocks(const std::string& txt);
    static std::string blocksToText(const std::vector<uint64_t>& blocks);
};

#endif
