#include <iostream>
#include <zlib.h>
#include <vector>

void decompressFileWithZLib(char* filename);

int main(int argc, char* argv[])
{
    std::cout << "Load compressed file from: " << argv[1];
    decompressFileWithZLib(argv[1]);
    return 0;
}

void decompressFileWithZLib(char* filename)
{
    gzFile inFileZ = gzopen(filename, "rb");

    if(inFileZ == NULL){
        printf("Error: Failed to gzopen %s\n", filename);
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
