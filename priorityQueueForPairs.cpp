#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

//max heap-but on the basis of second property
struct ComparePair{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string,int>, vector<pair<string, int>>, ComparePair> pq;  //name,rank // default-max heap but on the basis of first property
    pq.push(make_pair("aman", 1000));
    pq.push(make_pair("bhumika", 500));
    pq.push(make_pair("chitrakshi", 4000));

    while(!pq.empty()){
        cout << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}