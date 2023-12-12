#ifndef RLE1_H
#define RLE1_H

#include "cipher.h"
#include <string>

class RLE : public Cipher
{
public:
    std::string encode(const std::string&) override;
    std::string decode(const std::string&) override;
};

#endif //RLE1_H
