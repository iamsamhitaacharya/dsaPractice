// stack implementation using vector

#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<int>vec;
public:
    bool isEmpty(){
        if(vec.size()==0){
            return true;
        }
        return false;
    }
    void push(int val){
        vec.push_back(val); // O(1) time complexity
    }
    void pop(){
        if(vec.empty()){
            cout<<"Stack is empty"<<endl; 
            return;
        }
        vec.pop_back(); // O(1) time complexity
    }
    int top(){
        if(vec.empty()){
            cout<<"Stack is empty"<<endl;
            return -1; // or throw an exception
        }
        //return vec[vec.size()-1];
        return vec.back(); // O(1) time complexity
    }
    void print(){
        while(!isEmpty()){
            cout<<top()<<" ";
            pop();
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    // s.print();
    cout<<"Top element: "<<s.top()<<endl; // Output: 20 
    s.pop();
    cout<<"Top element after pop: "<<s.top()<<endl; // Output: 10
    s.pop();
    s.pop(); // Output: Stack is empty
    return 0;
}