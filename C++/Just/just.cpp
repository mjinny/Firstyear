#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//Account class declaration
class Account{
protected:
//data members of Account class
	int accno;
	char name[50];
	int no_ofdeposit;
	int no_ofwithdrawl;
	float first_deposit;
	float final_balance;
	float int_rate;
	float monthly_sc;

public:
//default constructor
	Account(){
		int_rate = 6.25;
	}
	//member function declaration
	void create_account();
	float get_balance();
	int get_withdrawls();
	int get_deposit();
	void get_sc(float);
	void cut_balance();
	void extra_charge_wd();
	//virtual function for depositing amount
	virtual void makeDeposit(float amt){
		final_balance += amt;
		no_ofdeposit++;//increases everytime a deposit is made
	}
	//virtual function for withdrawl
	virtual void makeWithdrawal(float amt){
		final_balance -= amt;
		no_ofwithdrawl++;//increases everytime a withdrawl is done
	}
	//virtual function that calculates interest
	virtual void calcInt(){
		float monthlyinterest;
		float interest = (int_rate / 12);
		monthlyinterest = final_balance * interest;
		final_balance += monthlyinterest;
	}

	virtual void monthlyProc(){
		final_balance -= monthly_sc;
		calcInt();
		no_ofdeposit = 0;
		no_ofwithdrawl = 0;
		monthly_sc = 0;
	}
};
//create_account function defined outside class for user input
void Account::create_account(){
	cout << "Enter account number: ";
	cin >> accno;
	cout << "Enter account name: ";
	fflush(stdin);
	gets(name);
	cout << "Enter balance: ";
	cin >> first_deposit;
	final_balance = first_deposit;
}
//get_balance function defined outside class that returns final_balance
float Account::get_balance(){
	return final_balance;
}
//get_withdrawl function defined outside class that returns no of withdrawls
int Account::get_withdrawls(){
	return no_ofwithdrawl;
}
//get_deposit function that returns no of deposits made
int Account::get_deposit(){
	return no_ofdeposit;
}
//get_sc function that sets monthly servuce charge
void Account::get_sc(float charge){
	monthly_sc += charge;
}
//cut-balance function that reduces final balance by 15
void Account::cut_balance(){
	final_balance -= 15;
}
//extra_charge_wd function that reduces final balance by 1
void Account::extra_charge_wd(){
	final_balance -= 1;
}

//saving class derived from Account base class
class saving : public Account{
protected:
	char status;//data field

public:
//default constructor
	saving(){
		if (get_balance() >= 25)
			status = 'A';
		else
			status = 'I';
	}
//member functions declared
	void stats(float);
	char get_status();
	void makeDeposit(float amount);
	void makeWithdrawal(float amount);
	void monthlyProc();
	void withdrawn(float amount);
	int getSavingsNumber();
	void showAccDetails();
};
//status function defined outside class that checks whether the account is active or inactive
void saving::stats(float amount){
	if (final_balance >= 25)
		status = 'A';
	else
		status = 'I';
}
//get_status function that returns status
char saving::get_status(){
	return status;
}

//makeDeposit function that deposits the amount entered 
void saving::makeDeposit(float amount){
	float total = get_balance() + amount;
	stats(total);
	Account::makeDeposit(amount);
}
//makeWithdrawl function that withdraws amount if the account is active
void saving::makeWithdrawal(float amount){
	if (status == 'A')
		Account::makeWithdrawal(amount);
	else
		cout << "\nAccount Inactive. Withdrawl can't be done" << endl;
}
//monthlyProc function that sets service charge acrding to amount of withdrawls
void saving::monthlyProc(){
	if (get_withdrawls() > 4){
		monthly_sc = no_ofwithdrawl - 4;
		Account::monthlyProc();
	}
	else{
		Account::monthlyProc();
	}
}

void saving::withdrawn(float amount){
	Account::makeWithdrawal(amount);
}
int saving::getSavingsNumber(){
	return accno;
}
//function to display account details
void saving::showAccDetails(){
	cout<<left;
	cout << setw(18) << name << setw(18) << accno << setw(18)  << first_deposit;
	cout << setw(18) << final_balance << setw(18) << no_ofdeposit << setw(18)  << no_ofwithdrawl << setw(18) << monthly_sc << endl;
}
//class declaration File
class File{
private:
	saving sv;//data field

public:
//member functions
	void createSavingsAccount();
	void depositAmount();
	void withdrawAmount();
	void calculateStatistics();
	void showDetails();
	void modifyaccount();
};
//member functions declared outside class
//function to create savings account
void File::createSavingsAccount(){
	fstream file;
	//opens the file
	file.open("savings.txt", ios::ate | ios::in | ios::out | ios::binary);
	sv.create_account();
	if (file.write((char *)&sv, sizeof(sv))){
		cout << "\nAccount created successfully!" << endl;
	}
	else{
		cout << "\nAccount not created" << endl;
	}
	//file close
	file.close();
}
//function to deposit amount into account
void File::depositAmount(){
	fstream file;
	//file open
	file.open("savings.txt", ios::ate | ios::in | ios::out | ios::binary);
	file.seekg(0);
	int account;
	cout << "Enter account number: ";
	cin >> account;
	while (file.read((char *)&sv, sizeof(sv))){
		if (account == sv.getSavingsNumber()){
			cout << "\nAccount found\n";

			int pos = file.tellg();
			file.seekp(pos - sizeof(sv));

			int d;
			cout << "Enter amount to deposit: ";
			cin >> d;
			sv.makeDeposit(d);
			if (file.write((char *)&sv, sizeof(sv))){
				cout << "\nAmount deposited" << endl;
			}
			else{
				cout << "\nDeposit unsuccessful" << endl;
			}
		}
		else{
			continue;
		}
	}
	//file close
	file.close();
}
//function for withdrawls
void File::withdrawAmount(){
	fstream file;
	file.open("savings.txt", ios::ate | ios::in | ios::out | ios::binary);
	file.seekg(0);
	int account;
	cout << "Enter account number: ";
	cin >> account;
	while (file.read((char *)&sv, sizeof(sv))){
		if (account == sv.getSavingsNumber()){
			cout << "\naccount found\n";

			int pos = file.tellg();
			file.seekp(pos - sizeof(sv));
			int w;
			cout << "Enter amount to withdraw: ";
			cin >> w;
			sv.makeWithdrawal(w);
			if (file.write((char *)&sv, sizeof(sv))){
				cout << "\nsuccessful" << endl;
			}
			else{
				cout << "\nunsuccessful" << endl;
			}
		}
		else
		{
			continue;		}
}
	file.close();
}
//function to modify account
void File::modifyaccount(){
	bool found=false;
	fstream file;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!file)
	{
		cout<<"File could not be open";
		return;
	}
	while(!file.eof() && found==false)
	{
		file.read((char *)&sv, sizeof(sv)));
		if(sv.accno==n)
		{
			sv.showAccDetails();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			file.seekp(pos,ios::cur);
		    file.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";

}
//function to calculate statistics
void File::calculateStatistics(){
	string auth;
	fstream file;
	cout << "Do you want to proceed(y or n): ";
	cin >> auth;
	while (true){
		if (auth == "y"){
			file.open("savings.txt", ios::ate | ios::in | ios::out | ios::binary);
			file.seekg(0);
			int account;
			cout << "Enter account number: ";
			cin >> account;
			while (file.read((char *)&sv, sizeof(sv))){
				if (account == sv.getSavingsNumber()){
					int pos = file.tellg();
					file.seekp(pos - sizeof(sv));
					cout << "\nAccount Found" << endl;
					sv.monthlyProc();
					file.write((char *)&sv, sizeof(sv));
				}
				else{
					continue;
				}
			}
			file.close();
		}
		else if (auth == "n"){
			break;
		}
		else{
			cout << "Try again!: ";
		}
		break;
	}
}
//function to show account details
void File::showDetails(){
	fstream file;
	file.open("savings.txt", ios::ate | ios::in | ios::out | ios::binary);
	file.seekg(0);
	int account;
	cout << "Enter account number: ";
	cin >> account;
	//displays the data in account
	cout << setw(15) << left << "Name" << setw(18) << left << "Account Number" << setw(18) << left << "Initial Balance" << setw(18) << left << "Final Balance";
	cout << setw(18) << left << "No. of deposit" << setw(18) << left << "No. of withdrawal" << setw(18) << left << "Service charge" << endl;
	while (file.read((char *)&sv, sizeof(sv))){
		if (account == sv.getSavingsNumber()){
			sv.showAccDetails();
		}
		else{
			continue;
		}
	}
	file.close();
}
//menu function
int menu(){
	int ch1;
	cout << "\n1. Create Account";
	cout << "\n2. Show Account Details";
	cout << "\n3. Make Deposit";
	cout << "\n4. Make Withdrawal";
	cout << "\n5. Modify Account";
	cout << "\n6. Calculate Monthly Statistics";
	cout << "\n7. Exit";
	cout << "\nEnter your choice: ";
	cin >> ch1;
	return (ch1);
}
//main function
int main(){
	//instance of File class
	File am;
	int ch1;
	while (1){
		ch1 = menu();

		switch (ch1){//switch case

		case 1:
			am.createSavingsAccount();//function calls
			break;

		case 2:
			am.showDetails();
			break;

		case 3:
			am.depositAmount();
			break;

		case 4:
			am.withdrawAmount();

			break;

		case 6:
			am.calculateStatistics();

			break;

		case 7:
			exit(0);
		default:
			cout << "Enter valid choice";
		}
	}

	return 0;
}
