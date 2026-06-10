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


int heightOfTree(Node* root){
    if(root==NULL) return 0;
    int leftHeight=heightOfTree(root->left)+1;
    int rightHeight=heightOfTree(root->right)+1;
    return max(leftHeight,rightHeight);
}

int diameter(Node* root){
    if(root==NULL) return 0;
    int currDiam=heightOfTree(root->left)+heightOfTree(root->right)+1;
    int leftDiam=diameter(root->left);
    int rightDiam=diameter(root->right);
    return max(currDiam,max(leftDiam,rightDiam));
}





int main(){
    vector<int>nodes={1,2,4,9,10,-1,-1,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    Node* root=buildTree(nodes);
    cout <<"root is " << root->data << endl;
    cout << " diameter of a tree is : " << diameter(root);
    return 0;
}