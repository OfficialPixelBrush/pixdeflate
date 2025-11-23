#include "deflate.h"

// Write an uncompressed block of data
int8_t WriteUncompressedBlock(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<bool>& compressedData,
    bool blockFinal = false
) {
    // Write Header
    WriteBits(BTYPE_UNCOMPRESSED, 2, compressedData);
    data.push_back(blockFinal);
    // Write Length
    WriteShort( int16_t(data.size()), compressedData);
    WriteShort(~int16_t(data.size()), compressedData);
    // Add raw data
    for (auto v : data) {
        WriteByte(v, compressedData);
    }
    return COMPRESSIONRESULT_SUCCESS;
}

// Write an compressed block of data (static huffman codes)
int8_t WriteStaticCompressedBlock(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<bool>& compressedData,
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
    std::vector<bool> compressedDataStream;
    switch (compressionLevel) {
        case COMPRESSIONLEVEL_NONE:
            WriteUncompressedBlock(data,compressedDataStream);
            break;
        case COMPRESSIONLEVEL_MAX:
        case COMPRESSIONLEVEL_ANY:
        case COMPRESSIONLEVEL_MIN:
            WriteStaticCompressedBlock(data,compressedDataStream);
            break;
        default:
            return COMPRESSIONRESULT_INVALID_LEVEL;
    }
    if (compressedDataStream.empty()) return COMPRESSIONRESULT_FAILURE;
    return ConvertStreamToBytes(compressedData, compressedDataStream);
}