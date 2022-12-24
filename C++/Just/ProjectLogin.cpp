#include<iostream>
using namespace std;
int combiner;
int count;
class bank{
    int accNo;
    int balance;
    string name;
    string pass;
    public:
        bank(string name,int balance,string pass){
            count++;
            this->accNo=count;
            this->balance=balance;
            this->name=name;
            this->pass=pass;
        }
        bank(){}
        void data();
        void login();
        void deposit();
        void getInfo();
        void transfer();
        void seperateInfo();
        void totalCustomers();
        void setInfo();
}b[100]{
    bank("Sushant Neupane",200000,"Anything10"),
    bank("Yogesh Bhatta",300000,"Anything20"),
    bank("Utsab Sapkota",500000,"Anything30")
};
int main(){
    // // int combiner;
    bank objForLogin;
    // objForLogin.login();
    // objForLogin.deposit();
    // objForLogin.getInfo();
    // objForLogin.transfer();
    int n2;
    cin>>n2;
    for(int i=0;i<n2;i++){
         b[count].setInfo();
    }
    aboveSeperate:
    objForLogin.seperateInfo();
    cout<<"press 1 to check info again."<<endl;
    int n;
    cin>>n;
    if(n==1){
        goto aboveSeperate;
    }

    objForLogin.totalCustomers();
    return 0;
}
void bank :: login(){
    int loginAcno;
    string loginPass;
    bool credentials=0;
    aboveLogin:
    cout<<"Enter the account Number : ";
    cin>>loginAcno;
    fflush(stdin);
    cout<<"Enter the password :";
    getline(cin,loginPass);
    fflush(stdin);
    for(int i=0;i<count;i++){
        if((loginAcno==b[i].accNo) && (loginPass == b[i].pass)){
            cout<<"Welcome to the account "<<b[i].name<<endl;
            cout<<"Your remaining balance is :"<<b[i].balance<<endl;
            combiner=i;
            credentials=1;
        }
    }
    if(credentials==0){
        cout<<"Your credentials did not match please try again : "<<endl;
        goto aboveLogin;
    }

}

void bank :: deposit(){
    int depositAmount;
    cout<<"Enter the amount to deposit : ";
    cin>>depositAmount;
    b[combiner].balance+=depositAmount;
}
void bank :: getInfo(){
    cout<<"Account Number : "<<b[combiner].accNo<<endl;
    cout<<"Remaining balance : "<<b[combiner].balance<<endl;
}
void bank :: transfer(){
    cout<<"Enter the account number to transfer the money : ";
    int transferAccount;
    cin>>transferAccount;
    cout<<"Enter the amount to transfer :";
    int transferAmount;
    cin>>transferAmount;
    for(int i=0;i<count;i++){
        if((b[i].accNo==transferAccount)){
            b[i].balance+=transferAmount;
            b[combiner].balance-=transferAmount;
        }
    }
}

void bank :: seperateInfo(){
    cout<<"Enter your account Number : ";
    int seperateAcno;
    cin>>seperateAcno;
    fflush(stdin);
    cout<<"Enter the password : ";
    string seperatePass;
    getline(cin,seperatePass);
    fflush(stdin);
    for(int i=0;i<count;i++){
        if((seperateAcno==b[i].accNo)){//&&(seperatePass==b[i].pass)){
            cout<<"Welcome to the account "<<b[i].name<<endl;
            cout<<"Account Number : "<<b[i].accNo<<endl;
            cout<<"Your total balance is : "<<b[i].balance<<endl;
        }
    }

}
void bank :: totalCustomers(){
    cout<<"The total number of customers is : "<<count<<endl;
}

void bank :: setInfo(){
    count++;
    cout<<"Enter applicants Name : ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Enter applicants Password : ";
    fflush(stdin);
    getline(cin,pass);
    cout<<"Enter starting balance : ";
    fflush(stdin);
    cin>>balance;
    accNo=count;
    cout<<"Your account number is :"<<accNo;
    cout<<endl;
}