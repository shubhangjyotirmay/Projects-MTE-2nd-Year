#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdio>
#include<iomanip>

using namespace std;

class item
{
   int itemNo;
   char itemName[50];
   float itemPrice;
   public:
	    void createItem()
	    {
	       cout<<"\n\t # NEW ITEM ENTRY ";
	       cout<<"\n\t # Enter the item name here : ";
		   cin>>itemName;
	       cout<<"\n\t # Enter the item number here : ";
           cin>>itemNo;
           cout<<"\n\t # Enter the item price here : ";
           cin>>itemPrice;

	       cout<<"\n\t ITEM ADDED SUCCESSFULLY. ";
	    }
	    void showItem()
	    {
	       cout<<"\n\t # ITEM DETAILS ARE :- ";
	       cout<<"\n\t # Item name : ";
		   puts(itemName);
	       cout<<"\n\t # Item number : ";
		   cout<<itemNo;
		   cout<<"\n\t # Item price : ";
		   cout<<itemPrice;

	    }
	    void modifyItem()
	    {
	       cout<<"\n\t # Item number is : ";
		   cout<<itemNo;
	       cout<<"\n\t # Modify the item name here : ";
		   cin>>itemName;
		   cout<<"\n\t # Modify the item price here : ";
		   cin>>itemPrice;

	    }
	    int returnItemNo()
	    {
	       return itemNo;
	    }
	    float returnItemPrice()
	    {
	       return itemPrice;
	    }
	    void report()
	    {
	       cout<<"\n\t\t"<<itemNo<<setw(15)<<itemName<<setw(20)<<itemPrice<<endl;
	    }
};

class customer
{
   int custNo;
   char custName[20];
   float amount;

   public:
	    void createCustomer()
	    {
	       cout<<"\n\t # NEW CUSTOMER ENTRY : ";
	       cout<<"\n\t # Enter customer's no here :- ";
		   cin>>custNo;
	       cout<<"\n\t # Enter customer's name here :- ";
           cin>>custName;

	       cout<<"\n\t CUSTOMER RECORD CREATED. ";
	    }
	    void showCustomer()
	    {
	       cout<<"\n\t # CUSTOMER'S DETAILS ARE : ";
	       cout<<"\n\t # Customer's no. :- ";
		   cout<<custNo;
	       cout<<"\n\t # Customer's name :- ";
           puts(custName);

	    }
	    void modifyCustomer()
	    {
           cout<<"\n\t # Customer's no. :- ";
		   cout<<custNo;
           cout<<"\n\t # Modify customer's name here :- ";
           cin>>custName;

	    }
	    int returnCustNo()
	    {
	       return custNo;
	    }
	    void report()
	    {
	       cout<<"\n\t\t"<<custNo<<setw(20)<<custName<<setw(25)<<endl;
	    }
};
fstream f1,f2;
item i;
customer c;
//*********************************************************************
//                       FUNCTION TO WRITE IN FILE
//*********************************************************************

void writeItem()
{
   char ch;
   f1.open("item.dat",ios::out|ios::app);
   do
   {  system("cls");
      i.createItem();
      f1.write((char*)&i,sizeof i);
      cout<<"\n\n\t Do you want to add more record ? (y/n?) : ";
      cin>>ch;
   }while(ch=='y'||ch=='Y');
   f1.close();
}
 void writeCustomer()
{
   char ch;
   f1.open("customer.dat",ios::out|ios::app);
   do
   {
      c.createCustomer();
      f1.write((char*)&c,sizeof c);
      cout<<"\n\n\t Do you want to add more record ? (y/n?) : ";
       cin>>ch;
   }while(ch=='y'||ch=='Y');
   f1.close();
}
//************************************************************************
//                FUNCTION TO READ SPECIFIC RECORD FROM FILE
//************************************************************************

void displayItemDetails()
{
   system("cls");
   int num;
   cout<<"\n\t # Please enter the item no. : ";
   cin>>num;
   int flag=0;
   f1.open("item.dat",ios::in);
   while(f1.read((char*)&i,sizeof i))
   {
      if((i.returnItemNo())==num)
      {
	 i.showItem();
	 flag=1;
      }
   }
   f1.close();
   if(flag==0)
    cout<<"\n\t Item does not exist. ";
    getch();
}
void displayCustDetails(int n)
{
   int flag=0;
   f1.open("customer.dat",ios::in);
   while(f1.read((char*)&c,sizeof c))
   {
      if((c.returnCustNo())==n)
      {
	 c.showCustomer();
	 flag=1;
      }
   }
   f1.close();
   if(flag==0)
    cout<<"\n\t Customer does not exist. ";
    getch();
};
//************************************************************************
//               FUNCTION TO MODIFY RECORD OF FILE
//************************************************************************

void modifyItem()
{
   int n;
   int found=0;
   system("cls");
   cout<<"\n\t # MODIFY ITEM RECORD ";
   cout<<"\n\t # Enter the item no. here : ";
    cin>>n;
   f1.open("item.dat",ios::in|ios::out);
   while(f1.read((char*)&i,sizeof i) && found==0)
   {
      if((i.returnItemNo())==n)
      {
	 i.showItem();
	 cout<<"\n\t # Enter the new item details here : ";
	 i.modifyItem();
	 int pos=-1*sizeof(i);
	 f1.seekp(pos,ios::cur);
	 f1.write((char*)&i,sizeof i);
	 cout<<"\n\t Record updated. ";
	 found=1;
      }
   }
   f1.close();
   if(found==0)
    cout<<"\n\t Item Record not found. ";
    getch();
}

void modifyCustomer()
{
   system("cls");
   int n;
   int found=0;
   cout<<"\n\t # MODIFY CUSTOMER RECORD ";
   cout<<"\n\t # Enter the customer no. here : ";
    cin>>n;
   f1.open("customer.dat",ios::in|ios::out);
   while(f1.read((char*)&c,sizeof c) && found==0)
   {
      if((c.returnCustNo())==n)
      {
	 c.showCustomer();
	 cout<<"\n\t # Enter the new details of customer here : ";
	 c.modifyCustomer();
	 int pos=-1*sizeof(c);
	 f1.seekp(pos,ios::cur);
	 f1.write((char*)&c,sizeof c);
	 cout<<"\n\t Record updated. ";
	 found=1;
      }
   }
   f1.close();
   if(found==0)
    cout<<"\n\t Customer does not exist. ";
    getch();
}
//************************************************************************
//           FUNCTION TO DELETE RECORD OF FILE
//************************************************************************

void deleteCustomer()
{
   system("cls");
   int n;
   int flag=0;
   cout<<"\n\t # DELETE CUSTOMER RECORD ";
   cout<<"\n\t # Enter the customer no. whose record you want to delete :";
    cin>>n;
   f1.open("customer.dat",ios::out|ios::in);
   fstream f2;
   f2.open("temp.dat",ios::out);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c,sizeof c))
   {
      if((c.returnCustNo())!=n)
      {
	 f2.write((char*)&c,sizeof c);
      }
      else
	 flag=1;
   }
   f2.close();
   f1.close();
   remove("customer.dat");
   rename("temp.dat","customer.dat");
   if(flag==1)
     cout<<"\n\t Record deleted. ";
   else
     cout<<"\n\t Record not found. ";
   getch();
}
void deleteItem()
{
   int n;
   system("cls");

   cout<<"\n\t # DELETE ITEM ";
   cout<<"\n\t # Enter the item no. of the item you want to delete :";
    cin>>n;
   f1.open("item.dat",ios::in|ios::out);
   fstream f2;
   f2.open("temp.dat",ios::out);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&i,sizeof i))
   {
      if((i.returnItemNo())!=n)
      {
	 f2.write((char*)&i,sizeof i);
      }
   }
   f2.close();
   f1.close();
   remove("item.dat");
   rename("temp.dat","item.dat");

   cout<<"\n\t Item deleted. ";
   getch();

}
//***********************************************************************
//           FUNCTION TO DISPLAY ALL CUSTOMER LIST
//***********************************************************************
void displayAllCustomer()
{
   system("cls");
   f1.open("customer.dat",ios::in);
   if(!f1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t\t\t\t CUSTOMER LIST ";
   cout<<"\n\t ==========================================================";
   cout<<"\n\t Customer No."<<setw(20)<<"Customer Name"<<setw(25);
   cout<<"\n\t ==========================================================";
   while(f1.read((char*)&c,sizeof c))
   {
      c.report();
   }
   f1.close();
   getch();
}
//***********************************************************************
//            FUNCTION TO DISPLAY ALL ITEMS
//***********************************************************************
void displayAllItem()
{
   system("cls");
   f1.open("item.dat",ios::in);
   if(!f1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t\t\t\t ITEM LIST ";
   cout<<"\n\t ==========================================================";
   cout<<"\n\t Item no."<<setw(15)<<"Item Name"<<setw(20)<<"Item Price";
   cout<<"\n\t ==========================================================";
   while(f1.read((char*)&i,sizeof i))
   {
      i.report();
   }
   f1.close();
   getch();
};
//***********************************************************************
//            FUNCTION TO PLACE ORDER
//***********************************************************************

void placeOrder()
{
   system("cls");
   int ch,no,amount;
   char a;
   amount=0;
   displayAllItem();
   cout<<"\n\t Enter the customer no. here :- ";
   cin>>no;
   int flag1=0;
   f1.open("customer.dat",ios::in);
   while(f1.read((char*)&c,sizeof c))
   {
      if((c.returnCustNo())==no)
      {
	    c.showCustomer();
	    flag1=1;
      }
   }
   f1.close();
   if(flag1==0)
    cout<<"\n\t Customer does not exist. ";
   else {
   cout<<"\n\t # ORDER INVOICE :";
   do
   {
      cout<<"\n\t # Enter your choice(item no.) here :- ";
      cin>>ch;
      int flag=0;
      f1.open("item.dat",ios::in);
      while(f1.read((char*)&i,sizeof i))
      {
         if((i.returnItemNo())==ch)
         {
             amount+=i.returnItemPrice();
             flag=1;
         }
      }
      f1.close();
      if(flag==0)
       cout<<"\n\t Item does not exist. ";
      cout<<"\n\t Do you want to add more ? ";
      cin>>a;
   }while(a=='y'|| a=='Y');
   cout<<"\n\t Total Bill :- ";
   cout<<amount;
   }
}
//***********************************************************************
//                         INTRO FUNCTION
//***********************************************************************
void intro()
{
   system("cls");
   gotoxy(35,11);
   cout<<"\n\t RESTAURANT MANAGEMENT SIMULATION";
   gotoxy(35,20);
   cout<<"\n\t SYSTEM ";
   cout<<"\n\t Made by : Utkarsh Jain ";
   cout<<"\n\t Made by : Shubhang Jyotirmay ";
   getch();
}
//***********************************************************************
//            ADMINISTRATOR MENU FUNCTION
//***********************************************************************
void admin_menu()
{
   system("cls");
   int ch;
   cout<<"\n\t ADMINISTRATOR MENU ";
   cout<<"\n\t 1.Create customer record ";
   cout<<"\n\t 2.Display all customer record ";
   cout<<"\n\t 3.Display specific customer record ";
   cout<<"\n\t 4.Modify customer record ";
   cout<<"\n\t 5.Delete customer record ";
   cout<<"\n\t 6.Create item ";
   cout<<"\n\t 7.Display all items ";
   cout<<"\n\t 8.Display specific item ";
   cout<<"\n\t 9.Modify item ";
   cout<<"\n\t 10.Delete item ";
   cout<<"\n\t 11.Back to Main Menu ";
   cout<<"\n\n\t Please enter your choice (1-11) : ";
   cin>>ch;
   switch(ch)
   {
      case 1:  system("cls");
	           writeCustomer();
               break;
      case 2:  displayAllCustomer();
	           break;
      case 3:  int num;
	           system("cls");
               cout<<"\n\t # Please enter the customer no. ";
	           cin>>num;
	           displayCustDetails(num);
	           break;
      case 4:  modifyCustomer();
	           break;
      case 5:  deleteCustomer();
	           break;
      case 6:  system("cls");
	           writeItem();
	           break;
      case 7:  displayAllItem();
	           break;
      case 8:  displayItemDetails();
	           break;
      case 9:  modifyItem();
	           break;
      case 10: deleteItem();
	           break;
      case 11: return;
      default : cout<<"\n\t Wrong input.";

   }
   admin_menu();
}

void menuManage() {
    int ch;
   char a;
   intro();
   do
   {
      system("cls");
      cout<<"\n\t Main Menu ";
      cout<<"\n\t 1. Item Menu. ";
      cout<<"\n\t 2. Place Order. ";
      cout<<"\n\t 3. Admin Menu. ";
      cout<<"\n\t 4. Exit";
      cout<<"\n\n\t PLEASE ENTER YOUR CHOICE (1-4) : ";
       cin>>ch;
      switch(ch)
      {
	 case 1: displayAllItem();
             break;
	 case 2: placeOrder();
             break;
	 case 3: admin_menu();
             break;
	 case 4: exit(0);
             break;
	 default : cout<<"\n\t Wrong choice ";
		       break;
      }
      cout<<"\n\t Do you want to continue (y/n?) : ";
      cin>>a;
   }while(a=='y'|| a=='Y');
}
