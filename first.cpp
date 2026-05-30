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













