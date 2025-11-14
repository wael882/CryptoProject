// CaesarCipher.cpp
#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int shift)
    : m_shift(shift)
{
}

static char applyShift(char c, int shift)
{
    // version simple : on décale dans la table ASCII
    return static_cast<char>(c + shift);
}

std::string CaesarCipher::encrypt(const std::string& input) const
{
    std::string output = input;
    for (char& c : output)
    {
        c = applyShift(c, m_shift);
    }
    return output;
}

std::string CaesarCipher::decrypt(const std::string& input) const
{
    std::string output = input;
    for (char& c : output)
    {
        c = applyShift(c, -m_shift);
    }
    return output;
}
