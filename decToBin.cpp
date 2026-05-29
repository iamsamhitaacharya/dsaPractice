
#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int decToBin(int dec){
    int ans = 0;
    int pow = 1;
    while(dec>0){
        
        int rem = dec % 2;
        ans = (rem * pow) + ans  ;
        pow = pow * 10;
        dec = dec / 2;
    }
    return ans;

}
int main(){
    cout << "Enter the decimal number";
    int n;
    cin >> n;
    cout << "Its binary is " << decToBin(n);
}
