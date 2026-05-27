//Linked List

#include<iostream>
using namespace std;
class Node{
 
public:
   int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
    ~Node(){
        // cout << endl << "~Node";
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};
class List{
    Node*  head;
    Node* tail;
public:
    List(){
        head=tail=NULL;

    }
    ~List(){
        // cout <<endl<< "~List";
        if(head!=NULL){
            delete head;
            head=NULL;
        }
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next = head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
     }
    void pop_front(){
        if(head==NULL){
            cout << "LL is empty";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        
     }
     void pop_back(){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
     }

     void printLL(){
        cout << endl;
        Node* ptr=head;
        while(ptr!=NULL){
            cout << ptr->data << "->";
            ptr=ptr->next;
        }
        cout<<"NULL";
     }
     void insertAfter(int val, int after){
        Node* newNode=new Node(val); // they all are created dynamically.
        // so must be explicitly deleted using destructor.
        Node* temp=head;
        while(temp->data!=after){
            temp=temp->next;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
        
     }
    void insertBefore(int val, int after){
        Node* newNode=new Node(val);
        Node* temp=head;
        while(temp->next->data!=after){
            temp=temp->next;
        }
        
        newNode->next=temp->next;
        temp->next=newNode;
        
     }
     int searchItr(int val){
        Node* temp=head;
        int idx=0;
        while(temp->next!=NULL){
            if(temp->data==val){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
     }
     int helper(int val, Node*temp,int idx){
       
        if(temp->data==val){
            
            return idx;
        }
         if(temp->next==NULL){
            return -1;
         }
        return helper(val,temp->next,idx+1);
     }
     int searchRec(int val){
         return helper(val, head,0);
     }
     void reverseLL(){
        Node* prev=NULL;
        Node* curr=head;
       
        while(curr!=NULL){
            Node* Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            
        }
        head=prev;
     }
     int getSize(){
        int n=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        return n;
     }

     void remove(int n){
     int size=getSize();
     Node* prev=head;
     for(int i=1;i<(size-n);i++){
        prev=prev->next;

     }
     prev->next=prev->next->next;
    }


    };




int main(){
    //basic structure of ll
    List ll{};
    //implementation of pushfront
   
    // ll.push_front(-1);
    //   ll.printLL();
    // ll.push_back(4);
    //   ll.printLL();
    
    // ll.insertAfter(-5,3);
    //   ll.printLL();
    // ll.insertBefore(100,0);
    //   ll.printLL();
    // Similarly we can insert at some position
    //same logic but use for loop as: 
    // for(int i=0;i<pos-1;i++){
    //same
    //}
    // ll.pop_front();
    // ll.printLL();
    // ll.pop_back();
    // ll.printLL();

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    
    ll.printLL();
    // cout << endl<< ll.searchItr(3);
    
    // cout << endl<< ll.searchRec(30);
    ll.reverseLL();
    ll.printLL();
    ll.remove(3);
    ll.printLL();
    
    return 0;
}