#include <queue>
#include <vector>
#include <iomanip>

//  ALL PATHS
void printAllPath(vector<int> &path) {
    cout << endl;
    cout << "\t\t\t" << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << " -> " << path[i];
    }
    cout << endl;
}

bool visitCheck(int x, vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == x) {
            return false;
        }
    }
    return true;
}

void allPaths() {
    system("cls");
    int s, d;
    gotoxy(38, 5);
    cout << "ENTER THE SOURCE: ";
    cin >> s;
    gotoxy(38, 6);
    cout << "ENTER THE DESTINATION: ";
    cin >> d;
    gotoxy(30, 8);
    cout << "ALL PATHS FROM " << s << " to " << d << " ARE:" << endl << endl;

    queue<vector<int>> q;
    vector<int> path;
    path.push_back(s);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];

        if (last == d) {
            printAllPath(path);
        }

        for (int i = 0; i < road.v; i++) {
            if (road.edges[last][i] != INT_MAX) {
                if (visitCheck(i, path) == true) {
                    vector<int> newPath(path);
                    newPath.push_back(i);
                    q.push(newPath);
                }
            }
        }
    }
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

//  SHORTEST PATH
int minDist(int shortDist[], bool visited[]) {
    int temp = INT_MAX, minInd;
    for (int i = 0; i < road.v; i++) {
        if (visited[i] == false && shortDist[i] <= temp) {
            temp = shortDist[i];
            minInd = i;
        }
    }
    return minInd;
}

void printHelper(int path[], int i) {
    if (path[i] == -1) {
        return;
    }
    printHelper(path, path[i]);
    cout << i << " ";
}

void printPath(int shortDist[], int path[], int s) {
    cout << "\t\t\t" << "SHORTEST PATH FROM " << s << " TO ALL OTHER POINT IS : " << endl;
    for (int i = 0; i < road.v; i++) {
        if ((i != s) && (shortDist[i] != INT_MAX) && (shortDist[i] != 0)) {
            cout << endl;
            cout << "\t\t\t" << s << " -> " << i << "    " << shortDist[i] << "KM" << "        " << s << " ";
            printHelper(path, i);
        }
        else if ((i != s) && (shortDist[i] == INT_MAX)) {
            cout << endl;
            cout << "\t\t\t" << s << " -> " << i << "    " << "NO PATH";
        }
        else if ((i != s) && (shortDist[i] == 0)) {
            cout << endl;
            cout << "\t\t\t" << s << " -> " << i << "    " << "NO PATH";
        }
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

void printOnePath(int shortDist[], int path[], int s, int d) {
    cout << "\t\t\t" << "SHORTEST PATH BETWEEN " << s << " AND " << d << " IS : " << endl << endl;

    if (shortDist[d] != INT_MAX) {
        cout << "\t\t\t" << s << " -> " << d << "    " << shortDist[d] << "KM" << "        " << s << " ";
        printHelper(path, d);
    }
    else {
        cout << "\t\t\t" << "NO PATH!";
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

// FOR TIME CALCULATION
void printTime(int shortDist[], int path[], int s, float tim[]) {
    cout << "\t\t";
    cout << "TIME TAKEN(TAKING AVG SPEED 30KM/HR) TO TRAVEL FROM " << s << " TO ALL OTHER POINT IS : " << endl;
    for (int i = 0; i < road.v; i++) {
        if ((i != s) && (shortDist[i] != INT_MAX) && (shortDist[i] != 0)) {
            cout << endl;
            cout << "\t\t";
            cout << s << " -> " << i << "   " << shortDist[i] << "KM" << "   " << fixed << setprecision(2) << tim[i] << "HRS" << "        " << s << " ";
            printHelper(path, i);
        }
        else if ((i != s) && (shortDist[i] == INT_MAX)) {
            cout << endl;
            cout << "\t\t" << s << " -> " << i << "    " << "NO PATH";
        }
        else if ((i != s) && (shortDist[i] == 0)) {
            cout << endl;
            cout << "\t\t" << s << " -> " << i << "    " << "NO PATH";
        }
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

void printOneTime(int shortDist[], int path[], int s, int d, float tim[]) {
    cout << "\t\t";
    cout << "TIME TAKEN(TAKING AVG SPEED 30KM/HR) TO TRAVEL BETWEEN " << s << " AND " << d << " IS : " << endl << endl;

    if (shortDist[d] != INT_MAX) {
        cout << "\t\t";
        cout << s << " -> " << d << "   " << shortDist[d] << "KM" << "   " << fixed << setprecision(2) << tim[d] << "HRS" <<  "        " << s << " ";
        printHelper(path, d);
    }
    else {
        cout << "\t\t" << "NO PATH!";
    }
    cout << endl << endl;
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
}

void dijkstra(int k) {
    system("cls");
    int s, d;
    if (k == 7) {
        cout << endl << endl << endl << endl << endl;
        cout << "\t\t\t" << "ENTER CITIES TO FIND THE SHORTEST PATH" << endl;
        cout << "\t\t\t" << "SOURCE : ";
        cin >> s;
        cout << "\t\t\t" << "DESTINATION : ";
        cin >> d;
    }
    else if (k == 8) {
        cout << endl << endl << endl << endl << endl;
        cout << "\t\t\t" << "ENTER STARTING CITY : ";
        cin >> s;
    }
    else if (k == 9) {
        cout << endl << endl << endl << endl << endl;
        cout << "\t\t\t" << "ENTER CITIES TO FIND THE TIME TAKEN FOR SHORTEST PATH" << endl;
        cout << "\t\t\t" << "SOURCE : ";
        cin >> s;
        cout << "\t\t\t" << "DESTINATION : ";
        cin >> d;
    }
    else {
        cout << endl << endl << endl << endl << endl;
        cout << "\t\t\t" << "ENTER STARTING CITY : ";
        cin >> s;
    }

    int shortDist[road.v], path[road.v];
    bool visited[road.v];
    float tim[road.v];
    for (int i = 0; i < road.v; i++) {
        visited[i] = false;
        path[i] = -1;
        shortDist[i] = INT_MAX;
        tim[i] = INT_MAX;
    }
    shortDist[s] = 0;
    tim[s] = 0;

    for (int i = 0; i < road.v - 1; i++) {
        int x = minDist(shortDist, visited);
        visited[x] = true;

        for (int j = 0; j < road.v; j++) {
            if ((visited[j] == false) && (road.edges[x][j] != INT_MAX) &&(shortDist[x] + road.edges[x][j] < shortDist[j])) {
                    path[j] = x;
                    shortDist[j] = shortDist[x] + road.edges[x][j];
                    tim[j] = shortDist[j] / speed;
            }
        }
    }

    if (k == 7) {
        printOnePath(shortDist, path, s, d);
    }
    else if (k == 8) {
        printPath(shortDist, path, s);
    }
    else if (k == 9) {
        printOneTime(shortDist, path, s, d, tim);
    }
    else {
        printTime(shortDist, path, s, tim);
    }
}
