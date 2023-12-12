#ifndef MATRIX_H
#define MATRIX_H

#include "cipher.h"

class MatrixCipher : public Cipher
{
public:
	std::string encode(const std::string &text) override;
    std::string decode(const std::string &encodedText) override;
};

#endif //MATRIX_h
