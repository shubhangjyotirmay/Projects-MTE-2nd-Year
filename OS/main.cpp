#include <iostream>
#include <cwchar>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "FCFS.cpp"
#include "SJF.cpp"
#include "RoundRobin.cpp"
#include "Priority.cpp"

using namespace std;

void welcome() {
    system("cls");
    gotoxy(10, 5);
    cout << "DELHI TECHNOLOGICAL UNIVERSITY";
    gotoxy(15, 7);
    cout << "INNOVATIVE PROJECT";
    gotoxy(16, 8);
    cout << "OPERATING SYSTEM";
    gotoxy(20, 9);
    cout << "SE-205";
    gotoxy(5, 11);
    cout << "PROJECT TITLE : OS ALGORITHMS VISUALISERS";
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
        gotoxy(16, 8);
        cout << "OPERATING SYSTEM";
        gotoxy(20, 9);
        cout << "SE-205";
        gotoxy(5, 11);
        cout << "PROJECT TITLE : OS ALGORITHMS VISUALISERS";
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
    do {
        system("cls");
        gotoxy(3, 5);
        cout << "MENU" << endl;
        cout << "1. FCFS" << endl;
        cout << "2. SJF" << endl;
        cout << "3. ROUND ROBIN" << endl;
        cout << "4. PRIORITY" << endl;
        cout << "5. EXIT" << endl << endl;
        cout << "ENTER CHOICE : ";
        cin >> ch;
        switch (ch) {
        case 1:
            fcfsMenu();
            break;
        case 2:
            sjfMenu();
            break;
        case 3:
            rrMenu();
            break;
        case 4:
            prioMenu();
        }
    } while (ch != 5);
    return 0;
}
