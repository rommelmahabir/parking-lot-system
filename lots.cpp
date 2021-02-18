#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "lot.h"
#include "lots.h"
#include "admin.h"
#include "admins.h"
#include "manager.h"
#include "managers.h"
#include "user.h"
#include "users.h"
using namespace std;

vector<string> Lots::Input() {
	string file_name;

	vector<string> csvFiles; //creates vector to store csv file names to return back to main.cpp
	string admins_file;
	string managers_file;
	string users_file;

	Lot *temp; //creates temporary lot object to store variables
	int lot_amount;
	int space;
	int r_space;
	int m_space;
	int d_space;

	cout << "Enter file name: ";
	getline(cin, file_name); //gets input file name from user

	ifstream inFile;
	inFile.open(file_name);

	while(!inFile.is_open()) { //checks if the file name works
		cout << "File not found." << endl << "Enter file name: ";
		getline(cin, file_name);
		inFile.open(file_name);
	}

	inFile >> lot_amount; //checks for amount of lots in file

	for(int i = 0; i < lot_amount; ++i) {
		inFile >> r_space; //reads in file values to variables
		inFile >> m_space;
		inFile >> d_space;
		space = r_space + m_space + d_space;

		temp = new Lot(space, r_space, m_space, d_space); //puts variables into temp object
		lotList.push_back(temp); //adds object to database
	}

	inFile >> admins_file; //reads in csv file names to variables
	inFile >> managers_file;
	inFile >> users_file;

	csvFiles.push_back(admins_file); //stores csv file names into vector
	csvFiles.push_back(managers_file);
	csvFiles.push_back(users_file);

	inFile.close(); //closes file

	return csvFiles; //returns csv file names to main so it can call Input() functions
}

void Lots::Output() {
	int lot_number = 0;
	int columns = 0; //will be used to count columns in layout output
	int rows = 0; //will be used to count amount of rows for regular parking space in layout output
	for(auto it = lotList.begin(); it != lotList.end(); ++it) {
		++lot_number;
		columns = (*it)->GetMSpace() + (*it)->GetDSpace(); //sets columns so that the first row is motorcycle and disability space, and every other row is regular space
		cout << "Parking lot number: " << lot_number << endl;
		cout << "Number of parking space: " << (*it)->GetSpace() << endl;
		cout << "Number of regular parking space: " << (*it)->GetRSpace() << endl;
		cout << "Number of motorcycle parking space: " << (*it)->GetMSpace() << endl;
		cout << "Number of disability parking space: " << (*it)->GetDSpace() << endl;
		cout << "Parking space layout is shown below." << endl;
		cout << "-";
		for(int i = 0; i < columns; ++i) {
			cout << "----";
		}
		cout << endl;

		cout << "|";
		for(int i = 0; i < (*it)->GetMSpace(); ++i) {
			cout << " M |"; //prints each motorcycle space
		}
		for(int i = 0; i < (*it)->GetDSpace(); ++i) {
			cout << " D |"; //prints each disability space
		}
		cout << endl;

		if(columns < 5) {
                        columns = 5; //minimum column count for regular space rows so that the layout isn't too long vertically
                }

		cout << "-";
		for(int i = 0; i < columns; ++i) {
                        cout << "----";
                }
		cout << endl;

		rows = (*it)->GetRSpace() / columns; //calculates proper row count to show all regular parking space
		if(((*it)->GetRSpace() % columns) != 0) {
			rows++; //rounds row count up if there's a remainder
		}

		for(int i = 0; i < rows; ++i) {
			cout << "|";
			if((rows - i) > 1) { //for every row other than the last one
                		for(int j = 0; j < columns; ++j) {
                        		cout << " R |"; //prints a full row of regular space
                		}
				cout << endl;
				cout << "-";
                	        for(int j = 0; j < columns; ++j) {
        	                        cout << "----";
	                        }
				cout << endl;
			}
			else { //for the last row
				for(int j = 0; j < (*it)->GetRSpace() - (i * columns); ++j) {
					cout << " R |"; //prints remaining regular space
				}
				cout << endl;
				cout << "-";
                	        for(int j = 0; j < (*it)->GetRSpace() - (i * columns); ++j) {
        	                        cout << "----";
	                        }
				cout << endl;
			}
		}
		cout << endl;
	}
}

void Lots::Cleanup() {
	for(auto it = lotList.begin(); it != lotList.end(); ++it) {
		delete *it; //deletes data from every object
	}
	lotList.clear(); //clears database
}
