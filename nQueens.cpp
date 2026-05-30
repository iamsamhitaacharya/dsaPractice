
#include<iostream>
#include<vector>
using namespace std;

int isSafe(vector<vector<char>>board,int r, int c){
    int n=board.size();
    //horizontally safe
    for(int i=0;i<c;i++){
        if(board[r][i]=='Q') return false;
    }
    //vertically safe
    for(int i=0;i<r;i++){
        if(board[i][c]=='Q') return false;
    }
    //left diagonally safe
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q') return false;
    }
    //right diagonally safe
    for(int i=r,j=c;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}


void printSolution(vector<vector<char>>board,int row,int col){
    cout << "-------------------------------------" << endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void nQueens(vector<vector<char>>board,int row){
    int n=board.size();
    bool check=false;
    if(row==n){
        printSolution(board,n,n);
         check=true;
        return ;
    }
    if(!check){
        for(int j=0;j<n;j++){
            if (isSafe(board,row,j)){
                board[row][j]='Q';
                nQueens(board,row+1);
                board[row][j]='.';
            }
        }
    }
}
    
int main(){
    vector<vector<char>>board;
    int n;
    cout << "Enter the value of n ";
    cin >> n;
    for(int i=0;i<n;i++){
        vector<char>rowl;
        for(int j=0;j<n;j++){
            rowl.push_back('.');
        }
        board.push_back(rowl);
    }
    nQueens(board,0);
    return 0;
}
