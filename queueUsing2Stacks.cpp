#include<iostream>
#include<stack>
using namespace std;

class Queue{

    stack<int>s1;
    stack<int>s2;
public:
    void push(int val){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        if(s1.empty()) cout<<"queue is empty   ";
        else s1.pop();
    }
    void front(){
        if(s1.empty()) cout<<"queue is empty   ";
        cout << s1.top() << "  ";
    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.front();
    q.pop();
    q.front();
    q.pop();
    q.front();
    q.pop();
}