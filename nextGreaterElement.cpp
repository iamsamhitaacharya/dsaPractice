#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextGreaterElement(vector<int>&arr,vector<int>&ans){
    stack<int>s;
    ans[arr.size()-1]=-1;
    s.push(arr[arr.size()-1]);
    for(int i=arr.size()-2;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}

int main(){
    vector<int>arr={6,8,0,1,3};
    vector<int>ans(arr.size());
    nextGreaterElement(arr,ans);
}