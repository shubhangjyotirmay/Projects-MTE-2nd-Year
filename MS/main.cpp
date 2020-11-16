#include <iostream>
#include <cwchar>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "counterOrder.cpp"
#include "homeDelivery.cpp"
#include "management.cpp"

using namespace std;

void welcome() {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_DEMIBOLD;
    std::wcscpy(cfi.FaceName, L"Courier");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    system("cls");
    system("color B2");
    gotoxy(10, 5);
    cout << "DELHI TECHNOLOGICAL UNIVERSITY";
    gotoxy(15, 7);
    cout << "INNOVATIVE PROJECT";
    gotoxy(12, 8);
    cout << "MODELLING AND SIMULATION";
    gotoxy(20, 9);
    cout << "SE-207";
    gotoxy(5, 11);
    cout << "PROJECT TITLE : RESTAURANT MANAGEMENT SYSTEM";
    gotoxy(5, 12);
    cout << "MADE BY       : SHUBHANG JYOTIRMAY  2K19/SE/123";
    gotoxy(21, 13);
    cout << "UTKARSH JAIN  2K19/SE/139";
    delay(1000);
    int i, j = 0;
    gotoxy(20, 17);
    cout << "LOADING";
    do {
        for (i = 0; i < 3; i++) {
        gotoxy(28 + i, 17);
        cout << ".";
        delay(500);
        }
        system("cls");
        gotoxy(10, 5);
        cout << "DELHI TECHNOLOGICAL UNIVERSITY";
        gotoxy(15, 7);
        cout << "INNOVATIVE PROJECT";
        gotoxy(12, 8);
        cout << "MODELLING AND SIMULATION";
        gotoxy(20, 9);
        cout << "SE-207";
        gotoxy(5, 11);
        cout << "PROJECT TITLE : RESTAURANT MANAGEMENT SYSTEM";
        gotoxy(5, 12);
        cout << "MADE BY       : SHUBHANG JYOTIRMAY  2K19/SE/123";
        gotoxy(21, 13);
        cout << "UTKARSH JAIN  2K19/SE/139";
        gotoxy(20, 17);
        cout << "LOADING";
        j++;
    } while (j < 3);
    system("cls");
}

int main()
{
    welcome();
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(3, 8);
        cout << "THE BURGER PALACE";
        gotoxy(7, 10);
        cout << "WELCOME" << endl;
        cout << "1. ORDER FROM COUNTER" << endl;
        cout << "2. HOME DELIVERY" << endl;
        cout << "3. MANAGEMENT SYSTEM" << endl;
        cout << "4. EXIT" << endl << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        switch (choice) {
        case 1:
            inputOrder();
            break;
        case 2:
            inpOrder();
            break;
        case 3:
            menuManage();
            break;
        }
    } while (choice != 4);
    return 0;
}
