#include "deflate.h"

// Write an uncompressed block of data
int8_t WriteUncompressedBlock(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& compressedData,
    bool blockFinal = false
) {
    uint8_t blockHeader = BTYPE_UNCOMPRESSED;
    if (blockFinal) blockHeader |= BFINAL;
    compressedData.push_back(blockHeader);
    WriteShort( int16_t(data.size()), compressedData);
    WriteShort(~int16_t(data.size()), compressedData);
    compressedData.insert(
        compressedData.end(),
        data.begin(),
        data.end()
    );
    return COMPRESSIONRESULT_SUCCESS;
}

// Write an compressed block of data (static huffman codes)
int8_t WriteStaticCompressedBlock(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& compressedData,
    bool blockFinal = false
) {
    uint8_t blockHeader = BTYPE_UNCOMPRESSED;
    if (blockFinal) blockHeader |= BFINAL;
    compressedData.push_back(blockHeader);
    WriteShort( int16_t(data.size()), compressedData);
    WriteShort(~int16_t(data.size()), compressedData);
    compressedData.insert(
        compressedData.end(),
        data.begin(),
        data.end()
    );
    return COMPRESSIONRESULT_SUCCESS;
}

// Compress data
int8_t Compress(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& compressedData,
    [[maybe_unused]] int8_t compressionLevel
) {
    switch (compressionLevel) {
        case COMPRESSIONLEVEL_NONE:
            return WriteUncompressedBlock(data,compressedData);
        case COMPRESSIONLEVEL_ANY:
            return WriteStaticCompressedBlock(data,compressedData);
        default:
            return COMPRESSIONRESULT_INVALID_LEVEL;
    }
    return COMPRESSIONRESULT_FAILURE;
}