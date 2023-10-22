#include "base.h"

void VYZ::SetType(int _type) {
	type = _type;
}

int VYZ::GetType() {
	return type;
}

void VYZ::SetErr(bool _err) {
	err = _err;
}

bool VYZ::GetErr() {
	return err;
}

VYZ::~VYZ() {

}