#pragma once
#include <unordered_map>
#include <queue>
#include <stack>
#include <utility>
#include <stdexcept>
#include "./implement/_myTree_implement.hpp"
#include "./myVertex.hpp"

template <typename V, typename _Hasher = std::hash<V>, typename _Eq = std::equal_to<V>>
class myGraph
{
public:
    myGraph() {}
    ~myGraph();
    
    // Mutators
    void addVertex(V const& v);
    void addEdge(V const& v, V const& d);
    void removeVertex(V const& v);

    // Accessors
    std::size_t size() const;
    myTree<V, _Hasher, _Eq> bfs(V const& v) const;
    myTree<V, _Hasher, _Eq> dfs(V const& v) const;
private:
    void dfs(
        myVertex<V>* current,
        std::unordered_map<myVertex<V>*, myVertex<V>*>& relative,
        std::unordered_set<myVertex<V>*>& isVisited
    ) const;

private:
    std::unordered_map<std::reference_wrapper<V const>, myVertex<V>, _Hasher, _Eq> db;
};

#include "./implement/_myGraph_implement.hpp"