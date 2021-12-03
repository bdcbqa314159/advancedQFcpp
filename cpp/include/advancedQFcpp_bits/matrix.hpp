#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <class T>
using matrix = std::vector<std::vector<T>>;

using size = unsigned int;

template <class T>
inline void matrix_resize(T &u, size N, size M)
{

    u.resize(N);

    for (auto &row : u)
        row.resize(M);
}

#endif