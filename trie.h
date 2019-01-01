#ifndef TRIE_H
#define TRIE_H

#include <string>

class Trie {
public:
    ~Trie ();
    
    void insert(std::string word);
    bool search(std::string word);
    bool isPrefix(std::string word);

private:
    struct Node {
        Node* children[26] = { nullptr };
        bool isLeaf = false;
    };

    Node* root = new Node();

    void deleteTrie(Node* node);
};

#endif 