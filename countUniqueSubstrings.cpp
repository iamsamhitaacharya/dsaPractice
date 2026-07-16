#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*>children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }

};

class Trie{

public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

   
    int countNodes(Node* root){
         int ans =0;
        for(const auto &child:root->children){
            ans+= countNodes(child.second);
        }
        return ans + 1;
    }

};

int main(){
    Trie trie;
    string str = "ababa";
    for(int i=0; i<str.size(); i++){
        trie.insert(str.substr(i));
    }
    cout << trie.countNodes(trie.root);


    return 0;
}