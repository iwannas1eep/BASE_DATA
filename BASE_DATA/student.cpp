#include "student.h"

Student::Student() {
    try {
        SetType(1);
        SetErr(false);
        cout << "Enter student's full name:" << endl
            << "Sur Name: ";
        cin.ignore(256, '\n');
        getline(cin, this->stdFIO.SurName);
        cout << "Name: ";
        getline(cin, this->stdFIO.Name);
        cout << "Last Name: ";
        getline(cin, this->stdFIO.LastName);
        cout << "Group: ";
        cin >> this->group;
        if (isalpha(this->group))
            throw 1;
        cout << "Specialty: ";
        cin.ignore(256, '\n');
        getline(cin, this->spec);
        cout << "Course Number: ";
        cin >> this->course;
        if (isalpha(this->course))
            throw 2;
        cout << "Average Grade: ";
        cin >> this->sr_ball;
        if (isalpha(this->sr_ball))
            throw 3;
    }
    catch (int) {
        cout << "Invalid input!" << endl;
    }
}

Student::Student(ifstream& fin) {
    SetType(1);
    fin.ignore(256, '\n');
    getline(fin, this->stdFIO.Name);
    getline(fin, this->stdFIO.SurName);
    getline(fin, this->stdFIO.LastName);
    fin >> this->group;
    fin.ignore(256, '\n');
    getline(fin, this->spec);
    fin >> this->course;
    fin >> this->sr_ball;
}

Student::~Student() {
    cout << "Student destructor" << endl;
}

void Student::Edit() {
    SetErr(false);
    int choose;
    FIO fio_temp;
    char i_temp;
    string s_temp;
    char f_temp;
    cout << "Select the parameter to edit:" << endl
        << "1 - Full Name." << endl
        << "2 - Group." << endl
        << "3 - Specialty." << endl
        << "4 - Course Number." << endl
        << "5 - Average Grade." << endl
        << "0 - Cancel." << endl << endl;

    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "Current: ";
            cout << this->stdFIO.Name << " "
                << this->stdFIO.SurName << " "
                << this->stdFIO.LastName << endl
                << "New:  First Name >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.Name);
            cout << "\tLast Name >> ";
            getline(cin, fio_temp.SurName);
            cout << "\tMiddle Name >> ";
            getline(cin, fio_temp.LastName);
            stdFIO = fio_temp;
            break;
        case 2:
            cout << "Current: ";
            cout << this->group << endl
                << "New >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            group = i_temp;
            break;
        case 3:
            cout << "Current: ";
            cout << this->spec << endl
                << "New >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            spec = s_temp;
            break;
        case 4:
            cout << "Current: ";
            cout << this->course << endl
                << "New >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 2;
            course = i_temp;
            break;
        case 5:
            cout << "Current: ";
            cout << this->sr_ball << endl
                << "New >> ";
            cin >> f_temp;
            if (isalpha(f_temp))
                throw 3;
            sr_ball = f_temp;
            break;
        default:
            break;
        }
    }
    catch (int) {
        cout << "Invalid input!" << endl;
    }
}

void Student::Save(ofstream& fout) {
    fout << GetType() << endl
        << this->stdFIO.Name << endl
        << this->stdFIO.SurName << endl
        << this->stdFIO.LastName << endl
        << this->group << endl
        << this->spec << endl
        << this->course << endl
        << this->sr_ball << endl;
}

void Student::Print(ostream& out) {
    out << "Student:" << endl
        << "Full Name:" << this->stdFIO.Name << " " << this->stdFIO.SurName << " " << this->stdFIO.LastName << endl
        << "Group:" << this->group << endl
        << "Specialty:" << this->spec << endl
        << "Course Number:" << this->course << endl
        << "Average Grade:" << this->sr_ball << endl
        << "---------------------------------" << endl;
}
