#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a word in the trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Check if any word in the trie starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (!node->children.count(ch))
                return false;
            node = node->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("world");

    cout << boolalpha;
    cout << "Search 'hello': " << trie.search("hello") << endl;     // true
    cout << "Search 'hell': " << trie.search("hell") << endl;       // false
    cout << "Starts with 'hell': " << trie.startsWith("hell") << endl; // true

    return 0;
}
