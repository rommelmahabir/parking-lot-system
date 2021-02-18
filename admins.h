#ifndef ADMINS_H
#define ADMINS_H

#include <vector>
#include <string>
#include "admin.h"
using namespace std;

class Admins{
public:
    void Input(string admins_file);
    void Output();
    void Cleanup();
    void Login(int current_id);
    void Menu();
    void AddEmp();
    void RemoveEmp();
    void SearchEmp();
    void ChangePass();
	bool CheckID(int current_id);
private:
    typedef vector<Admin*> adminType;
    adminType adminList;
    int current_id;

};
#endif
