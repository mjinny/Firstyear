//variable = (condition) ? expressionTrue : expressionFalse;
#include<iostream>
using namespace std;
int main(){
    int a,b,c,result;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<"Enter third number: ";
    cin>>c;
    result = (a>b && a>c) ? (a) : ((b>c) ? (b):(c)); 
    cout<<"Largest number is "<<result;
    return 0;
    }