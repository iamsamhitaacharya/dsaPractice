#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool duplicateParenthesis(string str){
    stack<char>s;
    for(char ch:str){
        if(ch!=')'){
            s.push(ch);
        }else{
            if(s.top()=='(') return true;
            else{
                while(s.top()!='(' && (!s.empty())){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;
}
int main(){
    string str1="(a+b)";
    string str2="((a+b)+((z)))";
    cout << duplicateParenthesis(str2);
    return 0;
}