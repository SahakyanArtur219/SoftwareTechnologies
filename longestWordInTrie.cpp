#include <iostream>
#include <unordered_map>
#include <string>
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

    // Helper DFS to find the longest word
    void dfs(TrieNode* node, string& current, string& longest) {
        if (node->isEndOfWord) {
            if (current.length() > longest.length()) {
                longest = current;
            }
        }

        for (auto& [ch, child] : node->children) {
            current.push_back(ch);
            dfs(child, current, longest);
            current.pop_back(); // backtrack
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Find the longest word in the trie
    string findLongestWord() {
        string current, longest;
        dfs(root, current, longest);
        return longest;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("applesauce");
    trie.insert("app");
    trie.insert("apply");

    cout << "Longest word in the Trie: " << trie.findLongestWord() << endl;

    return 0;
}
