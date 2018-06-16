#ifndef _UINT_SEQ_H_
#define _UINT_SEQ_H_


#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>
#include "data_types.h"
#include "common.h"
template<unsigned int BITS>
class base_seq
{
public:
    static const int Width = BITS/8;
    uint8_t data[Width];

public:
    base_seq()
    {
        memset(data, 0, sizeof(data));
    }

    base_seq(const std::vector<unsigned char>& vch);

    bool IsNull()
    {
        for(int i = 0; i < Width; ++i)
        {
            if(data[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    void SetNull()
    {
        memset(data, 0, sizeof(data));
    }

    inline int Compare(const base_seq& other){return memcpy(data, 
    other.data, sizeof(data));}

    friend inline bool operator==(const base_seq& one, const base_seq& 
    second){return one.compare(second) == 0;}
    friend inline bool operator!=(const base_seq& one, const base_seq& 
    second){return one.compare(second) != 0;}
    friend inline bool operator<(const base_seq& one, const base_seq& 
    second){return one.compare(second) < 0;}

    std::string GetHex();
    void SetHex(const char* psz);
    void SetHex(const std::string& str);
    std::string ToString();
    unsigned char* begin(){return &data[0];}
    unsigned char* end(){return &data[Width];}

     unsigned int size(){return sizeof(data);}

    uint64_t GetUint64(int pos) const
    {
        const uint8_t* ptr = data + pos * 8;
        return ((uint64_t)ptr[0]) | \
               ((uint64_t)ptr[1]) << 8 | \
               ((uint64_t)ptr[2]) << 16 | \
               ((uint64_t)ptr[3]) << 24 | \
               ((uint64_t)ptr[4]) << 32 | \
               ((uint64_t)ptr[5]) << 40 | \
               ((uint64_t)ptr[6]) << 48 | \
               ((uint64_t)ptr[7]) << 56;
    }

    template<typename Stream>
    void Serialize(Stream& s) const
    {
        s.write((char*)data, sizeof(data));
    }

    template<typename Stream>
    void Unserialize(Stream& s)
    {
        s.read((char*)data, sizeof(data));
    }

};
class uint160 : public base_seq<160> 
{
public:
    uint160() {}
    explicit uint160(const std::vector<unsigned char>& vch) : base_seq<160>(vch) {}
};

class uint256 : public base_seq<256> {
public:
    
    uint256() {}
    explicit uint256(const std::vector<unsigned char>& vch) : base_seq<256>(vch) {}

    /** A cheap hash function that just returns 64 bits from the result, it can be
     * used when the contents are considered uniformly random. It is not appropriate
     * when the value can easily be influenced from outside as e.g. a network adversary could
     * provide values to trigger worst-case behavior.
     */
    uint64_t GetCheapHash() const
    {
        return ReadLE64(data);
    }
};

/* uint256 from const char *.
 * This is a separate function because the constructor uint256(const char*) can result
 * in dangerously catching uint256(0).
 */
inline uint256 uint256S(const char *str)
{
    uint256 rv;
    rv.SetHex(str);
    return rv;
}
/* uint256 from std::string.
 * This is a separate function because the constructor uint256(const std::string &str) can result
 * in dangerously catching uint256(0) via std::string(const char*).
 */
inline uint256 uint256S(const std::string& str)
{
    uint256 rv;
    rv.SetHex(str);
    return rv;
}

#endif
