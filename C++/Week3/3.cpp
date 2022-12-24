#include <iostream>
#include <string.h>
using namespace std;
class Data{
	string name;
	string address;
	int age;
	long long int number;

public:
	string getname(){
		return name;
	}
	string getaddress(){
		return address;
	}
	int getage(){
		return age;
	}
	long long int getnumber(){
		return number;
	}
	void setdata(string name, string address, int age, long long int number){
		this->name = name;
		this->address = address;
		this->age = age;
		this->number = number;
	}
};
void display(Data data){
	cout << "Name : " << data.getname() << endl;
	cout << "Addres : " << data.getaddress() << endl;
	cout << "Age : " << data.getage() << endl;
	cout << "Phone Number : " << data.getnumber() << endl;
}
int main(){
	Data my;
	Data friends;
	Data family;
	my.setdata("Jenny", "Mondstadt", 18, 1234567890);
	friends.setdata("Kaeya", "Mondstadt", 20, 9087654321);
	family.setdata("Shanks", "Liyue", 40, 1023498765);
	cout << "My Information: " << endl;
	display(my);
	cout << endl;
	cout << "Friends Information: " << endl;
	display(friends);
	cout << endl;
	cout << "Family Information: " << endl;
	display(family);
	return 0;
}