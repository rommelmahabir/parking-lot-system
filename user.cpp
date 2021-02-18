#include <iostream>
#include <string>
#include "user.h"
using namespace std;

User::User(string name, int id, string pass, string make, string model, string year, string plate) {
        this->name = name;
        this->id = id;
        this->pass = pass;
        this->make = make;
        this->model = model;
        this->year = year;
        this->plate = plate;
}

void User::SetName(string name) {
        this->name = name;
}

void User::SetID(int id) {
        this->id = id;
}

void User::SetPass(string pass) {
        this->pass = pass;
}

void User::SetMake(string make) {
        this->make = make;
}

void User::SetModel(string model) {
        this->model = model;
}

void User::SetYear(string year) {
        this->year = year;
}

void User::SetPlate(string plate) {
        this->plate = plate;
}


string User::GetName() {
        return name;
}

int User::GetID() {
        return id;
}

string User::GetPass() {
        return pass;
}

string User::GetMake() {
        return make;
}

string User::GetModel() {
        return model;
}

string User::GetYear() {
        return year;
}

string User::GetPlate() {
        return plate;
}


