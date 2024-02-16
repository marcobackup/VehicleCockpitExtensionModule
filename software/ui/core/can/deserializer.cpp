#include "deserializer.h"

Deserializer::Deserializer() {}

uint8_t Deserializer::unpackLeftShiftU8(uint8_t value, uint8_t shift, uint8_t mask) {
    return static_cast<uint8_t>((static_cast<uint8_t>(value & mask)) << shift);
}

uint16_t Deserializer::unpackLeftShiftU16(uint16_t value, uint16_t shift, uint16_t mask) {
    return static_cast<uint16_t>((static_cast<uint16_t>(value & mask)) << shift);
}

uint32_t Deserializer::unpackLeftShiftU32(uint32_t value, uint32_t shift, uint32_t mask) {
    return static_cast<uint32_t>((static_cast<uint32_t>(value & mask)) << shift);
}

uint64_t Deserializer::unpackLeftShiftU64(uint64_t value, uint64_t shift, uint64_t mask) {
    return static_cast<uint64_t>((static_cast<uint64_t>(value & mask)) << shift);
}

uint8_t Deserializer::unpackRightShiftU8(uint8_t value, uint8_t shift, uint8_t mask) {
    return static_cast<uint8_t>((static_cast<uint8_t>(value & mask)) >> shift);
}

uint16_t Deserializer::unpackRightShiftU16(uint16_t value, uint16_t shift, uint16_t mask) {
    return static_cast<uint16_t>((static_cast<uint16_t>(value & mask)) >> shift);
}

uint32_t Deserializer::unpackRightShiftU32(uint32_t value, uint32_t shift, uint32_t mask) {
    return static_cast<uint32_t>((static_cast<uint32_t>(value & mask)) >> shift);
}

uint64_t Deserializer::unpackRightShiftU64(uint64_t value, uint64_t shift, uint64_t mask) {
    return static_cast<uint64_t>((static_cast<uint64_t>(value & mask)) >> shift);
}
