#include "teacher.h"

teacher::teacher() {
    try {
        SetType(2);
        SetErr(false);
        cout << "Введите ФИО:" << endl
            << "Фамилия: ";
        cin.ignore(256, '\n');
        getline(cin, this->prepFIO.SurName);
        cout << "Имя: ";
        getline(cin, this->prepFIO.Name);
        cout << "Отчество: ";
        getline(cin, this->prepFIO.LastName);
        cout << "Группа: ";
        cin >> this->groups;
        if (isalpha(this->groups))
            throw 1;
        cout << "Дисциплина: ";
        cin.ignore(256, '\n');
        getline(cin, this->disc);
    }
    catch (int) {
        SetErr(true);
        cout << "Номер группы состоит из цифр!" << endl;
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
    cout << "Дестр преподавателя" << endl;
}

void teacher::Edit() {
    SetErr(false);
    int choose;
    FIO fio_temp;
    char i_temp;
    string s_temp;
    cout << "Выберите параметр для редактирования:" << endl
        << "1 - ФИО." << endl
        << "2 - Группа." << endl
        << "3 - Дисциплина." << endl
        << "0 - Отмена." << endl << endl;
    cin >> choose;
    try {
        switch (choose) {
        case 1:
            cout << "Текущее: ";
            cout << this->prepFIO.SurName << " "
                << this->prepFIO.Name << " "
                << this->prepFIO.LastName << endl
                << "New:  Фамилия >> ";
            cin.ignore(256, '\n');
            getline(cin, fio_temp.SurName);
            cout << "\tИмя >> ";
            getline(cin, fio_temp.Name);
            cout << "\tОтчество >> ";
            getline(cin, fio_temp.LastName);
            prepFIO = fio_temp;
            break;
        case 2:
            cout << "Текущее: ";
            cout << this->groups << endl
                << "Новое >> ";
            cin >> i_temp;
            if (isalpha(i_temp))
                throw 1;
            groups = i_temp;
            break;
        case 3:
            cout << "Текущее: ";
            cout << this->disc << endl
                << "Новое >> ";
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
        cout << "Номер группы состоит из цифр!" << endl;
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
    out << "Преподаватель: " << endl
        << "Фио: " << this->prepFIO.SurName << " " << this->prepFIO.Name << " " << this->prepFIO.LastName << endl
        << "Группа: " << this->groups << endl
        << "Дисциплина: " << this->disc << endl
        << "-----------------------------------" << endl;
}
