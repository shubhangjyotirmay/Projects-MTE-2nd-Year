#include <fstream>
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// class definition
class hospital {
    char hospName[20];
    int hospNo;
    int doctor;
    int nurse;
    int othStaff;
    int currPatient;
    bool isMedStore;
    bool genSur;
    bool cardiology;
    bool ENT;
    bool neurology;
    bool orthopedics;
    bool oncology;
    bool physiotherapy;
    bool urology;
public:
    hospital() {
        strcpy(hospName, "NA");
        hospNo = 0;
        doctor = 0;
        nurse = 0;
        othStaff = 0;
        currPatient = 0;
        isMedStore = false;
        genSur = false;
        cardiology = false;
        ENT = false;
        neurology = false;
        orthopedics = false;
        oncology = false;
        physiotherapy = false;
        urology = false;
    }
    void getDataHosp();
    void showDataHosp();
    char* retHospName();
    int retHospNo();
    int retDoctor();
    int retNurse();
    int retOthStaff();
    int retCurrPatient();
    bool retIsMedStore();
    bool retGenSur();
    bool retCard();
    bool retENT();
    bool retNeuro();
    bool retOrtho();
    bool retOnco();
    bool retPhysio();
    bool retUro();
    void changeHospName(char *);
    void changeDoctor(int);
    void changeNurse(int);
    void changeOthStaff(int);
    void changeCurrPatient(int);
    void changeIsMedStore(bool);
    void changeGenSur(bool);
    void changeCard(bool);
    void changeENT(bool);
    void changeNeuro(bool);
    void changeOrtho(bool);
    void changeOnco(bool);
    void changePhysio(bool);
    void changeUro(bool);
};


// function prototypes
void createHosp();   // create new file
void addHosp();      // add data to existing file
void dispHosp();
void modifyHospName();
void modifyDoctor();
void modifyNurse();
void modifyOthStaff();
void modifyCurrPatient();
void modifyIsMed();
void modifyGenSur();
void modifyCard();
void modifyENT();
void modifyNeuro();
void modifyOrtho();
void modifyOnco();
void modifyPhysio();
void modifyUro();
void searchByHName();
void searchByHNo();
void sortByHName();
void sortByHNo();
void sortByDoc();
void sortByNur();
void sortByStaff();
void sortbyPat();
void deleteHosp();
void transferHosp();     //  for delete function
void hospTable();
void hospTableDept();
void menuHosp();
void menuHEnterDisp();
void menuHUpdate();
void menuHSearch();
void menuHSort();

// class function definitions
void hospital::getDataHosp() {
    gotoxy(32, 5);
    cout << "Enter Hospital Name : ";
    getchar();
    fgets(hospName, 20, stdin);
    gotoxy(32, 6);
    cout << "Enter Hospital No : ";
    cin >> hospNo;
    gotoxy(32, 7);
    cout << "Enter Number of Doctors : ";
    cin >> doctor;
    gotoxy(32, 8);
    cout << "Enter Number of Nurses : ";
    cin >> nurse;
    gotoxy(32, 9);
    cout << "Enter Number of other staff : ";
    cin >> othStaff;
    gotoxy(32, 10);
    cout << "Enter Number of current patient : ";
    cin >> currPatient;
    char a;
    gotoxy(32, 11);
    cout << "Is there a medical store nearby?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        isMedStore = true;
    }
    gotoxy(32, 12);
    cout << "Enter Departments : ";
    gotoxy(32, 13);
    cout << "Is there General Surgery?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        genSur = true;
    }
    gotoxy(32, 14);
    cout << "Is there Cardiology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        cardiology = true;
    }
    gotoxy(32, 15);
    cout << "Is there ENT?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        ENT = true;
    }
    gotoxy(32, 16);
    cout << "Is there Neurology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        neurology = true;
    }
    gotoxy(32, 17);
    cout << "Is there Orthopedics?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        orthopedics = true;
    }
    gotoxy(32, 18);
    cout << "Is there Oncology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        oncology = true;
    }
    gotoxy(32, 19);
    cout << "Is there Physiotherapy?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        physiotherapy = true;
    }
    gotoxy(32, 20);
    cout << "Is there Urology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        urology = true;
    }
}

void hospital::showDataHosp() {
    gotoxy(28, 5);
    cout << "details of the hospital are : ";
    gotoxy(28, 6);
    cout << "Name of Hospital : " << hospName;
    gotoxy(28, 7);
    cout << "Hospital No : " << hospNo;
    gotoxy(28, 8);
    cout << "No of doctors : " << doctor;
    gotoxy(28, 9);
    cout << "No of nurses : " << nurse;
    gotoxy(28, 10);
    cout << "No of other staff : " << othStaff;
    gotoxy(28, 11);
    cout << "No of current patients : " << currPatient;
    gotoxy(28, 12);
    cout << "Medical Store nearby : ";
    if (isMedStore == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 13);
    cout << "Departments : ";
    gotoxy(28, 14);
    cout << "General Surgery : ";
    if (genSur == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 15);
    cout << "Cardiology : ";
    if (cardiology == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 16);
    cout << "ENT : ";
    if (ENT == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 17);
    cout << "Neurology : ";
    if (neurology == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 18);
    cout << "Orthopedics : ";
    if (orthopedics == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 19);
    cout << "Oncology : ";
    if (oncology == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 20);
    cout << "Physiotherapy : ";
    if (physiotherapy == true) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    gotoxy(28, 21);
    cout << "Urology : ";
    if (urology == true) {
        cout << "Yes" << endl << endl;
    }
    else {
        cout << "No" << endl << endl;
    }
}

char* hospital::retHospName() {
    return hospName;
}

int hospital::retHospNo() {
    return hospNo;
}

int hospital::retDoctor() {
    return doctor;
}

int hospital::retNurse() {
    return nurse;
}

int hospital::retOthStaff() {
    return othStaff;
}

int hospital::retCurrPatient() {
    return currPatient;
}

bool hospital::retIsMedStore() {
    return isMedStore;
}

bool hospital::retGenSur() {
    return genSur;
}

bool hospital::retCard() {
    return cardiology;
}

bool hospital::retENT() {
    return ENT;
}

bool hospital::retNeuro() {
    return neurology;
}

bool hospital::retOrtho() {
    return orthopedics;
}

bool hospital::retOnco() {
    return oncology;
}

bool hospital::retPhysio() {
    return physiotherapy;
}

bool hospital::retUro() {
    return urology;
}

void hospital::changeHospName(char* newHospName) {
    strcpy(hospName, newHospName);
}

void hospital::changeDoctor(int newDoc) {
    doctor = newDoc;
}

void hospital::changeNurse(int newNur) {
    nurse = newNur;
}

void hospital::changeOthStaff(int newStaff) {
    othStaff = newStaff;
}

void hospital::changeCurrPatient(int newPat) {
    currPatient = newPat;
}

void hospital::changeIsMedStore(bool newIsMed) {
    isMedStore = newIsMed;
}

void hospital::changeGenSur(bool newGen) {
    genSur = newGen;
}

void hospital::changeCard(bool newCard) {
    cardiology = newCard;
}

void hospital::changeENT(bool newENT) {
    ENT = newENT;
}

void hospital::changeNeuro(bool newNeu) {
    neurology = newNeu;
}

void hospital::changeOrtho(bool newOrtho) {
    orthopedics = newOrtho;
}

void hospital::changeOnco(bool newOnco) {
    oncology = newOnco;
}

void hospital::changePhysio(bool newPh) {
    physiotherapy = newPh;
}

void hospital::changeUro(bool newUro) {
    urology = newUro;
}

// functions definition
void createHosp() {
    hospital hosp;
    fstream filout;
    filout.open("hospital.dat", ios::binary | ios::out);
    char ch;
    do {
        system("cls");
        hosp.getDataHosp();
        filout.write((char*)&hosp, sizeof(hosp));
        gotoxy(32, 22);
        cout << "more hospitals?(y/n) : ";
        cin >> ch;
    } while (ch == 'y');
    filout.close();
    gotoxy(32, 24);
    cout << "file hospital.dat created!";
    gotoxy(32, 25);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void addHosp() {
    fstream fil;
    hospital hosp;
    fil.open("hospital.dat", ios::binary | ios::app);
    char ch;
    do {
        system("cls");
        hosp.getDataHosp();
        fil.write((char*)&hosp, sizeof(hosp));
        gotoxy(32, 22);
        cout << "more hospitals?(y/n) : ";
        cin >> ch;
    } while (ch == 'y');
    fil.close();
    gotoxy(32, 24);
    cout << "New hospitals successfully added!";
    gotoxy(32, 25);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void dispHosp() {
    hospital hosp;
    fstream filin;
    filin.open("hospital.dat", ios::binary | ios::in);
    cout << "List of Hospitals : " << endl;
    while (filin.read((char*)&hosp, sizeof(hosp))) {
        system("cls");
        hosp.showDataHosp();
        delay(2000);
        cout << "Press Enter to continue" << endl;
        cin.ignore();
        cin.ignore();
    }
    filin.close();
}

void modifyHospName() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newHospName[20];
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(35, 7);
            cout << "Old Name : " << hosp.retHospName();
            gotoxy(35, 8);
            cout << "Enter new name of the hospital : ";
            getchar();
            fgets(newHospName, 20, stdin);
            gotoxy(35, 10);
            cout << "record is being updated...";
            hosp.changeHospName(newHospName);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(35, 12);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(35, 7);
        cout << "Hospital not found!";
    }
    gotoxy(35, 14);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyDoctor() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id, newDoc;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(35, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(35, 8);
            cout << "Old No of Doctors : " << hosp.retDoctor();
            gotoxy(35, 9);
            cout << "Enter new No of Doctors : ";
            cin >> newDoc;
            gotoxy(35, 11);
            cout << "record is being updated...";
            hosp.changeDoctor(newDoc);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(35, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(35, 7);
        cout << "Hospital not found!";
    }
    gotoxy(35, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyNurse() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id, newNur;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(35, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(35, 8);
            cout << "Old No of Nurses : " << hosp.retNurse();
            gotoxy(35, 9);
            cout << "Enter new No of Nurses : ";
            cin >> newNur;
            gotoxy(35, 11);
            cout << "record is being updated...";
            hosp.changeNurse(newNur);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(35, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(35, 7);
        cout << "Hospital not found!";
    }
    gotoxy(35, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyOthStaff() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id, newStaff;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(35, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(35, 8);
            cout << "Old No of staff : " << hosp.retOthStaff();
            gotoxy(35, 9);
            cout << "Enter new No of Doctors : ";
            cin >> newStaff;
            gotoxy(35, 11);
            cout << "record is being updated...";
            hosp.changeOthStaff(newStaff);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(35, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(35, 7);
        cout << "Hospital not found!";
    }
    gotoxy(35, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyCurrPatient() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id, newPat;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(35, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(35, 8);
            cout << "Old No of Patients : " << hosp.retCurrPatient();
            gotoxy(35, 9);
            cout << "Enter new No of Patients : ";
            cin >> newPat;
            gotoxy(35, 11);
            cout << "record is being updated...";
            hosp.changeCurrPatient(newPat);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(35, 13);
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(35, 7);
        cout << "Hospital not found!";
    }
    gotoxy(35, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyIsMed() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newIsMed;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a medical store nearby? : ";
            if (hosp.retIsMedStore() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a medical store nearby now?(y/n) : ";
            cin >> newIsMed;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newIsMed == 'y') {
                hosp.changeIsMedStore(true);
            }
            else {
                hosp.changeIsMedStore(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyGenSur() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newGen;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a General Surgery Department? : ";
            if (hosp.retIsMedStore() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a General Surgery Department now?(y/n) : ";
            cin >> newGen;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newGen == 'y') {
                hosp.changeGenSur(true);
            }
            else {
                hosp.changeGenSur(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyCard() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newCard;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Cardiology Department? : ";
            if (hosp.retCard() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Cardiology Department now?(y/n) : ";
            cin >> newCard;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newCard == 'y') {
                hosp.changeCard(true);
            }
            else {
                hosp.changeCard(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyENT() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newENT;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a ENT Department? : ";
            if (hosp.retENT() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a ENT Department now?(y/n) : ";
            cin >> newENT;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newENT == 'y') {
                hosp.changeENT(true);
            }
            else {
                hosp.changeENT(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyNeuro() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newNeu;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Neurology Department? : ";
            if (hosp.retNeuro() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Neurology Department now?(y/n) : ";
            cin >> newNeu;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newNeu == 'y') {
                hosp.changeNeuro(true);
            }
            else {
                hosp.changeNeuro(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyOrtho() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newOrtho;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Orthopedics Department? : ";
            if (hosp.retOrtho() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Orthopedics Department now?(y/n) : ";
            cin >> newOrtho;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newOrtho == 'y') {
                hosp.changeOrtho(true);
            }
            else {
                hosp.changeOrtho(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyOnco() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newOnco;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Oncology Department? : ";
            if (hosp.retOnco() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Oncology Department now?(y/n) : ";
            cin >> newOnco;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newOnco == 'y') {
                hosp.changeOnco(true);
            }
            else {
                hosp.changeOnco(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyPhysio() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newPhy;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Physiology Department? : ";
            if (hosp.retPhysio() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Physiology Department now?(y/n) : ";
            cin >> newPhy;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newPhy == 'y') {
                hosp.changePhysio(true);
            }
            else {
                hosp.changePhysio(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyUro() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newUro;
    gotoxy(22, 5);
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            gotoxy(22, 7);
            cout << "Hospital Name : " << hosp.retHospName();
            gotoxy(22, 8);
            cout << "Before if there was a Urology Department? : ";
            if (hosp.retUro() == true) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
            gotoxy(22, 9);
            cout << "Is there a Urology Department now?(y/n) : ";
            cin >> newUro;
            gotoxy(22, 11);
            cout << "record is being updated...";
            if (newUro == 'y') {
                hosp.changeUro(true);
            }
            else {
                hosp.changeUro(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            delay(1000);
            gotoxy(22, 13);
            cout << "record updated!";
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        gotoxy(22, 7);
        cout << "Hospital not found!";
    }
    gotoxy(22, 15);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void searchByHName() {
    fstream fil;
    hospital hosp;
    char s[20];
    int flag = 0;
    fil.open("hospital.dat", ios::binary | ios::in);
    gotoxy(33, 3);
    cout << "Enter name of hospital : ";
    getchar();
    fgets(s, 20, stdin);
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (strcmpi(hosp.retHospName(), s) == 0) {
            hosp.showDataHosp();
            flag++;
            break;
        }
    }
    if (flag == 0) {
        gotoxy(33, 5);
        cout << "Hospital not found";
    }
    fil.close();
    gotoxy(33, 23);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void searchByHNo() {
    fstream fil;
    hospital hosp;
    int temp;
    int flag = 0;
    fil.open("hospital.dat", ios::binary | ios::in);
    gotoxy(35, 3);
    cout << "Enter hospital No : ";
    cin >> temp;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == temp) {
            hosp.showDataHosp();
            flag++;
            break;
        }
    }
    if (flag == 0) {
        gotoxy(35, 5);
        cout << "Hospital not found";
    }
    fil.close();
    gotoxy(35, 23);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void sortByHName() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (strcmpi(hosp1.retHospName(), hosp2.retHospName()) > 0) {
                fil.seekp(j * sizeof(hospital));
                fil.write((char*)&hosp2, sizeof(hosp2));
                fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void sortByHNo() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (hosp1.retHospNo() > hosp2.retHospNo()) {
                fil.seekp(j * sizeof(hospital));
                    fil.write((char*)&hosp2, sizeof(hosp2));
                    fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void sortByDoc() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (hosp1.retDoctor() > hosp2.retDoctor()) {
                fil.seekp(j * sizeof(hospital));
                    fil.write((char*)&hosp2, sizeof(hosp2));
                    fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void sortByNur() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (hosp1.retNurse() > hosp2.retNurse()) {
                fil.seekp(j * sizeof(hospital));
                    fil.write((char*)&hosp2, sizeof(hosp2));
                    fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void sortByStaff() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (hosp1.retOthStaff() > hosp2.retOthStaff()) {
                fil.seekp(j * sizeof(hospital));
                    fil.write((char*)&hosp2, sizeof(hosp2));
                    fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void sortbyPat() {
    fstream fil;
    hospital hosp1, hosp2;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    fil.seekg(0, ios::end);
    int NOR = fil.tellg() / sizeof(hospital);
    for (int i = 0; i < NOR - 1; i++) {
        for (int j = 0; j < NOR - i - 1; j++) {
            fil.seekg(j * sizeof(hospital));
            fil.read((char*)&hosp1, sizeof(hosp1));
            fil.read((char*)&hosp2, sizeof(hosp2));
            if (hosp1.retCurrPatient() > hosp2.retCurrPatient()) {
                fil.seekp(j * sizeof(hospital));
                    fil.write((char*)&hosp2, sizeof(hosp2));
                    fil.write((char*)&hosp1, sizeof(hosp1));
            }
        }
    }
    fil.close();
    gotoxy(43, 2);
    cout << "SORTING DONE" << endl;
    delay(800);
    gotoxy(43, 4);
    cout << "SORTED LIST: " << endl;
    delay(1000);
    hospTable();
}

void deleteHosp() {
    fstream fil1, fil2;
    hospital hosp;
    int flag = 0;
    fil1.open("hospital.dat", ios::binary | ios::in);
    fil2.open("deleteH.dat", ios::binary | ios::out);
    int id;
    gotoxy(20, 5);
    cout << "Enter Hospital No of hospital which has to be deleted : ";
    cin >> id;
    while (fil1.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() != id) {
            fil2.write((char*)&hosp, sizeof(hosp));
        }
        else {
            flag++;
        }
    }
    fil1.close();
    fil2.close();
    if (flag == 0) {
        gotoxy(20, 7);
        cout << "record not found!";
    }
    else {
        transferHosp();
        gotoxy(20, 7);
        cout << "record is being deleted...";
        delay(1000);
        gotoxy(20, 9);
        cout << "Hospital removed!";
    }
    gotoxy(20, 11);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void transferHosp() {
    fstream fil, filT;
    hospital hosp;
    fil.open("deleteH.dat", ios::binary | ios::in);
    filT.open("hospital.dat", ios::binary | ios::out);
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        filT.write((char*)&hosp, sizeof(hosp));
    }
    fil.close();
    filT.close();
}

void hospTable() {
    system("cls");
    hospital hosp;
    ifstream fil;
    fil.open("hospital.dat", ios::binary);
    gotoxy(40, 6);
    cout << "List Of Hospitals";
    gotoxy(7, 7);
    cout << "=========================================";
    cout << "========================================";
    gotoxy(8, 8);
    cout << "HOSP ID";
    gotoxy(16, 8);
    cout << "HOSP NAME";
    gotoxy(30, 8);
    cout << "DOCTORS";
    gotoxy(39, 8);
    cout << "NURSES";
    gotoxy(47, 8);
    cout << "OTHER STAFF";
    gotoxy(60, 8);
    cout << "CURR PATIENTS";
    gotoxy(75, 8);
    cout << "MEDICAL STORE";
    gotoxy(7, 9);
    cout << "=========================================";
    cout << "========================================";
    int j = 0;
    while (fil.read((char*)&hosp,sizeof(hosp))) {
        gotoxy(8, (j + 10));
        cout << hosp.retHospNo();
        gotoxy(16, (j + 10));
        cout << hosp.retHospName();
        gotoxy(30, (j + 10));
        cout << hosp.retDoctor();
        gotoxy(39, (j + 10));
        cout << hosp.retNurse();
        gotoxy(47, (j + 10));
        cout << hosp.retOthStaff();
        gotoxy(60, (j + 10));
        cout << hosp.retCurrPatient();
        gotoxy(75, (j + 10));
        if (hosp.retIsMedStore() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        j++;
    }
    gotoxy(7, 10 + j);
    cout << "========================================";
    cout << "========================================";
    cout << endl << endl;
    delay(1500);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
    hospTableDept();
}

void hospTableDept() {
    int j;
    system("cls");
    hospital hosp;
    ifstream fil;
    fil.open("hospital.dat", ios::binary);
    gotoxy(40, 6);
    cout << "List Of Hospitals";
    gotoxy(2, 7);
    cout << "=================================================";
    cout << "================================================";
    gotoxy(3, 8);
    cout << "HOSP ID";
    gotoxy(11, 8);
    cout << "HOSP NAME";
    gotoxy(25, 8);
    cout << "GEN SURGERY";
    gotoxy(38, 8);
    cout << "CARDIOLOGY";
    gotoxy(50, 8);
    cout << "ENT";
    gotoxy(55, 8);
    cout << "NEUROLOGY";
    gotoxy(66, 8);
    cout << "ORTHO";
    gotoxy(73, 8);
    cout << "ONCOLOGY";
    gotoxy(83, 8);
    cout << "PHYSIO";
    gotoxy(91, 8);
    cout << "UROLOGY";
    gotoxy(2, 9);
    cout << "=================================================";
    cout << "================================================";
    j = 0;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        gotoxy(3, (j + 10));
        cout << hosp.retHospNo();
        gotoxy(11, (j + 10));
        cout << hosp.retHospName();
        gotoxy(25, (j + 10));
        if (hosp.retGenSur() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(38, (j + 10));
        if (hosp.retCard() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(50, (j + 10));
        if (hosp.retENT() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(55, (j + 10));
        if (hosp.retNeuro() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(66, (j + 10));
        if (hosp.retOrtho() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(73, (j + 10));
        if (hosp.retOnco() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(83, (j + 10));
        if (hosp.retPhysio() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(91, (j + 10));
        if (hosp.retUro() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        j++;
    }
    gotoxy(2, 10 + j);
    cout << "=================================================";
    cout << "================================================";
    cout << endl << endl;
    fil.close();
    delay(1500);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void menuHosp() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(42, 5);
        cout << "HOSPITAL MENU";
        gotoxy(38, 7);
        cout << "1. ENTER/DISPLAY MENU";
        gotoxy(38, 8);
        cout << "2. UPDATE MENU";
        gotoxy(38, 9);
        cout << "3. SEARCH MENU";
        gotoxy(38, 10);
        cout << "4. SORT MENU";
        gotoxy(38, 11);
        cout << "5. BACK TO MAIN MENU";
        gotoxy(38, 12);
        cout << "6. EXIT FROM PROGRAM";
        gotoxy(38, 14);
        cout << "Select The Menu: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            menuHEnterDisp();
            break;
        case 2:
            menuHUpdate();
            break;
        case 3:
            menuHSearch();
            break;
        case 4:
            menuHSort();
            break;
        case 6:
            exit(0);
            break;
        }
    } while (choice != 5);
}

void menuHEnterDisp() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(40, 5);
        cout << "ENTER/DISPLAY MENU";
        gotoxy(36, 7);
        cout << "1. CREATE NEW FILE";
        gotoxy(36, 8);
        cout << "2. ADD DATA TO EXISTING FILE";
        gotoxy(36, 9);
        cout << "3. DISPLAY FILE";
        gotoxy(36, 10);
        cout << "4. DISPLAY IN TABULAR FORM";
        gotoxy(36, 11);
        cout << "5. BACK TO MAIN MENU";
        gotoxy(36, 13);
        cout << "Select The Menu: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            createHosp();
            break;
        case 2:
            addHosp();
            break;
        case 3:
            dispHosp();
            break;
        case 4:
            hospTable();
            break;
        }
    } while (choice != 5);
}

void menuHUpdate() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(44, 5);
        cout << "UPDATE MENU";
        gotoxy(20, 7);
        cout << "1. REMOVE A HOSPITAL FROM LIST";
        gotoxy(20, 8);
        cout << "2. CHANGE HOSPITAL NAME";
        gotoxy(20, 9);
        cout << "3. CHANGE DOCTOR COUNT IN A HOSPITAL";
        gotoxy(20, 10);
        cout << "4. CHANGE NURSE COUNT IN A HOSPITAL";
        gotoxy(20, 11);
        cout << "5. CHANGE STAFF COUNT IN A HOSPITAL";
        gotoxy(20, 12);
        cout << "6. CHANGE PATIENT COUNT IN A HOSPITAL";
        gotoxy(20, 13);
        cout << "7. CHANGE MEDICAL STORE AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 14);
        cout << "8. CHANGE GENERAL SURGERY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 15);
        cout << "9. CHANGE CARDIOLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 16);
        cout << "10. CHANGE ENT DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 17);
        cout << "11. CHANGE NEUROLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 18);
        cout << "12. CHANGE ORTHOPEDICS DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 19);
        cout << "13. CHANGE ONCOLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 20);
        cout << "14. CHANGE PHYSIOTHERAPY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 21);
        cout << "15. CHANGE UROLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL";
        gotoxy(20, 22);
        cout << "16. BACK TO MAIN MENU";
        gotoxy(20, 24);
        cout << "Select The Menu: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            deleteHosp();
            break;
        case 2:
            modifyHospName();
            break;
        case 3:
            modifyDoctor();
            break;
        case 4:
            modifyNurse();
            break;
        case 5:
            modifyOthStaff();
            break;
        case 6:
            modifyCurrPatient();
            break;
        case 7:
            modifyIsMed();
            break;
        case 8:
            modifyGenSur();
            break;
        case 9:
            modifyCard();
            break;
        case 10:
            modifyENT();
            break;
        case 11:
            modifyNeuro();
            break;
        case 12:
            modifyOrtho();
            break;
        case 13:
            modifyOnco();
            break;
        case 14:
            modifyPhysio();
            break;
        case 15:
            modifyUro();
            break;
        }
    } while (choice != 16);
}

void menuHSearch() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(44, 5);
        cout << "SEARCH MENU";
        gotoxy(37, 7);
        cout << "1. SEARCH BY HOSPITAL ID";
        gotoxy(37, 8);
        cout << "2. SEARCH BY HOSPITAL NAME";
        gotoxy(37, 9);
        cout << "3. BACK TO MAIN MENU";
        gotoxy(37, 11);
        cout << "Select The Menu: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            searchByHNo();
            break;
        case 2:
            searchByHName();
            break;
        }
    } while (choice != 3);
}

void menuHSort() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(45, 5);
        cout << "SORT MENU";
        gotoxy(38, 7);
        cout << "1. SORT BY HOSPITAL NAME";
        gotoxy(38, 8);
        cout << "2. SORT BY HOSPITAL ID";
        gotoxy(38, 9);
        cout << "3. SORT BY DOCTOR COUNT";
        gotoxy(38, 10);
        cout << "4. SORT BY NURSE COUNT";
        gotoxy(38, 11);
        cout << "5. SORT BY STAFF COUNT";
        gotoxy(38, 12);
        cout << "6. SORT BY PATIENT COUNT";
        gotoxy(38, 13);
        cout << "7. BACK TO MAIN MENU";
        gotoxy(38, 15);
        cout << "NOTE: ALL THE MENUS WILL SORT IN ASCENDING ORDER";
        gotoxy(38, 17);
        cout << "Select The Menu: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            sortByHName();
            break;
        case 2:
            sortByHNo();
            break;
        case 3:
            sortByDoc();
            break;
        case 4:
            sortByNur();
            break;
        case 5:
            sortByStaff();
            break;
        case 6:
            sortbyPat();
            break;
        }
    } while (choice != 7);
}
