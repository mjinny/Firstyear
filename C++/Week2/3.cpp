#include<iostream>
using namespace std;
int main(){
    struct Apartment{
        int nbedroom;
        int nbath;
        int rent;
    };
    Apartment s;
    cout<<"Enter no of bedrooms: ";
    cin>>s.nbedroom;
    cout<<"Enter no of baths: ";
    cin>>s.nbath;
    if(s.nbedroom ==1 && s.nbath ==1){
        s.rent = 650;
        cout<<"Rent is $"<<s.rent;
    }
    else if(s.nbedroom ==1 && s.nbath ==2)
        cout<<"Apartment not available"<<endl;
    else if(s.nbedroom ==2 && s.nbath ==1){
        s.rent = 829;
        cout<<"Rent is $"<<s.rent;
    }   
    else if(s.nbedroom ==2 && s.nbath ==2){
        s.rent = 925;
        cout<<"Rent is $"<<s.rent;
    }
    else if(s.nbedroom ==3 && s.nbath ==1)
        cout<<"Apartment not available"<<endl;
    else if(s.nbedroom ==3 && s.nbath ==2){
        s.rent = 1075;
        cout<<"Rent is $"<<s.rent;
    }
    else
        cout<<"Requested combination is not available"<<endl;
    return 0;
}