#ifndef DESERIALIZER_H
#define DESERIALIZER_H
#include <cstdint>

class Deserializer
{
public:
    Deserializer();
    uint8_t unpackLeftShiftU8(uint8_t value, uint8_t shift, uint8_t mask);
    uint16_t unpackLeftShiftU16(uint16_t value, uint16_t shift, uint16_t mask);
    uint32_t unpackLeftShiftU32(uint32_t value, uint32_t shift, uint32_t mask);
    uint64_t unpackLeftShiftU64(uint64_t value, uint64_t shift, uint64_t mask);
    uint8_t unpackRightShiftU8(uint8_t value, uint8_t shift, uint8_t mask);
    uint16_t unpackRightShiftU16(uint16_t value, uint16_t shift, uint16_t mask);
    uint32_t unpackRightShiftU32(uint32_t value, uint32_t shift, uint32_t mask);
    uint64_t unpackRightShiftU64(uint64_t value, uint64_t shift, uint64_t mask);
};

#endif // DESERIALIZER_H
