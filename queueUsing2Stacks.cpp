#include<iostream>
#include<stack>
using namespace std;

class Queue{

    stack<int>s1;
    stack<int>s2;
public:
    void push(int val){

    }
    void pop(){

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