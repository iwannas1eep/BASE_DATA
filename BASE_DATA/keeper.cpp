#include "keeper.h"

int Choose() {
    int x = 0;
    cout << "Выберите класс:" << endl
        << "1 - Студенты." << endl
        << "2 - Преподаватели." << endl
        << "3 - Персонал." << endl << endl;
    cin >> x;
    return x;
}

int count = 0;

Keeper::Keeper() {
    this->Value = nullptr;
    this->size = 0;
}

Keeper::~Keeper() {
    delete[] Value;
}

int Keeper::GetSize() {
    return size;
}

void Keeper::Add() {
    try {
        VYZ** temp = new VYZ * [size + 1];
        int i = 0;
        while (i < size) {
            temp[i] = Value[i];
            i++;
        }
        switch (Choose()) {
        case 1:
            temp[size] = new Student;
            break;
        case 2:
            temp[size] = new teacher;
            break;
        case 3:
            temp[size] = new Personal;
            break;
        }
        if ((!temp[size]) || (temp[size]->GetErr()))
            throw 1;
        size++;
        if (Value)
            delete[] Value;
        Value = temp;
        cout << "Объект успешно добавлен!" << endl;
    }
    catch (int) {
        cout << "Ошибка!" << endl;
    }
}

void Keeper::Add(int _type, ifstream& fin) {
    VYZ** temp = new VYZ * [size + 1];
    int i = 0;
    while (i < size) {
        temp[i] = Value[i];
        i++;
    }
    switch (_type) {
    case 1:
        temp[size] = new Student(fin);
        break;
    case 2:
        temp[size] = new teacher(fin);
        break;
    case 3:
        temp[size] = new Personal(fin);
        break;
    }
    ::count++;
    size++;
    if (Value)
        delete[] Value;
    Value = temp;
}

void Keeper::Edit() {
    int x;
    if (!size)
        cout << "Контейнер пуст!" << endl;
    for (int i = 0; i < size; i++) {
        cout << "[" << i + 1 << "] ";
        switch (Value[i]->GetType()) {
        case 1:
            cout << "Студент" << endl;
            break;
        case 2:
            cout << "Преподаватель" << endl;
            break;
        case 3:
            cout << "Персонал" << endl;
            break;
        default:
            break;
        }
    }
    try {
        cout << ">> ";
        cin >> x;
        if ((x < 1) || (x > size)) {
            throw 1;
        }
        x -= 1;
        Value[x]->Edit();
        if ((Value[x]->GetErr()) || (!Value[x]))
            cout << "Провал!" << endl;
        else
            cout << "Успешно!" << endl;
    }
    catch (int) {
        cout << "Выбранный элемент недоступен!" << endl;
    }
}

void Keeper::Del() {
    int x;
    if (!size)
        cout << "Контейнер пуст!" << endl;
    for (int i = 0; i < size; i++) {
        switch (Value[i]->GetType()) {
        case 1:
            cout << "[" << i + 1 << "] Студент." << endl;
            break;
        case 2:
            cout << "[" << i + 1 << "] Преподаватель." << endl;
            break;
        case 3:
            cout << "[" << i + 1 << "] Персонал." << endl;
            break;
        default:
            break;
        }
    }
    cout << ">> ";
    cin >> x;
    x -= 1;
    if (size == 1) {
        delete[] Value;
        Value = nullptr;
        cout << "Успешно!" << endl;
        size--;
    }
    VYZ** temp = new VYZ * [size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (x == i)
            continue;
        temp[j--] = Value[i];
    }
    delete[] Value;
    Value = temp;
    size--;
    cout << "Успешно!" << endl;
}

void Keeper::Save() {
    ofstream fout("test.txt");
    for (int i = 0; i < size; i++) {
        Value[i]->Save(fout);
    }
    fout.close();
    cout << "Сохранено!" << endl;
}

void Keeper::Load() {
    ifstream fin("test.txt");
    if (fin.fail())
        cout << "Файл пуст!" << endl;
    int type = 0;
    while (fin) {
        fin >> type;
        if (fin.peek() == -1)
            break;
        Add(type, fin);
    }
    fin.close();
    if ((::count == 1) || (::count == 21))
        cout << "Успешно загружен [" << ::count << "]." << endl;
    if (((::count > 1) && (::count < 5)) || ((::count > 21) && (::count < 25)))
        cout << "Успешно загружен [" << ::count << "]." << endl;
    if ((::count > 4) && (::count < 21))
        cout << "Успешно загружен [" << ::count << "]." << endl;
    ::count = 0;
}

ostream& operator<< (ostream& out, Keeper& obj) {
    if (!obj.size) {
        cout << "Контейнер пуст!" << endl;
        return out;
    }
    for (int i = 0; i < obj.size; i++) {
        obj.Value[i]->Print(out);
    }
    return out;
}
