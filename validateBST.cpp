#include<iostream>
#include<vector>
#include<climits>
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


bool validateBST(Node* root,Node* max, Node* min){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }
    if(!validateBST(root->left ,root , min)){
        return validateBST(root->left,root ,min);
    }
    if(!validateBST(root->right,max,root )){
        return validateBST(root->right,max ,root );
    }
    return true;
}


int main(){

    int arr[6]= {3,2,5,1,4};

    Node* root = buildBST(arr,6);
    inorder(root);
    cout << endl;
    cout << validateBST(root,NULL,NULL);
    
    return 0;
}