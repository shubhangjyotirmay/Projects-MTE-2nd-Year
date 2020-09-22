#include <iostream>
#include <cstdlib>
#include <string>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "hospital.cpp"

using namespace std;

// function definitions
void welcome();

// main function
int main()
{
    /*system("cls");
    welcome();
    delay(2000);
    system("cls");*/
    cout << "HELLO" << endl;
    delay(2000);
    menuHosp();
    return 0;
}

/*void welcome() {
    system("cls");
    gotoxy(60, 9);
    cout << "WELCOME";
    gotoxy(44, 11);
    cout << "Subject: Object Oriented Programming";
    gotoxy(60, 12);
    cout << "SE-203";
    gotoxy(44, 15);
    cout << "Project Title : City Management System";
    gotoxy(50, 17);
    cout << "Made By : Shubhang Jyotirmay";
    gotoxy(60, 18);
    cout << "2K19/SE/123";
    gotoxy(60, 19);
    cout << "Utkarsh Jain";
    gotoxy(60, 20);
    cout << "2K19/SE/139";
}*/
