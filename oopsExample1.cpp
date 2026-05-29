
// Q1. Create a class to store Complex numbers. Using operator overloading, create the logic to subtract one complex number from another.
//  Note- In Complex numbers, the real part of 1st gets subtracted from the real part of 2nd number. Same goes for the imaginary part.


#include<iostream>
using namespace std;

class Complex{
    public:
    int real;
    int img;
    Complex(int r, int img){
        this->real=r;
        this->img=img;
    }
    void show(){
        cout << real << "+" << img << "i\n";
    }
    Complex operator -(Complex &c2){
        int resReal=this->real-c2.real;
        int resImg=this->img-c2.img;
        Complex c3(resReal,resImg);
        return c3;
    }
};

int main(){
    Complex c1(2,6);
    Complex c2(3,5);
    Complex c3= c1-c2;
    c3.show();
    
    return 0;
}