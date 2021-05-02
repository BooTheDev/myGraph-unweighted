#pragma once
#include "../myTree.hpp"

template <typename V, typename _Hasher, typename _Eq>
myTree<V, _Hasher, _Eq>::myTree(
    myVertex<V> const* root_in,
    std::unordered_map<myVertex<V>*, myVertex<V>*> relative_in,
    std::unordered_map<std::reference_wrapper<V const>, myVertex<V>, _Hasher, _Eq> const& db_in
)
    : root{root_in}, relative{relative_in}, db{db_in}
{}

template <typename V, typename _Hasher, typename _Eq>
myVertex<V> const* myTree<V, _Hasher, _Eq>::getRoot() const
{
    return root;
}

template <typename V, typename _Hasher, typename _Eq>
std::vector<V> myTree<V, _Hasher, _Eq>::path(V const& v) const {
    std::vector<V> result;

    auto v_in = db.find(v);
    if (v_in == db.end())
       throw std::invalid_argument{"invalid argument"};

    auto current = const_cast<myVertex<V>*>(&v_in->second);
    if (!relative.contains(current))
        return {};

    while (current != nullptr) {
        result.push_back(*current->pData);
        current = relative.at(current);
    }

    return result;
}