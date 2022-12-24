#include <iostream>
using namespace std;
// Date class declaration
class Date{
    int day;
    int month;
    int year;

public:
//**************************************
// Default constructor
//************************************** 
    Date(){  //Initialized day, month and year
        day = 1;
        month = 1;
        year = 2000;
    }
//*************************************** 
// Parameterized constructor
//***************************************
    Date(int d, int m, int y){ //Assigning values to day, month and year
        day = d;
        month = m;
        year = y;
    }
//***************************************** 
// display fun to display dates
//***************************************** 
    void display(){
        cout << "\nDate in day/month/year format: " << endl;
        cout << day << "/" << month << "/" << year << endl;
    }
};
//***************************************** 
// main function
//***************************************** 
int main(){
    int day, month, year;
    // User input for dates
    cout << "Enter day: ";
    cin >> day;
    if (day < 1 || day > 31){
        cout << "Invalid. Enter day again: ";
        cin >> day;
    }
    cout << "Enter month: ";
    cin >> month;
    if (month < 1 || month > 12){
        cout << "Invalid. Enter month again: ";
        cin >> month;
    }
    cout << "Enter year: ";
    cin >> year;
    if (year < 1){
        cout << "Invalid. Enter year again: ";
        cin >> year;
    }
    //instance of class Date
    Date date1; 
    Date date2(day, month, year);
    //calling display function
    date1.display(); 
    date2.display();
    return 0;
}