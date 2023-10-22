#pragma once
#include "base.h"
#include "data.h"
using namespace std;

class teacher : public VYZ {
private:
	FIO prepFIO;
	char groups;
	string disc;
public:
	teacher();
	teacher(ifstream& fin);
	~teacher();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};