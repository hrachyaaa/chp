#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
public:
	virtual ~Cipher() = default;

public:
    virtual std::string encode(const std::string &text) = 0;
    virtual std::string decode(const std::string &encodedText) = 0;
};

#endif //CIPHER_H
