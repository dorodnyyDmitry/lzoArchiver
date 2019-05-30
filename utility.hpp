#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <fstream>

namespace utility {

    int read(std::ifstream&,char*, int);

    void write32(std::ofstream&,int);

    int read32(std::ifstream&);

    inline void write(std::ofstream& out,char* write_from, int block_size){
        out.write(write_from, block_size);
    }

    inline int total_block_size(int initial_block_size){
        return initial_block_size + initial_block_size/16 +64 +3; //max block size with header
    }

}
#endif // UTILITY_HPP
