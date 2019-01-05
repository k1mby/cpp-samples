#include "fenwick.h"

int main() {

    std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };

    FenwickTree fenwick(nums);

    assert(fenwick.sum(0) == 1);
    assert(fenwick.sum(2) == 6);
    assert(fenwick.sum(6) == 28);

    nums[2] += 3; // 1,2,6,4,5,6,7
    fenwick.update(2, 3);

    assert(fenwick.sum(2) == 9);
    assert(fenwick.sum(6) == 31);

    return 0;
}