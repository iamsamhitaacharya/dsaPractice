#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

int main(){
    // unordered_set<int>s;
    set<int>s;

    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(5);  //ignores
    
    cout << s.size() << endl;

    for(auto el : s){
        cout << el << endl;
    }

    s.erase(2);

    if(s.find(2) != s.end()){
        cout << "2 exists" <<endl;
    }else{
        cout <<"2 doesn't exist" << endl;
    }

    return 0;
}