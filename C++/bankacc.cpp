  #include <iostream>
#include <fstream>
 #include <iomanip>
using namespace std;
class Account
{
	protected:
		char name[30];
		long long int number;
		double initial_balance, final_balance, annual_int_rate, monthly_service_charges;
		int no_of_dep, no_of_wd, accnumber;
		char email[20];
	public:
		Account()
		{
		 	annual_int_rate = 12;
		}
		 
		void setAccount()
		{
			cout << "Enter account number: ";
			cin >> accnumber;
			cout << "Enter initial balance: ";
			cin >> initial_balance;
			cout << "Enter account name: ";
			fflush(stdin);
			gets(name);
			cout<<"Enter number: ";
			cin>>number;
			cout<<"Enter email: ";
			fflush(stdin);
			gets(email);
			final_balance = initial_balance;
		}
		
		virtual void makeDeposit(float amt)
		{
			final_balance += amt ;
			no_of_dep++;
		}
		
		virtual void makeWithdrawal(float amt)
		{
			final_balance -= amt;
			no_of_wd++;
		}
		
		void calcInt()
		{
			float monthlyinterest;
			float interest = (annual_int_rate/12);
			monthlyinterest=final_balance*interest;
			final_balance += monthlyinterest;
		}
		
		virtual void monthlyProc()
		{
			final_balance -= monthly_service_charges;
			calcInt();
			no_of_dep = 0;
			no_of_wd = 0;
			monthly_service_charges = 0;
		}
		
		float get_balance()
		{
			return final_balance;
		}
		int get_no_of_wd()
		{
			return no_of_wd;
		}
		int get_no_of_dep()
		{
			return no_of_dep;
		}
		void get_extra_service_charge(float charge)
		{
			monthly_service_charges += charge;
		}
		void cut_balance()
		{
			final_balance -= 15;
		}
		void extra_charge_for_wd()
		{
			final_balance -= 1;
		}
};

class saving_account : public Account
{
	protected:
		char stat;
	public:
		saving_account()
		{
			if (get_balance() >= 25)
			stat = 'A';
			else
			stat = 'I';
		}
		void status(float amount)
		{
			if(final_balance>=25)
			{
				stat = 'A' ;
			}
			else
			{
				stat = 'I';
			}
		}
		char get_status()
		{
			return stat;
		}
		
		void makeDeposit(float amount)
		{
			float total = get_balance() + amount;
			status(total);
			Account::makeDeposit(amount);
		}
		
		void makeWithdrawal(float amount)
		{
			if(stat == 'A')
			{
				Account::makeWithdrawal(amount);
			}
			else
			{	
				cout << "\nWithdraw Cancelled" << endl;
			}
		}
		
		void monthlyProc()
		{
			if(get_no_of_wd()>4)
			{
				monthly_service_charges = (no_of_wd-4)*1;
				Account::monthlyProc();
			}
			else
			{
				Account::monthlyProc();
			}
		}
		
		void withdrawn(float amount)
		{
			Account::makeWithdrawal(amount);
		}
		int getSavingsNumber()
		{
			return accnumber;
		}
		void showSvAccDetails()
		{
	
			
			cout<<setw(18)<<left<<name<<setw(18)<<left<<accnumber<<setw(18)<<left<<email;
			cout<<setw(18)<<left<<number<<setw(18)<<left<<initial_balance;
			cout<<setw(18)<<left<<final_balance<<setw(18)<<left<<no_of_dep<<setw(18)<<left<<no_of_wd<<setw(18)<<left<<monthly_service_charges<<endl;
		}
};
class checking_account : public Account{
	protected:
	public:
	void makeWithdrawal(float amount)
	{
		if (get_balance() - amount < 0)
		{
			cut_balance();
			cout << "Balance is insufficient"<<endl;
		}
		else
		{
			monthlyProc();
			Account::makeWithdrawal(amount);
			cout<<amount << " is withdrawn." <<endl;
		}
	}
	void monthlyProc()
	{
		if(no_of_wd>final_balance)
		{
			monthly_service_charges += 15;
			final_balance = final_balance - monthly_service_charges;
		}
		else
		{
			Account::monthlyProc();
		}
	}
	int getCheckingNumber()
	{
		return accnumber;
	}
	void showCkAccDetails()
	{ 
		cout<<setw(18)<<left<<name<<setw(18)<<left<<accnumber<<setw(18)<<left<<email;
		cout<<setw(18)<<left<<number<<setw(18)<<left<<initial_balance;
		cout<<setw(18)<<final_balance<<setw(18)<<left<<no_of_wd<<setw(18)<<left<<monthly_service_charges<<endl;
	}
};
class Manager
{
	private:
		saving_account sv;
		checking_account ck;
	public:
		void createNewSavingsFile();
		void createNewCheckingFile();
		void createSavingsAccount();
		void createCheckingAccount();
		void depositAmount();
		void withdrawSvAmount();
		void withdrawCkAmount();
		void calculateSvStatistics();
		void calculateCkStatistics();
		void showSvDetails();
		void showCkDetails();
};

void Manager::createNewSavingsFile()
{
	fstream file;
	string authentication;
	cout << "Are you sure you want to create file(yes or no): ";
	while(true)
	{
		cin >> authentication;
		if(authentication=="yes")
		{
			file.open("savings.txt", ios::out|ios::binary);
			if(file.fail())
			{
				cout << "\nFile creation failed!" << endl;
				exit(0);
			}
			else
			{
				cout << "\nFile created successfully!" << endl;
				break;
			}
		}
		else if(authentication=="no")
		{
			cout << "\nExiting...." << endl;
			exit(0);
		}
		else
		{
			cout << "\nWrong key! Try Again!: " << endl;
		}
	}
	file.close();
}
void Manager::createNewCheckingFile()
{
	fstream file;
	string authentication;
	cout << "Are you sure you want to create file(yes or no): ";
	while(true)
	{
		cin >> authentication;
		if(authentication=="yes")
		{
			file.open("checking.txt", ios::out|ios::binary);
			if(file.fail())
			{
				cout << "\nFile creation failed!" << endl;
				exit(0);
			}
			else
			{
				cout << "\nFile created successfully!" << endl;
				break;
			}
		}
		else if(authentication=="no")
		{
			cout << "\nExiting...." << endl;
			exit(0);
		}
		else
		{
			cout << "\nWrong key! Try Again!: " << endl;
		}
	}
	file.close();
}

void Manager::createSavingsAccount()
{
	fstream file;
	file.open("savings.txt", ios::ate|ios::in|ios::out|ios::binary);
	sv.setAccount();
	if(file.write((char *)&sv, sizeof(sv)))
	{
		cout << "\nAccount created successfully!" << endl;
	}
	else
	{
		cout << "\nCoud not create account!" << endl;
	}
	file.close();
}

void Manager::createCheckingAccount()
{
	fstream file;
	file.open("checking.txt", ios::ate|ios::in|ios::out|ios::binary);
	sv.setAccount();
	if(file.write((char *)&sv, sizeof(sv)))
	{
		cout << "\nAccount created successfully!" << endl;
	}
	else
	{
		cout << "\nCoud not create account!" << endl;
	}
	file.close();
}
void Manager::depositAmount()
{
	fstream file;
	file.open("savings.txt", ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	int account;
	cout << "Enter account number: ";
	cin >> account;
	while(file.read((char *)&sv, sizeof(sv)))
	{
		if(account==sv.getSavingsNumber())
		{
			cout << "\n***** ACCOUNT FOUND *****\n";
			
			int pos = file.tellg();
			file.seekp(pos-sizeof(sv));
			
			int d;
			cout << "Enter amount to deposit: ";
			cin >> d;
			sv.makeDeposit(d);
			if(file.write((char *)&sv, sizeof(sv)))
			{
				cout << "\nAMOUNT SUCCESSFULLY DEPOSITED!" << endl;
			}
			else
			{
			cout << "\nERROR! DEPOSIT UNSUCCESSFUL!" << endl;
			}
		}
		else
		{
			continue;
		}
	}
	file.close();
}

void Manager::withdrawSvAmount()
{
	fstream file;
	file.open("savings.txt", ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	int account;
		cout << "Enter account number: ";
		cin >> account;
	while(file.read((char *)&sv, sizeof(sv)))
	{
		if(account==sv.getSavingsNumber())
		{
			cout << "\n***** ACCOUNT FOUND *****\n";
			
			int pos = file.tellg();
			file.seekp(pos-sizeof(sv));
			int w;
				cout << "Enter amount to withdraw: ";
				cin >> w;
			sv.makeWithdrawal(w);
			if(file.write((char *)&sv, sizeof(sv)))
			{	
				cout << "\nWRITING SUCCESSFUL..." << endl;
			}
			else
			{
			cout << "\nERROR! WRITING UNSUCCESSFUL!" << endl;
			}
		}
		else
		{
			continue;
		}
		}
	file.close();
}

void Manager::withdrawCkAmount()
{
	fstream file;
	file.open("checking.txt", ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	int account;
		cout << "Enter account number: ";
		cin >> account;
	while(file.read((char *)&ck, sizeof(ck)))
	{
		if(account ==ck.getCheckingNumber())
		{
			cout << "\n***** ACCOUNT FOUND *****\n";
			int pos = file.tellg();
			file.seekp(pos-sizeof(ck));
			int w;
				cout << "Enter amount to withdraw: ";
				cin >> w;
			ck.makeWithdrawal(w);
			if(file.write((char *)&ck, sizeof(ck)))
			{
				cout << "\nWRITING SUCCESSFUL..." << endl;
			}
			else{
				cout << "\nERROR! WRITING UNSUCCESSFUL!" << endl;
			}
		}
		else
		{
			continue;
		}
	}
	file.close();
}

void Manager::calculateSvStatistics()
{
	string auth;
	fstream file;
	cout << "Do you want to proceed(y or n): ";
	cin >> auth;
	while(true)
	{
		if(auth=="y")
		{
		file.open("savings.txt", ios::ate|ios::in|ios::out|ios::binary);
		file.seekg(0);
		int account;
			cout << "Enter account number: ";
			cin >> account;
			while(file.read((char *)&sv, sizeof(sv)))
			{
				if(account==sv.getSavingsNumber())
				{
					int pos = file.tellg();
					file.seekp(pos-sizeof(sv));
					cout << "\nAccount Found" << endl;
					sv.monthlyProc();
					file.write((char *)&sv, sizeof(sv));
				}
				else
				{
					continue;
				}
			}
			file.close();
			}
		else if(auth=="n")
		{
			break;
		}
		else
		{
			cout << "Try again!: ";
		}
		break;
		}
}

void Manager::calculateCkStatistics()
{
	string auth;
	fstream file;
	cout << "Do you want to proceed(y or n): ";
	cin >> auth;
	while(true)
	{
		if(auth=="y")
		{
		file.open("checking.txt", ios::ate|ios::in|ios::out|ios::binary);
		file.seekg(0);
		int account;
			cout << "Enter account number: ";
			cin >> account;
			while(file.read((char *)&sv, sizeof(sv)))
			{
				if(account==ck.getCheckingNumber())
				{
				int pos = file.tellg();
				file.seekp(pos-sizeof(ck));
				cout << "\nAccount Found" << endl;
				ck.monthlyProc();
				file.write((char *)&ck, sizeof(ck));
				}
				else
				{
					continue;
				}
			}
			file.close();
		}
		else if(auth=="n")
		{
			break;
		}
		else
		{
			cout << "Try again!: ";
		}
	break;
	}
}
void Manager::showSvDetails()
{
	fstream file;
	file.open("savings.txt", ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	int account;
		cout << "Enter account number: ";
		cin >> account;
		cout<<setw(15)<<left<<"Name"<<setw(18)<<left<<"Account Number"<<setw(18)<<left<<"Email"<<setw(18)<<left<<"Number"<<setw(18)<<left<<"Initial Balance"<<setw(18)<<left<<"Final Balance";
		cout<<setw(18)<<left<<"No. of deposit"<<setw(18)<<left<<"No. of withdrawal"<<setw(18)<<left<<"Service charge"<<endl;
	while(file.read((char *)&sv, sizeof(sv)))
	{
		if(account==sv.getSavingsNumber())
		{
			sv.showSvAccDetails();
		}
		else
		{
			continue;
		}
	}
	file.close();
}

void Manager::showCkDetails()
{
	fstream file;
	file.open("checking.txt", ios::ate|ios::in|ios::out|ios::binary);
	file.seekg(0);
	int account;
		cout << "Enter account number: ";
		cin >> account;
		cout<<setw(15)<<left<<"Name"<<setw(18)<<left<<"Account Number"<<setw(18)<<left<<"Email"<<setw(18)<<left<<"Number"<<setw(18)<<left<<"Initial Balance"<<setw(18)<<left<<"Final Balance";
		cout<<setw(18)<<left<<"No. of withdrawal"<<setw(18)<<left<<"Service charge"<<endl;
	while(file.read((char *)&ck, sizeof(ck)))
	{
		if(account==ck.getCheckingNumber())
		{
			ck.showCkAccDetails();
		}
		else
		{
			continue;
		}
	}
	file.close();
}


int main()
{
	int ch;
	Manager am;
	cout << "\n1. Savings Account";
	cout << "\n2. Checking Account";
	cout << "\nPress any key to exit";
	cout << "\nEnter your choice: ";
	cin >> ch;
	if(ch==1)
	{
		int ch1;
		while(true)
		{
			system("cls");
			cout << "\n1. Create File";
			cout << "\n2. Create Savings Account";
			cout << "\n3. Show Account Details";
			cout << "\n4. Make Deposit";
			cout << "\n5. Make Withdrawal";
			cout << "\n6. Calculate Monthly Statistics";
			cout << "\n7. Exit";
			cout << "\nEnter your choice: ";
			cin >> ch1;
			
			switch(ch1)
			{
				case 1:
				am.createNewSavingsFile();
				system("pause");
				break;
				
				case 2:
				am.createSavingsAccount();
				system("pause");
				break;
				
				case 3:
				am.showSvDetails();
				system("pause");
				break;
				
				case 4:
				am.depositAmount();
				system("pause");
				break;
				
				case 5:
				am.withdrawSvAmount();
				system("pause");
				break;
				
				case 6:
				am.calculateSvStatistics();
				system("pause");
				break;
				
				case 7:
				exit(0);
			}
		}
	}
	else if(ch==2)
	{
		int ch1;
		while(true)
		{
			system("cls");
			cout << "\n1. Create File";
			cout << "\n2. Create Checking Account";
			cout << "\n3. Show Account Details";
			cout << "\n4. Make Withdrawal";
			cout << "\n5. Calculate Monthly Statistics";
			cout << "\n6. Exit";
			cout << "\nEnter your choice: ";
			cin >> ch1;
			
			switch(ch1)
			{
				case 1:
				am.createNewCheckingFile();
				system("pause");
				break;
				
				case 2:
				 am.createCheckingAccount();
				 system("pause");
				 break;
				 
				case 3:
				 am.showCkDetails();
				 system("pause");
				 break;
				 
				case 4:
				 am.withdrawCkAmount();
				 system("pause");
				 break;
				 
				case 5:
				 am.calculateCkStatistics();
				 system("pause");
				 break;
				 
				case 6:
				 exit(0);
			}
		}
	}
	else
	{
		exit(0);
	}
	return 0;
}

