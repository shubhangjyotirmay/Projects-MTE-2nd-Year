#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
burger type  -  code  -  time(in min)
single cheese burger  -  1  -  7
double cheese burger  -  2  -  8
chicken burger        -  3  -  10
fish burger           -  4  -  11
paneer burger         -  5  -  9
*/

void generateSer(int (&serviceTime)[10]) {
    gotoxy(3, 5);
    int i = 0, temp;
    string s;
    int choice;
    do {
        system("cls");
        gotoxy(8, 5);
        cout << "MENU" << endl;
        cout << "1. SINGLE CHEESE BURGER" << endl;
        cout << "2. DOUBLE CHEESE BURGER" << endl;
        cout << "3. CHICKEN BURGER" << endl;
        cout << "4. FISH BURGER" << endl;
        cout << "5. PANEER BURGER" << endl << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        switch (choice) {
        case 1:
            serviceTime[i] = 7;
            temp = 7;
            s = "SINGLE CHEESE BURGER";
            break;
        case 2:
            serviceTime[i] = 8;
            temp = 8;
            s = "DOUBLE CHEESE BURGER";
            break;
        case 3:
            serviceTime[i] = 10;
            temp = 10;
            s = "CHICKEN BURGER";
            break;
        case 4:
            serviceTime[i] = 11;
            temp = 11;
            s = "FISH BURGER";
            break;
        case 5:
            serviceTime[i] = 9;
            temp = 9;
            s = "PANEER BURGER";
            break;
        }
        cout << endl;
        cout << "CUSTOMER " << i + 1 << " HAS ORDERED " << s << endl;
        cout << s << " TAKES " << temp << " MINUTES TO PREPARE" << endl << endl << endl;
        i++;
        delay(800);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
    } while (i < 10);
    system("cls");
    gotoxy(0, 6);
    cout << "ORDER OF 10 CUSTOMERS NOTED!" << endl;
    cout << "PROCEEDING TO THE SIMULATION" << endl << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void generateArr(int (&arrivalTime)[10]) {
    system("cls");
    gotoxy(0, 5);
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, 10);
    arrivalTime[0] = 0;
    cout << "ARRIVAL TIME FOR CUSTOMER 1 IS : " << arrivalTime[0] << endl;
    delay(1000);
    for (int i = 1; i < 10; i++) {
        int temp = distribution(generator);
        arrivalTime[i] = arrivalTime[i - 1] + temp;
        distribution.reset();
        cout << "ARRIVAL TIME FOR CUSTOMER " << i + 1 << " IS : " << arrivalTime[i] << endl;
        delay(1000);
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void inputOrder() {
    int serviceTime[10], arrivalTime[10];
    generateSer(serviceTime);
    generateArr(arrivalTime);

    int server1SS[10], server1SE[10], server1ST[10];
    int server2SS[10], server2SE[10], server2ST[10];
    int waitTime[10], sysTime[10];
    server1SS[0] = 0;
    server1SE[0] = serviceTime[0];
    server1ST[0] = serviceTime[0];
    server2SE[0] = -1;
    server2SS[0] = -1;
    server2ST[0] = -1;
    waitTime[0] = 0;
    sysTime[0] = serviceTime[0];
    for (int i = 1; i < 10; i++) {
        int temp = arrivalTime[i];
        if (temp < server1SE[i - 1] && temp < server2SE[i - 1]) {
            int first = (server1SE[i - 1] <= server2SE[i - 1]) ? 1 : 2;
            if (first == 1) {
                server1SS[i] = server1SE[i - 1];
                server1SE[i] = server1SS[i] + serviceTime[i];
                server1ST[i] = serviceTime[i];
                server2SS[i] = -1;
                server2SE[i] = server2SE[i - 1];
                server2ST[i] = -1;
                waitTime[i] = server1SE[i - 1] - temp;
                sysTime[i] = waitTime[i] + serviceTime[i];
            }
            else {
                server2SS[i] = server2SE[i - 1];
                server2SE[i] = server2SS[i] + serviceTime[i];
                server2ST[i] = serviceTime[i];
                server1SS[i] = -1;
                server1SE[i] = server1SE[i - 1];
                server1ST[i] = -1;
                waitTime[i] = server2SE[i - 1] - temp;
                sysTime[i] = waitTime[i] + serviceTime[i];
            }
        }
        else if (temp < server1SE[i - 1]) {
            server2SS[i] = temp;
            server2SE[i] = temp + serviceTime[i];
            server2ST[i] = serviceTime[i];
            server1SS[i] = -1;
            server1SE[i] = server1SE[i - 1];
            server1ST[i] = -1;
            waitTime[i] = 0;
            sysTime[i] = serviceTime[i];
        }
        else {
            server1SS[i] = temp;
            server1SE[i] = temp + serviceTime[i];
            server1ST[i] = serviceTime[i];
            server2SS[i] = -1;
            server2SE[i] = server2SE[i - 1];
            server2ST[i] = -1;
            waitTime[i] = 0;
            sysTime[i] = serviceTime[i];
        }
    }

    system("cls");
    gotoxy(39, 5);
    cout << "PERFORMANCE ANALYSIS" << endl;
    cout << "==================================================";
    cout << "==================================================";
    gotoxy(31, 7);
    cout << "SERVER 1";
    gotoxy(61, 7);
    cout << "SERVER 2";
    gotoxy(1, 8);
    cout << "CUSTOMER";
    gotoxy(12, 8);
    cout << "ARRIVAL";
    gotoxy(13, 9);
    cout << "TIME";
    gotoxy(22, 8);
    cout << "SERVICE";
    gotoxy(23, 9);
    cout << "START";
    gotoxy(32, 8);
    cout << "SERVICE";
    gotoxy(33, 9);
    cout << "TIME";
    gotoxy(42, 8);
    cout << "SERVICE";
    gotoxy(44, 9);
    cout << "END";
    gotoxy(52, 8);
    cout << "SERVICE";
    gotoxy(53, 9);
    cout << "START";
    gotoxy(62, 8);
    cout << "SERVICE";
    gotoxy(63, 9);
    cout << "TIME";
    gotoxy(72, 8);
    cout << "SERVICE";
    gotoxy(74, 9);
    cout << "END";
    gotoxy(82, 8);
    cout << "WAITING";
    gotoxy(83, 9);
    cout << "TIME";
    gotoxy(92, 8);
    cout << "TIME IN";
    gotoxy(93, 9);
    cout << "SHOP" << endl;
    cout << "==================================================";
    cout << "==================================================";
    for (int i = 0; i < 10; i++) {
        gotoxy(4, 11 + i);
        cout << i + 1;
        gotoxy(14, 11 + i);
        cout << arrivalTime[i];
        if (server1SS[i] != -1) {
            gotoxy(24, 11 + i);
            cout << server1SS[i];
            gotoxy(34, 11 + i);
            cout << server1ST[i];
            gotoxy(45, 11 + i);
            cout << server1SE[i];
        }
        if (server2SS[i] != -1) {
            gotoxy(54, 11 + i);
            cout << server2SS[i];
            gotoxy(64, 11 + i);
            cout << server2ST[i];
            gotoxy(75, 11 + i);
            cout << server2SE[i];
        }
        gotoxy(84, 11 + i);
        cout << waitTime[i];
        gotoxy(94, 11 + i);
        cout << sysTime[i] << endl;
        delay(1000);
    }
    cout << "==================================================";
    cout << "==================================================" << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}
