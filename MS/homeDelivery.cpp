#include <iostream>
#include <string>
#include <random>
#include <climits>

using namespace std;

/*
burger type  -  code  -  time(in min)
single cheese burger  -  1  -  7
double cheese burger  -  2  -  8
chicken burger        -  3  -  10
fish burger           -  4  -  11
paneer burger         -  5  -  9
*/

void genSer(int (&serviceTime)[10], int (&deliveryTime)[10]) {
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
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(10, 30);
    for (int i = 0; i < 10; i++) {
        int temp = distribution(generator);
        deliveryTime[i] = temp;
        distribution.reset();
    }
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void genArr(int (&arrivalTime)[10]) {
    system("cls");
    gotoxy(0, 5);
    arrivalTime[0] = 0;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(1, 30);
    cout << "ORDER FOR CUSTOMER 1 PLACED AT : " << arrivalTime[0] << endl;
    delay(1000);
    for (int i = 1; i < 10; i++) {
        int temp = distribution(generator);
        arrivalTime[i] = arrivalTime[i - 1] + temp;
        distribution.reset();
        cout << "ORDER FOR CUSTOMER " << i + 1 << " PLACED AT : " << arrivalTime[i] << endl;
        delay(1000);
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void inpOrder() {
    int serviceTime[10], arrivalTime[10], deliverytime[10];
    genSer(serviceTime, deliverytime);
    genArr(arrivalTime);

    string deliveryBoy[10];
    int ramesh[10], suresh[10], waitTime[10];
    deliveryBoy[0] = "RAMESH";
    ramesh[0] = (2 * deliverytime[0]) + serviceTime[0];
    suresh[0] = arrivalTime[1];
    waitTime[0] = serviceTime[0] + deliverytime[0];
    for (int i = 1; i < 10; i++) {
        int temp = arrivalTime[i];
        if (temp < ramesh[i - 1] && temp < suresh[i - 1]) {
            int first = (ramesh[i - 1] <= suresh[i - 1]) ? 1 : 2;
            if (first == 1) {
                deliveryBoy[i] = "RAMESH";
                ramesh[i] = ramesh[i - 1] + deliverytime[i] + serviceTime[i];
                suresh[i] = suresh[i - 1];
                if (temp > ramesh[i - 1]) {
                    ramesh[i] = temp;
                    ramesh[i] += temp;
                }
                if (ramesh[i] - temp < 0) {
                    waitTime[i] = 0;
                }
                else {
                    waitTime[i] = ramesh[i] - temp;
                }
                ramesh[i] += deliverytime[i];
            }
            else {
                deliveryBoy[i] = "SURESH";
                suresh[i] = ((suresh[i - 1] == INT_MIN) ? deliverytime[i] + serviceTime[i] : (suresh[i - 1] + deliverytime[i] + serviceTime[i]));
                ramesh[i] = ramesh[i - 1];
                if (temp > suresh[i - 1]) {
                    suresh[i] = temp;
                    suresh[i] += temp;
                }
                if (suresh[i] - temp < 0) {
                    waitTime[i] = 0;
                }
                else {
                    waitTime[i] = suresh[i] - temp;
                }
                suresh[i] += deliverytime[i];
            }
        }
        else if (temp < ramesh[i - 1]) {
            deliveryBoy[i] = "SURESH";
            suresh[i] = ((suresh[i - 1] == INT_MIN) ? deliverytime[i] + serviceTime[i] : (suresh[i - 1] + deliverytime[i] + serviceTime[i]));
            ramesh[i] = ramesh[i - 1];
            if (temp > suresh[i - 1]) {
                suresh[i] = temp;
                suresh[i] += temp;
            }
            if (suresh[i] - temp < 0) {
                waitTime[i] = 0;
            }
            else {
                waitTime[i] = suresh[i] - temp;
            }
            suresh[i] += deliverytime[i];
        }
        else {
            deliveryBoy[i] = "RAMESH";
            ramesh[i] = ramesh[i - 1] + deliverytime[i] + serviceTime[i];
            suresh[i] = suresh[i - 1];
            if (temp > ramesh[i - 1]) {
                ramesh[i] = temp;
                ramesh[i] += temp;
            }
            if (ramesh[i] - temp < 0) {
                waitTime[i] = 0;
            }
            else {
                waitTime[i] = ramesh[i] - temp;
            }
            ramesh[i] += deliverytime[i];
        }
    }

    system("cls");
    gotoxy(31, 5);
    cout << "PERFORMANCE ANALYSIS" << endl;
    cout << "=========================================";
    cout << "=========================================";
    gotoxy(1, 7);
    cout << "ORDER NO";
    gotoxy(12, 7);
    cout << "ORDER PLACED";
    gotoxy(14, 8);
    cout << "AT TIME";
    gotoxy(27, 7);
    cout << "ORDER PREPARATION";
    gotoxy(33, 8);
    cout << "TIME";
    gotoxy(47, 7);
    cout << "ORDER DELIVERY";
    gotoxy(52, 8);
    cout << "TIME";
    gotoxy(64, 7);
    cout << "WAITING";
    gotoxy(65, 8);
    cout << "TIME";
    gotoxy(74, 7);
    cout << "ALLOTED";
    gotoxy(76, 8);
    cout << "TO" << endl;
    cout << "=========================================";
    cout << "=========================================";
    for (int i = 0; i < 10; i++) {
        gotoxy(4, 10 + i);
        cout << i + 1;
        gotoxy(17, 10 + i);
        cout << arrivalTime[i];
        gotoxy(35, 10 + i);
        cout << serviceTime[i];
        gotoxy(53, 10 + i);
        cout << deliverytime[i];
        /*if (deliveryBoy[i] == "RAMESH") {
            cout << ramesh[i];
        }
        else {
            cout << suresh[i];
        }*/
        gotoxy(66, 10 + i);
        cout << waitTime[i];
        gotoxy(74, 10 + i);
        cout << deliveryBoy[i] << endl;
        delay(1000);
    }
    cout << "=========================================";
    cout << "=========================================" << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}
