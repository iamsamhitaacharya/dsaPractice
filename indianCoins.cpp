// We are given an infinite supply of denominations [1,2,5,10,20,50,100,500,2000].
//  Find min no of coins tocmake change for a value V.

#include<iostream>
#include<vector>
using namespace std;

int indianCoins(vector<int>coins, int V){
    int ans=0;
    for(int i=coins.size()-1;i>=0 && V>0; i--){
        if(V>=coins[i]){
            ans+=V/coins[i];
            V%=coins[i];
        }
    }
    cout << "Minimum number of coins to make change is " << ans;
    return ans;
}

int main(){
    vector<int>coins={1,2,5,10,20,50,100,500,2000};
    int V=2000;
    indianCoins(coins,V);
    return 0;
}