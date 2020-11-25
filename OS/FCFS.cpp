#include <iostream>
#include <vector>

using namespace std;

// functions for same same arrival times
void waitTimeSame(vector<int> &processS, vector<int> &burstTimeS, vector<int> &waitTimeS) {
    waitTimeS.push_back(0);
    int temp;

    for (int i = 1; i < processS.size(); i++) {
        temp = burstTimeS[i - 1] + waitTimeS[i - 1];
        waitTimeS.push_back(temp);
    }
}

void turnArTimeSame(vector<int> &processS, vector<int> &burstTimeS, vector<int> &waitTimeS, vector<int> &turnArTimeS) {
    int temp;
    for (int i = 0; i < processS.size(); i++) {
        temp = burstTimeS[i] + waitTimeS[i];
        turnArTimeS.push_back(temp);
    }
}

void avgTimeSame(vector<int> &processS, vector<int> &burstTimeS) {
    system("cls");
    vector<int> waitTimeS;
    vector<int> turnArTimeS;
    int totWaitTimS = 0, totTurnArTimS = 0;

    waitTimeSame(processS, burstTimeS, waitTimeS);
    turnArTimeSame(processS, burstTimeS, waitTimeS, turnArTimeS);

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
    for (int i = 0; i < processS.size(); i++) {
        totWaitTimS = totWaitTimS + waitTimeS[i];
        totTurnArTimS = totTurnArTimS + turnArTimeS[i];
        gotoxy(4, 8 + i);
        cout << i + 1;
        gotoxy(17, 8 + i);
        cout << burstTimeS[i];
        gotoxy(31, 8 + i);
        cout << waitTimeS[i];
        gotoxy(48, 8 + i);
        cout << turnArTimeS[i] << endl;
        delay(1000);
    }
    cout << "==============================";
    cout << "==============================";
    cout << endl << endl;

    cout << "AVERAGE WAITING TIME = " << (float)totWaitTimS / (float)(processS.size()) << endl;
    cout << "AVERAGE TURN AROUND TIME = " << (float)totTurnArTimS / (float)(processS.size()) << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void fcfsInputSame() {
    vector<int> processS;
    vector<int> burstTimeS;
    char choice;
    int proNo, btNo;

    cout << "IN THIS PROGRAM WE HAVE ASSUMED ARRIVAL TIMES AS 0 FOR ALL PROCESSES." << endl;
    cout << "THEREFORE TURNAROUND AND COMPLETION TIMES ARE SAME." << endl << endl;

    do {
        cout << "ENTER PROCESS NUMBER: ";
        cin >> proNo;
        cout << "ENTER BURST TIME FOR PROCESS " << proNo << ": ";
        cin >> btNo;
        processS.push_back(proNo);
        burstTimeS.push_back(btNo);
        cout << "ENTER MORE PROCESSES?(y/n) : ";
        cin >> choice;
    } while (choice == 'y');

    cout << processS.size() << " PROCESSES AND THEIR BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();

    avgTimeSame(processS, burstTimeS);
}

// functions for processes with different arrival times
void waitTime(vector<int> &process, vector<int> &arrTime, vector<int> &burstTime, vector<int> &wtTime) {
    vector<int> serviceTime;
    serviceTime.push_back(0);
    wtTime.push_back(0);

    int tempSer, tempWait;
    for (int i = 1; i < process.size(); i++) {
        tempSer = serviceTime[i - 1] + burstTime[i - 1];
        serviceTime.push_back(tempSer);
        tempWait = serviceTime[i] - arrTime[i];
        wtTime.push_back(tempWait);

        if (wtTime[i] < 0) {
            wtTime[i] = 0;
        }
    }
}

void turnArTime(vector<int> &process, vector<int> &burstTime, vector<int> &wtTime, vector<int> &tatTime) {
    int temp;
    for (int i = 0; i < process.size(); i++) {
        temp = burstTime[i] + wtTime[i];
        tatTime.push_back(temp);
    }
}

void avgTime(vector<int> &process, vector<int> &arrTime, vector<int> &burstTime) {
    system("cls");
    vector<int> wtTime;
    vector<int> tatTime;

    waitTime(process, arrTime, burstTime, wtTime);
    turnArTime(process, burstTime, wtTime, tatTime);

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
    int totWait = 0, totTat = 0;
    for (int i = 0; i < process.size(); i++) {
        totWait = totWait + wtTime[i];
        totTat = totTat + tatTime[i];
        int compTime = tatTime[i] + arrTime[i];
        gotoxy(4, 8 + i);
        cout << i + 1;
        gotoxy(17, 8 + i);
        cout << burstTime[i];
        gotoxy(31, 8 + i);
        cout << arrTime[i];
        gotoxy(46, 8 + i);
        cout << wtTime[i];
        gotoxy(63, 8 + i);
        cout << tatTime[i];
        gotoxy(82, 8 + i);
        cout << compTime << endl;
        delay(1000);
    }
    cout << "==============================================";
    cout << "==============================================";
    cout << endl << endl;

    cout << "AVERAGE WAITING TIME = " << (float)totWait / (float)(process.size()) << endl;
    cout << "AVERAGE TURN AROUND TIME = "<< (float)totTat / (float)(process.size()) << endl << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
}

void fcfsInput() {
    vector<int> process;
    vector<int> arrTime;
    vector<int> burstTime;
    char choice;
    int proNo, arrNo, btNo;

    do {
        cout << "ENTER PROCESS NUMBER: ";
        cin >> proNo;
        cout << "ENTER ARRIVAL TIME FOR PROCESS " << proNo << ": ";
        cin >> arrNo;
        cout << "ENTER BURST TIME FOR PROCESS " << proNo << ": ";
        cin >> btNo;
        process.push_back(proNo);
        arrTime.push_back(arrNo);
        burstTime.push_back(btNo);
        cout << "ENTER MORE PROCESSES?(y/n) : ";
        cin >> choice;
    } while (choice == 'y');

    cout << process.size() << " PROCESSES AND THEIR ARRIVAL TIME AND BURST TIME NOTED!" << endl;
    delay(1000);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();

    avgTime(process, arrTime, burstTime);
}

// main menu
void fcfsMenu() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(7, 5);
        cout << "FCFS MENU" << endl;
        cout << "1. SAME ARRIVAL TIME" << endl;
        cout << "2. DIFFERENT ARRIVAL TIME" << endl;
        cout << "3. BACK TO PREVIOUS MENU" << endl;
        cout << "ENTER CHOICE: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            fcfsInputSame();
            break;
        case 2:
            fcfsInput();
            break;
        }
    } while (choice != 3);
}
