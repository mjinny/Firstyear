#include<iostream>
using namespace std;
int main(){
    int days, year,month,day;
    cout<<"Enter number of days: ";
    cin>>days;
    year=days/365;
    month=(days%365)/30;
    day=(days%365)%30;
    cout<<"Year Month and Days: "<<year<<"-"<<month<<"-"<<day;
}