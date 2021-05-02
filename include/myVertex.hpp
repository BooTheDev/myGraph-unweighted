#pragma once
#include <unordered_set>

template <typename V>
class myVertex
{
public:
    V const* pData;
    std::unordered_set<myVertex<V>*> pNeighbors;
public:
    myVertex(V const* ptr) : pData{ ptr } {}
    ~myVertex() { delete pData; }
};
