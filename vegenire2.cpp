#include <iostream>
#include <string>

std::string encrypt(const std::string& text, const std::string& key) {
    std::string encryptedText = "";
    size_t keyLength = key.length();

    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        char keyChar = key[i % keyLength];
        char encryptedChar = ((ch + keyChar) % 255);
        encryptedText += encryptedChar;
    }

    return encryptedText;
}

std::string decrypt(const std::string& text, const std::string& key) {
    std::string decryptedText = "";
    size_t keyLength = key.length();

    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        char keyChar = key[i % keyLength];
        char decryptedChar = ((ch - keyChar + 255) % 255);
        decryptedText += decryptedChar;
    }

    return decryptedText;
}

int main() {
    std::string plainText = "Hello, World!";
    std::string secretKey = "PRIVATEKEY";

    std::string encryptedText = encrypt(plainText, secretKey);
    std::string decryptedText = decrypt(encryptedText, secretKey);

    std::cout << "Plain Text:     " << plainText << std::endl;
    std::cout << "Secret Key:     " << secretKey << std::endl;
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
