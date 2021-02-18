#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin {
public:
    Admin(string name, int id, string pass);
    void SetName(string name);
    void SetID(int id);
    void SetPass(string pass);
    string GetName();
    int GetID();
    string GetPass();
private:
    string name;
    int id;
    string pass;
};
#endif
