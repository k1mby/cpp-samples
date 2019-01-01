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

// Union by Rank
void DisjointSet::unionSets(int x, int y) {

    int xp = findParent(x);
    int yp = findParent(y);
    
    if (rank[xp] > rank[yp]) {
        parent[yp] = xp;
    } else if (rank[yp] > rank[xp]) {
        parent[xp] = yp;
    } else {
        parent[yp] = xp;
        rank[xp]++;
    }
}


/*
// Union by Size
void DisjointSet::unionSets(int x, int y) {
        
        int xp = find(x);
        int yp = find(y);
        
        if (xp == yp)
            return;
        
        if (setSize[xp] > setSize[yp]) {
            parent[yp] = xp;
            setSize[xp] += setSize[yp];
        } else {
            parent[xp] = yp;
            setSize[yp] += setSize[xp];
        }
    }
*/