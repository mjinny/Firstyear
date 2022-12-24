#include <iostream>
using namespace std;
class Employee{
    string name;
    int ID;
    string department;
    string position;

public:
    Employee(string n, int i, string d, string p){
        name = n;
        ID = i;
        department = d;
        position = p;
    }
    Employee(string n, int i){
        name = n;
        ID = i;
        department = " ";
        position = " ";
    }
    Employee(){
        name = " ";
        ID = 0;
        department = " ";
        position = " ";
    }
    void setdata(string n, int i, string d, string p){
        name = n;
        ID = i;
        department = d;
        position = p;
    }
    string getname(){
        return name;
    }
    int getid(){
        return ID;
    }
    string getdepart(){
        return department;
    }
    string getposition(){
        return position;
    }
};

void display(Employee employee){
    cout << "Name: " << employee.getname() << endl;
    cout << "ID: " << employee.getid() << endl;
    cout << "Department: " << employee.getdepart() << endl;
    cout << "Position: " << employee.getposition() << endl;
}
int main(){
    cout << "Employee details: " << endl;
    Employee first("Susan Meyers", 47899, "Accounting", "Vice president");
    Employee second("Mark Jones", 39119, "IT", "Programmer");
    Employee third("Joy Rogers", 81774, "Manufacturing", "Engineer");
    cout <<endl;
    display(first);
    cout << endl;
    display(second);
    cout << endl;
    display(third);
    return 0;
}