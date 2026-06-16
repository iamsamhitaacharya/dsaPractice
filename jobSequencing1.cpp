#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}

int jobSequencing(vector<pair<int,int>>pairs){
   
    sort(pairs.begin(),pairs.end(), compare);
    int safeDeadline=pairs[0].first+1;
    int maxProfit=pairs[0].second;   
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first>=safeDeadline){
            maxProfit+=pairs[i].second;
            safeDeadline++;
        }
    }
    return maxProfit;
}
int main(){
    vector<pair<int,int>>pairs={make_pair(4,20), make_pair(1,10), make_pair(1,40), make_pair(1,40)};
    cout<< " the maximum profit is " << jobSequencing(pairs);
    
    return 0;
}