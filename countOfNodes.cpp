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
int countOfANode(Node* root){
    if(root==NULL) return 0;
    int leftCount=countOfANode(root->left);
    int rightCount=countOfANode(root->right);
    return leftCount+rightCount+1;
}



int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout << "root is " << root->data << endl ;
    cout << "count of a nodes is : " << countOfANode(root);
    return 0;
}