#include <iostream>

using namespace std;

class graphMat {
public:
    int v;
    int **edges;

    graphMat(int n) {
        v = n;
        edges = new int*[n];
        for (int i = 0; i < v; i++) {
            edges[i] = new int[v];
            for (int j = 0; j < v; j++) {
                edges[i][j] = INT_MAX;
            }
        }
    }

    ~graphMat() {
        for (int i = 0; i < v; i++) {
            delete [] edges[i];
        }
        delete [] edges;
    }
};
const int num = 4;
graphMat road(num);
const int speed = 30;

void inputRoads() {
    system("cls");
    gotoxy(30, 5);
    cout << "START ENTERING THE DETAILS OF THE ROADS" << endl << endl;
    delay(1000);
    int maxEdge = num * (num - 1), length, source, dest;
    char choice;
    do {
        gotoxy(40, 7);
        cout << "ENTER THE SOURCE : ";
        cin >> source;
        gotoxy(40, 8);
        cout << "ENTER THE DESTINATION: ";
        cin >> dest;
        if (source == dest) {
            gotoxy(40, 9);
            cout << "WRONG INPUT";
        }
        else if (source < 0 || source >= num || dest < 0 || dest >= num) {
            gotoxy(40, 9);
            cout << "WRONG INPUT";
        }
        else {
            gotoxy(40, 9);
            cout << "ENTER LENGTH OF ROAD: ";
            cin >> length;
            gotoxy(40, 10);
            cout << "DATA OF ROAD ADDED!";
            road.edges[source][dest] = length;
            maxEdge--;
        }
        if (maxEdge != 0) {
            gotoxy(40, 12);
            cout << "ENTER MORE ROADS?(y/n): ";
            cin >> choice;
        }
        system("cls");
    } while (choice == 'y' && maxEdge > 0);

    delay(1000);
    gotoxy(40, 7);
    cout << "DATA OF ALL THE ROADS ADDED!";
    gotoxy(40, 9);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

void displayRoads() {
    system("cls");
    gotoxy(32, 3);
    cout << "DETAILS OF ALL ROADS ARE AS FOLLOWS";
    gotoxy(32, 5);
    cout << "==================";
    cout << "=================";
    gotoxy(35, 6);
    cout << "SOURCE";
    gotoxy(44, 6);
    cout << "DESTINATION";
    gotoxy(58, 6);
    cout << "LENGTH(KM)";
    gotoxy(32, 7);
    cout << "==================";
    cout << "=================";
    int k = 0;
    for (int i = 0; i < road.v; i++) {
        for (int j = 0; j < road.v; j++) {
            if (i == j) {
                continue;
            }
            if (road.edges[i][j] != INT_MAX) {
                gotoxy(37, 8 + k);
                cout << i;
                gotoxy(49, 8 + k);
                cout << j;
                gotoxy(60, 8 + k);
                cout << road.edges[i][j];
                k++;
            }
            else {
                gotoxy(37, 8 + k);
                cout << i;
                gotoxy(49, 8 + k);
                cout << j;
                gotoxy(60, 8 + k);
                cout << "-";
                k++;
            }
        }
    }
    gotoxy(32, 8 + k);
    cout << "===================";
    cout << "==================";
    delay(1000);
    gotoxy(34, 10 + k);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}
