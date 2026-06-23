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

int kthAncestor(Node* root, int node, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int leftSubtree=kthAncestor(root->left, node, k);

    int rightSubtree=kthAncestor(root->right, node, k);
    
    if(leftSubtree==-1 && rightSubtree==-1){
        return -1;
    }
    int validVal =leftSubtree==-1?rightSubtree:leftSubtree;
    if(validVal+1==k){
        cout << k << "th ancestor of a node is " << root->data;
    }
    return validVal+1;
  

}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int k=2;
    int node =5;

     kthAncestor(root,node,k);
    return 0;
}