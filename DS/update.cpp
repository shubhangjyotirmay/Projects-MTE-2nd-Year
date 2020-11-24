void changeLength();

void addRoad() {
    system("cls");
    int s, d, l;
    gotoxy(22, 5);
    cout << "ENTER THE CITIES BETWEEN WHICH NEW ROAD HAS TO BE ADDED" << endl;
    gotoxy(38, 7);
    cout << "SOURCE: ";
    cin >> s;
    gotoxy(38, 8);
    cout << "DESTINATION: ";
    cin >> d;
    gotoxy(38, 9);
    cout << "LENGTH OF ROAD: ";
    cin >> l;

    if (s == d) {
        gotoxy(38, 11);
        cout << "CANNOT ADD ROAD BETWEEN " << s << " AND " << d;
        gotoxy(38, 12);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if ((s < 0 || s >= num) && (d < 0 && d >= num)) {
        gotoxy(38, 11);
        cout << "NO SUCH LOCATIONS AS " << s << " end " << d;
        gotoxy(38, 12);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (s < 0 || s >= num) {
        gotoxy(38, 11);
        cout << "NO SUCH LOCATION AS " << s;
        gotoxy(38, 12);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (d < 0 && d >= num) {
        gotoxy(38, 11);
        cout << "NO SUCH LOCATION AS " << d;
        gotoxy(38, 12);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if (road.edges[s][d] != INT_MAX) {
        gotoxy(38, 11);
        cout << "ROAD ALREADY EXISTS BETWEEN " << s << " and " << d;
        char ch;
        gotoxy(38, 12);
        cout << "DID TO MEAN TO UPDATE THE ROAD DEATILS?(y/n): ";
        cin >> ch;
        if (ch == 'y') {
            changeLength();
            return;
        }
        else {
            gotoxy(38, 14);
            cout << "PRESS ENTER TO CONTINUE";
            cin.ignore();
            cin.ignore();
            return;
        }
    }

    road.edges[s][d] = l;
    gotoxy(38, 11);
    cout << "ROAD ADDED SUCCESSFULLY!";
    delay(1000);
    gotoxy(38, 13);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    displayRoads();
}

void deleteRoad() {
    system("cls");
    int s, d;
    gotoxy(26, 5);
    cout << "ENTER THE CITIES BETWEEN WHICH THE ROAD EXISTS";
    gotoxy(38, 7);
    cout << "SOURCE: ";
    cin >> s;
    gotoxy(38, 8);
    cout << "DESTINATION: ";
    cin >> d;
    cout << endl;

    if (s == d) {
        gotoxy(38, 10);
        cout << "ROAD DOES NOT EXIST BETWEEN " << s << " AND " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if ((s < 0 || s >= num) && (d < 0 && d >= num)) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATIONS AS " << s << " end " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (s < 0 || s >= num) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATION AS " << s;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (d < 0 && d >= num) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATION AS " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if (road.edges[s][d] == INT_MAX) {
        gotoxy(38, 10);
        cout << "NO ROAD EXISTS BETWEEN " << s << " and " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    road.edges[s][d] = INT_MAX;
    gotoxy(38, 13);
    cout << "ROAD DELETED SUCCESSFULLY!";
    delay(1000);
    gotoxy(38, 14);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    displayRoads();
}

void changeLength() {
    system("cls");
    int s, d;
    gotoxy(26, 5);
    cout << "ENTER THE CITIES BETWEEN WHICH THE ROAD EXISTS";
    gotoxy(38, 7);
    cout << "SOURCE: ";
    cin >> s;
    gotoxy(38, 8);
    cout << "DESTINATION: ";
    cin >> d;

    if (s == d) {
        gotoxy(38, 10);
        cout << "ROAD DOES NOT EXIST BETWEEN " << s << " AND " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if ((s < 0 || s >= num) && (d < 0 && d >= num)) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATIONS AS " << s << " end " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (s < 0 || s >= num) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATION AS " << s;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }
    else if (d < 0 && d >= num) {
        gotoxy(38, 10);
        cout << "NO SUCH LOCATION AS " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    if(road.edges[s][d] != INT_MAX) {
        gotoxy(38, 10);
        cout << "OLD LENGTH OF ROAD: " << road.edges[s][d] << "KM";
    }
    else {
        gotoxy(38, 10);
        cout << "ROAD DOES NOT EXIST BETWEEN " << s << " AND " << d;
        gotoxy(38, 11);
        cout << "PRESS ENTER TO CONTINUE";
        cin.ignore();
        cin.ignore();
        return;
    }

    int newlength;
    gotoxy(38, 12);
    cout << "ENTER NEW LENGTH OF ROAD: ";
    cin >> newlength;
    road.edges[s][d] = newlength;
    delay(1000);
    gotoxy(38, 13);
    cout << "LENGTH OF ROAD UPDATED SUCCESSFULLY!";
    delay(1000);
    gotoxy(38, 15);
    cout << "PRESS ENTER TO CONTINUE";
    cin.ignore();
    cin.ignore();
    displayRoads();
}
