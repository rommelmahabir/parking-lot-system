#include <iostream>
#include <string>
#include "manager.h"
using namespace std;

Manager::Manager(string name, int id, string pass) {
        this->name = name;
        this->id = id;
        this->pass = pass;
}

void Manager::SetName(string name) {
        this->name = name;
}

void Manager::SetID(int id) {
        this->id = id;
}

void Manager::SetPass(string pass) {
        this->pass = pass;
}

string Manager::GetName() {
        return name;
}

int Manager::GetID() {
        return id;
}

string Manager::GetPass() {
        return pass;
}
