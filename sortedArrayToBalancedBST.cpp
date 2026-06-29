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
        left = right = NULL;
    }
};

Node* balancedBST(vector<int>arr, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* currNode = new Node(arr[mid]);
    currNode->left = balancedBST(arr,st,mid-1);
    currNode->right = balancedBST(arr,mid+1,end);
    return currNode;
}

int main(){
    vector<int>arr={3,4,5,6,7,8,9};
    Node* root = balancedBST(arr, 0, arr.size()-1);
    cout <<  "the root of a balanced BST is: " << root->data;
    return 0;
}