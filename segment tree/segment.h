#ifndef SEGEMENT_TREE_H
#define SEGEMENT_TREE_H

#include <vector>

/* Segment Tree */

class SegmentTree {
public:
    SegmentTree(std::vector<int> values);
    void update(int i, int val);
    int query(int i, int j);

private:
    int n;
    std::vector<int> tree;
    void buildTree(std::vector<int> values);
    int merge(int i, int j);
};

#endif 