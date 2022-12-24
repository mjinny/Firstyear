#include <iostream>
#include <string>
using namespace std;
//Declaration of Date class
class Date{
    int day;
    int month;
    int year;

public:
//default constructor
    Date(){
        day = 18;
        month = 4;
        year = 2021;
    }
//parameterized constructor
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
//friend function to acces private member of the class
    friend Date operator-(Date, Date);
    string monthname(){//function to store array of month names
        string namemonth[] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return namemonth[month];
    }
//function to store the max day of a month
    int maxdate(){
        int maxday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
        {
            maxday[2] = 29;
        }
        return maxday[month];
    }
//first display function
    void display1(){
        int a;
        string s;
        a = year % 100;
        if (a < 10)
        {
            s = to_string(a);
            s = "0" + s;
        }
        else
            s = to_string(a);
        cout << month << "/" << day << "/" << s << endl;
    }
//second display function
    void display2(){
        cout << monthname() << " " << day << "," << year << endl;
    }
//third display function
    void display3(){
        cout << day << " " << monthname() << "," << year << endl;
    }
//fourth display function
    void display4(){
        int no = year * 365 +month*30 + day;
        cout << no << " days";
    }
    void operator++(){//prefix increment operator overloading
        day++;
        if (day > maxdate()){
            month++;
            day = 1;
        }
        if (month > 12){
            year++;
            day = 1;
            month = 1;
        }
    }
    void operator++(int){//postfix increment operator overloading
        day++;
        if (day > maxdate()){
            month++;
            day = 1;
        }
        if (month > 12){
            year++;
            day = 1;
            month = 1;
        }
    }
    void operator--(){//prefix decrement operator overloading
        day--;
        if (day < 1){
            month--;
            day = maxdate();
        }
        if (month < 1){
            year--;
            month = 12;
            day = maxdate();
        }
    }
    void operator--(int){//postfix decrement operator overloading
        day--;
        if (day < 1){
            month--;
            day = maxdate();
        }
        if (month < 1){
            year--;
            month = 12;
            day = maxdate();
        }
    }
//comparison operator overloading
    bool operator == (Date & d)
{
	if((day == d.day) &&(month == d.month) && (year == d.year))
	{
		return true;
	}
	else
	{
		return false;
	}
}
};
//subtraction operator overloading
Date operator-(Date date1, Date date2){
    return Date((date1.day - date2.day), (date1.month - date2.month), (date1.year - date2.year));
}
//main function
int main(){
    int day, month, year;//variables declared
//user input
    cout << "Enter year: ";
    cin >> year;
    if (year < 1){
        cout << "Invalid. Enter year again: ";
        cin >> year;
    }
    cout << "Enter month: ";
    cin >> month;
    if (month < 1 || month > 12){
        cout << "Invalid. Enter month again: ";
        cin >> month;
    }
    cout << "Enter day: ";
    cin >> day;
    if (day < 1 || day > 31){
        cout << "Invalid. Enter day again: ";
        cin >> day;
    }
    cout << "The dates in different format: " << endl;
    Date d1;//instance of Date class
//calling display functions
    d1.display1();
    d1.display2();
    d1.display3();
    cout << endl;
    Date d2(day, month, year);//instance of Date class
//calling display functions
    d2.display1();
    d2.display2();
    d2.display3();

    cout << "\nDecrement" << endl;
    d2--;//decrementing Date object
    d2.display2();
    cout << "\nIncrement" << endl;
    d2++;//Incrementing Date object
    d2.display2();
    Date d4;//instance of Date class
    d4 = d2-d1;//difference of two Date objects
    if(d1 == d2)
	{
		cout << "The dates are equal so the difference is 0"<< endl;
	}
    else{
        cout << "\nDifference: ";
        d4.display4();
    }
    return 0;
}