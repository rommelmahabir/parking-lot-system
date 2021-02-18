//  CSCE 2110
//  Group 33

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "lot.h"
#include "lots.h"
#include "manager.h"
#include "managers.h"
#include "user.h"
#include "users.h"
#include "admin.h"
#include "admins.h"
#include "ticket.h"
#include "tickets.h"
using namespace std;

Lots lots;
Admins admins;
Managers managers;
Users users;
Tickets tickets;

int main()
{
	vector<string> csvFiles; //vector for csv file names

	csvFiles = lots.Input(); //both inputs data into the lots database and retrieves csv file names
	lots.Output();
	admins.Input(csvFiles[0]); //inputs data into databases and outputs the data
	admins.Output();
	managers.Input(csvFiles[1]);
	managers.Output();
	users.Input(csvFiles[2]);
	users.Output();

	int option;
	int idAttempt;
	int selection;
	bool IDmatch;
	bool plateMatch;
	string inputPlate;

	while(option != 3){
		selection = 0;
		cout << "\n*************** Main Menu ***************" << endl;	// Single login menu for the parking System
		cout << "Enter 1 to login to the system." << endl;
		cout << "Enter 2 to register in the system." << endl;
		cout << "Enter 3 to exit the system." << endl;
		cout << "Option: ";
		cin >> option;

		switch (option){
		    case 1:
				cout<< "Enter your ID: ";
				cin>> idAttempt;

				IDmatch = false;

				while (IDmatch == false) {//checks to make sure that id is a valid id
					if (admins.CheckID(idAttempt) == true) {
						IDmatch = true;
					}
					else if (managers.CheckID(idAttempt) == true) {
						IDmatch = true;
					}
					else if (users.CheckID(idAttempt) == true) {
						IDmatch = true;
					}
					else {
						cout<< "Invalid ID. Try again: ";
						cin>> idAttempt;
					}
				}
				if (idAttempt >= 101 && idAttempt <= 500){	//calls the admin menu for id between the range

					admins.Login(idAttempt);

					while(selection != 15) {
						cout << "\nSelect the following option for a particular task.         " << endl;
						cout << "Select 1 to add new Administrative Employee.                          " << endl;
						cout << "Select 2 to remove new Administrative Employee.                       " << endl;
						cout << "Select 3 to view all Administrative Employee information.             " << endl;
						cout << "Select 4 to search information for a specific Administrative Employee." << endl;
						cout << "Select 5 to change password.                                          " << endl;
						cout << "Select 6 to add new Management Employee.                              " << endl;
						cout << "Select 7 to remove new Management Employee.                           " << endl;
						cout << "Select 8 to view all Management Employee information.                 " << endl;
						cout << "Select 9 to search information for a specific Management Employee.    " << endl;
						cout << "Select 10 to remove User.                                             " << endl;
						cout << "Select 11 to view all User information.                               " << endl;
						cout << "Select 12 to search information for a specific User.                  " << endl;
						cout << "Select 13 to view appeal information.                                 " << endl;
						cout << "Select 14 to process an appeal.                                       " << endl;
						cout << "Select 15 to logout.                                                  " << endl;
						cout << "Option: ";
						cin >> selection;

						switch (selection){
							case 1:
								admins.AddEmp();
								break;
							case 2:
								admins.RemoveEmp();
								break;
							case 3:
								admins.Output();
								break;
							case 4:
								admins.SearchEmp();
								break;
							case 5:
								admins.ChangePass();
								break;
							case 6:
								managers.AddManager();
								break;
							case 7:
								managers.RemoveManager();
								break;
							case 8:
								managers.Output();
								break;
							case 9:
								managers.SearchManager();
								break;
							case 10:
								users.RemoveUser();
								break;
							case 11:
								users.Output();
								break;
							case 12:
								users.SearchUser();
								break;
							case 13:
								//BONUS: view appeal Information
								tickets.ViewAppeals();
								break;
							case 14:
								//BONUS: process an appeal
								tickets.ProcessAppeal(idAttempt);
								break;
							case 15:
								cout<< "You have successfully logged out."<<endl; //exit
								break;
							default:
								cout<< "You have selected an invalid option. Please try again." <<endl;
						}
					}
				}
				else if (idAttempt >= 501 && idAttempt <= 1000) {//calls the manager menu for id between the range
					managers.Login(idAttempt);

					while (selection != 9) {
						cout << "\nSelect the following option for a particular task.      " << endl;
						cout << "Select 1 to remove user.                                  " << endl;
						cout << "Select 2 to view all user information.                    " << endl;
						cout << "Select 3 to search information of a specific user.        " << endl;
						cout << "Select 4 to issue a ticket.                               " << endl;
						cout << "Select 5 to view all the ticket information.              " << endl;
						cout << "Select 6 to view a specific ticket information in details." << endl;
						cout << "Select 7 to remove a specific ticket information.         " << endl;
						cout << "Select 8 to change password.                              " << endl;
						cout << "Select 9 to Log out.                                      " << endl;
						cout << "Option: ";
						cin >> selection;
						cin.ignore();

						switch (selection) {
							case 1:
								users.RemoveUser();
								break;
							case 2:
								users.Output();
								break;
							case 3:
								users.SearchUser();
								break;
							case 4:
								cout << "Enter vehicle plate number: ";
								getline(cin, inputPlate);
								plateMatch = false;
								plateMatch = users.CheckPlate(inputPlate);//returns true or false, depending on whether plate num is stored in database

								if (plateMatch) {//if plate exists
									tickets.AddTicket(idAttempt, inputPlate, users);
								}
								else {//If plate does not exist
									cout << "Plate does not match any on record. " << endl;
								}
								break;
							case 5:
								tickets.ViewAllTickets();
								break;
							case 6:
								tickets.ViewTicket();
								break;
							case 7:
								tickets.DeleteTicket();
								break;
							case 8:
								managers.ChangePass();
								break;
							case 9:
								cout<< "You have successfully logged out."<<endl; //exit
								break;
							default:
								cout<< "You have selected an invalid option. Please try again."<<endl;
						}
					}
				}
				else if (idAttempt >= 1001 && idAttempt <= 99999999) {//calls the user menu for id between the range
					users.Login(idAttempt);

					while (selection != 8) {
						cout << "\nSelect the following option for a particular task." << endl;
						cout << "Select 1 to change password.                        " << endl;
						cout << "Select 2 to change vehicle information.             " << endl;
						cout << "Select 3 to view vehicle information.               " << endl;
						cout << "Select 4 to view all ticket information.            " << endl;
						cout << "Select 5 to pay a ticket amount.                    " << endl;
						cout << "Select 6 to appeal against a ticket.                " << endl;
						cout << "Select 7 to view appeal information.                " << endl;
						cout << "Select 8 to Log out.                                " << endl;
						cout << "Option: ";
						cin >> selection;

						switch (selection) {
						 	case 1:
								users.ChangePass();
								break;
							case 2:
								users.ChangeVehicle();
								break;
							case 3:
								users.ViewVehicle();
								break;
							case 4:
								tickets.userView(idAttempt);
								break;
							case 5:
								tickets.PayTicket();
								break;
							case 6:
								//BONUS: Appeal against a ticket
								tickets.AppealTicket();
								break;
							case 7:
								//BONUS: View appeal information
								tickets.AppealStatus(idAttempt);
								break;
							case 8:
								cout<< "You have successfully logged out."<<endl; //exit
								break;
						}
					}
				}
				else {
					cout << "Invalid User ID. Please try again."<<endl;
				}
				break;
			case 2:
				users.AddUser();
				break;
			case 3:
				cout << "You have successfuly exited the system." << endl;	//EXIT THE MENU
				break;
			default:
				cout << "!!Wrong option!! Select the right choice again." << endl;
		}
	}

	//cleans up the databases
	lots.Cleanup();
	admins.Cleanup();
	managers.Cleanup();
	users.Cleanup();
	tickets.Cleanup();

	return 0;
}
