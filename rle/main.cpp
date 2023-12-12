#include "rle1.h"

#include <iostream>

int main() {
    std::string input;
    std::cin >> input;
    RLE ed;
    std::string encoded = ed.encode(input);
    std::string decoded = ed.decode(input);

    std::cout << "Original String: " << input << std::endl;
    std::cout << "Encoded String: " << encoded << std::endl;
    std::cout << "Decoded String: " << decoded << std::endl;

    return 0;
}
