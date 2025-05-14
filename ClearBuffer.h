#ifndef CLEAR_BUFFER
#define CLEAR_BUFFER

#include <iostream>
#include <limits>

// inline so compiler doesn't see multiple copies of the same thing when it's included in multiple files

// defaulting to std::cin if no stream is passed
inline void ClearBuffer(std::istream& is = std::cin) {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


#endif