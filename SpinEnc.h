//
// Created by suteerth on 3/18/16.
//

#ifndef CCRYPTO_SPINENC_H
#define CCRYPTO_SPINENC_H


#include <iostream>
#include <string>
using namespace std;

class Vigenere
{

private:
    string key;
public:

    Vigenere(string key);
    string encrypt(string text);
    string decrypt(string text);
};



#endif //CCRYPTO_SPINENC_H
