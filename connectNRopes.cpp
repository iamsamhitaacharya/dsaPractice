#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int connectNRopes(vector<int>&lengths){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<lengths.size();i++){
        pq.push(lengths[i]);
    }
    int ans=0;
    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int sum=min1+min2;
        pq.push(sum);
        ans+=sum;
    }
    return ans;
}

int main(){
    vector<int>lengths = {4, 3, 2, 6};
    cout << " min cost to connect these ropes is " << connectNRopes(lengths);
    return 0;
}