#include<iostream>
#include<list>
using namespace std;

template<class T>
class Stack{
    list<T>ll;
    public:
    bool isEmpty(){
        if(ll.size()==0){
            return true;
        }
        return false;
    }
    void push(T val){
        ll.push_front(val);
    }
    void pop(){
        if(isEmpty()){
            cout << " Stack is empty " << endl;
        }
        ll.pop_front();
    }
    void top(){
        if(isEmpty()){
            cout << " Stack is empty " << endl;
        }
        cout << ll.front() << endl;
    }
};

int main(){
    Stack<char>s;
    s.push('a');
    s.push('b');
    s.top();""
    s.pop();
    s.top();
    s.pop();
    s.pop();
    return 0;
}