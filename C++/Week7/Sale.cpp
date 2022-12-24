#include<iostream>
#include<string>
using namespace std;
class Salesperson;
class Sale{
    int month;
    int samt;
    int ID;
    public:
    
    friend void display(Sale, Salesperson);
    Sale(int month,int samt, int ID){
        if(month<1 || month>31){
            this->month=1;
        }
        else{
            this->month=month;
        }
        this->samt=samt;
        this->ID=ID;
    }
};
class Salesperson{
    int ID;
    string lname;
    public:
    friend void display(Sale, Salesperson);
    Salesperson(int ID, string lname){
        this->ID=ID;
        this->lname=lname;
    }
};
void display(Sale data, Salesperson data2){
    
    cout<<"On date: "<<data.month<<", Sales amounting $"<<data.samt<<" sold by " <<data2.lname<<"ID#"<<data2.ID;
}
int main(){
    int month,samt,ID;
    string lname;
    cout<<"Enter month date: ";
    cin>>month;
    cout<<"Enter sales amount: ";
    cin>>samt;
    cout<<"Enter ID no: ";
    cin>>ID;
    cout<<"Enter last name: ";
    cin>>lname;
    Sale sale(month, samt, ID);
    Salesperson salesperson(ID, lname);
    display(sale, salesperson);
    return 0;
}