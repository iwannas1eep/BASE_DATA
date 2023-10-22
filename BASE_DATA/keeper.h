#pragma once
#include "base.h"
#include "personal.h"
#include "teacher.h"
#include "student.h"
#include <fstream>
#include <iostream>
using namespace std;

class Keeper {
private:
	VYZ** Value;
	int size;
public:
	Keeper();
	~Keeper();
	int GetSize();
	void Add();
	void Add(int _type, ifstream& fin);
	void Edit();
	void Del();
	void Save();
	void Load();
	friend ostream& operator<< (ostream& out, Keeper& obj);
};