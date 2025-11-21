#pragma once

#include "defines.h"

// Read and write multi-byte values
void WriteShort(int16_t value, std::vector<uint8_t>& data);
int16_t ReadShort(std::vector<uint8_t>& data, size_t& offset);