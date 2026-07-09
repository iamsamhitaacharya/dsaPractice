#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
    // unordered_map<string, int>m;
    map<string, int>m;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["China"] = 150;
    m["India"] = 150;


    for(pair<string, int> country : m){
        cout << country.first << "," << country.second << endl;
    }

    if(m.count("Nepal")){
        cout << "Nepal exists" << endl;
    }else{
        cout << "Nepal doesn't exist" << endl;
    }

    m.erase("Nepal");

    if(m.count("Nepal")){
        cout << "Nepal exists" << endl;
    }else{
        cout << "Nepal doesn't exist" << endl;
    }

    m["Nepal"] = 200;

    return 0;
}