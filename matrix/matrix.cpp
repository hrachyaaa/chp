#include "matrix.h"

#include <vector>
#include <cmath>

std::string MatrixCipher::encode(const std::string &text) 
{
	int key = ceil(sqrt(text.length())); 
    int numRows = ceil(static_cast<double>(text.length()) / key);
        
    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(key, ' '));

    int index = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < key; col++) {
            if (index < text.length()) {
                matrix[row][col] = text[index++];
            }
        }
    }

    std::string encodedText;
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < numRows; row++) {
            encodedText += matrix[row][col];
        }
    }

    return encodedText;
}
std::string MatrixCipher::decode(const std::string &encodedText) 
{
	int key = ceil(sqrt(encodedText.length())); 
    int numRows = ceil(static_cast<double>(encodedText.length()) / key);

    std::vector<std::vector<char>> matrix(numRows, std::vector<char>(key, ' '));

    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int row = 0; row < numRows; row++) {
            if (index < encodedText.length()) {
                matrix[row][col] = encodedText[index++];
            }
        }
    }

    std::string decodedText;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < key; col++) {
            decodedText += matrix[row][col];
        }
    }

    return decodedText;
}
