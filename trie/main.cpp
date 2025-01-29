#include "trie.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  Trie trie;
  std::cout << "expected false, is: " << trie.exists("hello") << std::endl;

  trie.insert("hello");
  std::cout << "expected true, is: " << trie.exists("hello") << std::endl;
  std::cout << "expected true, is: " << trie.startsWith("he") << std::endl;
  std::cout << "expected false, is: " << trie.exists("he") << std::endl;

  trie.insert("world");
  std::cout << "expected true, is: " << trie.exists("world") << std::endl;
  std::cout << "expected false, is: " << trie.startsWith("wed") << std::endl;
  std::cout << "expected false, is: " << trie.exists("worldel") << std::endl;

  trie.insert("wordle");
  std::cout << "expected false, is: " << trie.exists("worldel") << std::endl;
  std::cout << "expected true, is: " << trie.startsWith("word") << std::endl;
  std::cout << "expected true, is: " << trie.exists("wordle") << std::endl;

  trie.insert("he");
  std::cout << "expected false, is: " << trie.exists("h") << std::endl;
  std::cout << "expected true, is: " << trie.startsWith("he") << std::endl;
  std::cout << "expected true, is: " << trie.exists("he") << std::endl;

  return 0;
}
