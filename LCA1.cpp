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

bool findPath(Node* root, int n, vector<int>&path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    bool isLeft=findPath(root->left, n, path);
    bool isRight=findPath(root->right, n, path);
    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;

}
int LCA1(Node* root, int n1, int n2){
    vector<int>path1;
    vector<int>path2;   
    findPath(root, n1, path1);
    findPath(root, n2, path2);
    int lca=-1;
    for(int i=0,j=0;i<path1.size()&& j<path2.size();i++,j++){
        if(path1[i]!=path2[j]){
            return lca;
        }
        lca=path1[i]; 
    }
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);
    int n1=5;
    int n2=4;
    cout << "common ansector is: " << LCA1(root,n1,n2);
    return 0;
}