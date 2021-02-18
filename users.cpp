#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <ctime>
#include "user.h"
#include "users.h"
using namespace std;

void Users::Input(string users_file) {
  User *temp; //creates temporary user object to store variables
  string name;
  int id;
  string pass;
  string make;
  string model;
  string year;
  string plate;

  ifstream inFile;
  inFile.open(users_file); //opens file

  while(inFile.peek()!=EOF) {
      getline(inFile, name, ','); //reads in file values to variables
      inFile >> id;
      inFile.ignore();
      getline(inFile, pass, ',');
      getline(inFile, make, ',');
      getline(inFile, model, ',');
      getline(inFile, year, ',');
      getline(inFile, plate, '\n');

      temp = new User(name, id, pass, make, model, year, plate); //puts variables into temp object
      userList.push_back(temp); //adds object to database
  }
  inFile.close(); //closes file
}

//Adds a user
void Users::AddUser(){
  User *temp;
  string name;
  string pass;
  string make;
  string model;
  string year;
  string plate;
  int id;
  int cont = 0;

  while(cont != 1){
    cont = 1;
    srand(time(NULL)); //random id generator
    id = (rand() % 89999999)+ 1000001;
    for(auto it = userList.begin(); it != userList.end(); ++it) {   //iterator to check if id already exist
      if ((*it)->GetID() == id) {
        cont = 0;
      }
    }
  }

  cout << "Enter name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Your auto generated User ID is: "<< id << endl;
  cout << "Enter password: ";
  getline(cin, pass);
  cout << "Now enter your vehicle information..." << endl;
  cout << "Enter new vehicle make: ";
  getline(cin, make);
  cout << "Enter new vehicle model: ";
  getline(cin, model);
  cout << "Enter new vehicle year: ";
  getline(cin, year);
  cout << "Enter new vehicle plate number: ";
  getline(cin, plate);

  temp = new User(name, id, pass, make, model, year, plate); //grabs all the stored var into temp
  userList.push_back(temp); //pushes the tmep var to the database
  cout << "Registration is complete" << endl;
}

//Removes User
void Users::RemoveUser(){
  int id;
  User *temp;
  cout << "Enter the User ID on the account you want to remove: ";
  cin >> id;

  for (auto it = userList.begin(); it != userList.end(); ++it) {
    if((*it)->GetID() == id){
      userList.erase(it);
	  cout << "User has been successfully removed." << endl;
      return;
    }
  }
  cout << "User wasn't found!" << endl;
  cout << "Nothing was removed." << endl;
}

//Search User
void Users::SearchUser(){
  int id;
  cout << "Enter the User's ID: ";
  cin >> id;

  for (auto it = userList.begin(); it != userList.end(); ++it) {
    if((*it)->GetID() == id){
      cout << "             Name                          ID               Make               Model                 Year           Plate Number" << endl;
      cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << left << setw(36) << (*it)->GetName() << " " << (*it)->GetID() << " " << right << setw(19) << (*it)->GetMake() << " "; //prints the info for a single user
		      cout << setw(19) << (*it)->GetModel() << " " << setw(19) << (*it)->GetYear() << " " << setw(19) << (*it)->GetPlate() << endl;  //such as name, id, make, model, year, and plate #
	  return;
    }
  }
  cout << "User not found." << endl;
}

void Users::Output() {
      cout << "-----------------------------------------------------All User Information-------------------------------------------------------" << endl;
      cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
      cout << "             Name                          ID               Make               Model                 Year           Plate Number" << endl;
      cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
      for(auto it = userList.begin(); it != userList.end(); ++it) {
          cout << left << setw(36) << (*it)->GetName() << " " << (*it)->GetID() << " " << right << setw(19) << (*it)->GetMake() << " "; //outputs name, id, vehicle make, model,...
		      cout << setw(19) << (*it)->GetModel() << " " << setw(19) << (*it)->GetYear() << " " << setw(19) << (*it)->GetPlate() << endl; //...year, and plate number of every user
      }
      cout << endl;
}

void Users::Login(int current_id){ //Checks password
  this->current_id=current_id;
  string passAttempt;

  cout<< "Enter your Password: ";
  cin>>passAttempt;

  for(auto it = userList.begin(); it != userList.end(); ++it) {
    if ((*it)->GetID() == current_id) {
    		if ((*it)->GetPass() != passAttempt) {
      			cout<< "Password attempt incorrect. Please try again." << endl;
      			Login(current_id);  //return to menu
    		}
    }
  }
}

bool Users::CheckID(int current_id) { //Used to determine if ID exists within database
	this->current_id=current_id;

	for(auto it = userList.begin(); it != userList.end(); ++it) {   //iterator
		if ((*it)->GetID() == current_id) {
			return true;
		}
	}
	return false;
}

bool Users::CheckPlate(string plateNum) { //Used to determine if plate number exists within database
	this->plateNum=plateNum;

	for(auto it = userList.begin(); it != userList.end(); ++it) {   //iterator
		if ((*it)->GetPlate() == plateNum) {
			return true;
		}
	}
	return false;
}

void Users::ChangePass(){ //This function checks if the password is in the database, then gives the option to the user to change password
    string pass;
    cout<< "Enter your new password."<<endl;
    cin>> pass;
    cin.ignore();

    for(auto it = userList.begin(); it != userList.end(); ++it) {   //iterator
      if ((*it)->GetID() == current_id) {   //checks for match against id
        (*it)->SetPass(pass);       //change password
		cout << "Password has been successfully updated." << endl;
      }
    }
}

//Changes vehicle information
void Users::ChangeVehicle(){
  string make;
  string model;
  string year;
  string plate;

  cout << "Enter new vehicle make: ";
  cin.ignore();
  getline(cin, make);
  cout << "Enter new vehicle model: ";
  getline(cin, model);
  cout << "Enter new vehicle year: ";
  getline(cin, year);
  cout << "Enter new vehicle plate number: ";
  getline(cin, plate);

  for(auto it = userList.begin(); it != userList.end(); ++it) {   //iterator
    if ((*it)->GetID() == current_id) {   //checks for match against id
      (*it)->SetMake(make); //Stores the vars into the database and rewrites the old info
      (*it)->SetModel(model);
      (*it)->SetYear(year);
      (*it)->SetPlate(plate);
    }

  }
}

//Funtion to view the user vehicle information
void Users::ViewVehicle(){
  for(auto it = userList.begin(); it != userList.end(); ++it) {
    if ((*it)->GetID() == current_id) {
      cout << "\nVehicle make: " << (*it)->GetMake() << endl;
      cout << "Vehicle model: " << (*it)->GetModel() << endl;
      cout << "Vehicle year: " << (*it)->GetYear() << endl;
      cout << "Vehicle plate number: " << (*it)->GetPlate() << endl;
    }
  }
}

//Function to cleanup the user database
void Users::Cleanup() {
      for(auto it = userList.begin(); it != userList.end(); ++it) {
              delete *it; //deletes data from every object
      }
      userList.clear(); //clears database
}

void Users::Reference(string &ownerName, int &ownerID, string &make, string &model, string &year, string plate) {//Passes variables by reference to copy specific data to different location

  for (auto it = userList.begin(); it != userList.end(); ++it) {
    if((*it)->GetPlate() == plate){
	  ownerName = (*it)->GetName();
	  ownerID = (*it)->GetID();
      make = (*it)->GetMake();
      model = (*it)->GetModel();
      year = (*it)->GetYear();
      return;
    }
  }
  cout << "No such reference found" << endl; //If Plate num not found
}
