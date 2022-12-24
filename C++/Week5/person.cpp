#include<iostream>
#include<string>
using namespace std;
// Person class declaration
class Person{
    string lname;
    string fname;
    string zipcode;
    public:
//**************************************
// Default constructor
//************************************** 
        Person(){//Initialized lname, fname and zipcode
            lname="N/A";
            fname="N/A";
            zipcode="X";
        }
//*************************************** 
// Parameterized constructor
//***************************************
        Person(string fn, string ln, string zc){//Assigned values to fname, lname and zipcode
            fname=fn;
            lname=ln;
            zipcode=zc;
        }
//***************************************** 
// display fun to display info
//***************************************** 
        void display(){
            cout<<"First name: " << fname <<endl;
            cout<<"Last name: " << lname <<endl;
            cout<<"Zipcode: " << zipcode <<endl<<endl;
        }  
};
//***************************************** 
// main function
//***************************************** 
int main(){
    //instances of class Person
    Person person1;
    Person person2("Zoro","Roronoa","123");
    //calling display function
    person1.display();
    person2.display();

    return 0;
}