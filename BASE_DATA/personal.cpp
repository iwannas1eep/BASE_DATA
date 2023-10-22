#include "personal.h"

Personal::Personal() {
    try {
        SetType(3);
        SetErr(false);
        cout << "������� ���:" << endl
            << "�������: ";
        cin.ignore(256, '\n');
        getline(cin, this->persFIO.SurName);
        cout << "���: ";
        getline(cin, this->persFIO.Name);
        cout << "��������: ";
        getline(cin, this->persFIO.LastName);
        cout << "�������������: ";
        getline(cin, this->spec);
        cout << "����� ��������: ";
        cin >> this->tel;
        if (isalpha(this->tel))
            throw 1;
        cout << "������� ���������������: ";
        cin.ignore(256, '\n');
        getline(cin, this->obl);
    }
    catch (int) {
        SetErr(true);
        cout << "����� �������� ������� �� ����!" << endl;
    }
}

Personal::Personal(ifstream& fin) {
    SetType(3);
    fin.ignore(256, '\n');
    getline(fin, this->persFIO.SurName);
    getline(fin, this->persFIO.Name);
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
    cout << "�������� �������� ��� ��������������:" << endl
        << "1 - ���." << endl
        << "2 - �������������." << endl
        << "3 - ����� ��������." << endl
        << "4 - ������� ���������������." << endl
        << "0 - ������." << endl << endl;
    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "�������: ";
            cout << this->persFIO.SurName << " "
                << this->persFIO.Name << " "
                << this->persFIO.LastName << endl
                << "�����:  ������� >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.SurName);
            cout << "\n ��� >> ";
            getline(cin, fio_temp.Name);
            cout << "\t�������� >> ";
            getline(cin, fio_temp.LastName);
            persFIO = fio_temp;
            break;
        case 2:
            cout << "�������: ";
            cout << this->spec << endl
                << "����� >> ";
            cin.ignore(256, '\n');
            getline(cin, s_temp);
            spec = s_temp;
            break;
        case 3:
            cout << "�������: ";
            cout << this->tel << endl
                << "����� >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            tel = i_temp;
            break;
        case 4:
            cout << "�������: ";
            cout << this->obl << endl
                << "����� >> ";
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
        cout << "����� �������� ������� �� ����!" << endl;
    }
}

void Personal::Save(ofstream& fout) {
    fout << GetType() << endl
        << this->persFIO.SurName << endl
        << this->persFIO.Name << endl
        << this->persFIO.LastName << endl
        << this->spec << endl
        << this->tel << endl
        << this->obl << endl;
}

void Personal::Print(ostream& out) {
    out << "��������: " << endl
        << "���: " << this->persFIO.SurName << " " << this->persFIO.Name << " " << this->persFIO.LastName << endl
        << "�������������: " << this->spec << endl
        << "����� ��������: " << this->tel << endl
        << "������� ���������������: " << this->obl << endl
        << "------------------------------" << endl;
}
