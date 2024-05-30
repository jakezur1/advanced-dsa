#include <iostream>
#include <vector>
#include "trie.hpp"


int main(int argc, char* argv[]) {
    Trie trie;
    cout << "expected false, is: " << trie.exists("hello") << endl;

    trie.insert("hello");
    cout << "expected true, is: " << trie.exists("hello") << endl;
    cout << "expected true, is: " << trie.startsWith("he") << endl;
    cout << "expected false, is: " << trie.exists("he") << endl;

    trie.insert("world");
    cout << "expected true, is: " << trie.exists("world") << endl;
    cout << "expected false, is: " << trie.startsWith("wed") << endl;
    cout << "expected false, is: " << trie.exists("worldel") << endl;

    trie.insert("wordle");
    cout << "expected false, is: " << trie.exists("worldel") << endl;
    cout << "expected true, is: " << trie.startsWith("word") << endl;
    cout << "expected true, is: " << trie.exists("wordle") << endl;

    trie.insert("he");
    cout << "expected false, is: " << trie.exists("h") << endl;
    cout << "expected true, is: " << trie.startsWith("he") << endl;
    cout << "expected true, is: " << trie.exists("he") << endl;
    
    return 0;
}
