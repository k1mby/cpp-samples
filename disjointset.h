#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <unordered_map>

class DisjointSet {
public:
    void makeSet(int x);
    int findParent(int x);
    void unionSets(int x, int y);

private:
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> rank;
};

#endif