#ifndef TICKETS_H
#define TICKETS_H

#include <vector>
#include <string>
#include "user.h"
#include "users.h"
#include "ticket.h"
using namespace std;

class Tickets : protected Users{
public:
  void AddTicket(int, string, Users);
  void DeleteTicket();
  void ViewTicket();
  void ViewAllTickets();
  void PayTicket();
  void Cleanup();
  void userView(int);
  void ViewAppeals();
  void ProcessAppeal(int);
  void AppealTicket();
  void AppealStatus(int);
private:
  typedef vector<Ticket*> ticketType;
  ticketType ticketList;
};

#endif
