#include "rle1.h"

std::string RLE::encode(const std::string& input) 
{
    int count = 1;
    std::string encoded;
    for (int i = 0; i < input.length(); i++) {
        if (i < input.length() - 1 && input[i] == input[i + 1]) {
            count++;
        } else {
            encoded += input[i];

            if (count > 1) {
                encoded += std::to_string(count);
            }
            count = 1;
        }
    }

    return encoded;
}
std::string RLE::decode(const std::string& encoded) 
{
    int i = 0;
    std::string decoded;
    while (i < encoded.length()) {
        char character = encoded[i];
        i++;
        std::string count_str;
        while (i < encoded.length() && isdigit(encoded[i])) {
            count_str += encoded[i];
            i++;
        }

        int count = (count_str.empty()) ? 1 : std::stoi(count_str);
        for (int j = 0; j < count; j++) {
            decoded += character;
        }
    }

    return decoded;
}
