#include "uint_seq.h"
#include "uitil.h"
#include "stdio.h"
#include "string.h"

template <unsigned int BITS>
base_seq<BITS>::base_seq(const std::vector<unsigned char>& vuc)
{
    memcpy(data, vuc.data(), sizeof(data));
}



template <unsigned int BITS>
std::string base_seq<BITS>::GetHex()
{
    return ::HexStr(std::reverse_iterator<const uint8_t*>(data + sizeof(data)), std::reverse_iterator<const uint8_t*>(data));
}

template <unsigned int BITS>
void base_seq<BITS>::SetHex(const char* psz)
{
    memset(data, 0, sizeof(data));

    // skip leading spaces
    while (isspace(*psz))
        psz++;

    // skip 0x
    if (psz[0] == '0' && tolower(psz[1]) == 'x')
        psz += 2;

    // hex string to uint
    const char* pbegin = psz;
    while (::HexDigit(*psz) != -1)
        psz++;
    psz--;
    unsigned char* p1 = (unsigned char*)data;
    unsigned char* pend = p1 + Width;
    while (psz >= pbegin && p1 < pend) {
        *p1 = ::HexDigit(*psz--);
        if (psz >= pbegin) {
            *p1 |= ((unsigned char)::HexDigit(*psz--) << 4);
            p1++;
        }
    }
}

template <unsigned int BITS>
void base_seq<BITS>::SetHex(const std::string& str)
{
    SetHex(str.c_str());
}

template <unsigned int BITS>
std::string base_seq<BITS>::ToString()
{
    return (GetHex());
}

// Explicit instantiations for base_seq<160>
template base_seq<160>::base_seq(const std::vector<unsigned char>&);
template std::string base_seq<160>::GetHex();
template std::string base_seq<160>::ToString();
template void base_seq<160>::SetHex(const char*);
template void base_seq<160>::SetHex(const std::string&);

// Explicit instantiations for base_seq<256>
template base_seq<256>::base_seq(const std::vector<unsigned char>&);
template std::string base_seq<256>::GetHex();
template std::string base_seq<256>::ToString();
template void base_seq<256>::SetHex(const char*);
template void base_seq<256>::SetHex(const std::string&);

// Explicit instantiations for base_seq<512>
template base_seq<512>::base_seq(const std::vector<unsigned char>&);
template std::string base_seq<512>::GetHex();
template std::string base_seq<512>::ToString();
template void base_seq<512>::SetHex(const char*);
template void base_seq<512>::SetHex(const std::string&);


