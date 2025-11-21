#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

#define NON_COMPRESSIBLE_BLOCK_LIMIT 65535

// Huffman trees are walked down by
// going through the bit sequence until a 
// value is hit

#define BFINAL 0b00000001
#define BTYPE  0b00000110

#define BTYPE_UNCOMPRESSED      0b00000000
#define BTYPE_FIXED_HUFFMAN     0b00000010
#define BTYPE_DYNAMIC_HUFFMAN   0b00000100
#define BTYPE_RESERVED          0b00000110

enum CompressionLevel {
    COMPRESSIONLEVEL_NONE,
    COMPRESSIONLEVEL_ANY,
    COMPRESSIONLEVEL_MIN,
    COMPRESSIONLEVEL_MAX
};

enum CompressionResult {
    COMPRESSIONRESULT_SUCCESS,
    COMPRESSIONRESULT_FAILURE,
    COMPRESSIONRESULT_INVALID_BTYPE,
    COMPRESSIONRESULT_INVALID_LEVEL,
    COMPRESSIONRESULT_MISMATCHED_COMPLEMENT
};