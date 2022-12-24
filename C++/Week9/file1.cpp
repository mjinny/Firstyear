#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class Student{
    int rollno;
    float total;
public:
    void indata(){
        cout<<"Enter roll an total marks: ";
        cin>>rollno>>total;
    }
    void outdata(){
        cout<<rollno<<total;
    }
    int getroll(){
        return rollno;
    }
};
int main(){
    ofstream fout("xyz.dat", ios::binary | ios::app);
    Student stu;
    int n,i=0;
    cout<<"enter no of records: ";
    cin>>n;
    while(i<n){
        stu.indata();
        fout.write((char*)&stu, sizeof(stu));
        i++;
    }
    fout.close();
    ifstream fin("xyz.dat", ios::binary);
    ofstream fout1("def.dat", ios::binary);
    if(!fin){
        cout<<"error";
            exit(-1);
    }
    int roll;
    cout<<"enter roll to delete: ";
    cin>>roll;
    while(!fin.eof()){
        fin.read((char*)&stu,sizeof stu);
        if(stu.getroll() !=roll){
            fout1.write((char*)&stu, sizeof(stu));
        }
    }
    fin.close();
    fout1.close();
    remove("xyz.dat");
    rename("def.dat","xyz.dat");
    return 0;
}