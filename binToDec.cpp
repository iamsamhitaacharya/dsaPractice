#include<iostream>
using namespace std;

int binToDec(int bin){
    int ans =0;
    int pow = 1;
    while(bin>0){
        
        int rem = bin % 10;
        ans = ans + (rem * pow);
        pow = pow * 2;
        bin = bin / 10;
    }
    return ans;

}
int main(){
    cout << "Enter the binary number";
    int n;
    cin >> n;
    cout << "Its decimal is " << binToDec(n);
}
