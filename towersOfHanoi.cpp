//Towers of Haoni


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void towersOfHaoni(char src,char dest,char helper,int n){
    if(n==1){
        cout << "move disk from " << src << " to " << dest <<"\n";
        return;
    }
    towersOfHaoni(src,helper,dest,n-1);


    cout << "move disk from " << src << " to " << dest << "\n";
    towersOfHaoni(helper,dest,src,n-1);
 

}

int main(){
   
    towersOfHaoni('A','C','B',5);
    return 0;
}