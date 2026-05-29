//PRINT FACTORIAL

// #include <iostream>
// using namespace std;

// int printFactorial(int n){
//     int fact = 1;
//     if(n == 0 || n == 1){
//         return n;
//     }
//     return n*printFactorial(n-1);
// }

// int main(){
//     int a, b;
//     cout << "Enter a number ";
//     cin >> a;
    
//     int res = printFactorial(a);
//     cout << res;
// }


// BIN TO DEC

// #include <iostream>
// using namespace std;

// int binToDec(int bin){
//     int ans =0;
//     int pow = 1;
//     while(bin>0){
        
//         int rem = bin % 10;
//         ans = ans + (rem * pow);
//         pow = pow * 2;
//         bin = bin / 10;
//     }
//     return ans;

// }
// int main(){
//     cout << "Enter the binary number";
//     int n;
//     cin >> n;
//     cout << "Its decimal is " << binToDec(n);
// }


//DEC TO BIN

// #include <iostream>
// using namespace std;

// int decToBin(int dec){
//     int ans = 0;
//     int pow = 1;
//     while(dec>0){
        
//         int rem = dec % 2;
//         ans = (rem * pow) + ans  ;
//         pow = pow * 10;
//         dec = dec / 2;
//     }
//     return ans;

// }
// int main(){
//     cout << "Enter the decimal number";
//     int n;
//     cin >> n;
//     cout << "Its binary is " << decToBin(n);
// }


// POINTER
//Binary Search

// #include <iostream>
// using namespace std;

// int binSearch(int arr[], int n, int key){
//     int st = 0, end = n-1 ;
    
//     while (st<=end){
//         int mid = st + (end - st)/2 ;
//          if ( arr[mid] == key){
//             return mid ;
//         } else if(key > arr[mid]){
//             st = mid + 1 ;
//         } else {
//             end = mid - 1 ;
//         }
//     }
//     return -1 ;
// }

// int main(){
//     int arr[] = { 4, 6, 9, 12, 34, 45, 67, 77, 99 };
//     int n = sizeof(arr)/sizeof(int);
//     int key = 877 ;
//     cout << binSearch(arr,n,key);
//     return 0 ;
// }


//Print Subarrays

// #include <iostream>
// using namespace std ;

// int main(){
//     int arr[] = {1, 2, 3, 4, 5};
    
    
//         for(int st = 0 ; st < 5 ; st++){
//             for(int end = st ; end < 5 ; end ++){
//                 for(int i= st; i<=end; i ++){
//                     cout << arr[i];
//                 }
//                 cout << " ";
//             }
            
//         }
    
// }


// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int>arr={1,5,2,8};
//     sort(arr.begin(),arr.end());
//     for(auto i :arr){
//         cout << i << " ";
//     }
// }


//OOPS Assignment questions

//Q1. Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
//  Note- In Complex numbers, the real part of 1st gets subtracted from the real part of 2nd number. Same goes for the imaginary part.


// #include<iostream>
// using namespace std;

// class Complex{
//     public:
//     int real;
//     int img;
//     Complex(int r, int img){
//         this->real=r;
//         this->img=img;
//     }
//     void show(){
//         cout << real << "+" << img << "i\n";
//     }
//     Complex operator -(Complex &c2){
//         int resReal=this->real-c2.real;
//         int resImg=this->img-c2.img;
//         Complex c3(resReal,resImg);
//         return c3;
//     }
// };

// int main(){
//     Complex c1(2,6);
//     Complex c2(3,5);
//     Complex c3= c1-c2;
//     c3.show();
    
//     return 0;
// }


//RECURSION

//PRINT nTh fibonacci number

// #include<iostream>
// using namespace std;

// int fib(int n){
//     if(n==1){
//         return 0;
//     }if(n==2){
//         return 1;
//     }
//     return fib(n-1)+fib(n-2);
// }
// int main(){
//     int res=fib(7);
//     cout << res;
//     return 0;
// }

//calculate x to the power n.

// #include<iostream>
// using namespace std;
// int power(int x, int n){
//     if(n==0){
//         return 1;
//     }
//     if(n==1){
//         return x;
//     }
//     return x*power(x,n-1);
// }
// int main(){
//     cout << power(2,5);
//     return 0;
// }

//FIMD ALL OCCURENCES

// #include<iostream>
// using namespace std;
// int allOccur(int arr[], int n,int i,int key){
//     if(i==n) return -1;
//     if(arr[i]==key){
//         cout << i << " ";
//     }
//     allOccur(arr,n,i+1,key);
    

// }
// int main(){
//     int arr[9]={3,2,4,5,6,2,7,2,2};
    
//     allOccur(arr,9,0,2);
//     return 0;
// }



////////////REMAININGGGGGGGGGGGGGGGGGGGGGGGGG//////////////////
// We are given a string S, we need to find the count of all contiguous substrings starting and ending with the same character.[LeetcodePremiumQs]

// #include<iostream>
// #include<vector>
// using namespace std;

// int countSubstrs(string str, int i,int j, int n){
//     if(n==1){
//         return 1;
//     }
//     if(n<=0){
//         return 0;
//     }
//     int res=countSubstrs(str,i+1,j,n-1)+
//     countSubstrs(str,i,j-1,n-1)-
//     countSubstrs(str,i+1,j-1,n-2);
//     if(str[i]==str[j]){
//         res++;
//     }
//     return res;
// }
// int main(){
//     string str="abcab";
//     int n=str.size();
//     cout<<countSubstrs(str,0,n-1,n)<<endl;
//     return 0;
// }

//Towers of Haoni
// #include<iostream>
// #include<vector>
// #include<stack>

// using namespace std;

// void towersOfHaoni(char src,char dest,char helper,int n){
//     if(n==1){
//         cout << "move disk from " << src << " to " << dest <<"\n";
//         return;
//     }
//     towersOfHaoni(src,helper,dest,n-1);


//     cout << "move disk from " << src << " to " << dest << "\n";
//     towersOfHaoni(helper,dest,src,n-1);
 

// }

// int main(){
   
//     towersOfHaoni('A','C','B',5);
//     return 0;
// }



//----------NQueeenssss_----

// #include<iostream>
// #include<vector>
// using namespace std;

// int isSafe(vector<vector<char>>board,int r, int c){
//     int n=board.size();
//     //horizontally safe
//     for(int i=0;i<c;i++){
//         if(board[r][i]=='Q') return false;
//     }
//     //vertically safe
//     for(int i=0;i<r;i++){
//         if(board[i][c]=='Q') return false;
//     }
//     //left diagonally safe
//     for(int i=r,j=c;i>=0 && j>=0;i--,j--){
//         if(board[i][j]=='Q') return false;
//     }
//     //right diagonally safe
//     for(int i=r,j=c;i>=0 && j<n;i--,j++){
//         if(board[i][j]=='Q') return false;
//     }
//     return true;
// }


// void printSolution(vector<vector<char>>board,int row,int col){
//     cout << "-------------------------------------" << endl;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// void nQueens(vector<vector<char>>board,int row){
//     int n=board.size();
//     bool check=false;
//     if(row==n){
//         printSolution(board,n,n);
//          check=true;
//         return ;
//     }
//     if(!check){
// for(int j=0;j<n;j++){
//         if (isSafe(board,row,j)){
//             board[row][j]='Q';
//             nQueens(board,row+1);
//             board[row][j]='.';
//         }
       
       
//     }
//     }
//     }
    




// int main(){
//     vector<vector<char>>board;
//     int n;
//     cout << "Enter the value of n ";
//     cin >> n;
//     for(int i=0;i<n;i++){
//         vector<char>rowl;
//         for(int j=0;j<n;j++){
//             rowl.push_back('.');
//         }
//         board.push_back(rowl);
//     }
//    nQueens(board,0);

//     // printSolution(board,n,n);


//     return 0;
// }



//Sudoku Solver

// #include<iostream>
// #include<vector>
// using namespace std;

// bool isSafe(vector<vector<int>>&board, int row, int col , int key){
//     // horizontally safe
//     for(int i=0;i<9;i++){
//         if(board[row][i]==key) return false;
//     }
//     //vertically safe
//     for(int i=0;i<9;i++){
//         if(board[i][col]==key) return false;
//     }
//     //gridwise safe
//     int stRow=(row/3)*3;
//     int stCol=(col/3)*3;
//     for(int i=stRow;i<=stRow+2;i++){
//         for(int j=stCol;j<=stCol+2;j++){
//             if(board[i][j]==key) return false;
//         }
//     }
//     return true;
// }

// void printSudoku(vector<vector<int>>&board){
//     int n=9;
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// bool sudokuSolver(vector<vector<int>>&board,int r, int c){
//     if(r==9){
//         printSudoku(board);
//         return true;
//     }
//     int nextc=c+1;
//     int nextr=r;
//     if(c+1==9){
//         nextr=r+1;
//         nextc=0;
//     }


//     if(board[r][c]!=0){
//         return sudokuSolver(board,nextr,nextc);
//     }else{
//         for(int i=1;i<=9;i++){
//             if(isSafe(board,r,c,i)){
//                 board[r][c]=i;
//                 if(sudokuSolver(board,nextr,nextc)) return true;
//                 board[r][c]=0;
//             }
//         }
//     }
//     return false;


// }

// int main(){
// vector<vector<int>> board = {
//     {5,3,0,0,7,0,0,0,0},
//     {6,0,0,1,9,5,0,0,0},
//     {0,9,8,0,0,0,0,6,0},
//     {8,0,0,0,6,0,0,0,3},
//     {4,0,0,8,0,3,0,0,1},
//     {7,0,0,0,2,0,0,0,6},
//     {0,6,0,0,0,0,2,8,0},
//     {0,0,0,4,1,9,0,0,5},
//     {0,0,0,0,8,0,0,7,9}
// };

//     bool check= sudokuSolver(board,0,0);
    
// cout << check;
//     return 0;
// }


//Rat in a maze

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



// #include<iostream>
// #include<vector>
// using namespace std;
//     void ratInMaze(vector<vector<int>>&maze,int row,int col,string ans){
//         int n=maze.size();
//         int m=maze[0].size();
        
            
//             if(row==n-1 && col==m-1){
//              cout << ans << "  ";
//              return;
//             }
            
//             if(row<0 || col<0 || row>=n || col>=m){
//                 return;
//             }
//             if(maze[row][col]==0) return;
        
        
//             maze[row][col]=false;
        
//             //up
//             ratInMaze(maze,row-1,col,ans+"U");
//             //down
//             ratInMaze(maze,row+1,col,ans+"D");
//             //right
//             ratInMaze(maze,row,col+1,ans+"R");
//             //left
//             ratInMaze(maze,row,col-1,ans+"L");
//         maze[row][col]=true;
        


//     }
// int main(){


//     vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
              
//     string ans="";
//     int n=maze.size();
//     int m=maze[0].size();

//     ratInMaze(maze,0,0,ans);
//     return 0;
// }


