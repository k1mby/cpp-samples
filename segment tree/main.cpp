#include "segment.h"
#include <iostream>

int main() {

    std::vector<int> values = { 5, 2, 1, 8, 3, 4 };

    SegmentTree segtree(values);
    
    // Try a few queries
    assert(segtree.query(0, 5) == 23);
    assert(segtree.query(0, 0) == 5);
    assert(segtree.query(2, 4) == 12);

    // Update
    segtree.update(3, 20);
    assert(segtree.query(2, 4) == 24);

    // Index out of range
    try {
        segtree.update(-1, 4);
    } catch (const std::out_of_range& error) {
        std::cerr << error.what() << std::endl;
    }
    
    try {
        segtree.query(-1, 4);
    } catch (const std::out_of_range& error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}