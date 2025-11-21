#include "helper.h"

// Read and write multi-byte values
void WriteShort(int16_t value, std::vector<uint8_t>& data) {
    data.push_back(uint8_t((value      ) & 0xFF));
    data.push_back(uint8_t((value >>  8) & 0xFF));
}

int16_t ReadShort(std::vector<uint8_t>& data, size_t& offset) {
    int16_t value = 0;
    value |= int16_t(data[offset++]     );
    value |= int16_t(data[offset++] << 8);
    return value;
}