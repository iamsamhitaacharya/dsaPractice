#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> stockSpan(vector<int>stock){
    stack<int>s;
    vector<int>ans(stock.size());
    s.push(0);
    ans[0]=1;

    for(int i=1;i<stock.size();i++){
        while(!s.empty() && (stock[s.top()] <= stock[i])){
            s.pop();
        }
        if(s.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-s.top();
 
        }
        s.push(i);
    }
    return ans;
}

int main() {
   vector<int>stock={100, 80, 60, 70, 60, 85, 100};
   vector<int>span=stockSpan(stock);
    for(int i=0;i<span.size();i++){
         cout<<span[i]<<" ";
   
    }
}