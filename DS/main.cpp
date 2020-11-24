#include <iostream>
#include <fstream>
#include <cwchar>
#include <climits>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "graph.cpp"
#include "update.cpp"
#include "paths.cpp"

using namespace std;

void welcome() {
    system("cls");
    gotoxy(35, 5);
    cout << "DELHI TECHNOLOGICAL UNIVERSITY";
    gotoxy(40, 6);
    cout << "INNOVATIVE PROJECT";
    gotoxy(42, 8);
    cout << "DATA STRUCTURES";
    gotoxy(45, 9);
    cout << "SE-201";
    gotoxy(30, 11);
    cout << "PROJECT TITLE : ROAD MANAGEMENT SYSTEM";
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
        delay(500);
        }
        system("cls");
        gotoxy(35, 5);
        cout << "DELHI TECHNOLOGICAL UNIVERSITY";
        gotoxy(40, 6);
        cout << "INNOVATIVE PROJECT";
        gotoxy(42, 8);
        cout << "DATA STRUCTURES";
        gotoxy(45, 9);
        cout << "SE-201";
        gotoxy(30, 11);
        cout << "PROJECT TITLE : ROAD MANAGEMENT SYSTEM";
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
        gotoxy(47, 5);
        cout << "MENU";
        gotoxy(27, 7);
        cout << "1. INPUT THE ROADS";
        gotoxy(27, 8);
        cout << "2. DISPLAY THE ROADS";
        gotoxy(27, 9);
        cout << "3. ADD A NEW ROAD";
        gotoxy(27, 10);
        cout << "4. DELETE A ROAD";
        gotoxy(27, 11);
        cout << "5. CHANGE LENGTH OF A ROAD";
        gotoxy(27, 12);
        cout << "6. FIND ALL PATHS BETWEEN TWO POINTS";
        gotoxy(27, 13);
        cout << "7. FIND SHORTEST PATH BETWEEN TWO POINTS";
        gotoxy(27, 14);
        cout << "8. FIND SHORTEST PATH FROM ONE POINT TO ALL OTHER POINTS";
        gotoxy(27, 15);
        cout << "9. FIND TRAVEL TIME THROUGH SHORTEST PATH BETWEEN TWO POINTS";
        gotoxy(27, 16);
        cout << "10. FIND TRAVEL TIME THROUGH SHORTEST PATH FROM ONE POINT";
        gotoxy(27, 17);
        cout << "11. EXIT";
        gotoxy(27, 19);
        cout << "ENTER CHOICE: ";
        cin >> ch;
        switch(ch) {
        case 1:
            inputRoads();
            break;
        case 2:
            displayRoads();
            break;
        case 3:
            addRoad();
            break;
        case 4:
            deleteRoad();
            break;
        case 5:
            changeLength();
            break;
        case 6:
            allPaths();
            break;
        case 7:
            dijkstra(7);
            break;
        case 8:
            dijkstra(8);
            break;
        case 9:
            dijkstra(9);
            break;
        case 10:
            dijkstra(10);
        }
    } while (ch != 11);

    return 0;
}
