
#ifndef CRYPTO_IF_H
#define CRYPTO_IF_H

#include <stdint.h>
#include <stdlib.h>
#include <string>

class Crypto_IF
{
    Crypto_IF();
    Crypto_IF* Assign(const unsigned char* data, size_t len);
    void Hash(unsigned char* hash);
    Crypto_IF* Reset();
};


#endif
