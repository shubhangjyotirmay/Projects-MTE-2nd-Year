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
    cout << "Enter Hospital Name : ";
    getchar();
    fgets(hospName, 20, stdin);
    cout << "Enter Hospital No : ";
    cin >> hospNo;
    cout << "Enter Number of Doctors : ";
    cin >> doctor;
    cout << "Enter Number of Nurses : ";
    cin >> nurse;
    cout << "Enter Number of other staff : ";
    cin >> othStaff;
    cout << "Enter Number of current patient : ";
    cin >> currPatient;
    char a;
    cout << "Is there a medical store nearby?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        isMedStore = true;
    }
    cout << "Enter Departments : " << endl;
    cout << "Is there General Surgery?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        genSur = true;
    }
    cout << "Is there Cardiology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        cardiology = true;
    }
    cout << "Is there ENT?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        ENT = true;
    }
    cout << "Is there Neurology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        neurology = true;
    }
    cout << "Is there Orthopedics?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        orthopedics = true;
    }
    cout << "Is there Oncology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        oncology = true;
    }
    cout << "Is there Physiotherapy?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        physiotherapy = true;
    }
    cout << "Is there Urology?(y/n) : ";
    cin >> a;
    if (a == 'y') {
        urology = true;
    }
}

void hospital::showDataHosp() {
    cout << "details of the hospital are : " << endl;
    cout << "Name of Hospital : " << hospName << endl;
    cout << "Hospital No : " << hospNo << endl;
    cout << "No of doctors : " << doctor << endl;
    cout << "No of nurses : " << nurse << endl;
    cout << "No of other staff : " << othStaff << endl;
    cout << "No of current patients : " << currPatient << endl;
    cout << "Medical Store nearby : ";
    if (isMedStore == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Departments : " << endl;
    cout << "General Surgery : ";
    if (genSur == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Cardiology : ";
    if (cardiology == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "ENT : ";
    if (ENT == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Neurology : ";
    if (neurology == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Orthopedics : ";
    if (orthopedics == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Oncology : ";
    if (oncology == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Physiotherapy : ";
    if (physiotherapy == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << "Urology : ";
    if (urology == true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
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
        hosp.getDataHosp();
        filout.write((char*)&hosp, sizeof(hosp));
        cout << "more hospitals?(y/n) : ";
        cin >> ch;
    } while (ch == 'y');
    filout.close();
    cout << "file hospital.dat created!" << endl;
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
        hosp.getDataHosp();
        fil.write((char*)&hosp, sizeof(hosp));
        cout << "more hospitals?(y/n) : ";
        cin >> ch;
    } while (ch == 'y');
    fil.close();
    cout << "New hospitals successfully added!" << endl;
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
        hosp.showDataHosp();
        delay(2000);
    }
    filin.close();
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
}

void modifyHospName() {
    int flag = 0;
    hospital hosp;
    fstream fil;
    fil.open("hospital.dat", ios::binary | ios::in | ios::out);
    int id;
    char newHospName[20];
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Old Name : " << hosp.retHospName() << endl;
            cout << "Enter new name of the hospital : ";
            getchar();
            fgets(newHospName, 20, stdin);
            hosp.changeHospName(newHospName);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Old No of Doctors : " << hosp.retDoctor();
            cout << "Enter new No of Doctors : ";
            cin >> newDoc;
            hosp.changeDoctor(newDoc);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Old No of Nurses : " << hosp.retNurse();
            cout << "Enter new No of Nurses : ";
            cin >> newNur;
            hosp.changeNurse(newNur);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Old No of staff : " << hosp.retOthStaff();
            cout << "Enter new No of Doctors : ";
            cin >> newStaff;
            hosp.changeOthStaff(newStaff);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Old No of Patients : " << hosp.retCurrPatient();
            cout << "Enter new No of Patients : ";
            cin >> newPat;
            hosp.changeCurrPatient(newPat);
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a medical store nearby? : ";
            if (hosp.retIsMedStore() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a medical store nearby now?(y/n) : ";
            cin >> newIsMed;
            if (newIsMed == 'y') {
                hosp.changeIsMedStore(true);
            }
            else {
                hosp.changeIsMedStore(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a General Surgery Department? : ";
            if (hosp.retIsMedStore() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a General Surgery Department now?(y/n) : ";
            cin >> newGen;
            if (newGen == 'y') {
                hosp.changeGenSur(true);
            }
            else {
                hosp.changeGenSur(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Cardiology Department? : ";
            if (hosp.retCard() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Cardiology Department now?(y/n) : ";
            cin >> newCard;
            if (newCard == 'y') {
                hosp.changeCard(true);
            }
            else {
                hosp.changeCard(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a ENT Department? : ";
            if (hosp.retENT() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a ENT Department now?(y/n) : ";
            cin >> newENT;
            if (newENT == 'y') {
                hosp.changeENT(true);
            }
            else {
                hosp.changeENT(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Neurology Department? : ";
            if (hosp.retNeuro() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Neurology Department now?(y/n) : ";
            cin >> newNeu;
            if (newNeu == 'y') {
                hosp.changeNeuro(true);
            }
            else {
                hosp.changeNeuro(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Orthopedics Department? : ";
            if (hosp.retOrtho() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Orthopedics Department now?(y/n) : ";
            cin >> newOrtho;
            if (newOrtho == 'y') {
                hosp.changeOrtho(true);
            }
            else {
                hosp.changeOrtho(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Oncology Department? : ";
            if (hosp.retOnco() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Oncology Department now?(y/n) : ";
            cin >> newOnco;
            if (newOnco == 'y') {
                hosp.changeOnco(true);
            }
            else {
                hosp.changeOnco(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Physiology Department? : ";
            if (hosp.retPhysio() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Physiology Department now?(y/n) : ";
            cin >> newPhy;
            if (newPhy == 'y') {
                hosp.changePhysio(true);
            }
            else {
                hosp.changePhysio(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter Hospital No whose name has to be changed : ";
    cin >> id;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (hosp.retHospNo() == id) {
            cout << "Hospital Name : " << hosp.retHospName() << endl;
            cout << "Before if there was a Urology Department? : ";
            if (hosp.retUro() == true) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
            cout << "Is there a Urology Department now?(y/n) : ";
            cin >> newUro;
            if (newUro == 'y') {
                hosp.changeUro(true);
            }
            else {
                hosp.changeUro(false);
            }
            int current = fil.tellg();
            fil.seekp(current - sizeof(hosp));
            fil.write((char*)&hosp, sizeof(hosp));
            cout << "record updated!" << endl;
            flag++;
            break;
        }
    }
    fil.close();
    if (flag == 0) {
        cout << "Hospital not found!" << endl;
    }
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
    cout << "Enter name of hospital : ";
    fgets(s, 20, stdin);
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        if (strcmpi(hosp.retHospName(), s) == 0) {
            hosp.showDataHosp();
            flag++;
            break;
        }
    }
    if (flag == 0) {
        cout << "Hospital not found" << endl;
    }
    fil.close();
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
        cout << "Hospital not found" << endl;
    }
    fil.close();
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
    string s1, s2;
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
    cout << "SORTING DONE" << endl;
    delay(1000);
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
    cout << "SORTING DONE" << endl;
    delay(800);
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
    cout << "SORTING DONE" << endl;
    delay(800);
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
    cout << "SORTING DONE" << endl;
    delay(800);
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
    cout << "SORTING DONE" << endl;
    delay(800);
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
    cout << "SORTING DONE" << endl;
    delay(800);
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
        cout << "record not found!" << endl;
    }
    else {
        transferHosp();
        cout << "Hospital removed!" << endl;
    }
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
    gotoxy(32, 6);
    cout << "List Of Hospitals";
    gotoxy(1, 7);
    cout << "========================================";
    cout << "========================================";
    gotoxy(1, 8);
    cout << "HOSP ID";
    gotoxy(9, 8);
    cout << "HOSP NAME";
    gotoxy(23, 8);
    cout << "DOCTORS";
    gotoxy(32, 8);
    cout << "NURSES";
    gotoxy(40, 8);
    cout << "OTHER STAFF";
    gotoxy(53, 8);
    cout << "CURR PATIENTS";
    gotoxy(68, 8);
    cout << "MEDICAL STORE" << endl;
    cout << "========================================";
    cout << "========================================";
    int j = 0;
    while (fil.read((char*)&hosp,sizeof(hosp))) {
        gotoxy(1, (j + 10));
        cout << hosp.retHospNo();
        gotoxy(9, (j + 10));
        cout << hosp.retHospName();
        gotoxy(23, (j + 10));
        cout << hosp.retDoctor();
        gotoxy(32, (j + 10));
        cout << hosp.retNurse();
        gotoxy(40, (j + 10));
        cout << hosp.retOthStaff();
        gotoxy(53, (j + 10));
        cout << hosp.retCurrPatient();
        gotoxy(68, (j + 10));
        if (hosp.retIsMedStore() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        j++;
    }
    cout << endl;
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
    gotoxy(32, 6);
    cout << "List Of Hospitals";
    gotoxy(1, 7);
    cout << "================================================";
    cout << "================================================";
    gotoxy(1, 8);
    cout << "HOSP ID";
    gotoxy(9, 8);
    cout << "HOSP NAME";
    gotoxy(23, 8);
    cout << "GEN SURGERY";
    gotoxy(36, 8);
    cout << "CARDIOLOGY";
    gotoxy(48, 8);
    cout << "ENT";
    gotoxy(53, 8);
    cout << "NEUROLOGY";
    gotoxy(64, 8);
    cout << "ORTHO";
    gotoxy(71, 8);
    cout << "ONCOLOGY";
    gotoxy(81, 8);
    cout << "PHYSIO";
    gotoxy(89, 8);
    cout << "UROLOGY" << endl;
    cout << "================================================";
    cout << "================================================";
    j = 0;
    while (fil.read((char*)&hosp, sizeof(hosp))) {
        gotoxy(1, (j + 10));
        cout << hosp.retHospNo();
        gotoxy(9, (j + 10));
        cout << hosp.retHospName();
        gotoxy(23, (j + 10));
        if (hosp.retGenSur() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(36, (j + 10));
        if (hosp.retCard() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(48, (j + 10));
        if (hosp.retENT() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(53, (j + 10));
        if (hosp.retNeuro() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(64, (j + 10));
        if (hosp.retOrtho() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(71, (j + 10));
        if (hosp.retOnco() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(81, (j + 10));
        if (hosp.retPhysio() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        gotoxy(89, (j + 10));
        if (hosp.retUro() == true) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        j++;
    }
    cout << endl;
    cout << "================================================";
    cout << "================================================";
    cout << endl << endl;
    fil.close();
    delay(1500);
    cout << "Press Enter to continue" << endl;
    cin.ignore();
    cin.ignore();
    menuHosp();
}

void menuHosp() {
    system("cls");
    int choice;
    do {
        system("cls");
        gotoxy(3, 5);
        cout << "HOSPITAL MENU" << endl;
        cout << "1. ENTER/DISPLAY MENU" << endl;
        cout << "2. UPDATE MENU" << endl;
        cout << "3. SEARCH MENU" << endl;
        cout << "4. SORT MENU" << endl;
        cout << "5. BACK TO MAIN MENU" << endl;
        cout << "6. EXIT FROM PROGRAM" << endl;
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
        gotoxy(3, 5);
        cout << "ENTER/DISPLAY MENU" << endl;
        cout << "1. CREATE NEW FILE" << endl;
        cout << "2. ADD DATA TO EXISTING FILE" << endl;
        cout << "3. DISPLAY FILE" << endl;
        cout << "4. DISPLAY IN TABULAR FORM" << endl;
        cout << "5. BACK TO MAIN MENU" << endl;
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
        gotoxy(3, 5);
        cout << "UPDATE MENU" << endl;
        cout << "1. REMOVE A HOSPITAL FROM LIST" << endl;
        cout << "2. CHANGE HOSPITAL NAME" << endl;
        cout << "3. CHANGE DOCTOR COUNT IN A HOSPITAL" << endl;
        cout << "4. CHANGE NURSE COUNT IN A HOSPITAL" << endl;
        cout << "5. CHANGE STAFF COUNT IN A HOSPITAL" << endl;
        cout << "6. CHANGE PATIENT COUNT IN A HOSPITAL" << endl;
        cout << "7. CHANGE MEDICAL STORE AVAILABILTY IN A HOSPITAL" << endl;
        cout << "8. CHANGE GENERAL SURGERY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "9. CHANGE CARDIOLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "10. CHANGE ENT DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "11. CHANGE NEUROLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "12. CHANGE ORTHOPEDICS DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "13. CHANGE ONCOLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "14. CHANGE PHYSIOTHERAPY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "15. CHANGE UROLOGY DEPARTMENT AVAILABILTY IN A HOSPITAL" << endl;
        cout << "16. BACK TO MAIN MENU" << endl;
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
        gotoxy(3, 5);
        cout << "SEARCH MENU" << endl;
        cout << "1. SEARCH BY HOSPITAL ID" << endl;
        cout << "2. SEARCH BY HOSPITAL NAME" << endl;
        cout << "3. BACK TO MAIN MENU" << endl;
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
        gotoxy(3, 5);
        cout << "SORT MENU" << endl;
        cout << "1. SORT BY HOSPITAL NAME" << endl;
        cout << "2. SORT BY HOSPITAL ID" << endl;
        cout << "3. SORT BY DOCTOR COUNT" << endl;
        cout << "4. SORT BY NURSE COUNT" << endl;
        cout << "5. SORT BY STAFF COUNT" << endl;
        cout << "6. SORT BY PATIENT COUNT" << endl;
        cout << "7. BACK TO MAIN MENU" << endl << endl;
        cout << "NOTE: ALL THE MENUS WILL SORT IN ASCENDING ORDER" << endl << endl;
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
