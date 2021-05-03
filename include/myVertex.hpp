#pragma once
#include <unordered_set>

template <typename V>
struct myVertex
{
    V const* pData;
    std::unordered_set<myVertex<V>*> pNeighbors;
};
