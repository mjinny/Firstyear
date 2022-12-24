#include<iostream>
using namespace std;
// Car class declaration
class Car{
    public:
    static int count; //static
//**************************************
// constructor
//************************************** 
    Car(){
        count++;
        
        cout  << count <<" car is created "<< endl;
    }
//**************************************
// Destructor
//************************************** 
    ~Car(){
        count--;

        cout << "Count value: " << count << endl;
    }
};
int Car::count=0;//initializing static member count
//**************************************
// main function
//************************************** 
int main(){
    cout << "Constructor called" << endl;
    Car car[5]; //array of object
    cout << "\nDestructor called" << endl;
    return 0;
}
