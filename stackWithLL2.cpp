#include<iostream>
using namespace std;

template<class T>

class Node{
public:
    T data;
    Node* next;
    
    Node(T val){
        data=val;
        next=NULL;
    }       
};
template<class T>
class Stack{
    Node<T>* head;
    public:
    Stack(){
        head=NULL;
    }
    void push(T val){
        Node<T>* n=new Node<T>(val);
        n->next=head;
        head=n;
    }
    void pop(){
        if(head==NULL){
            cout << " Stack is empty " << endl;
            return;
        }
        Node<T>* temp=head;
        head=head->next;
        delete temp;
    }
    void top(){
        if(head==NULL){
            cout << " Stack is empty " << endl;
            return;
        }
        cout << head->data << endl;
    }
};

int main(){
    Stack<char>s;
    s.push('A');
    s.push('B');
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.pop();
    return 0;
}