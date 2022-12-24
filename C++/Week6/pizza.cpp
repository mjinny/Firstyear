#include<iostream>
#include<string>
using namespace std;
//Declaration of Pizza class
class Pizza{
private:
    string topping;
    int diameter;
    double price;
    const static string STDTOP;
    const static int STDSIZE;
    const static double STDPRICE;

public:
    Pizza(const string = STDTOP, const int = STDSIZE, const double = STDPRICE);
    void setValues();
    void displayValues();
};
//assigning values to static members
const string Pizza::STDTOP = "cheese";
const int Pizza::STDSIZE = 12;
const double Pizza::STDPRICE = 8.99;
//parameterized constructor
Pizza::Pizza(const string top, const int size,const double price){//Assigning values to top, size and price
    topping = top;
    diameter = size;
    // this is a pointer to the current object of the class
    this->price = price;
}
//Function to display the values of pizza
void Pizza::displayValues(){
    cout << "a " << diameter << " inch " << topping << " pizza. Price $" << price << endl;
}
//Function to set values given by the user
void Pizza::setValues(){
    const double TOPPINGPREMIUM = 1.00;
    const double SIZEPREMIUM = 1.50;
    cout << "Enter Topping: ";
    cin >> topping;
    if (topping != STDTOP)
        price = STDPRICE + TOPPINGPREMIUM;
    cout << "Enter Size: ";
    cin >> diameter;
    if (diameter > STDSIZE)
        price += SIZEPREMIUM;
}
//main function
int main(){
    //instances of Pizza class
    
    Pizza aPizza;
    char standard;//standard variable declared
    cout << "The standard pizza is:";
    aPizza.displayValues();
    cout << "Let me take your order" << endl;
    cout << "Do you want the standard pizza -y or n?";
    cin >> standard;
    if (standard != 'y')
        aPizza.setValues();
    cout << "Your order is: ";
    aPizza.displayValues();
    return 0;
}
    /*Pizza stdPizza;
    Pizza special("pineapple");
    Pizza deluxeSpecial("saussage", 16);
    Pizza veryDeluxeSpecial("lobster", 20, 17.99);
    //displaying values by calling displayValue function
    cout<<"The standard pizza is: ";
    stdPizza.displayValues();
    cout<<"Today's special is: ";
    special.displayValues();
    cout<<"The deluxe special is ";
    deluxeSpecial.displayValues();
    cout<<"And the very deluxe special is ";
    veryDeluxeSpecial.displayValues();*/