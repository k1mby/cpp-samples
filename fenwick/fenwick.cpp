#include "fenwick.h"

FenwickTree::FenwickTree(std::vector<int> nums) {
    n = nums.size();
    tree = std::vector<int>(n + 1, 0);
    buildTree(nums);
}

void FenwickTree::buildTree(std::vector<int> nums) {
    for (int i = 0; i < n; i++) {
        update(i, nums[i]);
    }
}

void FenwickTree::update(int i, int val) {
    i += 1;

    while (i <= n) {
        tree[i] += val;
        i = getNext(i);
    }
}

int FenwickTree::getNext(int i) {
    return i + (i & -i);
}

int FenwickTree::sum(int i) {
    i += 1;
    int sum = 0;

    while (i > 0) {
        sum += tree[i];
        i = getParent(i);
    }

    return sum;
}

int FenwickTree::getParent(int i) {
    return i - (i & -i);
}