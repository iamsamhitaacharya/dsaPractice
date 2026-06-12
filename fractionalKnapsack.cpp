#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,double>pair1, pair<int,double>pair2){
    return pair1.second>pair2.second; //descendin
}

double fractionalKnapsack(vector<int>val, vector<int> wt, int W){
    double ans;
    vector<double> ratio(val.size());
    for(int i=0; i<val.size(); i++){
        ratio[i]=(double)val[i]/wt[i];
    }
    vector<pair<int,double>>pairs(val.size());
    for(int i=0; i<ratio.size(); i++){
        pairs[i]=make_pair(i,ratio[i]);
    }
    sort(pairs.begin(), pairs.end(), compare);
    for(int i=0; i<pairs.size(); i++){
        if(wt[pairs[i].first]<=W){
            ans+=val[pairs[i].first];
            W-=wt[pairs[i].first];
        }else{
            ans+=pairs[i].second*W;
            W=0;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10,20,30};
    int W = 50;
    double ans= fractionalKnapsack(val,wt,W);
    cout <<"max value of a knapsack is : " << ans;
    return 0;
}