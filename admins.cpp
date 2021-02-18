#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "admin.h"
#include "admins.h"
#include "manager.h"
#include "managers.h"
#include "user.h"
#include "users.h"
using namespace std;

void Admins::Input(string admins_file) {
  Admin *temp; //creates temporary admin object to store variables
  string name;
	int id;
	string pass;

  ifstream inFile;
  inFile.open(admins_file); //opens file

  while(inFile.peek()!=EOF) {
  	getline(inFile, name, ','); //reads in file values to variables
  	inFile >> id;
  	inFile.ignore();
  	getline(inFile, pass, '\n');

    temp = new Admin(name, id, pass); //puts variables into temp object
    adminList.push_back(temp); //adds object to database
  }
  inFile.close(); //closes file
}

void Admins::Output() {
	cout << "\nAll Administrative Employee Information" << endl;
  cout << "---------------------------------------" << endl;
  cout << "          Name                ID       " << endl;
  cout << "---------------------------------------" << endl;

	for(auto it = adminList.begin(); it != adminList.end(); ++it) {
      cout << left << setw(31) << (*it)->GetName() << " " << (*it)->GetID() << endl; //outputs name and id of every admin
  }
	cout << endl;
}

//MENU
void Admins::Login(int current_id) {//Checks password
	this->current_id=current_id;

	string passAttempt;
	cout<< "Enter your Password: ";
	cin>>passAttempt;

	for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //cross checks with the database
		if ((*it)->GetID() == current_id) {
			if ((*it)->GetPass() != passAttempt) {
				cout<< "Password attempt incorrect. Please try again."<<endl;
				Login(current_id);  //return to menu
			}
		}
	}
}

bool Admins::CheckID(int current_id) {//Used to determine if ID exists within database
	this->current_id=current_id;

	for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //iterator
		if ((*it)->GetID() == current_id) {
			return true;
		}
	}

	return false;
}

//ADD
void Admins::AddEmp() {
  Admin *temp; //creates temporary admin object to store variables
  string name;
  int id;
  string pass;
  int cont = 0;

  cout<< "\nEnter Administrative Employee's name: ";
  cin.ignore();
  getline (cin,name);

  while(cont != 1){
    cont = 1;
    srand(time(NULL));      //random id generator
    id = (rand()%400)+101;
    for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //iterator to check if id already exist
      if ((*it)->GetID() == id) {
        cont = 0;
      }
    }
  }
  cout<< "Auto generated User ID for this Administrative Employee account is: "<<id<<endl;
  cout<< "Set a password for this Administrative Employee account: ";
  cin>> pass;

  temp = new Admin(name, id, pass); //puts variables into temp object
  adminList.push_back(temp); //adds object to database
  
  cout << "Administrative Employee has been successfully added." << endl;

}

//REMOVE
void Admins::RemoveEmp() {
  int id;
  cout<< "Enter the User ID of the Administrative Employee to be removed: ";
  cin>> id;

  for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //iterator
    if ((*it)->GetID() == id) {
      adminList.erase(it);
	  cout << "Admin has been successfully removed." << endl;
      return;
    }
  }
  cout << "Admin wasn't found!" << endl;
  cout << "Nothing was removed." << endl;
}

//SEARCH
void Admins::SearchEmp() {
  int id;
  cout<<"Enter the User ID to search for the Administrative Employee: ";
  cin>> id;

  for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //iterator
    if ((*it)->GetID() == id) {
		cout << "---------------------------------------" << endl;
		cout << "          Name                ID       " << endl;
		cout << "---------------------------------------" << endl;
		cout << left << setw(31) << (*it)->GetName() << " " << (*it)->GetID() << endl;  //print
		return; //returns to main after employee is displayed
    }
  }
  
  cout << "Admin not found." << endl;
}

//CHANGE PASSWORD
void Admins::ChangePass() {
  string pass;
  cout << "Enter your new password: ";
  cin >> pass;
  cin.ignore();

  for(auto it = adminList.begin(); it != adminList.end(); ++it) {   //iterator
    if ((*it)->GetID() == current_id) {   //checks for match against id
      (*it)->SetPass(pass);       //change password
	  cout << "Password has been successfully updated." << endl;
    }
  }
}

void Admins::Cleanup() {
        for(auto it = adminList.begin(); it != adminList.end(); ++it) {
                delete *it; //deletes data from every object
        }
        adminList.clear(); //clears database
}
