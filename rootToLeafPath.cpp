#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
public:
    Node(int val){
        this->data=val;
        left=right=NULL;
    }
};

static int idx=-1;

Node* buildTree(vector<int>&nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node* currNode= new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}


void path(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left ==NULL && root->right == NULL){
        cout << "Path: ";
        for(auto it: ans){
            cout << it <<" ";
        }
        
    
        cout << endl;
        
    }
    
    path(root->left, ans);
    path(root-> right, ans);
    ans.pop_back();
}


int main(){
    vector<int>nodes={8,5,3,1,-1,-1,4,-1,-1,6,-1,-1,10,-1,11,-1,14,-1,-1};
    Node* root=buildTree(nodes);
    cout <<"root is " << root->data;
    cout << endl;
    vector<int>ans;
    path(root,ans);

    return 0;
}