// main.cpp
#include <iostream>
#include "CryptoService.h"

int main()
{
    std::string inputPath, outputPath;
    int modeInt;
    int shift;
    int keyInt;
    bool encrypt;

    std::cout << "Fichier source : ";
    std::cin >> inputPath;

    std::cout << "Mode (1 = Cesar, 2 = XOR, 3 = Cesar+XOR) : ";
    std::cin >> modeInt;

    std::cout << "1 = Chiffrer, 0 = Dechiffrer : ";
    std::cin >> encrypt;

    std::cout << "Fichier destination : ";
    std::cin >> outputPath;

    std::cout << "Valeur de decalage (Cesar) : ";
    std::cin >> shift;

    std::cout << "Cle XOR (0-255) : ";
    std::cin >> keyInt;

    CipherMode mode = static_cast<CipherMode>(modeInt);
    CryptoService service;

    bool ok = service.processFile(inputPath,
                                  outputPath,
                                  mode,
                                  encrypt,
                                  shift,
                                  static_cast<unsigned char>(keyInt));

    if (ok)
        std::cout << "Operation terminee avec succes.\n";
    else
        std::cout << "Erreur lors du traitement.\n";

    return 0;
}
