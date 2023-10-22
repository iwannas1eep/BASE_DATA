#include "keeper.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	Keeper Contain;
	char menu = 0;
	cout << "Áàçà ÂÓÇà:" << endl;
	do {
		try {
			cout << "Current number of items in the container: " << Contain.GetSize() << "." << endl
				<< "Select an action:" << endl
				<< "1 - Add an item." << endl
				<< "2 - Edit an item." << endl
				<< "3 - Delete an item." << endl
				<< "4 - Save data to a file." << endl
				<< "5 - Load data from a file." << endl
				<< "6 - Display data from the container." << endl
				<< "0 - Exit." << endl << endl;
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
			cout << "Incorrect input!" << endl;
		}
		system("pause");
		system("cls");
	} while (menu != '0');
	return 0;
}