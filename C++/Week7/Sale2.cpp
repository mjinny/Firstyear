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
    int saleID(){
        return ID;
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
    int saleID(){
        return ID;
    }
};
void display(Sale data, Salesperson data2){
    
    cout<<"On date: "<<data.month<<", Sales amounting $"<<data.samt<<" sold by " <<data2.lname<<"ID#"<<data2.ID;
}
/*bool validate(Sale & s, Salesperson & sp){
    for(int i=0;i<5;i++){
        if(s.saleID()==sp.salepersonID())
            return true;
        else
            return false;
    }
}*/
int main(){
    int month,samt,ID;
    cout<<"Enter month date: ";
    cin>>month;
    cout<<"Enter sales amount: ";
    cin>>samt;
    cout<<"Enter ID no: ";
    cin>>ID;
    Sale sale(month, samt, ID);
    Salesperson salesperson[5]={
        Salesperson(1,"kim"),
        Salesperson(2,"lim"),
        Salesperson(3,"dim"),
        Salesperson(4,"min"),
        Salesperson(5,"jim")
    };
    bool valid = false;
		for (int i=0; i<5; i++){
			if(sales.saleID() == salesperson[i].saleID())
			{
				valid = true;
				count++;
				break;
			}
		}
		if(!valid)
		{
			cout<< "Invalid ID" <<endl;
		}
		else
		{
			if(sales.saleID()==1)
				display(salesperson[0],sales);
			else if(sales.salesID()==2)
				display(salesperson[1],sales);
			else if(sales.salesID()==3)
				display(salesperson[2],sales);
			else if(sales.salesID()==4)
				display(salesperson[3],sales);
			else
				display(salesperson[5],sales);
		}
    return 0;
}