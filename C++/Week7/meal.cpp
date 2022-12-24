#include<iostream>
#include<string>
using namespace std;
class Meal{
    string name;
    int calcount;
    public:
    friend ostream& operator <<(ostream &, Meal &);
    friend istream& operator >>(istream&, Meal &);
    Meal(){
        name="Pizza";
        calcount=300;
    }
    Meal(string name,int calcount){
        this->name=name;
        this->calcount=calcount;
    }
    Meal operator +(Meal m){
        Meal t;
			t.calcount=calcount+m.calcount;
            t.name="daily total";
			return t;
    }
    void display(){
        cout<<"Entree name: "<<name<<endl;
        cout<<"Calorie: "<<calcount<<endl;
    }
};
ostream& operator <<(ostream& output , Meal &data)
{
	output <<"Calorie Count: " << data.calcount<<endl;
	return output;
}
istream& operator >>(istream& input, Meal &data){
    cout<<"\nEntree name for lunch: ";
    input>>data.name;
    cout<<"Calorie count: ";
    input>>data.calcount;
    return input;
}
int main(){
    Meal breakfast("Breakfast",300);
    Meal lunch(" ", 0);
    Meal dinner("Dinner",300);
    Meal total;
    cin>>lunch;
    cout<<lunch;
    breakfast.display();
    lunch.display();
    dinner.display();
    total=breakfast+lunch+dinner;
    total.display();
    return 0;
}