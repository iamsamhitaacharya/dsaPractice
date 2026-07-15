#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int count; // number of words passing through this node

    Node() {
        endOfWord = false;
        count = 0;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(const string& key) {
        Node* temp = root;
        for (char c : key) {
            if (temp->children.count(c) == 0) {
                temp->children[c] = new Node();
            }
            temp = temp->children[c];
            temp->count++;
        }
        temp->endOfWord = true;
    }

    void shortestUniquePrefix(const vector<string>& words, vector<string>& ans) {
        for (const string& word : words) {
            Node* temp = root;
            string prefix = "";
            for (char c : word) {
                prefix += c;
                temp = temp->children[c];
                if (temp->count == 1) {
                    break; 
                }
            }
            ans.push_back(prefix);
        }
    }
};

int main() {
    Trie trie;
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    for (const string& w : words) {
        trie.insert(w);
    }
    vector<string> ans;
    trie.shortestUniquePrefix(words, ans);

    for (size_t i = 0; i < words.size(); i++) {
        cout << words[i] << " -> " << ans[i] << endl;
    }
    return 0;
}