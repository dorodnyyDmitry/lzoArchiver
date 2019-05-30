#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP

#include <fstream>
#include <vector>

class Compressor{
public:
    Compressor(std::ifstream fin, std::ofstream fout);
    void compress(int);
    void decompress();
private:
    std::ifstream fin;
    std::ofstream fout;

};

#endif // COMPRESSOR_HPP
