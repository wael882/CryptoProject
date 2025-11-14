// XorCipher.cpp
#include "XorCipher.h"

XorCipher::XorCipher(unsigned char key)
    : m_key(key)
{
}

std::string XorCipher::encrypt(const std::string& input) const
{
    std::string output = input;
    for (char& c : output)
    {
        c = static_cast<char>(static_cast<unsigned char>(c) ^ m_key);
    }
    return output;
}

// XOR est symétrique : même opération pour déchiffrer
std::string XorCipher::decrypt(const std::string& input) const
{
    return encrypt(input);
}
