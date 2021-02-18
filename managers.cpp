#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include "manager.h"
#include "managers.h"
#include "user.h"
#include "users.h"
using namespace std;

void Managers::Input(string managers_file) {
Manager *temp; //creates temporary manager file object to store variables
string name;
int id;
string pass;

ifstream inFile;
inFile.open(managers_file); //opens file

  while(inFile.peek()!=EOF) {
    getline(inFile, name, ','); //reads in file values to variables
    inFile >> id;
    inFile.ignore();
    getline(inFile, pass, '\n');

    temp = new Manager(name, id, pass); //puts variables into temp object
    managerList.push_back(temp); //adds object to database
  }
inFile.close(); //closes file
}

//ADD Manager
void Managers::AddManager() {
  Manager *temp; //creates temporary manager object to store variables
  string name;
  int id;
  string pass;
  int cont = 0;

  cout<< "Enter Manager's name: "<<endl;
  cin.ignore();
  getline (cin,name);

  while(cont != 1){
    cont = 1;
    srand(time(NULL));      //random id generator
    id = (rand()%500)+501;

    for(auto it = managerList.begin(); it != managerList.end(); ++it) {   //iterator to check if id already exist
      if ((*it)->GetID() == id) {
        cont = 0;
      }
    }
  }
  cout<< "Auto generated User ID for this Manager account is: "<<id<<endl;
  cout<< "Set a password for this Manager account: ";
  cin>> pass;

  temp = new Manager(name, id, pass); //puts variables into temp object
  managerList.push_back(temp); //adds object to database
  
  cout << "Management Employee has been successfully added." << endl;
}

//REMOVE MANAGER
void Managers::RemoveManager() {
  int id;
  cout<< "Enter the User ID of the Manager to be removed: ";
  cin>> id;

  for(auto it = managerList.begin(); it != managerList.end(); ++it) {   //iterator
    if ((*it)->GetID() == id) {
      managerList.erase(it);
	  cout << "Manager has been successfully removed." << endl;
      return;
    }
  }
  cout << "Manager wasn't found!" << endl;
  cout << "Nothing was removed." << endl;
}

//SEARCH MANAGER
void Managers::SearchManager() {
  int id;
  cout<<"Enter the User ID to search for the Manager: ";
  cin>> id;

  for(auto it = managerList.begin(); it != managerList.end(); ++it) {   //iterator
    if ((*it)->GetID() == id) {
		cout << "-----------------------------------" << endl;
		cout << "             Name                ID" << endl;
		cout << "-----------------------------------" << endl;
		cout << left << setw(31) << (*it)->GetName() << " " << (*it)->GetID() << endl;  //print
		return;
    }
  }
  cout << "Manager not found." << endl;
}

void Managers::Output() {
   cout << "------All Employee Information-----" << endl;
   cout << "-----------------------------------" << endl;
   cout << "             Name                ID" << endl;
   cout << "-----------------------------------" << endl;

   for(auto it = managerList.begin(); it != managerList.end(); ++it) {
           cout << left << setw(31) << (*it)->GetName() << " " << (*it)->GetID() << endl; //outputs name and id of every manager
   }
   cout << endl;
}

void Managers::Login(int current_id) {//Checks password for current input ID
  this->current_id=current_id;
  string passAttempt;

  cout<< "Enter your Password: ";
  cin>>passAttempt;

  for(auto it = managerList.begin(); it != managerList.end(); ++it) {   //cross checks with the database
  	if ((*it)->GetID() == current_id) {
    		if ((*it)->GetPass() != passAttempt) {
      			cout<< "Password attempt incorrect. Please try again." << endl;
      			Login(current_id);  //return to menu
    		}
    	}
  }
}

bool Managers::CheckID(int current_id) {//Used to determine if ID exists within database
	this->current_id=current_id;

	for(auto it = managerList.begin(); it != managerList.end(); ++it) {   //iterator
		if ((*it)->GetID() == current_id) {
			return true; //if match is found
		}
	}
	return false;//if no match found 
}

void Managers::ChangePass(){
    string pass;
    cout << "Enter your new password: ";
    cin >> pass;
    cin.ignore();

    for(auto it = managerList.begin(); it != managerList.end(); ++it) {
      if ((*it)->GetID() == current_id) {   //checks for match against id
        (*it)->SetPass(pass);       //change password
      }
    }
}

void Managers::Cleanup() {
  for(auto it = managerList.begin(); it != managerList.end(); ++it) {
          delete *it; //deletes data from every object
  }
  managerList.clear(); //clears database
}
