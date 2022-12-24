#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<string>
// #include<cstring>
using namespace std;
int menu();
class Account{
    int accno;
    char name[50];
    float deposit;
    char type[10];
    // int no_ofDeposits;
    // int no_ofWithdrawls;
    float interest=6.25%;
    // float service_charge;
    
    public:
    Account(float balance, float interest){
        this->balance=balance;
        this->interest=interest;
    }
    void makeAccount();
    void displayAccount();
    void modifyAccount();
    void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
    /* void show();
    virtual void makeDeposit();
    virtual void makeWithdrawal();
    virtual void calcInt();
    virtual void monthlyProc(); */
};
void Account::makeAccount(){
    cout<<"Enter Account no: ";
    cin>>accno;
    cout<<"Enter name ";
    fflush(stdin);
    gets(name);
    cout<<"Balance to deposit: ";
    cin>>deposit;
}
void Account::show(){
    // cout<<left;
    // cout<<"\n"<<setw(10)<<bookid<<setw(10)<<price<<setw(10)<<title;
    cout<<"Account no: "<<accno<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Balance: "<<deposit;
}
// void Account::addaccount(){
//     ofstream fout;
//     fout.open("account.txt",ios::out|ios::app|ios::binary);
//     if(!fout)
//         cout<<"file cant open";
//     else    
//         fout.write((char*)this,sizeof(*this));
//     fout.close();
// }
void Account::displayaccount(){
    ifstream fin;
    fin.open("account.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"File not found";
    else{
        // showheader();
        //while(())
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            show();
            fin.read((char*)this,sizeof(*this));
        }
    }
    fin.close();
}
void Account::makeDeposit(){
    int accno;
    cout<<"enter the account number you want to deposit to:";
    cin>>accno;
}
char menu(){
    char ch;
    cout<<"\n1. Create an account"<<endl;
    cout<<"2. Make Deposit"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Display Information"<<endl;
    // cout<<"\n5. Delete book";
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    return(ch);
}
int main(){
    Book b;
    int ch;
    while(1){
        ch=menu();
        switch(ch){
            case 1:
                b.getbook();
                b.addbook();
                break;
            case 2:
                b.viewbook();
                break;
            case 3:
                b.searchbook();
                break;
            case 4:
                b.modifybook();
                break;
            case 5:
                b.deletebook();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Enter valid choice";
        }
    }
    return 0;
}