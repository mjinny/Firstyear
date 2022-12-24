#include<iostream>
using namespace std;
class Retailitem{
    string description;
    int unitsOnHand;
    double price;

public:
    Retailitem(string d, int u, double p)
    {
        description = d;
        unitsOnHand = u;
        price = p;
        }
        void setdata(string d, int u, double p){
            description = d;
            unitsOnHand = u;
            price = p;
        }
		string getdescription(){
			return description;
		}
		int getunitsOnHand(){
			return unitsOnHand;
		}
		double getprice(){
			return price;
		}
};
void display(Retailitem item){
    cout << "Description : " << item.getdescription() << endl;
    cout << "Units On Hand : " << item.getunitsOnHand() << endl;
    cout << "Price : " << item.getprice() << endl;
}
int main(){
    Retailitem item1("Jacket", 12, 59.95);
    Retailitem item2("Designer Jeans", 40, 34.95);
    Retailitem item3("Shirt", 20, 24.95);
    cout << "Item #1" << endl;
    display(item1);
    cout << endl;
    cout << "Item #2" << endl;
    display(item2);
    cout << endl;
    cout << "Item #3" << endl;
    display(item3);
    return 0;
}