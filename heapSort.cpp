#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void heapify(int x, vector<int>&arr, int n){
    if( x >= n) return ;
    int l = 2*x + 1;
    int r = 2*x + 2;
    int maxIdx = x;
    if( l < n && arr[l] > arr[maxIdx]){
        maxIdx = l;
    }
    if( r < n && arr[r] > arr[maxIdx]){
        maxIdx = r;
    }
    swap(arr[x], arr[maxIdx]);
    if(maxIdx != x){
        heapify(maxIdx, arr,n);
    }
}
int main(){
    vector<int>arr ={1,5,3,2,4};
    int n= arr.size();

    //heapsort
    //step-1:build max heap
    for(int i=arr.size()/2; i>=0 ;i--){  //O(n*logn)
        heapify(i,arr,n);
    }
    //step-2:sort: 
    for(int i = n-1; i>=0;  i--){    //O(n*logn)
        swap(arr[0], arr[i]);
        heapify(0,arr,i);
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}