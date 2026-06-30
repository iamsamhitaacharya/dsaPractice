#include<iostream>
#include<vector>
#include<climits>
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


class Info{

public:
    bool isBST;
    int min;
    int max;
    int size;
    Info(bool isBST, int min, int max,int size){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }

};

static int maxSize = 0;

Info* sizeOfLargestBST(Node* root){
    if(root==NULL){
        return new Info(true, INT_MAX, INT_MIN, 0);
    }

    Info* leftInfo = sizeOfLargestBST(root->left);
    Info* rightInfo = sizeOfLargestBST(root->right);

    int currMin = min(root->data,min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data,max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->size + rightInfo->size + 1;

    if(leftInfo->isBST && rightInfo->isBST 
        && root->data > leftInfo->max 
        && root->data < rightInfo->min){
        Info* currInfo = new Info(true,currMin, currMax, currSize);
        maxSize = max(maxSize, currSize);
        return currInfo;
    }
  
    return new Info(false,currMin, currMax, currSize);        
}


int main(){
    vector<int>nodes={50,30,5,-1,-1,20,-1,-1,60,45,-1,-1,70,65,-1,-1,80,-1,-1};
    Node* root=buildTree(nodes);
    cout <<"root is " << root->data;
    cout << endl;
    sizeOfLargestBST(root);
    cout << "Size of largest BST is " << maxSize;

    return 0;
}