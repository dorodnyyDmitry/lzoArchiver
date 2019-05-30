#include "compressor.hpp"
#include <iostream>
#include <lzo1z.h>
#include "utility.hpp"

Compressor::Compressor(std::ifstream fin, std::ofstream fout):fin(std::move(fin)), fout(std::move(fout))
{

}

void Compressor::compress(int block_size){
    lzo_init();
    utility::write32(fout, block_size);

    std::vector<char> input_buffer;
    input_buffer.reserve(block_size);

    std::vector<char> output_buffer;
    output_buffer.reserve(utility::total_block_size(block_size));

    std::vector<char> workmem;
    workmem.resize(LZO1Z_999_MEM_COMPRESS);

    void* input_buffer_p = &input_buffer.front();
    void* output_buffer_p = &output_buffer.front();

    unsigned long u_block_size = static_cast<unsigned long>(block_size);
    void* workmem_p = &workmem.front();

    while(true){

        int actual_block_size = utility::read(fin, &input_buffer.front(), block_size);


        lzo1z_999_compress(static_cast<unsigned char*>(input_buffer_p), actual_block_size, static_cast<unsigned char*>(output_buffer_p), &u_block_size, workmem_p);

        if(u_block_size < actual_block_size){
            utility::write32(fout, u_block_size);
            utility::write(fout, &output_buffer.front(), u_block_size);
        }
        else{
            utility::write32(fout, actual_block_size);
            utility::write(fout, &output_buffer.front(), actual_block_size);
        }
        if(actual_block_size < block_size)
            break;
    }
}



void Compressor::decompress(){
    lzo_init();
    int r = 0;
    int init_block_size = utility::read32(fin);

    int comp_block_size;
    unsigned long decomp_block_size;

    std::vector<char> input_buffer;
    input_buffer.reserve(init_block_size);

    std::vector<char> output_buffer;
    output_buffer.reserve(utility::total_block_size(init_block_size));

    void* input_buffer_p = &input_buffer.front();
    void* output_buffer_p = &output_buffer.front();

    while((comp_block_size = utility::read32(fin))){
        r = utility::read(fin, &input_buffer.front(), comp_block_size);
        if(r < init_block_size){
            lzo1z_decompress(static_cast<unsigned char*>(input_buffer_p), comp_block_size, static_cast<unsigned char*>(output_buffer_p), &decomp_block_size, NULL);
            utility::write(fout, &output_buffer.front(), decomp_block_size);
        }
        else
            utility::write(fout, &output_buffer.front(), comp_block_size);
    }
}
