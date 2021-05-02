#pragma once
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include "./myVertex.hpp"
template <typename V, typename _Hasher, typename _Eq>
class myTree
{
public:
    myTree(
        myVertex<V> const* root_in,
        std::unordered_map<myVertex<V>*, myVertex<V>*> relative_in,
        std::unordered_map<std::reference_wrapper<V const>, myVertex<V>, _Hasher, _Eq> const& db_in
    );
    myVertex<V> const* getRoot() const;
    std::vector<V> path(V const& v) const;
private:
    myVertex<V> const* root;
    std::unordered_map<myVertex<V>*, myVertex<V>*> const relative;
    std::unordered_map<std::reference_wrapper<V const>, myVertex<V>, _Hasher, _Eq> const& db;
};

#include "./implement/_myTree_implement.hpp"