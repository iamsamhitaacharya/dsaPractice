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

Node* LCA(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data ==n2){
        return root;
    }
    Node* leftLCA=LCA(root->left,n1,n2);
    Node* rightLCA=LCA(root->right,n1,n2);
    if(leftLCA==NULL && rightLCA==NULL){
        return NULL;
    }
    else if (leftLCA==NULL && rightLCA!=NULL){
        return rightLCA;
    }
    else if(leftLCA!=NULL && rightLCA==NULL){
        return leftLCA;
    }else{
        return root;
    }

}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int n1=4;
    int n2=5;
    cout << "Lowest common ancestor is " << LCA(root,n1,n2)->data;
    return 0;
}