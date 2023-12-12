#include <iostream>
#include <string>

class VigenereCipher 
{
public:
    VigenereCipher(std::string key) 
    {
        this->keyword = key;
    }

    std::string encrypt(const std::string& plaintext) 
    {
        std::string ciphertext;
        for (int i = 0; i < plaintext.length(); i++) {
            char plainChar = plaintext[i];
            char keyChar = keyword[i % keyword.length()];
            char encryptedChar = (plainChar + keyChar) % 26 + 'A';
            ciphertext += encryptedChar;
        }
        return ciphertext;
    }

    std::string decrypt(const std::string& ciphertext) 
    {
        std::string decryptedText;
        for (int i = 0; i < ciphertext.length(); i++) {
            char cipherChar = ciphertext[i];
            char keyChar = keyword[i % keyword.length()];
            char decryptedChar = (cipherChar - keyChar + 26) % 26 + 'A';
            decryptedText += decryptedChar;
        }
        return decryptedText;
    }

private:
    std::string keyword;
};

int main() {
    std::string key;
    std::cout << "Enter keyword: ";
    std::cin >> key;
    VigenereCipher vigenere(key);

    std::string plaintext;
    std::cout << "Enter the text: ";
    std::cin >> plaintext;
    
    std::cout << std::endl;

    std::string encryptedText = vigenere.encrypt(plaintext);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;
    std::string decryptedText = vigenere.decrypt(encryptedText);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}
