#ifndef GRIDINFO_H
#define GRIDINFO_H

#include <cstddef>

struct GridInfo 
{
    constexpr static size_t rows() { return 9; };
    constexpr static size_t cols() { return 9; };
};

#endif 