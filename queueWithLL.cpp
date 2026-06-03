#include<iostream>
using namespace std;

template<class T>
class Node{
public:
    T data;
    Node* next;
    Node(T val){
        this->data=val;
        this->next=NULL;
    }
};
template<class T>
class Queue{
    Node<T>*  head;
    Node<T>* tail;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
    }
  
    void push(T val){
        Node<T>* newNode=new Node<T>(val);
        
        if(tail==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void pop(){
        if(empty()){
            cout << " Queue is empty/n";
        }
        Node<T>* temp=head;
        head=temp->next;
        temp->next =NULL;
        delete temp;
    }
    T front(){
        if(empty()){
             cout << " Queue is empty/n";
        }
        return head->data;
    }
    bool empty(){
        return head==NULL;
    }
};

int main(){
    Queue<int> q;
    q.push(0);
    q.push(1);

    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<< q.front() << endl;
        q.pop();
    }

    return 0;
}