#include <windows.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip>

using namespace std;

class bus
{
   char busNo[10];
   char busColor[10];
   float arrivalTime;
   float departureTime;
   char from[10];
   char to[10];

   public:
        int totalSeats;
        int availableSeats;
	    void createTransport()
	    {
	       cout<<"\n\t\t # NEW TRANSPORT ENTRY : ";
	       cout<<"\n\t # Enter bus no. here :- ";
		   cin>>busNo;
	       cout<<"\n\t # Enter bus color here :- ";
           cin>>busColor;
           cout<<"\n\t # Enter arrival time here :- ";
           cin>>arrivalTime;
           cout<<"\n\t # Enter departure time here :- ";
           cin>>departureTime;
           cout<<"\n\t # Enter starting destination here :- ";
           cin>>from;
           cout<<"\n\t # Enter final destination here :- ";
           cin>>to;
           cout<<"\n\t # Enter total no. of seats here :- ";
           cin>>totalSeats;
           availableSeats=totalSeats;

	       cout<<"\n\t TRANSPORT RECORD CREATED. ";
	    }
	    void showTransport()
	    {
	       cout<<"\n\t\t # TRANSPORT DETAILS :- ";
	       cout<<"\n\t # Bus no. :- ";
		   cout<<busNo;
	       cout<<"\n\t # Bus color :- ";
           cout<<busColor;
           cout<<"\n\t # Arrival time :- ";
           cout<<arrivalTime;
           cout<<"\n\t # Departure time :- ";
           cout<<departureTime;
           cout<<"\n\t # Starting destination :- ";
           cout<<from;
           cout<<"\n\t # Final destination :- ";
           cout<<to;
           cout<<"\n\t # Total no. of seats :- ";
           cout<<totalSeats;
           cout<<"\n\t # Available no. of seats :- ";
           cout<<availableSeats;
	    }
	    void modifyTransport()
	    {
	       cout<<"\n\t # Bus number :- ";
		   cout<<busNo;
	       cout<<"\n\t # Enter the modified details here :- ";
		   cout<<"\n\t # New Arrival time :- ";
           cin>>arrivalTime;
           cout<<"\n\t # New Departure time :- ";
           cin>>departureTime;
           cout<<"\n\t # New starting destination :- ";
           cin>>from;
           cout<<"\n\t # New final destination :- ";
           cin>>to;
           cout<<"\n\t # Total no. of seats :- ";
           cin>>totalSeats;

	      cout<<"\n\t TRANSPORT RECORD MODIFIED. : ";
	    }
	    char* returnBusNo()
	    {
	       return busNo;
	    }
	    int returnAvailableSeats()
	    {
	        return availableSeats;
	    }
	    void report()
	    {
	       cout<<"\n\t "<<busNo<<setw(10)<<busColor<<setw(15)<<arrivalTime<<setw(20)<<departureTime<<setw(15);
	       cout<<from<<setw(15)<<to<<setw(15)<<totalSeats<<setw(20)<<availableSeats;
	    }
};
class passenger
{
    char pBusNo[10];
    char pName[10];
    int pNo;
    int seats;
public:
    void createPassenger()
    {
        cout<<"\n\t Enter passenger's name here :- ";
        cin>>pName;
        cout<<"\n\t Enter passenger's phone no. here :- ";
        cin>>pNo;
        cout<<"\n\t PASSENGER RECORD CREATED !! ";
    }
};
fstream tf1,tf2;
bus b;
passenger p;
//*********************************************************************
//                       FUNCTION TO WRITE IN FILE
//*********************************************************************

void writeTransport()
{
   system("cls");
   char ch;
   tf1.open("transport.dat",ios::out|ios::app);
   do
   {
      b.createTransport();
      tf1.write((char*)&b,sizeof b);
      cout<<"\n\n\t Doyou want to add more record ? (y/n?) : ";
       cin>>ch;
   }while(ch=='y'||ch=='Y');
   tf1.close();
}
//************************************************************************
//                FUNCTION TO READ SPECIFIC RECORD FROM FILE
//************************************************************************

void displayTransportDetails()
{
   system("cls");
   char n[10];
   cout<<"\n\t # Please enter the bus no. ";
   cin>>n;
   cout<<"\n\t # TRANSPORT DETAILS ARE : " ;
   int flag=0;
   tf1.open("transport.dat",ios::in);
   while(tf1.read((char*)&b,sizeof b))
   {
      if(strcmp(b.returnBusNo(),n)==0)
      {
	     b.showTransport();
	     flag=1;
      }
   }
   tf1.close();
   if(flag==0)
    cout<<"\n\t Transport does not exist. ";
    getch();
};
//************************************************************************
//               FUNCTION TO MODIFY RECORD OF FILE
//************************************************************************

void modifyTransport()
{
   system("cls");
   char n[10];
   int found=0;
   system("cls");
   cout<<"\n\t # MODIFY TRANSPORT RECORD ";
   cout<<"\n\t # Enter the plate no. of bus here : ";
    cin>>n;
   tf1.open("transport.dat",ios::in|ios::out);
   while(tf1.read((char*)&b,sizeof b) && found==0)
   {
      if(strcmp(b.returnBusNo(),n)==0)
      {
	 b.showTransport();
	 cout<<"\n\t # Enter the new details of transport here : ";
	 b.modifyTransport();
	 int pos=-1*sizeof(b);
	 tf1.seekp(pos,ios::cur);
	 tf1.write((char*)&b,sizeof b);
	 cout<<"\n\t Record updated. ";
	 found=1;
      }
   }
   tf1.close();
   if(found==0)
    cout<<"\n\t Transport does not exist. ";
   getch();
}
//************************************************************************
//           FUNCTION TO DELETE RECORD OF FILE
//************************************************************************

void deleteTransport()
{
   system("cls");
   char n[10];
   int flag=0;
   cout<<"\n\t # DELETE TRANSPORT RECORD ";
   cout<<"\n\t # Enter the plate no. of bus you want to delete :";
    cin>>n;
   tf1.open("transport.dat",ios::out|ios::in);
   fstream f2;
   f2.open("temp.dat",ios::out);
   tf1.seekg(0,ios::beg);
   while(tf1.read((char*)&b,sizeof b))
   {
      if(strcmp(b.returnBusNo(),n)!=0)
      {
	    f2.write((char*)&b,sizeof b);
      }
      else
	  flag=1;
   }
   f2.close();
   tf1.close();
   remove("transport.dat");
   rename("temp.dat","transport.dat");
   if(flag==1)
     cout<<"\n\t Record deleted. ";
   else
     cout<<"\n\t Record not found. ";
   getch();
}
//***********************************************************************
//           FUNCTION TO DISPLAY ALL TRANSPORT LIST
//***********************************************************************
void displayAllTransport()
{
   system("cls");
   tf1.open("transport.dat",ios::in);
   if(!tf1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t\t\t\t\t\t  TRANSPORT LIST ";
   cout<<"\n\t ======================================================================================================================";
   cout<<"\n\t Plate No."<<setw(10)<<"Color"<<setw(15)<<"Arrival Time"<<setw(20)<<"Depart. Time"<<setw(10);
   cout<<"From"<<setw(15)<<"To"<<setw(20)<<"Total Seats"<<setw(20)<<"Avail. Seats";
   cout<<"\n\t ======================================================================================================================";
   while(tf1.read((char*)&b,sizeof b))
   {
      b.report();
   }
   tf1.close();
   getch();
}
//***********************************************************************
//            FUNCTION TO BOOK A SEAT
//***********************************************************************
void bookSeat()
{
   system("cls");
   char sn[10],bn[10];
   int no;
   system("cls");
   cout<<"\n\t # BOOK SEAT :";
   cout<<"\n\t # Enter the bus no. : ";
    cin>>sn;
   tf1.open("transport.dat",ios::in|ios::out);
   tf2.open("book.dat",ios::in|ios::out);
   while(tf1.read((char*)&b,sizeof b))
   {
      if(strcmp(b.returnBusNo(),sn)==0)
      {
	    b.showTransport();
	    cout<<"\n\t # Available Seats are :- "<<b.availableSeats;
	    cout<<"\n\n\t Enter no. of seats to book here :- ";
	    cin>>no;
	    if(no<b.availableSeats)
        {
            cout<<"\n\t Enter your details here :- ";
            p.createPassenger();
            cout<<" \n\t SEATS BOOKED SUCCESSFULLY. !! ";
            b.availableSeats = b.totalSeats - no;
            b.returnAvailableSeats();
            int pos=-1*sizeof(b);
	        tf1.seekp(pos,ios::cur);
	        tf1.write((char*)&b,sizeof b);
            break;
        }
        else
          cout<<"\n\t Not Enough seats are available. ";
      }
      else   cout<<"\n\t Transport record does not exist. ";
   }
   tf1.close();
   tf2.close();
}
//***********************************************************************
//            ADMINISTRATOR MENU FUNCTION
//***********************************************************************
void admin_menu_trans()
{
   system("cls");
   int ch;
   cout<<"\n\t\t ADMINISTRATOR MENU ";
   cout<<"\n\t 1. Create transport record ";
   cout<<"\n\t 2. Display all transport record ";
   cout<<"\n\t 3. Display specific transport record ";
   cout<<"\n\t 4. Modify transport record ";
   cout<<"\n\t 5. Delete transport record ";
   cout<<"\n\t 6. Back to main menu ";
   cout<<"\n\n\t PLease enter your choice (1-6) : ";
   cin>>ch;
   switch(ch)
   {
      case 1: writeTransport();
	      break;
      case 2: displayAllTransport();
	      break;
      case 3: displayTransportDetails();
	      break;
      case 4: modifyTransport();
	      break;
      case 5: deleteTransport();
	      break;
      case 6: return;
      default : cout<<"\n\t Wrong input.";

   }  admin_menu_trans();

}
//***********************************************************************
//            THE MAIN FUNCTION OF PROGRAM
//***********************************************************************
int menuTrans()
{
   char ch,a;
   do
   {
      system("cls");
      cout<<"\n\t\t\t ******* Main Menu ******* ";
      cout<<"\n\n\t 1. Book Seat.";
      cout<<"\n\t 2. Transport Details.";
      cout<<"\n\t 3. Admin Menu";
      cout<<"\n\t 4. Exit";
      cout<<"\n\n\t PLEASE ENTER YOUR CHOICE (1-4) : ";
       cin>>ch;
      switch(ch)
      {
	 case '1': bookSeat();
		   break;
	 case '2': displayAllTransport();
		   break;
	 case '3': admin_menu_trans();
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
