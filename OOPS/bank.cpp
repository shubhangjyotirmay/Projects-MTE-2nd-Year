#include <windows.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>

using namespace std;

class account
{
   int accNo;
   char name[20];
   char type;
   public:
        int deposit;
	    void createAccount()
	    {
	       system("color 59");
	       cout<<"\n\t # NEW ACCOUNT ENTRY : ";
	       cout<<"\n\t\t # Enter holder's account no here : ";
		   cin>>accNo;
	       cout<<"\n\t\t # Enter holder's name here : ";
           cin>>name;
	       cout<<"\n\t\t # Enter account type here (c/s) : ";
		   cin>>type;
		   cout<<"\n\t\t # Enter amount to be deposited (>=500 for savings & >=1000 for current) :";
		   cin>>deposit;

	       cout<<"\n\t ACCOUNT RECORD CREATED. ";
	    }
	    void showAccount()
	    {
	       cout<<"\n\t # ACCOUNT'S DETAILS ARE : ";
	       cout<<"\n\t\t # Holder's account no. : ";
		   cout<<accNo;
	       cout<<"\n\t\t # Holder's name : ";
		   cout<<name;
	       cout<<"\n\t\t # Account type : ";
		   cout<<type;
		   cout<<"\n\t\t # Deposited amount :";
		   cout<<deposit;

	    }
	    void modifyAccount()
	    {
	       cout<<"\n\t # Holder's Account no. : ";
		   cout<<accNo;
	       cout<<"\n\t\t # Enter the modified name here : ";
		   cin>>name;
		   cout<<"\n\t\t # Enter the modified account type here (c/s) : ";
		   cin>>type;
		   cout<<"\n\t\t # Enter the modified amount here : ";
		   cin>>deposit;

	      cout<<"\n\t ACCOUNT RECORD MODIFIED. ";
	    }
	    int returnAccNo()
	    {
	       return accNo;
	    }
	    char returnAccType()
	    {
	        return type;
	    }
	    int returnDeposit()
	    {
	        return deposit;
	    }
	    void report()
	    {
	       cout<<"\n\t "<<accNo<<setw(15)<<name<<setw(15)<<type<<setw(15)<<deposit;
	    }
};
fstream bf1;
account a;
//*********************************************************************
//                       FUNCTION TO WRITE IN FILE
//*********************************************************************

void writeAccount()
{
   system("cls");
   char ch;
   bf1.open("account.dat",ios::out|ios::app);
   do
   {
      a.createAccount();
      bf1.write((char*)&a,sizeof a);
      cout<<"\n\n\t Do you want to add more record ? (y/n?) : ";
      cin>>ch;
   }while(ch=='y'||ch=='Y');
   bf1.close();
}
//************************************************************************
//                FUNCTION TO READ SPECIFIC RECORD FROM FILE
//************************************************************************

void displayAccountDetails()
{
   system("cls");
   int n;
   cout<<"\n\t # Please enter the account no. ";
   cin>>n;
   int flag=0;
   bf1.open("account.dat",ios::in);
   while(bf1.read((char*)&a,sizeof a))
   {
      if(a.returnAccNo()==n)
      {
	    a.showAccount();
	    flag=1;
      }
   }
   bf1.close();
   if(flag==0)
    cout<<"\n\t Account does not exist. ";
    getch();
};
//************************************************************************
//               FUNCTION TO MODIFY RECORD OF FILE
//************************************************************************

void modifyAccount()
{
   int n;
   int found=0;
   system("cls");
   cout<<"\n\t # MODIFY ACCOUNT RECORD ";
   cout<<"\n\t # Enter the holder's account no here : ";
    cin>>n;
   bf1.open("account.dat",ios::in|ios::out);
   while(bf1.read((char*)&a,sizeof a) && found==0)
   {
      if(a.returnAccNo()==n)
      {
	 a.showAccount();
	 cout<<"\n\n\t # Enter the new details of account here : ";
	 a.modifyAccount();
	 int pos=-1*sizeof(a);
	 bf1.seekp(pos,ios::cur);
	 bf1.write((char*)&a,sizeof a);
	 found=1;
      }
   }
   bf1.close();
   if(found==0)
    cout<<"\n\t Account does not exist. ";
    getch();
}
//************************************************************************
//           FUNCTION TO DELETE RECORD OF FILE
//************************************************************************

void deleteAccount()
{
   system("cls");
   int n;
   int flag=0;
   cout<<"\n\t # DELETE ACCOUNT RECORD ";
   cout<<"\n\t # Enter the account no. of the holder you want to delete :";
    cin>>n;
   bf1.open("account.dat",ios::out|ios::in);
   fstream f2;
   f2.open("temp.dat",ios::out);
   bf1.seekg(0,ios::beg);
   while(bf1.read((char*)&a,sizeof a))
   {
      if(a.returnAccNo()!=n)
      {
	    f2.write((char*)&a,sizeof a);
      }
      else
	 flag=1;
   }
   f2.close();
   bf1.close();
   remove("account.dat");
   rename("temp.dat","account.dat");
   if(flag==1)
     cout<<"\n\t Record deleted. ";
   else
     cout<<"\n\t Record not found. ";
   getch();
}
//***********************************************************************
//           FUNCTION TO DISPLAY ALL ACCOUNTS LIST
//***********************************************************************
void displayAllAccount()
{
   system("color 59");
   system("cls");
   bf1.open("account.dat",ios::in);
   if(!bf1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t  ACCOUNTS LIST ";
   cout<<"\n\t =======================================================================";
   cout<<"\n\t Account No"<<setw(15)<<"Name"<<setw(15)<<"Type"<<setw(15)<<"Amount";
   cout<<"\n\t =======================================================================";
   while(bf1.read((char*)&a,sizeof a))
   {
      a.report();
   }
   bf1.close();
   getch();
}

//***********************************************************************
//            FUNCTION TO WITHDRAW MONEY
//***********************************************************************
void withdrawAmount()
{
   system("color 59");
   char accType;
   int no,amount;
   int flag=0;
   system("cls");
   cout<<"\n\t # WITHDRAWAL :";
   cout<<"\n\t # Enter the holder's account no. : ";
    cin>>no;
   bf1.open("account.dat",ios::in|ios::out);
   while(bf1.read((char*)&a,sizeof a))
   {
      if(a.returnAccNo()==no)
      {
          flag==1;
          cout<<"\n\t # Enter the account type (c/s) : ";
          cin>>accType;
          if(a.returnAccType()==accType)
	      {
	        cout<<"\n\t Amount in your account is : ";
	        cout<<a.returnDeposit();
	        cout<<"\n\t # Enter the amount to withdraw : ";
	        cin>>amount;
	        if(amount<=a.returnDeposit())
	        {
	            a.deposit -= amount;
	            cout<<"\n\t Balance is : ";
	            cout<<a.returnDeposit();
	            cout<<"\n\t Amount withdrawn successfully. ";
	            int pos=-1*sizeof(a);
	            bf1.seekp(pos,ios::cur);
	            bf1.write((char*)&a,sizeof a);
	            break;

	        }
	        else
            {
                cout<<"\n\t Withdrawal exceeds the amount in the account. ";
            }
          }
          else
          {
              cout<<"\n\t Account type does not match with account no. ";
          }
      }
   }
   bf1.close();
}
//***********************************************************************
//            FUNCTION TO DEPOSIT MONEY
//***********************************************************************

void depositAmount()
{
   system("color 59");
   char accType;
   int no,amount;
   int flag=0;
   system("cls");
   cout<<"\n\t # DEPOSIT AMOUNT :";
   cout<<"\n\t # Enter the holder's account no. : ";
    cin>>no;
   bf1.open("account.dat",ios::in|ios::out);
   while(bf1.read((char*)&a,sizeof a))
   {
      if(a.returnAccNo()==no)
      {
          flag==1;
          cout<<"\n\t # Enter the account type (c/s) : ";
          cin>>accType;
          if(a.returnAccType()==accType)
	      {
	        cout<<"\n\t Amount in your account is : ";
	        cout<<a.returnDeposit();
	        cout<<"\n\t # Enter the amount to deposit : ";
	        cin>>amount;
	        a.deposit += amount;
	        cout<<"\n\t Balance is : ";
            cout<<a.returnDeposit();
            cout<<"\n\t Amount deposited successfully. ";
            int pos=-1*sizeof(a);
            bf1.seekp(pos,ios::cur);
            bf1.write((char*)&a,sizeof a);
            break;
          }
          else
          {
            cout<<"\n\t Account type does not match with account no. ";
          }
      }
   }

   bf1.close();
}
//***********************************************************************
//            ADMINISTRATOR MENU FUNCTION
//***********************************************************************
void admin_menu_bank()
{
   system("color 59");
   system("cls");
   int ch;
   cout<<"\n\t ADMINISTRATOR MENU \n";
   cout<<"\n\t 1.Create account record ";
   cout<<"\n\t 2.Display all accounts record ";
   cout<<"\n\t 3.Display specific account record ";
   cout<<"\n\t 4.Modify account record ";
   cout<<"\n\t 5.Delete account record ";
   cout<<"\n\t 6.Back to Main Menu ";
   cout<<"\n\n\t PLease enter your choice (1-6) : ";
   cin>>ch;
   switch(ch)
   {
      case 1: writeAccount();
	      break;
      case 2: displayAllAccount();
	      break;
      case 3: displayAccountDetails();
          break;
      case 4: modifyAccount();
	      break;
      case 5: deleteAccount();
	      break;
      case 6: return;
      default : cout<<"\n\t Wrong input.";

   }  admin_menu_bank();

}
//***********************************************************************
//            THE MAIN FUNCTION OF PROGRAM
//***********************************************************************
int menuBank()
{
   system("color 59");
   char ch,a;
   do
   {
      system("cls");
      cout<<"\n\t\t Main Menu \n";
      cout<<"\n\t 1. Withdraw Amount.";
      cout<<"\n\t 2. Deposit Amount.";
      cout<<"\n\t 3. Admin Menu";
      cout<<"\n\t 4. Exit";
      cout<<"\n\n\t PLEASE ENTER YOUR CHOICE (1-4) : ";
       cin>>ch;
      switch(ch)
      {
	 case '1': system("cls");
		       withdrawAmount();
		   break;
	 case '2': depositAmount();
		   break;
	 case '3': admin_menu_bank();
		   break;
	 case '4': exit(0);
		   break;
	 default : cout<<"\n\t Wrong choice ";
		   break;
      }
      cout<<"\n\t Do you want to continue (y/n?) : ";
      cin>>a;
   }while(a=='y'|| a=='Y');
   return 0;
}
