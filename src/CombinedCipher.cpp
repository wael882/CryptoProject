// CombinedCipher.cpp
#include "CombinedCipher.h"

CombinedCipher::CombinedCipher(int shift, unsigned char key)
    : m_caesar(shift),
      m_xor(key)
{
}

std::string CombinedCipher::encrypt(const std::string& input) const
{
    // 1. César
    std::string tmp = m_caesar.encrypt(input);
    // 2. XOR
    return m_xor.encrypt(tmp);
}

std::string CombinedCipher::decrypt(const std::string& input) const
{
    // Ordre inverse :
    // 1. XOR
    std::string tmp = m_xor.decrypt(input);
    // 2. César
    return m_caesar.decrypt(tmp);
}
