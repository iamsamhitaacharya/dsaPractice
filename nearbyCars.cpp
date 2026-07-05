#include<iostream>
#include<queue>
using namespace std;


struct ComparePair{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second > p2.second;
    }
};
int main(){
    vector<pair<int, int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    
    int k =2;

    priority_queue<pair<int,int>, vector<pair<int, int>>, ComparePair>pq;
    for(int i=0; i<pos.size(); i++){
        pq.push(make_pair(i,pos[i].first*pos[i].first + pos[i].second* pos[i].second));
    }

    for(int i =0; i<k; i++){
        cout << "C" <<  pq.top().first << endl;
        pq.pop();
    }


    return 0;
}
