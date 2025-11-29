#pragma once

#include "defines.h"

// Read and write multi-byte values
void WriteBits(uint64_t value, size_t length, std::vector<bool>& data);
void WriteByte(uint8_t value, std::vector<bool>& data);
void WriteShortBits(int16_t value, std::vector<bool>& data);
void WriteShort(int16_t value, std::vector<uint8_t>& data);
int16_t ReadShort(std::vector<uint8_t>& data, size_t& offset);

int8_t ConvertStreamToBytes(std::vector<uint8_t>& bytes, std::vector<bool>& bits);