#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int>q1,q2;
public:
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(){
        if(q1.empty()) return;
        else q1.pop();
    }
    void top(){
        if(q1.empty())return ;
        else {
            cout << q1.front() << " ";
        }
    }

};
int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    s.pop();
    s.top();
    return 0;
}