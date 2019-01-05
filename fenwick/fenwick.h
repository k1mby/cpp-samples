#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

class FenwickTree {
public:
    FenwickTree(std::vector<int> nums);
    void update(int i, int val);
    int sum(int i);

private:
    int n;
    std::vector<int> tree;
    
    void buildTree(std::vector<int> nums);
    int getNext(int i);
    int getParent(int i);
};

#endif