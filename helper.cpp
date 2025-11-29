#include "helper.h"

void WriteBits(uint64_t value, size_t length, std::vector<bool>& data) {
    for (size_t i = 0; i < length; i++) {
        data.push_back((value >> i) & 1);
    }
}

void WriteByte(uint8_t value, std::vector<bool>& data) {
    for (int i = 0; i < 8; i++) {
        data.push_back((value >> i) & 1);
    }
}

// Read and write multi-byte values
void WriteShortBits(int16_t value, std::vector<bool>& data) {
    WriteByte(uint8_t((value      ) & 0xFF), data);
    WriteByte(uint8_t((value >>  8) & 0xFF), data);
}

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

int8_t ConvertStreamToBytes(std::vector<uint8_t>& bytes, std::vector<bool>& bits) {
    // Add 7 to account for any partial bytes
    bytes.resize((bits.size() + 7) /8, 0);
    
    for (size_t i = 0; i < bits.size(); i++) {
        if (bits[i]) {
            bytes[i/8] |= 1 << i%8;
        }
    }
    return COMPRESSIONRESULT_SUCCESS;
}