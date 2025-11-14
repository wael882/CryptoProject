// ICipher.h
#pragma once
#include <string>

class ICipher
{
public:
    virtual ~ICipher() = default;

    virtual std::string encrypt(const std::string& input) const = 0;
    virtual std::string decrypt(const std::string& input) const = 0;
};
