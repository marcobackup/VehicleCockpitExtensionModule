#include "serializer.h"

Serializer::Serializer() {}

uint8_t Serializer::packLeftShiftU8(uint8_t value, uint8_t shift, uint8_t mask) {
    return static_cast<uint8_t>((static_cast<uint8_t>(value & shift)) << mask);
}

uint16_t Serializer::packLeftShiftU16(uint16_t value, uint16_t shift, uint16_t mask) {
    return static_cast<uint16_t>((static_cast<uint16_t>(value & shift)) << mask);
}

uint32_t Serializer::packLeftShiftU32(uint32_t value, uint32_t shift, uint32_t mask) {
    return static_cast<uint32_t>((static_cast<uint32_t>(value & shift)) << mask);
}

uint64_t Serializer::packLeftShiftU64(uint64_t value, uint64_t shift, uint64_t mask) {
    return static_cast<uint64_t>((static_cast<uint64_t>(value & shift)) << mask);
}

uint8_t Serializer::packRightShiftU8(uint8_t value, uint8_t shift, uint8_t mask) {
    return static_cast<uint8_t>((static_cast<uint8_t>(value & shift)) >> mask);
}

uint16_t Serializer::packRightShiftU16(uint16_t value, uint16_t shift, uint16_t mask) {
    return static_cast<uint16_t>((static_cast<uint16_t>(value & shift)) >> mask);
}

uint32_t Serializer::packRightShiftU32(uint32_t value, uint32_t shift, uint32_t mask) {
    return static_cast<uint32_t>((static_cast<uint32_t>(value & shift)) >> shift);
}

uint64_t Serializer::packRightShiftU64(uint64_t value, uint64_t shift, uint64_t mask) {
    return static_cast<uint64_t>((static_cast<uint64_t>(value & shift)) >> mask);
}
