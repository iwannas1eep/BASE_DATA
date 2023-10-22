#pragma once
#include "base.h"
#include "data.h"
using namespace std;

class Student : public VYZ {
private:
	FIO stdFIO;
	char group;
	string spec;
	char course;
	char sr_ball;
public:
	Student();
	Student(ifstream& fin);
	~Student();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};