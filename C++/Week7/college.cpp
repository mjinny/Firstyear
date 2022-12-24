#include <iostream>
#include <string>
using namespace std;
class CollegeDepartment{
public:
    string department;
    string chair;
    int classs;
    string *course;
    CollegeDepartment(){
        department = "art";
        chair = "Linda";
        classs = 0;
    }
    CollegeDepartment(string department, string chair, int classs){
        this->department = department;
        this->chair = chair;
        this->classs = classs;
    }
    friend ostream &operator<<(ostream &, CollegeDepartment &);
    friend istream &operator>>(istream &, CollegeDepartment &);
    bool operator<(CollegeDepartment &data){
        if (classs < data.classs)
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
ostream &operator<<(ostream &output, CollegeDepartment &data){
    output << "Department: " << data.department << endl;
    output << "Chair: " << data.chair << endl;
    output << "class: " << data.classs << endl;
    return output;
}
istream &operator>>(istream &input, CollegeDepartment &dataa){
    cout << "Enter department name: ";
    input >> dataa.department;
    cout << "Enter chair name: ";
    input >> dataa.chair;
    cout << "Enter no of classes: ";
    input >> dataa.classs;
    cout << endl;
    return input;
}
int main(){
    CollegeDepartment dep[4];
    for (int i = 0; i < 4; i++){
        cin >> dep[i];
    }
    cout << "The department details are: " << endl;
    for (int i = 0; i < 4; i++){
        cout << dep[i];
    }
    cout << "Assignning  dep1 to dep2" << endl;
    dep[0] = dep[1];
    cout << dep[1].department << " has been assigned to "
         << "dep1" << endl;
    cout << dep[0];
    return 0;
}