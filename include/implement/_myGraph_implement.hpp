#pragma once
#include "../myGraph.hpp"

template <typename V, typename _Hasher, typename _Eq>
myGraph<V, _Hasher, _Eq>::~myGraph() {
    db.clear();
}

template <typename V, typename _Hasher, typename _Eq>
void myGraph<V, _Hasher, _Eq>::addVertex(V const& v) {
    if (!db.contains(v)) {
        V const* tmp{ new V{v} };
        db.emplace(*tmp, tmp);
    }
}

template <typename V, typename _Hasher, typename _Eq>
void myGraph<V, _Hasher, _Eq>::addEdge(V const& v, V const& d) {
    this->addVertex(v);
    auto src = &(db.find(v)->second);
    this->addVertex(d);
    auto dest = &(db.find(d)->second);
    src->pNeighbors.insert(dest);
}

template <typename V, typename _Hasher, typename _Eq>
void myGraph<V, _Hasher, _Eq>::removeVertex(V const& v) {
    db.erase(v);
}

template <typename V, typename _Hasher, typename _Eq>
myTree<V, _Hasher, _Eq> myGraph<V, _Hasher, _Eq>::bfs(V const& v) const {
    auto op = db.find(v);
    if (op == db.end())
        throw std::invalid_argument{"can't find the vertex"};

    // Prepare for myTree
    auto root{ &op->second };
    auto current{ const_cast<myVertex<V>*>(root) };
    std::unordered_map<myVertex<V>*, myVertex<V>*> relative{ {current,nullptr} };
    std::unordered_set<myVertex<V>*> isVisited{ {current} };
    std::queue<myVertex<V>*> q{ {current} };

    while (!q.empty()) {
        current = q.front();
        q.pop();
        for (auto item : current->pNeighbors) {
            if (!isVisited.contains(item)) {
                q.push(item);
                isVisited.insert(item);
                relative.emplace(item, current);
            }
        }
    }
    return { root,relative,db };
}

template <typename V, typename _Hasher, typename _Eq>
myTree<V, _Hasher, _Eq> myGraph<V, _Hasher, _Eq>::dfs(V const& v) const {
    auto op = db.find(v);
    if (op == db.end())
        throw std::invalid_argument{ "can't find the vertex" };

    // Prepare for myTree
    auto root{ &op->second };
    auto current{ const_cast<myVertex<V>*>(root) };
    std::unordered_map<myVertex<V>*, myVertex<V>*> relative{ {current, nullptr} };
    std::unordered_set<myVertex<V>*> isVisited{ {current} };

    dfs(current, relative, isVisited);
    return { root,relative,db };
}

template <typename V, typename _Hasher, typename _Eq>
void myGraph<V, _Hasher, _Eq>::dfs(myVertex<V>* current, std::unordered_map<myVertex<V>*, myVertex<V>*>& relative, std::unordered_set<myVertex<V>*>& isVisited) const {
    for (auto item : current->pNeighbors) {
        if (!isVisited.contains(item)) {
            isVisited.insert(item);
            relative.emplace(item, current);
            dfs(item, relative, isVisited);
        }
    }
}
