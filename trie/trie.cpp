#include "trie.h"

Trie::~Trie () {
    deleteTrie(root);
}

void Trie::deleteTrie(Node* node) {
    if (!node)
        return;

    for (auto child : node->children) {
        deleteTrie(child);
    }

    delete node;
}

void Trie::insert(std::string word) {
    auto node = root;

    for (auto ch : word) {
        int i = ch - 'a';
        if (!node->children[i]) {
            node->children[i] = new Node();
        }
        node = node->children[i];
    }

    node->isLeaf = true;
}

bool Trie::search(std::string word) {
    auto node = root;

    for (auto ch : word) {
        int i = ch - 'a';
        if (!node->children[i]) {
            return false;
        }
        node = node->children[i];
    }

    return node->isLeaf;
}

bool Trie::isPrefix(std::string word) {
    auto node = root;

    for (auto ch : word) {
        int i = ch - 'a';
        if (!node->children[i]) {
            return false;
        }
        node = node->children[i];
    }

    return true;
}
