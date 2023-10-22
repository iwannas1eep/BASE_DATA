#include "teacher.h"

teacher::teacher() {
    try {
        SetType(2);
        SetErr(false);
        cout << "������� ���:" << endl
            << "�������: ";
        cin.ignore(256, '\n');
        getline(cin, this->prepFIO.SurName);
        cout << "���: ";
        getline(cin, this->prepFIO.Name);
        cout << "��������: ";
        getline(cin, this->prepFIO.LastName);
        cout << "������: ";
        cin >> this->groups;
        if (isalpha(this->groups))
            throw 1;
        cout << "����������: ";
        cin.ignore(256, '\n');
        getline(cin, this->disc);
    }
    catch (int) {
        SetErr(true);
        cout << "����� ������ ������� �� ����!" << endl;
    }
}

teacher::teacher(ifstream& fin) {
    SetType(2);
    fin.ignore(256, '\n');
    getline(fin, this->prepFIO.SurName);
    getline(fin, this->prepFIO.Name);
    getline(fin, this->prepFIO.LastName);
    fin >> this->groups;
    fin.ignore(256, '\n');
    getline(fin, this->disc);
}

teacher::~teacher() {
    cout << "����� �������������" << endl;
}

void teacher::Edit() {
    SetErr(false);
    int choose;
    FIO fio_temp;
    char i_temp;
    string s_temp;
    cout << "�������� �������� ��� ��������������:" << endl
        << "1 - ���." << endl
        << "2 - ������." << endl
        << "3 - ����������." << endl
        << "0 - ������." << endl << endl;
    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "�������: ";
            cout << this->prepFIO.SurName << " "
                << this->prepFIO.Name << " "
                << this->prepFIO.LastName << endl
                << "New:  ������� >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.SurName);
            cout << "\t��� >> ";
            getline(cin, fio_temp.Name);
            cout << "\t�������� >> ";
            getline(cin, fio_temp.LastName);
            prepFIO = fio_temp;
            break;
        case 2:
            cout << "�������: ";
            cout << this->groups << endl
                << "����� >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            groups = i_temp;
            break;
        case 3:
            cout << "�������: ";
            cout << this->disc << endl
                << "����� >> ";
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
        cout << "����� ������ ������� �� ����!" << endl;
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
    out << "�������������: " << endl
        << "���: " << this->prepFIO.SurName << " " << this->prepFIO.Name << " " << this->prepFIO.LastName << endl
        << "������: " << this->groups << endl
        << "����������: " << this->disc << endl
        << "-----------------------------------" << endl;
}
