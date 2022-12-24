#include <iostream>
#include <string>
using namespace std;
class Name{
private:
    string first; 
    string middle;
    string last; 
public:
    Name(string first, string middle, string last); 
    void displayFullName();
};
Name ::Name(string first, string middle, string last){
    this->first = first;
    this->middle = middle;
    this->last = last;
};
void Name ::displayFullName(){
    cout << first << " " << middle << " " << last << endl;
}
class CreditData{
private:
    double currentBalance;
    double maxBalance;     
public:
    CreditData(double, double = 0); 
    void displayCreditData();
};
CreditData ::CreditData(double currBal, double maxBal){
    currentBalance = currBal;
    if (maxBal < currBal)
        maxBalance = currBal;
    else
        maxBalance = maxBal;
}
void CreditData ::displayCreditData(){
    double creditLeft = maxBalance - currentBalance;
    cout << "Current balance : $" << maxBalance << "\nCredit left : $" << creditLeft << endl;
}
class Customer{
private:

    Name name;          
    CreditData credit;  
    string phoneNumber; 
public:
    Customer(string, string, string, double, double, string);
    void showCustomer();
};
Customer ::Customer(string firstName, string middleName, string lastName, double bal, double max, string phone)
    : name(firstName, middleName, lastName), credit(bal, max)
{
    phoneNumber = phone;
}
void Customer ::showCustomer(){
    cout << "Customer data : " << endl;
    name.displayFullName();
    cout << phoneNumber << endl;
    credit.displayCreditData();
}
int main(){
    int x;                            
    const int TIMES = 2;               
    string first, middle, last, phone; 
    double bal, lim;                   
    
    for (x = 0; x < TIMES; x++){
        cout << endl
             << "Please enter first name for customer #" << (x + 1) << " :";
        cin >> first;
        cout << "Please enter middle name : ";
        cin >> middle;
        cout << "Please enter the last name : ";
        cin >> last;
        cout << "Enter current balance :";
        cin >> bal;
        cout << "Enter credit limit : ";
        cin >> lim;
        cout << "Enter phone number : ";
        cin >> phone;
        Customer cust(first, middle, last, bal, lim, phone);
        cust.showCustomer();
    }
    return 0;
}