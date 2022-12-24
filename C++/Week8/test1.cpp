#include <iostream> 
using namespace std;
class A{
    public:
 	int a;
};
class B : public A{
    public:
 	B(){
         a = 100;
     }
};
class C{
    public:
 	int b = 200;
};
class D : public B, public C{
    public:
    void display(){
        cout << "Total : " << (a + b) << endl;
    }
};
int main(){
    D d;
    cout<<"Value of a :"<<d.a<<endl;
    cout<<"Value of b :"<<d.b<<endl;
    d.display();
    return 0;
} 

