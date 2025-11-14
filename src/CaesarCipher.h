// CaesarCipher.h
#pragma once
#include "ICipher.h"

class CaesarCipher : public ICipher
{
public:
    explicit CaesarCipher(int shift);

    std::string encrypt(const std::string& input) const override;
    std::string decrypt(const std::string& input) const override;

private:
    int m_shift;
};
