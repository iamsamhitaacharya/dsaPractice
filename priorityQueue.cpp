#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){

    //max heap
    priority_queue<int>pq;

    pq.push(5);
    pq.push(10);
    pq.push(3);

    while(!pq.empty()){
        cout << " top : " << pq.top() << endl;
        pq.pop();
    }

    cout << endl;
    //min heap
     priority_queue<int, vector<int>, greater<int>>pq1;

    pq1.push(5);
    pq1.push(10);
    pq1.push(3);

    while(!pq1.empty()){
        cout << " top : " << pq1.top() << endl;
        pq1.pop();
    }


    cout << endl;
    //for string
    priority_queue<string, vector<string>, greater<string>>pq2;

    pq2.push("Hi");
    pq2.push("Apple");
    pq2.push("c++");

    while(!pq2.empty()){
        cout << " top : " << pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}