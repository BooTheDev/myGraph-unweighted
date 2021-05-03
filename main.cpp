#include <iostream>
#include <string>
#include "./include/myGraph.hpp"

int main()
{
    myGraph<std::string> g;
    // Seattle
    g.addEdge("Seattle", {
        "San Francisco",
        "Denver",
        "Chicago"
        });
    // San Francissco
    g.addEdge("San Francisco", {
        "Seattle",
        "Denver",
        "Los Angeles"
        });
    // Los Angeles
    g.addEdge("Los Angeles", {
        "San Francisco",
        "Denver",
        "Kansas City",
        "Dallas"
        });
    // Denver
    g.addEdge("Denver", {
        "Seattle",
        "San Francisco",
        "Los Angeles",
        "Kansas City",
        "Chicago"
        });
    // Kansas City
    g.addEdge("Kansas City", {
        "Los Angeles",
        "Denver",
        "Chicago",
        "Dallas",
        "New York",
        "Atlanta"
        });
    // Chicago
    g.addEdge("Chicago", {
        "Seattle",
        "Denver",
        "Kansas City",
        "Boston",
        "New York"
        });
    // Boston
    g.addEdge("Boston", {
        "Chicago",
        "New York",
        });
    // New York
    g.addEdge("New York", {
        "Kansas City",
        "Chicago",
        "Boston",
        "Atlanta"
        });
    // Atlanta
    g.addEdge("Atlanta", {
        "Kansas City",
        "New York",
        "Miami",
        "Dallas",
        "Houston"
        });
    // Miami
    g.addEdge("Miami", {
        "Atlanta",
        "Houston"
        });
    // Dallas
    g.addEdge("Dallas", {
        "Los Angeles",
        "Kansas City",
        "Atlanta",
        "Houston"
        });
    // Houston
    g.addEdge("Houston", {
        "Atlanta",
        "Miami",
        "Dallas"
        });

    auto t = g.bfs("Seattle");
    auto p = t.path("Miami");

    for (auto item : p) {
        std::cout << " -> " << item;
    }
    std::cout << std::endl;
}
