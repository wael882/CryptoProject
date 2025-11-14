// CryptoService.h
#pragma once
#include <string>

enum class CipherMode
{
    Caesar = 1,
    Xor    = 2,
    Combined = 3
};

class CryptoService
{
public:
    bool processFile(const std::string& inputPath,
                     const std::string& outputPath,
                     CipherMode mode,
                     bool encrypt,
                     int caesarShift,
                     unsigned char xorKey);
};
