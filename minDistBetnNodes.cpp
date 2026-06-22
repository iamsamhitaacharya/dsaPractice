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

int dist(Node* root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int left=dist(root->left,n);
    if(left!=-1){
        return left+1;
    }
    int right= dist(root->right,n);
    if(right!=-1){
        return right+1;
    }
    return -1;

}

int minDist(Node* root, int n1, int n2){
    Node* lca=LCA(root, n1, n2);
    int dist1 = dist(lca,n1);
    int dist2= dist(lca,n2);
    return dist1+dist2;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int n1=2;
    int n2=6;
    cout << "Minimum distance between nodes is " << minDist(root,n1,n2);
    return 0;
}