#include<iostream>
#include<vector>
using namespace std;

vector<int> activitySelected(vector<int>start, vector<int>end){
    vector<int>ans;
    ans.push_back(0);
    int prev=0;
    for(int i=1;i<start.size();i++){
        if(start[i]>=end[prev]){
            ans.push_back(i);
            prev=i;
        }        
    }
    return ans;
}

int maxNumOfActivity(vector<int>start, vector<int>end){
    int prev=0;
    int count=1;
    for(int i=1;i<start.size();i++){
        if(start[i]>=end[prev]){
            count++;
            prev=i;
        }
    }
    return count;
}

int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,8,9};
    vector<int>ans=activitySelected(start,end);
    int count= maxNumOfActivity(start,end);
    cout << "The maximum number of activity that can be done is " << count  << endl;
        cout << "Activity selected are: " ;
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}