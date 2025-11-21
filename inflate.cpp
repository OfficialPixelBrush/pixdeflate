#include "inflate.h"

// Read an uncompressed block of data
int8_t ReadUncompressedBlock(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& decompressedData,
    size_t& offset
) {
    int16_t blockSize = ReadShort(data, offset);
    int16_t blockSizeComp = ReadShort(data, offset);
    if (blockSize != ~blockSizeComp) return COMPRESSIONRESULT_MISMATCHED_COMPLEMENT;

    decompressedData.insert(
        decompressedData.end(),
        data.begin() + long(offset),
        data.begin() + long(offset) + long(blockSize)
    );
    offset += size_t(blockSize);
    return COMPRESSIONRESULT_SUCCESS;
}

// Decompress data
int8_t Decompress(
    [[maybe_unused]] std::vector<uint8_t>& data,
    [[maybe_unused]] std::vector<uint8_t>& decompressedData
) {
    size_t blockIndex = 0;
    while(blockIndex < data.size()) {
        uint8_t blockHeader = data[blockIndex++];
        switch(blockHeader & BTYPE) {
            case BTYPE_UNCOMPRESSED:
                return ReadUncompressedBlock(data,decompressedData,blockIndex);
            default:
                return COMPRESSIONRESULT_INVALID_BTYPE;
        }
    }
    return COMPRESSIONRESULT_FAILURE;
}