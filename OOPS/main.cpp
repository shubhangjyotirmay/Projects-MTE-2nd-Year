#include <iostream>
#include <cstdlib>
#include <string>
#include <cwchar>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "hospital.cpp"
#include "bank.cpp"
#include "transport.cpp"
#include "education.cpp"

using namespace std;

void welcome() {
    system("cls");
    gotoxy(35, 5);
    cout << "DELHI TECHNOLOGICAL UNIVERSITY";
    gotoxy(40, 6);
    cout << "INNOVATIVE PROJECT";
    gotoxy(34, 8);
    cout << "OBJECT ORIENTED PROGRAMMING";
    gotoxy(45, 9);
    cout << "SE-203";
    gotoxy(30, 11);
    cout << "PROJECT TITLE : CITY MANAGEMENT SYSTEM";
    gotoxy(30, 12);
    cout << "MADE BY       : SHUBHANG JYOTIRMAY  2K19/SE/123";
    gotoxy(46, 13);
    cout << "UTKARSH JAIN  2K19/SE/139";
    delay(1000);
    int i, j = 0;
    gotoxy(45, 17);
    cout << "LOADING";
    do {
        for (i = 0; i < 3; i++) {
        gotoxy(53 + i, 17);
        cout << ".";
        delay(600);
        }
        system("cls");
        gotoxy(35, 5);
        cout << "DELHI TECHNOLOGICAL UNIVERSITY";
        gotoxy(40, 6);
        cout << "INNOVATIVE PROJECT";
        gotoxy(34, 8);
        cout << "OBJECT ORIENTED PROGRAMMING";
        gotoxy(45, 9);
        cout << "SE-203";
        gotoxy(30, 11);
        cout << "PROJECT TITLE : CITY MANAGEMENT SYSTEM";
        gotoxy(30, 12);
        cout << "MADE BY       : SHUBHANG JYOTIRMAY  2K19/SE/123";
        gotoxy(46, 13);
        cout << "UTKARSH JAIN  2K19/SE/139";
        gotoxy(45, 17);
        cout << "LOADING";
        j++;
    } while (j < 3);
    system("cls");
}

// main function
int main()
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 26;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_DEMIBOLD;
    std::wcscpy(cfi.FaceName, L"Courier");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    system("color 59");

    welcome();
    int ch;
    string s;
    do {
        system("cls");
        gotoxy(40, 5);
        cout << "LIST OF DEPARTMENTS";
        gotoxy(38, 7);
        cout << "1. HOSPITAL DEPARTMENT";
        gotoxy(38, 8);
        cout << "2. EDUCATION DEPARTMENT";
        gotoxy(38, 9);
        cout << "3. BANK DEPARTMENT";
        gotoxy(38, 10);
        cout << "4. TRANSPORT DEPARTMENT";
        gotoxy(38, 11);
        cout << "5. EXIT";
        gotoxy(38, 13);
        cout << "Select the department : ";
        cin >> ch;
        if (ch == 1) {
            gotoxy(38, 15);
            cout << "ENTER PASSWORD : ";
            cin >> s;
            if (s == "hospital") {
                menuHosp();
            }
            else {
                gotoxy(38, 16);
                cout << "WRONG PASSWORD";
                gotoxy(38, 18);
                cout << "MOVING TO THE MAIN MENU IN 3 SEC";
                delay(3000);
            }
        }
        else if (ch == 2) {
            gotoxy(38, 15);
            cout << "ENTER PASSWORD : ";
            cin >> s;
            if (s == "education") {
                menuEdu();
            }
            else {
                gotoxy(38, 16);
                cout << "WRONG PASSWORD";
                gotoxy(38, 18);
                cout << "MOVING TO THE MAIN MENU IN 3 SEC";
                delay(3000);
            }
        }
        else if (ch == 3) {
            gotoxy(38, 15);
            cout << "ENTER PASSWORD : ";
            cin >> s;
            if (s == "bank") {
                menuBank();
            }
            else {
                gotoxy(38, 16);
                cout << "WRONG PASSWORD";
                gotoxy(38, 18);
                cout << "MOVING TO THE MAIN MENU IN 3 SEC";
                delay(3000);
            }
        }
        else if (ch == 4) {
            gotoxy(38, 15);
            cout << "ENTER PASSWORD : ";
            cin >> s;
            if (s == "transport") {
                menuTrans();
            }
            else {
                gotoxy(38, 16);
                cout << "WRONG PASSWORD";
                gotoxy(38, 18);
                cout << "MOVING TO THE MAIN MENU IN 3 SEC";
                delay(3000);
            }
        }
    } while (ch != 5);
    return 0;
}
