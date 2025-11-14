// CryptoService.cpp
#include "CryptoService.h"
#include "CaesarCipher.h"
#include "XorCipher.h"
#include "CombinedCipher.h"
#include <fstream>
#include <memory>

static std::string readFile(const std::string& path)
{
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs)
        return {};

    return std::string((std::istreambuf_iterator<char>(ifs)),
                       std::istreambuf_iterator<char>());
}

static bool writeFile(const std::string& path, const std::string& data)
{
    std::ofstream ofs(path, std::ios::binary);
    if (!ofs)
        return false;

    ofs.write(data.data(), static_cast<std::streamsize>(data.size()));
    return true;
}

bool CryptoService::processFile(const std::string& inputPath,
                                const std::string& outputPath,
                                CipherMode mode,
                                bool encrypt,
                                int caesarShift,
                                unsigned char xorKey)
{
    std::string content = readFile(inputPath);
    if (content.empty())
        return false;

    // Choix du chiffreur
    std::unique_ptr<ICipher> cipher;

    switch (mode)
    {
    case CipherMode::Caesar:
        cipher = std::make_unique<CaesarCipher>(caesarShift);
        break;

    case CipherMode::Xor:
        cipher = std::make_unique<XorCipher>(xorKey);
        break;

    case CipherMode::Combined:
        cipher = std::make_unique<CombinedCipher>(caesarShift, xorKey);
        break;
    }

    std::string result;
    if (encrypt)
        result = cipher->encrypt(content);
    else
        result = cipher->decrypt(content);

    return writeFile(outputPath, result);
}
