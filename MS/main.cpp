#include <iostream>
#include "gotoxy.cpp"
#include "delay.cpp"
#include "counterOrder.cpp"
#include "management.cpp"

using namespace std;

int main()
{
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(5, 7);
        cout << "WELCOME" << endl;
        cout << "1. ORDER FROM COUNTER" << endl;
        cout << "2. MANAGEMENT SYSTEM" << endl;
        cout << "3. EXIT" << endl << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        switch (choice) {
        case 1:
            inputOrder();
            break;
        case 2:
            menuManage();
            break;
        }
    } while (choice != 3);
    return 0;
}
