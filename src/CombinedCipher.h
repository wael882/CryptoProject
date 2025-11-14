// CombinedCipher.h
#pragma once
#include "ICipher.h"
#include "CaesarCipher.h"
#include "XorCipher.h"

class CombinedCipher : public ICipher
{
public:
    CombinedCipher(int shift, unsigned char key);

    std::string encrypt(const std::string& input) const override;
    std::string decrypt(const std::string& input) const override;

private:
    CaesarCipher m_caesar;
    XorCipher    m_xor;
};
