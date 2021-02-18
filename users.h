#ifndef USERS_H
#define USERS_H

#include <vector>
#include <string>
#include "user.h"
using namespace std;

class Users {
public:
    void Input(string users_file);
    void Output();
    void Cleanup();
    void Login(int current_id);
    void AddUser();
    void RemoveUser();
    void SearchUser();
    void ChangePass();
    void ChangeVehicle();
    void ViewVehicle();
	  bool CheckID(int current_id);
	  bool CheckPlate(string plateNum);
	  void Reference(string &ownerName, int &ownerID, string &make, string &model, string &year, string plate);
	  typedef vector<User*> userType;
protected:
    userType userList;
    int current_id;
	string plateNum;
};

#endif
