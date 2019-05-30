#include "utility.hpp"
#include <fstream>


int utility::read(std::ifstream& in,char* read_to, int block_size){
    in.read(read_to, block_size);

    return in.gcount();
}

void utility::write32(std::ofstream& fo, int to_write){
    char buffer[4];
    for(int i = 0; i <4; i++)
        buffer[i] = static_cast<char>((to_write >> i*8) & 0xff);

    utility::write(fo, buffer, 4);

}

int utility::read32(std::ifstream& fi){
    unsigned char buffer[4];
    int to_read = 0;

    void* temp_buffer = buffer;

    utility::read(fi, static_cast<char*>(temp_buffer), 4);

    to_read   = static_cast<int>( buffer[0] )<<  0;
    to_read  |= static_cast<int>( buffer[1] )<<  8;
    to_read  |= static_cast<int>( buffer[2] )<<  16;
    to_read  |= static_cast<int>( buffer[3] )<<  24;

    return to_read;
}
