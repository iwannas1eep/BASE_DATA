#include "student.h"

Student::Student() {
    try {
        SetType(1);
        SetErr(false);
        cout << "������� ���:" << endl
            << "�������: ";
        cin.ignore(256, '\n');
        getline(cin, this->stdFIO.SurName);
        cout << "���: ";
        getline(cin, this->stdFIO.Name);
        cout << "��������: ";
        getline(cin, this->stdFIO.LastName);
        cout << "������: ";
        cin >> this->group;
        if (isalpha(this->group))
            throw 1;
        cout << "�������������: ";
        cin.ignore(256, '\n');
        getline(cin, this->spec);
        cout << "����: ";
        cin >> this->course;
        if (isalpha(this->course))
            throw 2;
        cout << "������� ����: ";
        cin >> this->sr_ball;
        if (isalpha(this->sr_ball))
            throw 3;
    }
    catch (int err) {
        SetErr(true);
        switch (err) {
        case 1:
            cout << "����� ������ ����� ���� ������ ������!" << endl;
            break;
        case 2:
            cout << "����� ����� ����� ���� ������ ������!" << endl;
            break;
        case 3:
            cout << "������� ���� ����� ���� ������ ������!" << endl;
            break;
        }
    }
}

Student::Student(ifstream& fin) {
    SetType(1);
    fin.ignore(256, '\n');
    getline(fin, this->stdFIO.SurName);
    getline(fin, this->stdFIO.Name);
    getline(fin, this->stdFIO.LastName);
    fin >> this->group;
    fin.ignore(256, '\n');
    getline(fin, this->spec);
    fin >> this->course;
    fin >> this->sr_ball;
}

Student::~Student() {
    cout << "����� ��������" << endl;
}

void Student::Edit() {
    SetErr(false);
    int choose;
    FIO fio_temp;
    char i_temp;
    string s_temp;
    char f_temp;
    cout << "�������� �������� ��� ��������������:" << endl
        << "1 - ���." << endl
        << "2 - ������." << endl
        << "3 - �������������." << endl
        << "4 - ����" << endl
        << "5 - ������� ����." << endl
        << "0 - ������." << endl << endl;

    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "Current: ";
            cout << this->stdFIO.SurName << " "
                << this->stdFIO.Name << " "
                << this->stdFIO.LastName << endl
                << "�����:  ������� >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.SurName);
            cout << "\t��� >> ";
            getline(cin, fio_temp.Name);
            cout << "\t�������� >> ";
            getline(cin, fio_temp.LastName);
            stdFIO = fio_temp;
            break;
        case 2:
            cout << "�������: ";
            cout << this->group << endl
                << "����� >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            group = i_temp;
            break;
        case 3:
            cout << "�������: ";
            cout << this->spec << endl
                << "����� >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            spec = s_temp;
            break;
        case 4:
            cout << "�������: ";
            cout << this->course << endl
                << "����� >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 2;
            course = i_temp;
            break;
        case 5:
            cout << "�������: ";
            cout << this->sr_ball << endl
                << "����� >> ";
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
        cout << "������!" << endl;
    }
}

void Student::Save(ofstream& fout) {
    fout << GetType() << endl
        << this->stdFIO.SurName << endl
        << this->stdFIO.Name << endl
        << this->stdFIO.LastName << endl
        << this->group << endl
        << this->spec << endl
        << this->course << endl
        << this->sr_ball << endl;
}

void Student::Print(ostream& out) {
    out << "�������: " << endl
        << "���: " << this->stdFIO.SurName << " " << this->stdFIO.Name << " " << this->stdFIO.LastName << endl
        << "������: " << this->group << endl
        << "�������������: " << this->spec << endl
        << "����: " << this->course << endl
        << "������� ����: " << this->sr_ball << endl
        << "---------------------------------" << endl;
}
