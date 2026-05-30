// Sudoku Solver

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>&board, int row, int col , int key){
    // horizontally safe
    for(int i=0;i<9;i++){
        if(board[row][i]==key) return false;
    }
    //vertically safe
    for(int i=0;i<9;i++){
        if(board[i][col]==key) return false;
    }
    //gridwise safe
    int stRow=(row/3)*3;
    int stCol=(col/3)*3;
    for(int i=stRow;i<=stRow+2;i++){
        for(int j=stCol;j<=stCol+2;j++){
            if(board[i][j]==key) return false;
        }
    }
    return true;
}

void printSudoku(vector<vector<int>>&board){
    int n=9;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool sudokuSolver(vector<vector<int>>&board,int r, int c){
    if(r==9){
        printSudoku(board);
        return true;
    }
    int nextc=c+1;
    int nextr=r;
    if(c+1==9){
        nextr=r+1;
        nextc=0;
    }


    if(board[r][c]!=0){
        return sudokuSolver(board,nextr,nextc);
    }else{
        for(int i=1;i<=9;i++){
            if(isSafe(board,r,c,i)){
                board[r][c]=i;
                if(sudokuSolver(board,nextr,nextc)) return true;
                board[r][c]=0;
            }
        }
    }
    return false;


}

int main(){
vector<vector<int>> board = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

    bool check= sudokuSolver(board,0,0);
    
cout << check;
    return 0;
}
