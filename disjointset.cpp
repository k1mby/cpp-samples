#include "disjointset.h"


void DisjointSet::makeSet(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int DisjointSet::findParent(int x) {

    if (!parent.count(x)) {
        makeSet(x);
        return x;
    } 
    
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

void DisjointSet::unionSets(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);

    if (rank[xp] > rank[yp]) {
        parent[y] = x;
    } else if (rank[yp] > rank[xp]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        rank[x]++;
    }
}