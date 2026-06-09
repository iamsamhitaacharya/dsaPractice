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


int sumOfNodes(Node* root){
    if(root==NULL) return 0;
    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);
    return leftSum+rightSum+root->data;
}



int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodes);
    cout <<"root is " << root->data;
    cout<< endl << "sum of nodes is: " << sumOfNodes(root);
    return 0;
}