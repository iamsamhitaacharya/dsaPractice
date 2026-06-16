#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Job{
    public: 
    int idx;
    int deadline;
    int profit;
     Job(int idx, int deadline, int profit){
        this->idx=idx;
        this->deadline=deadline;
        this->profit=profit;

     }
};

int jobSequencing(vector<pair<int,int>>pairs){
    int n=pairs.size();
    vector<Job>jobs;
    for(int i=0; i<n; i++){
        jobs.emplace_back(i,pairs[i].first, pairs[i].second);
    }
    sort(jobs.begin(), jobs.end(),[](Job &a, Job &b){
        return a.profit>b.profit;
    }); //lambda function 
    cout << "selecting Job " << jobs[0].idx<< endl;
    int profit = jobs[0].profit;
    int safeDeadline =2;
    for(int i=1;i<n;i++){
        if(jobs[i].deadline>=safeDeadline){
            cout << "selecting Job " << jobs[i].idx << endl;
            profit+=jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit;

}
int main(){
    vector<pair<int,int>>pairs={make_pair(4,20), make_pair(1,10), make_pair(1,40), make_pair(1,40)};
    cout<< " the maximum profit is " << jobSequencing(pairs);
    
    return 0;
}