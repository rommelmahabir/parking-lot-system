#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    User(string name, int id, string pass, string make, string model, string year, string plate);

    void SetName(string name);
    void SetID(int id);
    void SetPass(string pass);
	  void SetMake(string make);
	  void SetModel(string model);
	  void SetYear(string year);
	  void SetPlate(string plate);

    string GetName();
    int GetID();
    string GetPass();
	  string GetMake();
	  string GetModel();
	  string GetYear();
	  string GetPlate();
private:
    string name;
    int id;
    string pass;
	  string make;
	  string model;
	  string year;
	  string plate;
};

#endif
