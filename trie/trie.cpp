#include "trie.hpp"
#include <vector>

void Trie::insert(std::string word) {
  TrieNode *curr = root;

  for (char c : word) {
    if (curr->children[c - 'a'] == nullptr)
      curr->children[c - 'a'] = new TrieNode();

    curr = curr->children[c - 'a'];
  }

  curr->isWord = true;
}

bool Trie::exists(std::string word) {
  TrieNode *curr = root;

  for (char c : word) {
    if (curr->children[c - 'a'] == nullptr)
      return false;

    curr = curr->children[c - 'a'];
  }

  return curr->isWord;
}

bool Trie::startsWith(std::string prefix) {
  TrieNode *curr = root;

  for (char c : prefix) {
    if (curr->children[c - 'a'] == nullptr)
      return false;

    curr = curr->children[c - 'a'];
  }

  return true;
}
