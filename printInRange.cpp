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


void printInRange(Node* root, int st, int end){
    if(root==NULL) return;
    if(root->data <= end && root-> data >=st){
        cout << root->data << " ";
        printInRange(root->left, st, end);
        printInRange(root->right, st, end);
    }else if(root->data < st){
        printInRange(root->right, st, end);
    }else{
        printInRange(root->left, st, end);
    }
   
}
int main(){

    int arr[9]= {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr,9);
    cout << "Inorder Traversal of tree ";
     inorder(root);
    cout << endl;

    cout << "The node in the given range ";
     printInRange(root, 5, 12);
    
    return 0;
}