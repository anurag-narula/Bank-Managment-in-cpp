#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<windows.h>
#include<mmsystem.h>
using namespace std;



class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	char retaname() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};

void account::create_account()
{
	system("CLS");
	cout<<"\t\t\tFIELD CAN'T BE LEFT BLANK!!!"<<endl;
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
   bool found=false;
	account ac;
    fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
        {
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==acno)
		{
		    cout<<"\n\n\t\t\tRecord already exist";
		    found=true;
		  }
	}
	File.close();
	if(found==true)
    {
        return;
    }

	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
    cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	if(type=='C' && type=='S')
    {
    cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\n\t\t\tAccount Created..";
    }
    else
    {
        cout<<"invalid input(input should be C or S";
        cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
    }
}

void account::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}


void account::modify()
{
    cout<<"\t\t\tFIELD CAN'T BE LEFT BLANK!!!"<<endl;
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<" "<<deposit<<endl;
}


int account::retacno() const
{
	return acno;
}
char account::retaname() const
{
    return name[50] ;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void accn_no(int);
void accn_nme(char);

int main()
{
	char ch;
	char inname[20];
	int num;
	char type;
	string userName;
    string userPassword;
    int loginAttempt = 0;
    while (loginAttempt < 5)
    {
    cout<<"\t\t\t======================\n";
	cout<<"\t\t\t\tLOGIN";
	cout<<"\n\t\t\t======================\n";
        cout << "Please enter your user name: ";
        cin >> userName;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (userName == "anuragnarula" && userPassword == "anuragnarula66")
        {
            cout << "Welcome Anurag!\n";

	do
	{
	system("CLS");
	cout<<"\n\n\t\t\t\t========================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t========================\n";

		cout<<"\t\t\t\t   ::MAIN MENU::\n";
		cout<<"\n\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t7. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t8. SEE ACOUNT INFORMATION BY ACCN NO";
		cout<<"\n\t\t\t9. SEE ACOUNT INFORMATION BY ACCN HOLDER NAME";
		cout<<"\n\t\t\t0. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-0): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
        case '8':
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : ";
			cin>>num;
			accn_no(num);
			break;
        case '9':
		 	system("CLS");
			cout<<"\n\t\t\tAccount Holder Name : ";
	        cin>>inname;
	        accn_nme(inname[20]);
			break;
		 case '0':
		 	system("CLS");
			cout<<"\n\n\t\t\tBrought To You By Anurag Narula";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
}
    while(ch!='0');
        }
    else
        {
            cout<<"\n\n\t\t\t################################\n";
            cout << "\t\t\tInvalid login attempt!!!\n \t\t\tPlease try again.";
            cout<<"\n\n\t\t\t################################\n";
            PlaySound(TEXT("C:\\Users\\ANURAG\\Downloads\\wrongattempt.wav"),NULL,SND_SYNC);
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
        cout<<"\n\n\t\t\t******************************\n";
        cout << "\t\t\tToo many login attempts!";
        cout<<"\n\n\t\t\t******************************\n";
            return 0;

    }

	return 0;
}


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}
void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void accn_no(int a)
{
bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		cout<<ac.retacno()<<endl;
		if(ac.retacno()==a)
		{
			ac.show_account();
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void accn_nme(char namee)
{
    bool found=false;
	account ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		cout<<ac.retaname()<<endl;
		cout<<namee<<endl;
		if(ac.retaname()==namee)
		{
			ac.show_account();
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..";
}


void display_all()
{
	system("CLS");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited:(less than 50000)"<<endl;
				cin>>amt;
				int bal=ac.retdeposit()+amt;
				if(amt>50000)
                {
                    cout<<"\t\t\tlimit exceeded!!!";
                    PlaySound(TEXT("C:\\Users\\HP\\Downloads\\wrongattempt.wav"),NULL,SND_SYNC);
                }
                else
                    ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
                    {
					cout<<"Insufficience balance";
                    PlaySound(TEXT("C:\\Users\\HP\\Downloads\\wrongattempt.wav"),NULL,SND_SYNC);
                    }
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

