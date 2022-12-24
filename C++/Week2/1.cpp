#include<iostream>
using namespace std;
int main(){
    double celsius;
    cout<<"Enter temperature in celcuis: ";
    
    cin>>celsius; 
    
    double fahrenheit = (9.0 / 5) * celsius + 32; 
    cout<<"Temperature in Fahrenheit is "<<fahrenheit;
    return 0;
}