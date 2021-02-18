#ifndef MANAGERS_H
#define MANAGERS_H

#include <vector>
#include <string>
#include "manager.h"
using namespace std;

class Managers {
public:
    void Input(string managers_file);
    void Output();
    void Cleanup();
    void Login(int current_id);
    void AddManager();
    void RemoveManager();
    void SearchManager();
    void ChangePass();
	bool CheckID(int current_id);
private:
    typedef vector<Manager*> managerType;
    managerType managerList;
    int current_id;
};
#endif
