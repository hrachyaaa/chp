#include <iostream>
#include <string>

class Cipher 
{
public:
    virtual ~Cipher() = default;
    virtual std::string encode(const std::string& message) const = 0;
    virtual std::string decode(const std::string& message) const = 0;
};

class SubstitutionCipher : public Cipher 
{
private:
    std::string substitutionAlphabet;

public:
    SubstitutionCipher(const std::string& alphabet) 
     : substitutionAlphabet(alphabet) 
    {}

    std::string encode(const std::string& message) const override 
    {
        std::string encodedMessage = message;
        for (char& character : encodedMessage) {
            if (std::isalpha(character)) {
                char originalChar = std::toupper(character);
                int index = originalChar - 'A';

                if (index >= 0 && index < 26) {
                    char substitutedChar = substitutionAlphabet[index];
                    if (std::islower(character)) {
                        substitutedChar = std::tolower(substitutedChar);
                    }
                    character = substitutedChar;
                }
            }
        }
        return encodedMessage;
    }

    std::string decode(const std::string& message) const override 
    {
        std::string decodedMessage = message;
        for (char& character : decodedMessage) {
            if (std::isalpha(character)) {
                char substitutedChar = std::toupper(character);
                size_t index = substitutionAlphabet.find(substitutedChar);

                if (index != std::string::npos) {
                    char originalChar = 'A' + static_cast<char>(index);
                    if (std::islower(character)) {
                        originalChar = std::tolower(originalChar);
                    }
                    character = originalChar;
                }
            }
        }
        return decodedMessage;
    }
};

int main() 
{
    std::string substitutionAlphabet = "QWERTYUIOPASDFGHJKLZXCVBNM";
    SubstitutionCipher cipher(substitutionAlphabet);

    std::string message;

    std::cout << "Enter a message to encode: ";
    std::getline(std::cin, message);

    std::string encodedMessage = cipher.encode(message);
    std::cout << "Encoded message: " << encodedMessage << std::endl;

    std::string decodedMessage = cipher.decode(encodedMessage);
    std::cout << "Decoded message: " << decodedMessage << std::endl;

    return 0;
}
