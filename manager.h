#ifndef MANAGER_H
#define MANAGER_H

#include <string>
using namespace std;

class Manager {
public:
    Manager(string name, int id, string pass);
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
