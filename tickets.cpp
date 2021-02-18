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
#include "tickets.h"
#include "ticket.h"
using namespace std;

void Tickets::AddTicket(int issuerID, string plate, Users users) {//Adds tickets to the database
  Ticket *temp;
  int ticketID;
  int ticketAmount;
  string reason;
  string status;
  int cont = 0;

  string tempOwnerName, tempMake, tempModel, tempYear, appealReason, appealStatus;
  int tempOwnerID, adminAppeal;
  
  adminAppeal = 0;
  appealReason = "No Reason Provided";
  appealStatus = " ";

  //Here is were the ticket's id would be generetaed
  while(cont != 1){
    cont = 1;
    srand(time(NULL));      //random id generator
    ticketID = (rand() % 48999)+1001;
    for(auto it = ticketList.begin(); it != ticketList.end(); ++it) {   //iterator to check if id already exist
      if ((*it)->GetID() == ticketID) {//checks to make sure id is unique
        cont = 0;
      }
    }
  }

  cout << "Auto generated ticket number is: " << ticketID << endl;
  cout << "Enter ticket amount: $";
  cin >> ticketAmount;
  cin.ignore();

  cout << "Reason of ticket: ";
  getline(cin, reason);

  /* User info will be drawn here */
  users.Reference(tempOwnerName, tempOwnerID, tempMake, tempModel, tempYear, plate);//important user data is copied

  status = "Unpaid";

  //Uses parameterized constiructor to create a new object
  temp = new Ticket(ticketID, ticketAmount, status, reason, issuerID, tempOwnerName, tempOwnerID, tempMake, tempModel, tempYear, plate, adminAppeal, appealReason, appealStatus);
  ticketList.push_back(temp);// added to vector

  cout << "Ticket has been succesfully issued." << endl;
}

void Tickets::DeleteTicket() {//Deletes tickets from the database
  int ticketID;
  cout << "Enter the ticket ID: ";
  cin >> ticketID;

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    if((*it)->GetID() == ticketID){//If ticket is found, it is erased
      ticketList.erase(it);
	  cout << "Ticket has been successfully deleted." << endl;
      return;//returns to main
    }
  }
  //This message is only displayed if ticket was not found
  cout << "Ticket wasn't found" << endl;
  cout << "Nothing was removed!" << endl;
}

void Tickets::ViewTicket() {//Displays all info on a single ticket
  int ticketID;
  cout << "Enter the ticket ID: ";
  cin >> ticketID;

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    if((*it)->GetID() == ticketID){//check for ticked id
	  cout << "*--------Ticket Information--------*" << endl;
	  cout << "                                    " << endl;
	  cout << "Ticket Number: " << setw(21) << (*it)->GetID() << endl;
	  cout << "Amount Due: " << setw(22) << "$" <<(*it)->GetTicketAmount() << endl;
	  cout << "Issued By: " << setw(25) << (*it)->GetIssue() << endl;
	  cout << "Status: " << setw(28) << (*it)->GetTicketStatus() << endl;
	  cout << "Reason: " << setw(28) << (*it)->GetReason() << endl;
	  cout << "Owner: " << setw(29) << (*it)->GetOwnerName() << endl;
	  cout << "Owner Id: " << setw(26) << (*it)->GetOwnerID() << endl;
	  cout << "Make: " << setw(30) << (*it)->GetMake() << endl;
	  cout << "Model: " << setw(29) << (*it)->GetModel() << endl;
	  cout << "Year: " << setw(30) << (*it)->GetYear() << endl;
	  cout << "Plate: " << setw(29) << (*it)->GetPlate() << endl;
	  cout << "                                    " << endl;
	  cout << "*----------------------------------*" << endl;
      return;//returns to main once found
	}
  }
  cout << "There is no ticket with this number." << endl;//If ticket not found, this message is displayed
}

void Tickets::PayTicket() {//Used to pay tickets
  int ticketID;
  string choice;
  bool ticketFound = false;

  cout << "Enter the ticket number: ";
  cin >> ticketID;

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {//Displays info for ticket in question
    if((*it)->GetID() == ticketID){
		cout << "-------------------------------------Ticket Information---------------------------------------" << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << "Ticket number     Ticket amount     Issued by     Ticket Status          Reason               " << endl;
		cout << "----------------------------------------------------------------------------------------------" << endl;
		cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(18) << (*it)->GetTicketAmount() << " " << 
		left << setw(15) << (*it)->GetIssue() << " " << setw(15) << (*it)->GetTicketStatus() << " " << left << (*it)->GetReason() << endl;
		ticketFound = true;//this variable is used to determine whether or not matching ticket has been found
		cout << endl;
    }
  }
  
  if(!ticketFound){//If no ticket is found, user is returned to menu
      cout << "There is no ticket with this number." << endl;
      return;//returns to main
  }

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    if((*it)->GetID() == ticketID){
		if ((*it)->GetAppealStatus() == "Pending") {//If the ticket is under review, user cannot pay
			cout << "This ticket is under review and cannot be paid at this time." << endl;
		}
		else if ((*it)->GetTicketStatus() == "Resolved") {//If the ticket has been resolved, user cannot pay
			cout << "Ticket has been resolved" << endl;
		}
		else if ((*it)->GetTicketStatus() == "Paid") {//If the ticket has been payed, user cannot pay again
			cout << "Ticket has already been paid" << endl;
		}
		else if ((*it)->GetTicketStatus() == "Unpaid") {//Menu to pay ticket
			cout << "Do you want to pay $" << (*it)->GetTicketAmount() << " right now? (Type in 'y' or 'n'): ";
			cin >> choice;
			while (choice != "y" && choice != "n") {//Will continue to ask user until valid input
				cout << "Invalid Choice" << endl;
				cout << "Do you want to pay $" << (*it)->GetTicketAmount() << " right now? (Type in 'y' or 'n'): ";
				cin >> choice;
			}
			if (choice == "y") {//if user agrees to pay
			  cout << "The ticket amount is paid off." << endl;
			  (*it)->SetTicketStatus("Paid");//Ticket status changed to "Paid"
			  (*it)->SetTicketAmount(0);
			}
			else {//if user does not agree
			  cout << "The ticket has not been paid off." << endl;//Ticked status remains "Unpaid"
			}
        }
		else {//If all other conditions fail, which they shouldn't
			cout << "If you see this, then something isn't right" << endl;
		}
    }
  }
}

void Tickets::ViewAllTickets() {//Used by admins to view all tickets in database
  cout << "-------------------------------------Ticket Information---------------------------------------" << endl;//displayed once 
  cout << "----------------------------------------------------------------------------------------------" << endl;
  cout << "Ticket number     Ticket amount     Issued by     Ticket Status          Reason               " << endl;
  cout << "----------------------------------------------------------------------------------------------" << endl;
  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(18) << (*it)->GetTicketAmount() << " " << //Displayes part of all ticket info
	left << setw(15) << (*it)->GetIssue() << " " << setw(15) << (*it)->GetTicketStatus() << " " << left << (*it)->GetReason() << endl;
  }
  cout << endl;
}

void Tickets::Cleanup() {//Cleans ticket database
    for(auto it = ticketList.begin(); it != ticketList.end(); ++it) {
        delete *it; //deletes data from every object
    }
    ticketList.clear(); //clears database
}

void Tickets::userView(int userID) {//Used by users to view all tickets with their user ID
	int ticketCount = 0;

	for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
		if((*it)->GetOwnerID() == userID){//Checks for matching ticket ID
			if (ticketCount < 1) {//Header only displayed once. Will not display if no tickets are found
				cout << "-------------------------------------Ticket Information---------------------------------------" << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
				cout << "Ticket number     Ticket amount     Issued by     Ticket Status          Reason               " << endl;
				cout << "----------------------------------------------------------------------------------------------" << endl;
			}
			cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(18) << (*it)->GetTicketAmount() << " " << //formatted ticket info
			left << setw(15) << (*it)->GetIssue() << " " << setw(15) << (*it)->GetTicketStatus() << " " << left << (*it)->GetReason() << endl;
			++ticketCount;
  	  }
	}
	
	if (ticketCount < 1) {//If no tickets are found
		cout << "Congrats, you have no tickets!" << endl;
	}
}

void Tickets::ViewAppeals() {//Used by admins to view all appeals
  cout << "---------------------------------------------Ticket Appeal Information--------------------------------------------------" << endl;//Header displayed once at the start
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl;//of the function
  cout << "Ticket number     Ticket amount     Issued by     Appeal Status     Granted/Rejected by      Appeal Description         " << endl;
  cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
	  if ((*it)->GetAppealStatus() != " ") {//" " is the default value of appealStatus. If appealStatus == " ", no appeal request has been filed, so they wont show here
		cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(16) << (*it)->GetTicketAmount() << " " << //formatted appeal info
		left << setw(15) << (*it)->GetIssue() << " " << setw(22) << (*it)->GetAppealStatus() << " " << left << setw(20) << (*it)->GetAdminAppeal() << 
		left << setw(15) << (*it)->GetAppealReason() <<endl;
	  }
  }
  cout << endl;
}

void Tickets::ProcessAppeal(int appealID) {//Used by admins to process appeals
  int ticketID;
  string status;
  cout << "Enter Ticket ID: ";
  cin >> ticketID;
  cin.ignore();

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    if((*it)->GetID() == ticketID){
	  if ((*it)->GetAppealStatus() == "Pending") {//Pending tickets need to be processed
		  cout << "---------------------------------------------Ticket Appeal Information--------------------------------------------------" << endl;//Displays info for appeal
		  cout << "------------------------------------------------------------------------------------------------------------------------" << endl;//in question
		  cout << "Ticket number     Ticket amount     Issued by     Appeal Status     Granted/Rejected by      Appeal Description         " << endl;
		  cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		  cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(16) << (*it)->GetTicketAmount() << " " << 
		  left << setw(15) << (*it)->GetIssue() << " " << setw(22) << (*it)->GetAppealStatus() << " " << left << setw(20) << (*it)->GetAdminAppeal() << 
		  left << setw(15) << (*it)->GetAppealReason() <<endl;
		  cout << endl;
		  
		  cout << "Do you wish to accept or reject this appeal (Type a or r): ";
		  cin >> status;
		  
		  while (status != "a" && status != "r" ) {//ensures valid response is made
			  cout << "Invalid response. Please type either 'a' or 'r'" << endl;
			  cout << "Do you wish to grant or reject this appeal (Type a or r): ";
			  cin >> status;
		  }
		  (*it)->SetAdminAppeal(appealID);
		  
		  if (status == "a") {//If appeal is accepted
			  (*it)->SetAppealStatus("Accepted");//appealStatus set to "Accepted"
			  (*it)->SetTicketStatus("Resolved");//ticketStatus set to "Resolved"
			  (*it)->SetTicketAmount(0);//Ticket no longer needs to be paid
		  }
		  else {//if appeal is rejected
			  (*it)->SetAppealStatus("Rejected");//appealStatus set to "Rejected"
		  }
		  
		  cout << "Ticket status has been updated" << endl;
		  return;//returns to main
	  }
	  else if ((*it)->GetAppealStatus() != " ") {//If valid appeal is not "Pending", then it has already been processed. appealStatus == " " means no appeal has been filed
		  cout << "This appeal has already been processed." << endl;
		  return;
	  }
	  else {//If appeal has not been filed
		  cout << "There is no appeal request for this ticket" << endl;
		  return;
	  }
    }
  }
  cout << "There is no ticket with this number" << endl;//If no ticket ID matches 
}

void Tickets::AppealTicket() {//Used by user to appeal a ticket
  int ticketID;
  string appealReason;
  cout << "Enter Ticket ID: ";
  cin >> ticketID;
  cin.ignore();

  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
    if((*it)->GetID() == ticketID){//checks for matching ID
	  if ((*it)->GetAppealStatus() == " " && (*it)->GetTicketStatus() != "Paid") {//If ticket has not been appealed before and not paid
		  cout << "What is the reason for the appeal? ";
		  getline(cin, appealReason);
		  (*it)->SetAppealReason(appealReason);
		  (*it)->SetAppealStatus("Pending");//appealStatus set to "Pending"
		  cout << "Appeal is awaiting approval." << endl;
	  }
	  else if ((*it)->GetAppealStatus() == "Pending") {//If appeal has already been filed
		  cout << "This ticket is already under review." << endl;
	  }
	  else {//If ticket has already been paid or appeal has already been processed
		  cout << "This ticket cannot be appealed." << endl;
	  }
	  return;//Returns to main
    }
  }
  cout << "You have no tickets with this number." << endl;//If no matching id is found
}

void Tickets::AppealStatus(int userID) {//Used by user to check status of all their appeals
  int appealCount = 0;//similar to userView function, checke number of appeals
  
  for (auto it = ticketList.begin(); it != ticketList.end(); ++it) {
	if ((*it)->GetOwnerID() == userID && (*it)->GetAppealStatus() != " ") {//checks for matching Id and ignores tickets that have not been appealed
		if (appealCount < 1) {//Only displayed if user has appeals
			cout << "---------------------------------------------Ticket Appeal Information--------------------------------------------------" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Ticket number     Ticket amount     Issued by     Appeal Status     Granted/Rejected by      Appeal Description         " << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		cout << left << setw(17) << (*it)->GetID() << " " << left << "$" << setw(16) << (*it)->GetTicketAmount() << " " << 
		left << setw(15) << (*it)->GetIssue() << " " << setw(22) << (*it)->GetAppealStatus() << " " << left << setw(20) << (*it)->GetAdminAppeal() << 
		left << setw(15) << (*it)->GetAppealReason() <<endl;
		++appealCount;//increases appeal num
	}
  }
  
  if (appealCount < 1) {//If no appeals are found
		cout << "You have no appeals" << endl;
	}
}