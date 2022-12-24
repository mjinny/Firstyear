#include<iostream>
using namespace std;
class car{
    int yearModel;
    string make;
    int speed;
    public:
    car(int a, string b){
        yearModel=a;
        make=b;
        speed=0;
    }
    void accelerate(){
        speed+=5;
    }
    void getbreak(){
        speed-=5;
    }
    int getyear(){
        return yearModel;
    }
    string getmake(){
        return make;
    }
    int getspeed(){
        return speed;
    }
    
};
int main(){
    car car(2000,"Honda");
    cout<<"The model of the car year is "<<car.getyear()<<" and make is "<<car.getmake()<<endl<<endl;
	cout << "When Accelerated: " << endl;
	for (int i = 0; i < 5; i++)
	{
        car.accelerate();
        cout << "The current speed is: "<<car.getspeed()<< endl;
	}
    cout<<endl;
	cout<<"Brake: "<<endl;
	for (int i = 0; i < 5; i++)
	{
        
		car.getbreak();
        cout << "The current speed is: "<< car.getspeed()<< endl;
	}
    return 0;
}