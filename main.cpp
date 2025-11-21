#include "pixdeflate.h"
#include <cstdint>
#include <vector>
#include <iostream>

int main() {
    std::vector<uint8_t> data = {1,2,3,4,5,5,5,5,5,5,5,4,2,1};
    std::vector<uint8_t>   compressedData;
    std::vector<uint8_t> decompressedData;
    
    // Raw
    std::cout << "Raw" << std::endl;
    for (auto v : data) {
        std::cout << int(v) << ", ";
    }
    std::cout << std::endl << std::endl;

    // Compress data
    std::cout << "Compress: ";
    std::cout << int(Compress(data,compressedData,COMPRESSIONLEVEL_NONE)) << std::endl;
    for (auto v : compressedData) {
        std::cout << int(v) << ", ";
    }
    std::cout << std::endl << std::endl;

    // Decompress data
    std::cout << "Decompress: ";
    std::cout << int(Decompress(compressedData,decompressedData)) << std::endl;
    for (auto v : decompressedData) {
        std::cout << int(v) << ", ";
    }
    std::cout << std::endl;
    return 0;
}