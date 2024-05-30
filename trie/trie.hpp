#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <iostream>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;

    TrieNode() : children(26, nullptr), isWord(false){ }
};


class Trie {
public:
    Trie() : root(new TrieNode()) { }

    void insert(string word);

    bool exists(string word);

    bool startsWith(string prefix);

private:
    TrieNode* root;
};

#endif