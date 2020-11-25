#include <iostream>

using namespace std;

// functions for same same arrival times
void rrWtSame(int proc[], int num, int burTime[], int wt[], int timeQuantum) {
    int tempBt[num];
    for (int i = 0 ; i < num ; i++) {
        tempBt[i] =  burTime[i];
    }

    int currTime = 0;
    while (1) {
        bool done = true;
        for (int i = 0; i < num; i++) {
            if (tempBt[i] > 0) {
                done = false;
                if (tempBt[i] > timeQuantum) {
                    currTime += timeQuantum;
                    tempBt[i] -= timeQuantum;
                }
                else {
                    currTime += tempBt[i];
                    wt[i] = currTime - burTime[i];
                    tempBt[i] = 0;
                }
            }
        }
        if (done == true) {
            break;
        }
    }
}

void rrTatSame(int proc[], int num, int burTime[], int wt[], int tat[]) {
    for (int i = 0; i < num ; i++) {
        tat[i] = burTime[i] + wt[i];
    }
}

void rrAvgTimeSame(int proc[], int num, int burTime[], int timeQuantum) {
    int wt[num], tat[num], totWt = 0, totTat = 0;
    rrWtSame(proc, num, burTime, wt, timeQuantum);
    rrTatSame(proc, num, burTime, wt, tat);

    gotoxy(0, 5);
    cout << "==============================";
    cout << "==============================";
    gotoxy(1, 6);
    cout << "PROCESSES";
    gotoxy(13, 6);
    cout << "BURST TIME";
    gotoxy(26, 6);
    cout << "WAITING TIME";
    gotoxy(41, 6);
    cout << "TURN AROUND TIME" << endl;
    cout << "==============================";
    cout << "==============================";
    for (int i = 0; i < num; i++) {
        totWt = totWt + wt[i];
        totTat = totTat + tat[i];
        gotoxy(4, 8 + i);
        cout << i + 1;
        gotoxy(17, 8 + i);
        cout << burTime[i];
        gotoxy(31, 8 + i);
        cout << wt[i];
        gotoxy(48, 8 + i);
        cout << tat[i] << endl;
        delay(1000);
    }
    cout << "==============================";
    cout << "==============================";
    cout << endl << endl;

    cout << "AVERAGE WAITING TIME = " << (float)totWt / (float)num << endl;
    cout << "AVERAGE TURN AROUND TIME = " << (float)totTat / (float)num << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void rrInputSame() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;
    int proc[num], burTime[num];

    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> proc[i];
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> burTime[i];
        cout << endl;
    }
    cout << num << " PROCESSES AND BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    int timeQuantum = 2;
    rrAvgTimeSame(proc, num, burTime, timeQuantum);
}

// functions for processes with different arrival times
void rrWt(int proc[], int wt[], int num, int burTime[], int timeQuantum, int ct[], int arrTime[]) {
    int tempTime[num];
    for(int i = 0; i < num; i++) {
        tempTime[i] = burTime[i];
    }

    int t = 0;
    int arr = 0;
    while(true) {
        bool done = true;
        for(int i = 0; i < num; i++) {
            if(tempTime[i] > 0) {
                done = false;
                if(tempTime[i] > timeQuantum && arrTime[i] <= arr) {
                    t += timeQuantum;
                    tempTime[i] -= timeQuantum;
                    arr++;
                }
                else {
                    if(arrTime[i] <= arr) {
                        arr++;
                        t += tempTime[i];
                        tempTime[i] = 0;
                        ct[i] = t;
                    }
                }
            }
        }

        if(done == true) {
            break;
        }
    }
}

void rrTat(int proc[], int wt[], int num, int burTime[], int tat[], int ct[], int arrTime[]) {
    for(int i = 0; i < num; i++) {
        tat[i] = ct[i] - arrTime[i];
        wt[i] = tat[i] - burTime[i];
    }
}

void rrAvgTime(int proc[], int num, int burTime[], int timeQuantum, int arrTime[]) {
    int wt[num], tat[num], ct[num], totWt = 0, totTat = 0;
    rrWt(proc, wt, num, burTime, timeQuantum, ct, arrTime);
    rrTat(proc, wt, num, burTime, tat, ct, arrTime);

    gotoxy(0, 5);
    cout << "==============================================";
    cout << "==============================================";
    gotoxy(1, 6);
    cout << "PROCESSES";
    gotoxy(13, 6);
    cout << "BURST TIME";
    gotoxy(26, 6);
    cout << "ARRIVAL TIME";
    gotoxy(41, 6);
    cout << "WAITING TIME";
    gotoxy(56, 6);
    cout << "TURN AROUND TIME";
    gotoxy(75, 6);
    cout << "COMPLETION TIME" << endl;
    cout << "==============================================";
    cout << "==============================================";
    for (int i = 0; i < num; i++) {
        totWt = totWt + wt[i];
        totTat = totTat + tat[i];
        gotoxy(4, 8 + i);
        cout << i + 1;
        gotoxy(17, 8 + i);
        cout << burTime[i];
        gotoxy(31, 8 + i);
        cout << arrTime[i];
        gotoxy(46, 8 + i);
        cout << wt[i];
        gotoxy(63, 8 + i);
        cout << tat[i];
        gotoxy(82, 8 + i);
        cout << ct[i] << endl;
        delay(1000);
    }
    cout << "==============================================";
    cout << "==============================================";
    cout << endl << endl;

    cout << "AVERAGE WAITING TIME = " << (float)totWt / (float)num << endl;
    cout << "AVERAGE TURN AROUND TIME = "<< (float)totTat / (float)num << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void rrInput() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;
    int proc[num], arrTime[num], burTime[num];

    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> proc[i];
        cout << "ENTER ARRIVAL TIME FOR PROCESS " << i + 1 << ": ";
        cin >> arrTime[i];
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> burTime[i];
        cout << endl;
    }
    cout << num << " PROCESSES WITH THEIR ARRIVAL AND BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    int timeQuantum = 2;
    rrAvgTime(proc, num, burTime, timeQuantum, arrTime);
}

// main menu
void rrMenu() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(0, 5);
        cout << "ROUND ROBIN MENU" << endl;
        cout << "1. SAME ARRIVAL TIME" << endl;
        cout << "2. DIFFERENT ARRIVAL TIME" << endl;
        cout << "3. BACK TO PREVIOUS MENU" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            rrInputSame();
            break;
        case 2:
            rrInput();
            break;
        }
    } while (choice != 3);
}
