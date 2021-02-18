#include <iostream>
#include <string>
#include "admin.h"
using namespace std;

Admin::Admin(string name, int id, string pass) {
        this->name = name;
        this->id = id;
        this->pass = pass;
}

void Admin::SetName(string name) {
	this->name = name;
}

void Admin::SetID(int id) {
        this->id = id;
}

void Admin::SetPass(string pass) {
        this->pass = pass;
}

string Admin::GetName() {
	return name;
}

int Admin::GetID() {
        return id;
}

string Admin::GetPass() {
        return pass;
}

