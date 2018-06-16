#include "uint_seq.h"
#include "stdio.h"
#include "stdlib.h"
#include "sha256.h"

int main()
{
    CSHA256 sh2;
    sh2.Write((const unsigned char*)"123",3);
    unsigned char hash[32];
    memset(hash, 0, 32);
    sh2.Finalize(hash);
    for(int i = 0 ; i < 32; i++)
    {printf("%02x",hash[i]);}
    getchar();
    return 0;
}

