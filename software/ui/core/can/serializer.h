#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <cstdint>

class Serializer
{
public:
    Serializer();
    uint8_t packLeftShiftU8(uint8_t value, uint8_t shift, uint8_t mask);
    uint16_t packLeftShiftU16(uint16_t value, uint16_t shift, uint16_t mask);
    uint32_t packLeftShiftU32(uint32_t value, uint32_t shift, uint32_t mask);
    uint64_t packLeftShiftU64(uint64_t value, uint64_t shift, uint64_t mask);
    uint8_t packRightShiftU8(uint8_t value, uint8_t shift, uint8_t mask);
    uint16_t packRightShiftU16(uint16_t value, uint16_t shift, uint16_t mask);
    uint32_t packRightShiftU32(uint32_t value, uint32_t shift, uint32_t mask);
    uint64_t packRightShiftU64(uint64_t value, uint64_t shift, uint64_t mask);
};

#endif // SERIALIZER_H
