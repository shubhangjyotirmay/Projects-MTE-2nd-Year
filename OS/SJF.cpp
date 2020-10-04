#include <iostream>
#include <climits>

using namespace std;
int process[10][6];

// non - preemptive(SJF)
void sjfArrival(int process[][6], int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (process[j][1] > process[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    int temp = process[j][k];
                    process[j][k] = process[j + 1][k];
                    process[j + 1][k] = temp;
                }
            }
        }
    }
}

void sjfComplet(int process[][6], int num) {
    process[0][3] = process[0][1] + process[0][2];
    process[0][5] = process[0][3] - process[0][1];
    process[0][4] = process[0][5] - process[0][2];

    int a, b;
    for (int i = 1; i < num; i++) {
        a = process[i - 1][3];
        int temp = process[i][2];
        for (int j = i; j < num; j++) {
            if (a >= process[j][1] && temp >= process[j][2]) {
                temp = process[j][2];
                b = j;
            }
        }
        process[b][3] = a + process[b][2];
        process[b][5] = process[b][3] - process[b][1];
        process[b][4] = process[b][5] - process[b][2];
        for (int k = 0; k < 6; k++) {
            int x = process[b][k];
            process[b][k] = process[i][k];
            process[i][k] = x;
        }
    }
}

void sjfInput() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;

    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> process[i][0];
        cout << "ENTER ARRIVAL TIME FOR PROCESS " << i + 1 << ": ";
        cin >> process[i][1];
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> process[i][2];
        cout << endl;
    }
    cout << num << " PROCESSES AND THEIR ARRIVAL TIME AND BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    gotoxy(8, 3);
    cout << "BEFORE SCHEDULING" << endl;
    cout << "===================";
    cout << "===================";
    gotoxy(1, 5);
    cout << "PROCESS";
    gotoxy(11,  5);
    cout << "ARRIVAL TIME";
    gotoxy(26, 5);
    cout << "BURST TIME" << endl;
    cout << "===================";
    cout << "===================";
    for (int i = 0; i < 4; i++) {
        gotoxy(4, 7 + i);
        cout << process[i][0];
        gotoxy(17, 7 + i);
        cout << process[i][1];
        gotoxy(30, 7 + i);
        cout << process[i][2] << endl;
        delay(1000);
    }
    cout << "===================";
    cout << "===================";

    sjfArrival(process, num);
    sjfComplet(process, num);
    delay(1000);

    gotoxy(27, 11 + num);
    cout << "AFTER SCHEDULING" << endl;
    cout << "====================================";
    cout << "====================================";
    gotoxy(1, 13 + num);
    cout << "PROCESS";
    gotoxy(11, 13 + num);
    cout << "ARRIVAL TIME";
    gotoxy(26, 13 + num);
    cout << "BURST TIME";
    gotoxy(39, 13 + num);
    cout << "WAITING TIME";
    gotoxy(54, 13 + num);
    cout << "TURNAROUND TIME" << endl;
    cout << "====================================";
    cout << "====================================";
    for (int j = 0; j < num; j++) {
        gotoxy(4, 15 + num + j);
        cout << process[j][0];
        gotoxy(17, 15 + num + j);
        cout << process[j][1];
        gotoxy(30, 15 + num + j);
        cout << process[j][2];
        gotoxy(44, 15 + num + j);
        cout << process[j][4];
        gotoxy(61, 15 + num + j);
        cout << process[j][5] << endl;
        delay(1000);
    }
    cout << "====================================";
    cout << "====================================";
    cout << endl << endl;
    delay(1000);

    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

//  Pre-emptive(SRTF)
struct srtf {
    int procId;
    int arrTime;
    int burstTime;
};

void srtfWaitTime(srtf pro[], int num, int wt[]) {
    int remTime[num];
    for (int i = 0; i < num; i++) {
        remTime[i] = pro[i].burstTime;
    }

    int comp = 0, t = 0, shor = 0, m = INT_MAX, finTime;
    bool check = false;
    while (comp != num) {
        for (int j = 0; j < num; j++) {
            if ((pro[j].arrTime <= t) && (remTime[j] < m) && remTime[j] > 0) {
                m = remTime[j];
                shor = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        remTime[shor]--;
        m = remTime[shor];
        if (m == 0) {
            m = INT_MAX;
        }

        if (remTime[shor] == 0) {
            comp++;
            check = false;
            finTime = t + 1;
            wt[shor] = finTime - pro[shor].burstTime - pro[shor].arrTime;
            if (wt[shor] < 0) {
                wt[shor] = 0;
            }
        }
        t++;
    }
}

void srtfTurnArTime(srtf pro[], int num, int wt[], int tat[]) {
    for (int i = 0; i < num; i++) {
        tat[i] = pro[i].burstTime + wt[i];
    }
}

void srtfAvgTime(srtf pro[], int num) {
    int wt[num], tat[num], totWt = 0, totTat = 0;

    srtfWaitTime(pro, num, wt);
    srtfTurnArTime(pro, num, wt, tat);

    gotoxy(0, 6);
    cout << "===============================";
    cout << "==============================";
    gotoxy(1, 7);
    cout << "PROCESSES";
    gotoxy(13, 7);
    cout << "BURST TIME";
    gotoxy(26, 7);
    cout << "WAITING TIME";
    gotoxy(41, 7);
    cout << "TURN AROUND TIME" << endl;
    cout << "===============================";
    cout << "==============================";
    for (int i = 0; i < num; i++) {
        totWt += wt[i];
        totTat += tat[i];
        gotoxy(5, 9 + i);
        cout << pro[i].procId;
        gotoxy(17, 9 + i);
        cout << pro[i].burstTime;
        gotoxy(31, 9 + i);
        cout << wt[i];
        gotoxy(48, 9 + i);
        cout << tat[i] << endl;
        delay(1000);
    }
    cout << "===============================";
    cout << "==============================" << endl << endl;
    delay(1000);
    cout << "AVERAGE WAITING TIME: " << (float)totWt / (float)num << endl;
    cout << "AVERAGE TURN AROUND TIME: " << (float)totTat / (float)num << endl << endl;

    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void srtfInput() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;

    srtf pro[num];
    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> pro[i].procId;
        cout << "ENTER ARRIVAL TIME FOR PROCESS " << i + 1 << ": ";
        cin >> pro[i].arrTime;
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> pro[i].burstTime;
        cout << endl;
    }
    cout << num << " PROCESSES AND THEIR ARRIVAL TIME AND BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    srtfAvgTime(pro, num);
}

//  main menu
void sjfMenu() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(7, 5);
        cout << "SJF MENU" << endl;
        cout << "1. NON-PRE-EMPTIVE(SJF)" << endl;
        cout << "2. PRE-EMPTIVE(SRTF)" << endl;
        cout << "3. BACK TO PREVIOUS MENU" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            sjfInput();
            break;
        case 2:
            srtfInput();
            break;
        }
    } while (choice != 3);
}
