#include "teacher.h"

teacher::teacher() {
    try {
        SetType(2);
        SetErr(false);
        cout << "Enter teacher's full name:" << endl
            << "First Name: ";
        cin.ignore(256, '\n');
        getline(cin, this->prepFIO.Name);
        cout << "Last Name: ";
        getline(cin, this->prepFIO.SurName);
        cout << "Middle Name: ";
        getline(cin, this->prepFIO.LastName);
        cout << "Enter groups: ";
        cin >> this->groups;
        if (isalpha(this->groups))
            throw 1;
        cout << "Enter discipline: ";
        cin.ignore(256, '\n');
        getline(cin, this->disc);
    }
    catch (int) {
        SetErr(true);
        cout << "Group number can only be a number!" << endl;
    }
}

teacher::teacher(ifstream& fin) {
    SetType(2);
    fin.ignore(256, '\n');
    getline(fin, this->prepFIO.Name);
    getline(fin, this->prepFIO.SurName);
    getline(fin, this->prepFIO.LastName);
    fin >> this->groups;
    fin.ignore(256, '\n');
    getline(fin, this->disc);
}

teacher::~teacher() {
    cout << "Teacher destructor" << endl;
}

void teacher::Edit() {
    SetErr(false);
    int choose;
    FIO fio_temp;
    char i_temp;
    string s_temp;
    cout << "Select the parameter to edit:" << endl
        << "1 - Full Name." << endl
        << "2 - Groups." << endl
        << "3 - Discipline." << endl
        << "0 - Cancel." << endl << endl;
    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "Current: ";
            cout << this->prepFIO.Name << " "
                << this->prepFIO.SurName << " "
                << this->prepFIO.LastName << endl
                << "New:  First Name >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.Name);
            cout << "\tLast Name >> ";
            getline(cin, fio_temp.SurName);
            cout << "\tMiddle Name >> ";
            getline(cin, fio_temp.LastName);
            prepFIO = fio_temp;
            break;
        case 2:
            cout << "Current: ";
            cout << this->groups << endl
                << "New >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            groups = i_temp;
            break;
        case 3:
            cout << "Current: ";
            cout << this->disc << endl
                << "New >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            disc = s_temp;
            break;
        default:
            break;
        }
    }
    catch (int) {
        SetErr(true);
        cout << "Group number can only be a number!" << endl;
    }
}

void teacher::Save(ofstream& fout) {
    fout << GetType() << endl
        << this->prepFIO.Name << endl
        << this->prepFIO.SurName << endl
        << this->prepFIO.LastName << endl
        << this->groups << endl
        << this->disc << endl;
}

void teacher::Print(ostream& out) {
    out << "Teacher:" << endl
        << "Full Name:" << this->prepFIO.Name << " " << this->prepFIO.SurName << " " << this->prepFIO.LastName << endl
        << "Groups:" << this->groups << endl
        << "Discipline:" << this->disc << endl
        << "-----------------------------------" << endl;
}
