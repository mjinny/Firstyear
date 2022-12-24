#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Account{
protected:
int accno;
    char name[50];
    float deposit;
    float balance;
    float interest=6.25%;
    // int no_ofDeposits;
    // int no_ofWithdrawls;
    // float service_charge;
public:
    Account(float balance, float interest){
        this->balance=balance;
        this->interest=interest;
    }
    void display();
    void makeAccount();	//function to get data from user
	// void show_account() const;	//function to show data on screen
	// void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int set_accno() const;	//function to return account number
	int set_deposit() const;	//function to return balance amount
	// char set_type() const;	//function to return type of account
	virtual void makeDeposit(int, float, float, int);
	virtual void makeWithdrawal(int, float, float, int);
	virtual void calcInt(float, float, float, float);
	virtual void monthlyProc(int, int, float, float);
    void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
// void display_all();		//function to display all account details
// void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();
};
class Savings:public Account{
    public:
        string status;
};
void Account::show(){
    cout<<"Account no: "<<accno<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Balance: "<<deposit<<endl;
}
void Account::makeAccount(){
    cout<<"Enter Account no: ";
    cin>>accno;
    cout<<"Enter name ";
    fflush(stdin);
    gets(name);
    cout<<"Balance to deposit: ";
    cin>>deposit;
}
// void Account::calcInt(float cal_int, float monthly_int, float month_int_rate, float cal_balance){
// 	month_int_rate = cal_int / 12;
// 	monthly_int = cal_balance * monthly_int;
// 	cal_balance = cal_balance + monthly_int;
// 	cout << "\nMONTHLY INTERST AMOUNT		: " << monthly_int;
// }
// void CheckingAccount::makeDeposit(int mddeposit, float cabalance, float updatedcabalance, int countdeposit){
// 	cout << "ENTER AMOUNT FOR DEPOSIT = ";
// 	cin >> mddeposit;
// 	cout << "\nCUSTOMER'S BEGINING BALANCE		: "<< "$" << cabalance;
// 	updatedcabalance = cabalance + mddeposit;
// 	cout << "\nCUSTOMER'S TOTAL AMOUNT OF DEPOSIT	: "<< "$" << mddeposit;
// 	cout << "\nCUSTOMER'S ENDING BALANCE		: "<< "$" << updatedcabalance;
// 	cout << "\nNO. OF TIMES DEPOSITED MONEY		: " << countdeposit;
// }  
void Account::dep(int x)
{
	deposit+=x;
}
	
void Account::draw(int x)
{
	deposit-=x;
}
	
void Account::report() const
{
	cout<<accno<<setw(10)<<" "<<name<<setw(10)<<" "<<deposit<<endl;
}
	
int Account::set_accno() const
{
	return accno;
}

int Account::set_deposit() const
{
	return deposit;
}
char menu(){
    char ch;
    cout<<"\n1. Create an account"<<endl;
    cout<<"2. Make Deposit"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Display Information"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    return(ch);
}
void write_account()
{
	Account account;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	account.makeAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	outFile.close();
}
void display_sp(int n)
{
	Account account;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Account)))
	{
		if(Account.set_accno()==n)
		{
			Account.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}
void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Account account;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.set_accno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
    File.close();


	if(found==false)
		cout<<"\n\n Record Not Found ";
}
int main(){
    // Account account;
    char ch;
    while('1'){
        ch=menu();
        switch (ch)
        {
        case '1':

            break;
        case '2':
        
            break;
        case '3':
        
            break;
        case '4':
        
            break;
        case '5':
            exit('0');
            break;
        
        default:
            cout<<"Invalid choice";
            break;
        }
    }
    return 0;
}