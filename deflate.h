#pragma once

#include "defines.h"
#include "helper.h"

// Compress data
int8_t Compress(
    std::vector<uint8_t>& data,
    std::vector<uint8_t>& compressedData,
    int8_t compressionLevel = COMPRESSIONLEVEL_ANY
);