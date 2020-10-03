#include <windows.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdio>
#include<iomanip>

using namespace std;

COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class school
{
   char schoolName[50];
   int schoolCode;
   int teachers;
   int students;
   int othStaff;
   int totalSeats;
   char isBookStore[5];
   public:
        school()
	{
		strcpy(schoolName,"NULL");
		schoolCode=0;
		teachers=0;
		students=0;
		othStaff=0;
		totalSeats=0;
		strcpy(isBookStore,"NULL");
	}	
	void createSchool();
        void showSchool();
        void modifySchool();
	int returnSchoolCode();
        void report();
	~school();
};
void school::createSchool()
{
    cout<<"\n\t # NEW SCHOOL ENTRY ";
    cout<<"\n\t # Enter the school name here : ";
    cin>>schoolName;
    cout<<"\n\t # Enter the school number here : ";
    cin>>schoolCode;
    cout<<"\n\t # Enter following details : ";
    cout<<"\n\t\t # Teachers :- "; cin>>teachers;
    cout<<"\n\t\t # Students :- "; cin>>students;
    cout<<"\n\t\t # Other Staff :- "; cin>>othStaff;
    cout<<"\n\t\t # Total Seats :- "; cin>>totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cin>>isBookStore;
    cout<<"\n\t SCHOOL RECORD CREATED. ";
}

void school::showSchool()
{
    cout<<"\n\t # SCHOOL DETAILS ARE :- ";
    cout<<"\n\t # School name : ";
    puts(schoolName);
    cout<<"\n\t # School code : ";
    cout<<schoolCode;
    cout<<"\n\t # Other details : ";
    cout<<"\n\t\t # Teachers :- "; cout<<teachers;
    cout<<"\n\t\t # Students :- "; cout<<students;
    cout<<"\n\t\t # Other Staff :- "; cout<<othStaff;
    cout<<"\n\t\t # Total Seats :- "; cout<<totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cout<<isBookStore;
}

void school::modifySchool()
{
    cout<<"\n\t # School number is : ";
    cout<<schoolCode;
    cout<<"\n\t # Modify the school name here : ";
    cin>>schoolName;
    cout<<"\n\t # Modify following details : ";
    cout<<"\n\t\t # Teachers :- "; cin>>teachers;
    cout<<"\n\t\t # Students :- "; cin>>students;
    cout<<"\n\t\t # Other Staff :- "; cin>>othStaff;
    cout<<"\n\t\t # Total Seats :- "; cin>>totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cin>>isBookStore;
}
int school::returnSchoolCode()
{
    return schoolCode;
}
void school::report()
{
    cout<<"\n\t\t"<<schoolCode<<setw(15)<<schoolName<<setw(15)<<totalSeats<<setw(15)<<students;
    cout<<setw(15)<<teachers<<setw(15)<<othStaff<<setw(15)<<isBookStore<<endl;
}

//..............................................................................................
//..............................................................................................

class college
{
   int cCode;
   char cName[20];
   int professors;
   int students;
   int othStaff;
   int totalSeats;
   char isBookStore[5];
   public:
	college()
	{
		strcpy(cName,"NULL");
		cCode=0;
		professors=0;
		students=0;
		othStaff=0;
		totalSeats=0;
		strcpy(isBookStore,"NULL");
	}
        void createCollege();
        void showCollege();
        void modifyCollege();
	int returnCollegeCode();
	void report();
	~college();
};
void college::createCollege()
{
    cout<<"\n\t # NEW COLLEGE ENTRY : ";
    cout<<"\n\t # Enter college code here : ";
    cin>>cCode;
    cout<<"\n\t # Enter college name here : ";
    cin>>cName;
    cout<<"\n\t # Enter following details : ";
    cout<<"\n\t\t # Professors :- "; cin>>professors;
    cout<<"\n\t\t # Students :- "; cin>>students;
    cout<<"\n\t\t # Other Staff :- "; cin>>othStaff;
    cout<<"\n\t\t # Total Seats :- "; cin>>totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cin>>isBookStore;
    cout<<"\n\t COLLEGE RECORD CREATED. ";
}
void college::showCollege()
{
    cout<<"\n\t # COLLEGE DETAILS ARE : ";
    cout<<"\n\t # College Code :- ";
    cout<<cCode;
    cout<<"\n\t # College name :- ";
    puts(cName);
    cout<<"\n\t # Other details : ";
    cout<<"\n\t\t # Professors :- "; cout<<professors;
    cout<<"\n\t\t # Students :- "; cout<<students;
    cout<<"\n\t\t # Other Staff :- "; cout<<othStaff;
    cout<<"\n\t\t # Total Seats :- "; cout<<totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cout<<isBookStore;
}
void college::modifyCollege()
{
    cout<<"\n\t # College Code :- ";
    cout<<cCode;
    cout<<"\n\t # Modify the college name here :- ";
    cin>>cName;
    cout<<"\n\t # Modify following details : ";
    cout<<"\n\t\t # Professors :- "; cin>>professors;
    cout<<"\n\t\t # Students :- "; cin>>students;
    cout<<"\n\t\t # Other Staff :- "; cin>>othStaff;
    cout<<"\n\t\t # Total Seats :- "; cin>>totalSeats;
    cout<<"\n\t\t # Book Store available or not :- "; cin>>isBookStore;
}
int college::returnCollegeCode()
{
    return cCode;
}
void college::report()
{
    cout<<"\n\t\t"<<cCode<<setw(15)<<cName<<setw(15)<<totalSeats<<setw(15)<<students<<setw(15);
    cout<<professors<<setw(15)<<othStaff<<setw(15)<<isBookStore<<endl;
}

fstream f1,f2;
school s;
college c;
//*********************************************************************
//                       FUNCTION TO WRITE IN FILE
//*********************************************************************

void writeSchool()
{
   char ch;
   f1.open("school.dat",ios::out|ios::app);
   do
   {  system("cls");
      s.createSchool();
      f1.write((char*)&s,sizeof s);
      cout<<"\n\n\t Do you want to add more record ? (y/n?) : ";
      cin>>ch;
   }while(ch=='y'||ch=='Y');
   f1.close();
}
 void writeCollege()
{
   char ch;
   f1.open("college.dat",ios::out|ios::app);
   do
   {
      c.createCollege();
      f1.write((char*)&c,sizeof c);
      cout<<"\n\n\t Do you want to add more record ? (y/n?) : ";
       cin>>ch;
   }while(ch=='y'||ch=='Y');
   f1.close();
}
//************************************************************************
//                FUNCTION TO READ SPECIFIC RECORD FROM FILE
//************************************************************************

void displaySchoolDetails()
{
   system("cls");
   int num;
   cout<<"\n\t # Please enter the school code :- ";
   cin>>num;
   int flag=0;
   f1.open("school.dat",ios::in);
   while(f1.read((char*)&s,sizeof s))
   {
      if((s.returnSchoolCode())==num)
      {
	 s.showSchool();
	 flag=1;
      }
   }
   f1.close();
   if(flag==0)
    cout<<"\n\t School does not exist. ";
    getch();
}
void displayCollegeDetails(int n)
{
   int flag=0;
   f1.open("college.dat",ios::in);
   while(f1.read((char*)&c,sizeof c))
   {
      if((c.returnCollegeCode())==n)
      {
	 c.showCollege();
	 flag=1;
      }
   }
   f1.close();
   if(flag==0)
    cout<<"\n\t College does not exist. ";
    getch();
};
//************************************************************************
//               FUNCTION TO MODIFY RECORD OF FILE
//************************************************************************

void modifySchool()
{
   int n;
   int found=0;
   system("cls");
   cout<<"\n\t # MODIFY SCHOOL RECORD ";
   cout<<"\n\t # Enter the school code here : ";
    cin>>n;
   f1.open("school.dat",ios::in|ios::out);
   while(f1.read((char*)&s,sizeof s) && found==0)
   {
      if((s.returnSchoolCode())==n)
      {
	 s.showSchool();
	 cout<<"\n\t # Enter the new school details here : ";
	 s.modifySchool();
	 int pos=-1*sizeof(s);
	 f1.seekp(pos,ios::cur);
	 f1.write((char*)&s,sizeof s);
	 cout<<"\n\t Record updated. ";
	 found=1;
      }
   }
   f1.close();
   if(found==0)
    cout<<"\n\t School Record not found. ";
    getch();
}

void modifyCollege()
{
   system("cls");
   int n;
   int found=0;
   cout<<"\n\t # MODIFY COLLEGE RECORD ";
   cout<<"\n\t # Enter the college code here :- ";
    cin>>n;
   f1.open("college.dat",ios::in|ios::out);
   while(f1.read((char*)&c,sizeof c) && found==0)
   {
      if((c.returnCollegeCode())==n)
      {
	 c.showCollege();
	 cout<<"\n\t # Enter the new details of college here : ";
	 c.modifyCollege();
	 int pos=-1*sizeof(c);
	 f1.seekp(pos,ios::cur);
	 f1.write((char*)&c,sizeof c);
	 cout<<"\n\t Record updated. ";
	 found=1;
      }
   }
   f1.close();
   if(found==0)
    cout<<"\n\t College does not exist. ";
    getch();
}
//************************************************************************
//           FUNCTION TO DELETE RECORD OF FILE
//************************************************************************
void deleteSchool()
{
   int n;
   system("cls");
   cout<<"\n\t # DELETE SCHOOL ";
   cout<<"\n\t # Enter the school code of the school you want to delete :";
    cin>>n;
   f1.open("school.dat",ios::in|ios::out);
   fstream f2;
   f2.open("temp.dat",ios::out);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&s,sizeof s))
   {
      if((s.returnSchoolCode())!=n)
      {
	 f2.write((char*)&s,sizeof s);
      }
   }
   f2.close();
   f1.close();
   remove("school.dat");
   rename("temp.dat","school.dat");

   cout<<"\n\t School deleted. ";
   getch();

}
void deleteCollege()
{
   system("cls");
   int n;
   int flag=0;
   cout<<"\n\t # DELETE COLLEGE RECORD ";
   cout<<"\n\t # Enter the college whose record you want to delete :";
    cin>>n;
   f1.open("college.dat",ios::out|ios::in);
   fstream f2;
   f2.open("temp.dat",ios::out);
   f1.seekg(0,ios::beg);
   while(f1.read((char*)&c,sizeof c))
   {
      if((c.returnCollegeCode())!=n)
      {
	 f2.write((char*)&c,sizeof c);
      }
      else
	 flag=1;
   }
   f2.close();
   f1.close();
   remove("college.dat");
   rename("temp.dat","college.dat");
   if(flag==1)
     cout<<"\n\t Record deleted. ";
   else
     cout<<"\n\t Record not found. ";
   getch();
}
//***********************************************************************
//           FUNCTION TO DISPLAY ALL COLLEGES LIST
//***********************************************************************
void displayAllCollege()
{
   system("cls");
   f1.open("college.dat",ios::in);
   if(!f1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t\t\t\t COLLEGE LIST ";
   cout<<"\n\t =============================================================================================================";
   cout<<"\n\t College Code"<<setw(15)<<"College Name"<<setw(15)<<"Total Seats"<<setw(15)<<"Students"<<setw(15)<<"Professors"<<setw(15)<<"Other Staff"<<setw(15)<<"Book Store";
   cout<<"\n\t =============================================================================================================";
   while(f1.read((char*)&c,sizeof c))
   {
      c.report();
   }
   f1.close();
   getch();
}
//***********************************************************************
//            FUNCTION TO DISPLAY ALL SCHOOLS LIST
//***********************************************************************
void displayAllSchool()
{
   system("cls");
   f1.open("school.dat",ios::in);
   if(!f1)
   {
      cout<<"\n\t ERROR!!! Unable to open file. ";
      return;
   }
   cout<<"\n\t\t\t\t SCHOOL LIST ";
   cout<<"\n\t =========================================================================================================";
   cout<<"\n\t School Code"<<setw(15)<<"School Name"<<setw(15)<<"Total Seats"<<setw(15)<<"Students"<<setw(15)<<"Teachers"<<setw(15)<<"Other Staff"<<setw(15)<<"Book Store";
   cout<<"\n\t =========================================================================================================";
   while(f1.read((char*)&s,sizeof s))
   {
      s.report();
   }
   f1.close();
   getch();
};

//***********************************************************************
//            ADMINISTRATOR MENU FUNCTION
//***********************************************************************
void admin_menu()
{
   system("cls");
   int ch;
   cout<<"\n\t ADMINISTRATOR MENU ";
   cout<<"\n\t 1.Create College record ";
   cout<<"\n\t 2.Display all Colleges record ";
   cout<<"\n\t 3.Display specific College record ";
   cout<<"\n\t 4.modify College record ";
   cout<<"\n\t 5.delete College record ";
   cout<<"\n\t 6.Create School ";
   cout<<"\n\t 7.Display all Schools record";
   cout<<"\n\t 8.Display specific School record";
   cout<<"\n\t 9.Modify School record";
   cout<<"\n\t 10.Delete School record";
   cout<<"\n\t 11.Back to Main Menu ";
   cout<<"\n\n\t Please enter your choice (1-11) : ";
   cin>>ch;
   switch(ch)
   {
      case 1:  system("cls");
	           writeCollege();
               break;
      case 2:  displayAllCollege();
	           break;
      case 3:  int num;
	           system("cls");
               cout<<"\n\t # Please enter the college code :- ";
	           cin>>num;
	           displayCollegeDetails(num);
	           break;
      case 4:  modifyCollege();
	           break;
      case 5:  deleteCollege();
	           break;
      case 6:  system("cls");
	           writeSchool();
	           break;
      case 7:  displayAllSchool();
	           break;
      case 8:  displaySchoolDetails();
	           break;
      case 9:  modifySchool();
	           break;
      case 10: deleteSchool();
	           break;
      case 11: return;
      default : cout<<"\n\t Wrong input.";

   }
   admin_menu();
}
//***********************************************************************
//            THE MAIN FUNCTION OF PROGRAM
//***********************************************************************
int main()
{
   int ch;
   char a;
   do
   {
      system("cls");
      cout<<"\n\t Main Menu ";
      cout<<"\n\t 1. School List. ";
      cout<<"\n\t 2. College List. ";
      cout<<"\n\t 3. Admin Menu. ";
      cout<<"\n\t 4. Exit";
      cout<<"\n\n\t PLEASE ENTER YOUR CHOICE (1-4) : ";
       cin>>ch;
      switch(ch)
      {
	 case 1: displayAllSchool();
             break;
	 case 2: displayAllCollege();
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
   return 0;
}
//***********************************************************************
//           END OF PROJECT
//***********************************************************************
