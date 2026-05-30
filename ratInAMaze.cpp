#include<iostream>
#include<vector>
using namespace std;

    void ratInMaze(vector<vector<int>>&maze,int row,int col,string ans){
        int n=maze.size();
        int m=maze[0].size();
            if(row==n-1 && col==m-1){
                cout << ans << "  ";
                return;
            }
            if(row<0 || col<0 || row>=n || col>=m){
                return;
            }
            if(maze[row][col]==0) return;
            maze[row][col]=false;
            //up
            ratInMaze(maze,row-1,col,ans+"U");
            //down
            ratInMaze(maze,row+1,col,ans+"D");
            //right
            ratInMaze(maze,row,col+1,ans+"R");
            //left
            ratInMaze(maze,row,col-1,ans+"L");
            maze[row][col]=true;
    }
    int main(){
        vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};      
        string ans="";
        int n=maze.size();
        int m=maze[0].size();
        ratInMaze(maze,0,0,ans);
        return 0;
    }

// #include<iostream>
// #include<vector>
// using namespace std;
//     void ratInMaze(vector<vector<int>>&maze,int row,int col,string ans,vector<vector<bool>>&visited){
//         int n=maze.size();
//         int m=maze[0].size();
        
            
//             if(row==n-1 && col==m-1){
//              cout << ans <<endl;
//              return;
//             }
            
//             if(row<0 || col<0 || row>=n || col>=m){
//                 return;
//             }
//             if(maze[row][col]==0) return;
        
//         if(!visited[row][col]){
//             visited[row][col]=true;
        
//             //up
//             ratInMaze(maze,row-1,col,ans+"U",visited);
//             //down
//             ratInMaze(maze,row+1,col,ans+"D",visited);
//             //right
//             ratInMaze(maze,row,col+1,ans+"R",visited);
//             //left
//             ratInMaze(maze,row,col-1,ans+"L",visited);
//         visited[row][col]=false;
//         }


//     }
// int main(){


//     vector<vector<int>>maze={{1,1,1,1,1,0},
//                             {1,1,1,0,1,1},
//                             {1,1,1,1,1,1},
                           
//                         };
//     string ans="";
//     int n=maze.size();
//     int m=maze[0].size();
//     vector<vector<bool>>visited(n,vector<bool>(m,false));
//     ratInMaze(maze,0,0,ans,visited);
//     return 0;
// }





