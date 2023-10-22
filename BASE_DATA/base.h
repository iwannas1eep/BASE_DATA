#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class VYZ {
private:
	int type;
	bool err = false;
public:
	void SetType(int _type);
	int GetType();
	void SetErr(bool _err);
	bool GetErr();
	virtual ~VYZ() = 0;
	virtual void Save(ofstream& fout) = 0;
	virtual void Edit() = 0;
	virtual void Print(ostream& out) = 0;
};