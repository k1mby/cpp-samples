#include "segment.h"

#include <iostream>
#include <string>

SegmentTree::SegmentTree(std::vector<int> values) {
    if (values.empty()) {
        std::cerr << "Empty input, cannot build tree.";
        return;
    }
    n = values.size();
    tree = std::vector<int>(2 * n, 0);
    buildTree(values);
}

void SegmentTree::buildTree(std::vector<int> values) {
    // Set leaves - they are last n nodes
    for (int i = 0; i < n; i++) {
        tree[i + n] = values[i];
    }
    // Calculate parents as sum of left and right
    for (int i = n - 1; i >= 0; i--) {
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
}

void SegmentTree::update(int i, int val) {
    if (i < 0 || i >= n) {
        throw std::out_of_range("Update index out of range.");
    }

    // Update leaf 
    i += n;
    tree[i] = val;
    
    // Work up the tree, updating parents
    while (i > 1) { 
        i /= 2; 
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    } 
}

// Range sum queries
int SegmentTree::merge(int i, int j) {
    return i + j;
}

int SegmentTree::query(int i, int j) {
    if (i < 0 || j >= n) {
        throw std::out_of_range("Query index out of range.");
    }

    int sum = 0;
        
    // Start at leaf nodes
    i += n;
    j += n;
        
    while (i <= j) {
        // Start of range is a right child, add it & don't include parent
        if (i % 2 != 0) {
            sum += tree[i];
            i++;
        }
            
        // End of range is a left child, add it & don't include parent
        if (j % 2 == 0) {
            sum += tree[j];
            j--;
        }
            
        i /= 2;
        j /= 2;
    }
        
    return sum;
}