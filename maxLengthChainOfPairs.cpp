// A pair (c,d) can come after pair (a,b) if b<c.
// Find the longest chain which can be formed from a given set of pairs.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}

int maxLengthChainOfPairs(vector<pair<int,int>>&pairs){
    sort(pairs.begin(),pairs.end(),compare);
    int ans=1;
    int curr=pairs[0].second;
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first>curr){
            ans++;
            curr=pairs[i].second;
        }
    }
    cout <<" Maximum Chain length is " << ans;
    return ans;
}

int main(){
    vector<pair<int,int>>pairs(5);
    pairs[0]=make_pair(5,24);
    pairs[1]=make_pair(39,60);
    pairs[2]=make_pair(5,28);
    pairs[3]=make_pair(27,40);
    pairs[4]=make_pair(50,90);
    maxLengthChainOfPairs(pairs);
    return 0;
}