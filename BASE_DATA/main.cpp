#include "keeper.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	Keeper Contain;
	char menu = 0;
	setlocale(LC_ALL, "Russian");
	cout << "База ВУЗа:" << endl; // "База ВУЗа" - Database of Universities
	do {
		try {
			cout << "Текущее количество элементов в контейнере: " << Contain.GetSize() << "." << endl
				<< "Выберите действие:" << endl
				<< "1 - Добавить элемент." << endl
				<< "2 - Редактировать элемент." << endl
				<< "3 - Удалить элемент." << endl
				<< "4 - Сохранить данные в файл." << endl
				<< "5 - Загрузить данные из файла." << endl
				<< "6 - Вывести данные из контейнера." << endl
				<< "0 - Выход." << endl << endl;
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
			cout << "Некорректный ввод!" << endl; // "Некорректный ввод" - Incorrect input
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}