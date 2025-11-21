#pragma once

#include "defines.h"
#include "helper.h"

// Decompress data
int8_t Decompress(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& decompressedData
);