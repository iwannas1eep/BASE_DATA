#include "personal.h"

Personal::Personal() {
    try {
        SetType(3);
        SetErr(false);
        cout << "Enter full name:" << endl
            << "First Name: ";
        cin.ignore(256, '\n');
        getline(cin, this->persFIO.Name);
        cout << "Last Name: ";
        getline(cin, this->persFIO.SurName);
        cout << "Middle Name: ";
        getline(cin, this->persFIO.LastName);
        cout << "Enter specialty: ";
        getline(cin, this->spec);
        cout << "Enter phone number: ";
        cin >> this->tel;
        if (isalpha(this->tel))
            throw 1;
        cout << "Enter area of responsibility: ";
        cin.ignore(256, '\n');
        getline(cin, this->obl);
    }
    catch (int) {
        SetErr(true);
        cout << "Phone number can only be a number!" << endl;
    }
}

Personal::Personal(ifstream& fin) {
    SetType(3);
    fin.ignore(256, '\n');
    getline(fin, this->persFIO.Name);
    getline(fin, this->persFIO.SurName);
    getline(fin, this->persFIO.LastName);
    getline(fin, this->spec);
    fin >> this->tel;
    fin.ignore(256, '\n');
    getline(fin, this->obl);
}

Personal::~Personal() {
    cout << "Personal destructor";
}

void Personal::Edit() {
    int choose;
    FIO fio_temp;
    string s_temp;
    char i_temp;
    cout << "Select the parameter to edit:" << endl
        << "1 - Full Name." << endl
        << "2 - Specialty." << endl
        << "3 - Phone Number." << endl
        << "4 - Area of Responsibility." << endl
        << "0 - Cancel." << endl << endl;
    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "Current: ";
            cout << this->persFIO.Name << " "
                << this->persFIO.SurName << " "
                << this->persFIO.LastName << endl
                << "New:  First Name >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.Name);
            cout << "\tLast Name >> ";
            getline(cin, fio_temp.SurName);
            cout << "\tMiddle Name >> ";
            getline(cin, fio_temp.LastName);
            persFIO = fio_temp;
            break;
        case 2:
            cout << "Current: ";
            cout << this->spec << endl
                << "New >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            spec = s_temp;
            break;
        case 3:
            cout << "Current: ";
            cout << this->tel << endl
                << "New >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            tel = i_temp;
            break;
        case 4:
            cout << "Current: ";
            cout << this->obl << endl
                << "New >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            obl = s_temp;
            break;
        default:
            break;
        }
    }
    catch (int) {
        SetErr(true);
        cout << "Phone number can only be a number!" << endl;
    }
}

void Personal::Save(ofstream& fout) {
    fout << GetType() << endl
        << this->persFIO.Name << endl
        << this->persFIO.SurName << endl
        << this->persFIO.LastName << endl
        << this->spec << endl
        << this->tel << endl
        << this->obl << endl;
}

void Personal::Print(ostream& out) {
    out << "Personal:" << endl
        << "Full Name:" << this->persFIO.Name << " " << this->persFIO.SurName << " " << this->persFIO.LastName << endl
        << "Specialty:" << this->spec << endl
        << "Phone Number:" << this->tel << endl
        << "Area of Responsibility:" << this->obl << endl
        << "------------------------------" << endl;
}
