CryptoProject – Système de chiffrement et déchiffrement
Présentation

Ce projet propose un programme en C++ permettant de chiffrer et de déchiffrer le contenu d'un fichier texte selon trois méthodes différentes :

1. Chiffrement de type César

2. Chiffrement de type XOR

3. Chiffrement combiné (César + XOR)

L'utilisateur choisit :

-Le fichier source,

-Le mode de chiffrement ou déchiffrement,

-Les paramètres nécessaires (décalage César et clé XOR),

-Le fichier de destination.

Ce projet est développé en C++ avec une architecture orientée objet afin de séparer clairement les responsabilités et d'assurer une meilleure maintenabilité du code.



Fonctionnalités

-Lecture d'un fichier texte (crypté ou non)

-Chiffrement ou déchiffrement selon trois modes

-Rédaction du résultat dans un fichier de destination

-Implémentation modulaire utilisant une interface commune à toutes les méthodes de chiffrement

-Structure de code réutilisable et extensible



Architecture

Le projet utilise quatre composantes principales :

-Interface ICipher

Définit les méthodes communes à toutes les stratégies de chiffrement :

encrypt(const std::string&)

decrypt(const std::string&)

-Classe CaesarCipher

Implémente le chiffrement de type César (décalage ASCII).

-Classe XorCipher

Implémente le chiffrement utilisant l'opération XOR avec une clé.

-Classe CombinedCipher

Combine les deux mécanismes :

Chiffrement : César, puis XOR

Déchiffrement : XOR, puis César

-Service CryptoService

Gère :

La lecture du fichier source,

Le choix de la stratégie de chiffrement,

L’application du chiffrement ou déchiffrement,

L’écriture du fichier de destination.


Structure du projet:

CryptoProject/
│
├── src/
│   ├── ICipher.h
│   ├── CaesarCipher.h
│   ├── CaesarCipher.cpp
│   ├── XorCipher.h
│   ├── XorCipher.cpp
│   ├── CombinedCipher.h
│   ├── CombinedCipher.cpp
│   ├── CryptoService.h
│   ├── CryptoService.cpp
│   └── main.cpp
│
├── README.md
├── .gitignore
└── LICENSE

Compilation

Se rendre dans le dossier src puis compiler l'ensemble des fichiers :

g++ -std=c++17 *.cpp -o crypto


Le fichier exécutable généré portera le nom crypto sous Linux/macOS et crypto.exe sous Windows.

Exécution

Linux/macOS :

./crypto


Windows :

./crypto.exe


Le programme demande ensuite :

Le chemin du fichier source

Le mode de chiffrement/déchiffrement

1 : César

2 : XOR

3 : Combiné

Chiffrer (1) ou Déchiffrer (0)

Le fichier de destination

La valeur de décalage (César)

La clé XOR (entre 0 et 255)



Pour le déchiffrer, il suffit d'utiliser le même mode et les mêmes paramètres.