// XorCipher.h
#pragma once
#include "ICipher.h"

class XorCipher : public ICipher
{
public:
    explicit XorCipher(unsigned char key);

    std::string encrypt(const std::string& input) const override;
    std::string decrypt(const std::string& input) const override;

private:
    unsigned char m_key;
};
