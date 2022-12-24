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
    cout<<"\nEntree name: ";
    input>>data.name;
    cout<<"Calorie count: ";
    input>>data.calcount;
    return input;
}
int main(){
    Meal data[21];
	for(int i=0; i<21; i++){
		cin>>data[i];
	}
	for(int i=0; i<21; i++){
		cout<<data[i];
	}
	Meal total;
	for(int i=0; i<21; i++){
		total=total+data[i];
	}
	cout<<total;
    return 0;
}