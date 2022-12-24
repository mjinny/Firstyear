#include<iostream>
#include<string>
using namespace std;
class CollegeDepartment{
    public:
    string department;
    string chair;
    int classs;
    string *course;
        CollegeDepartment(){
            department="art";
            chair="Linda";
            classs=15;
        }
        CollegeDepartment(string department, string chair, int classs){
            this->department=department;
            this->chair=chair;
            this->classs=classs;
        }
        friend ostream& operator <<(ostream &, CollegeDepartment &);
        friend istream& operator >> (istream&, CollegeDepartment&);
        bool operator <(CollegeDepartment&data)
		{
            if(classs<data.classs)
                return true;
            return false;
        }
        CollegeDepartment &operator=(const CollegeDepartment &depart){
            department = depart.department;
            chair = depart.chair;
            classs = depart.classs;
            return *this;
        }
};
ostream& operator <<(ostream& output , CollegeDepartment &data)
{
	output <<"Department: " << data.department<<endl;
    output<<"Chair: "<<data.chair<<endl;
    output<<"class: "<<data.classs<<endl;
	return output;
}
istream& operator >> (istream&input, CollegeDepartment&dataa)
{
    cout<< "Enter department name: ";
    input >>dataa.department;
    cout<< "Enter chair name: ";
    input >>dataa.chair;
    cout<< "Enter no of classes: ";
    input >>dataa.classs;
    cout<<endl;
    return input;
}
int main(){
    CollegeDepartment dep1;
    cin >> dep1;
    cout << dep1;
    CollegeDepartment dep2;
    cin >> dep2;
    cout << dep2;
    if (dep1 < dep2){
        cout << "Department with fewest number of courses is " << dep1.department << endl;
        cout << "Department with most number of courses is " << dep2.department << endl;
    }
    else{
        cout << "Department with fewest number of courses is " << dep2.department << endl;
        cout << "Department with most number of courses is " << dep1.department << endl;
    }
    return 0;
}