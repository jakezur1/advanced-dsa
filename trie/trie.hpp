#ifndef TRIE_H
#define TRIE_H

#include <vector>

struct TrieNode {
  std::vector<TrieNode *> children;

  bool isWord;

  TrieNode() : children(26, nullptr), isWord(false) {}
};

class Trie {
public:
  Trie() : root(new TrieNode()) {}

  void insert(std::string word);

  bool exists(std::string word);

  bool startsWith(std::string prefix);

private:
  TrieNode *root;
};

#endif
