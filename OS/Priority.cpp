#include <iostream>
#include <algorithm>

using namespace std;

// functions for same same arrival times
struct prioPro {
    int proNo;
    int bt;
    int priority;
};

bool comparison(prioPro a, prioPro b) {
    return (a.priority > b.priority);
}

void prioWtSame(prioPro pri[], int num, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < num; i++) {
        wt[i] = pri[i - 1].bt + wt[i - 1];
    }
}

void prioTatSame(prioPro pri[], int num, int wt[], int tat[]) {
    for (int i = 0; i < num; i++) {
        tat[i] = pri[i].bt + wt[i];
    }
}

void prioAvgSame(prioPro pri[], int num) {
    int wt[num], tat[num], totWt = 0, totTat = 0;
    prioWtSame(pri, num, wt);
    prioTatSame(pri, num, wt, tat);

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
        cout << pri[i].proNo;
        gotoxy(17, 8 + i);
        cout << pri[i].bt;
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

void prioSchedule(prioPro pri[], int num) {
    sort(pri, pri + num, comparison);

    cout<< "ORDER OF EXECUTION OF PROCESSES BASED ON PRIORITY" << endl;
    for (int  i = 0; i < num; i++) {
        cout << pri[i].proNo <<" ";
    }

    prioAvgSame(pri, num);
}

void prioInputSame() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;

    prioPro pri[num];
    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> pri[i].proNo;
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> pri[i].bt;
        cout << "ENTER PRIORITY FOR PROCESS " << i + 1 << ": ";
        cin >> pri[i].priority;
        cout << endl;
    }
    cout << num << " PROCESSES AND THEIR BURST TIME AND PRIORITY NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    prioSchedule(pri, num);
}

// functions for processes with different arrival times
struct priProc {
    int proNo;
    int arrTime;
    int burTime;
    int priority;
};

bool comp(priProc a, priProc b) {
    if(a.arrTime == b.arrTime) {
        return a.priority < b.priority;
    }
    else {
        return a.arrTime < b.arrTime;
    }
}

void prioWt(priProc prio[], int num, int wt[]) {
    int service[50];
    service[0] = prio[0].arrTime;
    wt[0] = 0;
    for(int i = 1; i < num; i++) {
        service[i] = prio[i - 1].burTime + service[i - 1];
        wt[i] = service[i] - prio[i].arrTime;
        if (wt[i] < 0) {
            wt[i]=0;
        }
    }
}

void prioTat(priProc prio[], int num, int tat[], int wt[]) {
    for(int i = 0; i < num; i++) {
        tat[i] = prio[i].burTime + wt[i];
    }
}

void prioAvg(priProc prio[], int num) {
    int wt[num], tat[num], totWt = 0, totTat = 0;
    prioWt(prio, num, wt);
    prioTat(prio, num, tat, wt);

    int startTime[num], endTime[num];
    startTime[0] = prio[0].arrTime;
    endTime[0] = startTime[0] + tat[0];
    for(int i = 1; i < num; i++) {
        startTime[i] = endTime[i - 1];
        endTime[i] = startTime[i] + tat[i] - wt[i];
    }

    gotoxy(0, 5);
    cout << "====================================";
    cout << "===================================";
    gotoxy(1, 6);
    cout << "PROCESSES";
    gotoxy(13, 6);
    cout << "START TIME";
    gotoxy(26, 6);
    cout << "END TIME";
    gotoxy(37, 6);
    cout << "TURN AROUND TIME";
    gotoxy(57, 6);
    cout << "WAITING TIME" << endl;
    cout << "====================================";
    cout << "===================================";
    for (int i = 0; i < num; i++) {
        totWt = totWt + wt[i];
        totTat = totTat + tat[i];
        gotoxy(4, 8 + i);
        cout << prio[i].proNo;
        gotoxy(17, 8 + i);
        cout << startTime[i];
        gotoxy(28, 8 + i);
        cout << endTime[i];
        gotoxy(44, 8 + i);
        cout << tat[i];
        gotoxy(62, 8 + i);
        cout << wt[i] << endl;
        delay(1000);
    }
    cout << "====================================";
    cout << "===================================";
    cout << endl << endl;

    cout << "AVERAGE WAITING TIME = " << (float)totWt / (float)num << endl;
    cout << "AVERAGE TURN AROUND TIME = "<< (float)totTat / (float)num << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void prioInput() {
    system("cls");
    int num;
    cout << "ENTER THE NUMBER OF PROCESSES: ";
    cin >> num;
    cout << endl;

    priProc prio[num];
    for (int i = 0; i < num; i++) {
        cout << "ENTER PROCESS NO: ";
        cin >> prio[i].proNo;
        cout << "ENTER ARRIVAL TIME FOR PROCESS " << i + 1 << ": ";
        cin >> prio[i].arrTime;
        cout << "ENTER BURST TIME FOR PROCESS " << i + 1 << ": ";
        cin >> prio[i].burTime;
        cout << "ENTER PRIORITY FOR PROCESS " << i + 1 << ": ";
        cin >> prio[i].priority;
        cout << endl;
    }
    cout << num << " PROCESSES AND THEIR ARRIVAL TIME, BURST TIME AND PRIORITY NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    system("cls");

    sort(prio, prio + num, comp);
    prioAvg(prio, num);
}

// main menu
void prioMenu() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(0, 5);
        cout << "PRIORITY SCHEDULING MENU" << endl;
        cout << "1. SAME ARRIVAL TIME" << endl;
        cout << "2. DIFFERENT ARRIVAL TIME" << endl;
        cout << "3. BACK TO PREVIOUS MENU" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            prioInputSame();
            break;
        case 2:
            prioInput();
            break;
        }
    } while (choice != 3);
}
