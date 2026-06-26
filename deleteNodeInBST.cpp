#include<iostream>
#include<vector>
using namespace std;

class Node{
public: 
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        left=right = NULL;
    }
};


Node* insert(Node* root, int val){ //logn
    if(root==NULL){
        root= new Node(val);
        return root;
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right,val);
    }

    return root;
}
Node* buildBST(int arr[], int n){ //nlogn

    Node* root= NULL;

    for(int i=0; i<n; i++){
        root=insert(root, arr[i]);
    }

    return root;
}

void inorder(Node* root){

    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* iS(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;

}

Node* delNode(Node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=delNode(root->left, val);
    }else if(val>root->data){
        root->right=delNode(root->right,val);
    }
    if(root->data == val){
        //case:1
        if(root->left == NULL && root->right == NULL ){
            delete root;
            return NULL;
        }
        //ase:2
        if(root->left==NULL || root->right == NULL){
            return root->left == NULL? root->right : root->left;
        }
        //case:3
        Node* inorderSuccessor = iS(root->right);
        root->data=inorderSuccessor->data;
        root->right=delNode(root->right, inorderSuccessor->data);
        return root;
    }
    return root;
}


int main(){

    int arr[6]= {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    inorder(root);
    cout << endl;
    delNode(root,2);
    inorder(root);
    
    return 0;
}