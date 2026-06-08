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

void  preorderTraversal(Node* root){
    if(root==NULL) return ;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node* root){
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root){
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}



int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    cout <<"root is " << root->data << endl;
    cout << "preorder traversal of a tree is: " << endl;
    preorderTraversal(root);
    cout << endl <<  "inorder traversal of a tree is: " << endl;
    inorderTraversal(root);
    cout << endl << "postorder traversal of a tree is: " << endl;
    postorderTraversal(root);
    return 0;
}