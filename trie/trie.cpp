#include <iostream>
#include <vector>
#include "trie.hpp"

using namespace std;

void Trie::insert(string word) {
    TrieNode* curr = root;
    for (char c: word) {
        if (curr->children[c - 'a'] == nullptr) {
            curr->children[c - 'a'] = new TrieNode();
        }
        curr = curr->children[c - 'a'];
    }
    curr->isWord = true;
}

bool Trie::exists(string word) {
    TrieNode* curr = root;
    for (char c: word) {
        if (curr->children[c - 'a'] == nullptr) {
            return false;
        }
        curr = curr->children[c - 'a'];
    }
    return curr->isWord;
}

bool Trie::startsWith(string prefix) {
    TrieNode* curr = root;
    for (char c: prefix) {
        if (curr->children[c - 'a'] == nullptr) {
            return false;
        }
        curr = curr->children[c - 'a'];
    }
    return true;
}
