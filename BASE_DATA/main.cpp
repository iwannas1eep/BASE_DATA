#include "keeper.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	Keeper Contain;
	char menu = 0;
	setlocale(LC_ALL, "Russian");
	cout << "���� ����:" << endl; // "���� ����" - Database of Universities
	do {
		try {
			cout << "������� ���������� ��������� � ����������: " << Contain.GetSize() << "." << endl
				<< "�������� ��������:" << endl
				<< "1 - �������� �������." << endl
				<< "2 - ������������� �������." << endl
				<< "3 - ������� �������." << endl
				<< "4 - ��������� ������ � ����." << endl
				<< "5 - ��������� ������ �� �����." << endl
				<< "6 - ������� ������ �� ����������." << endl
				<< "0 - �����." << endl << endl;
			cin >> menu;
			if ((!isdigit(menu)) && ((menu >= 7) || (menu <= -1))) {
				throw 1;
			}
			switch (menu) {
			case '0':
				break;
			case '1':
				Contain.Add();
				break;
			case '2':
				Contain.Edit();
				break;
			case '3':
				Contain.Del();
				break;
			case '4':
				Contain.Save();
				break;
			case '5':
				Contain.Load();
				break;
			case '6':
				cout << Contain;
				break;
			}
		}
		catch (int) {
			cout << "������������ ����!" << endl; // "������������ ����" - Incorrect input
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}