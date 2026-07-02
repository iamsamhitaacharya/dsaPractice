#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Heap{
    vector<int>vec; //CBT  max heap
public:

    void push(int val){
        //step1
        vec.push_back(val);
        
        //fix heap
        int x =vec.size()-1; //childI
        int parI = (x-1)/2;

        while(parI>=0 && vec[x] > vec[parI]){  //for min heap just change the operator  to "<"
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int x){
        if( x >= vec.size()) return ;
        int l = 2*x + 1;
        int r = 2*x + 2;
        int maxIdx = x;
        if( l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        if( r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = r;
        }
        swap(vec[x], vec[maxIdx]);
        if(maxIdx != x){
            heapify(maxIdx);
        }


    }

    void pop(){
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        heapify(0);
    }

    int top(){
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }

};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);
    heap.push(80);

    while(!heap.empty()){
        cout << " top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}