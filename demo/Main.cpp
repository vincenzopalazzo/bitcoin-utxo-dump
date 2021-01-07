#include <iostream>
#include <zlib.h>
#include <vector>

void decompressFileWithZLib(const std::string &filename);

int main(int argc, char* argv[])
{
    decompressFileWithZLib(std::string(argv[1]));
    return 0;
}

void decompressFileWithZLib(const std::string &filename)
{
    gzFile inFileZ = gzopen(filename.c_str(), "rb");

    if(inFileZ == NULL){
        printf("Error: Failed to gzopen %s\n", filename.c_str());
        exit(0);
    }
    unsigned char unzipBuffer[8192];
    unsigned int unzippedBytes;
    std::vector<unsigned char> unzippedData;
    while (true)
    {
        unzippedBytes = gzread(inFileZ, unzipBuffer, 8192);
        if(unzippedBytes > 0) {
            unzippedData.insert(unzippedData.end(), unzipBuffer, unzipBuffer + unzippedBytes);
        }else{
            break;
        }
    }

    for(auto &character : unzippedData)
    {
        if(character == '.'){
            std::cout << "\n";
        }else{
            std::cout << character;
        }
    }
}
