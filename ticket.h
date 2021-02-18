#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include <string>
using namespace std;

class Ticket{
public:
  Ticket(int, int, string, string, int,  string, int, string, string, string, string, int, string, string);
  void SetID(int);
  void SetTicketAmount(int);
  void SetReason(string);
  void SetTicketStatus(string);
  void SetIssue(int);
  void SetOwnerName(string);
  void SetOwnerID(int);
  void SetMake(string);
  void SetModel(string);
  void SetYear(string);
  void SetPlate(string);
  void SetAdminAppeal(int);
  void SetAppealReason(string);
  void SetAppealStatus(string);
  
  int GetID();
  int GetTicketAmount();
  string GetReason();
  string GetTicketStatus();
  int GetIssue();
  string GetOwnerName();
  int GetOwnerID();
  string GetMake();
  string GetModel();
  string GetYear();
  string GetPlate();
  int GetAdminAppeal();
  string GetAppealReason();
  string GetAppealStatus();
  
private:
  int id;
  int ticketAmount;
  string ticketStatus;
  string reason;
  int issuerID;
  string ownerName;
  int ownerID;
  string make;
  string model;
  string year;
  string plate;
  int adminAppeal;
  string appealReason;
  string appealStatus;
};

#endif
