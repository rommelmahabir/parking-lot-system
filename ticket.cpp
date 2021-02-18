#include <vector>
#include <string>
#include "ticket.h"
using namespace std;

Ticket::Ticket(int id, int ticketAmount, string ticketStatus, string reason, int issuerID, string ownerName, int ownerID, string make, string model, string year, string plate, int adminAppeal, string appealReason, string appealStatus){
  this->id = id;
  this->ticketAmount = ticketAmount;
  this->ticketStatus = ticketStatus;
  this->reason = reason;
  this->issuerID = issuerID;
  this->ownerName = ownerName;
  this->ownerID = ownerID;
  this->make = make;
  this->model = model;
  this->year = year;
  this->plate = plate;
  this->adminAppeal = adminAppeal;
  this->appealReason = appealReason;
  this->appealStatus = appealStatus;
}

void Ticket::SetID(int ticketID){
  this->id = ticketID;
}
void Ticket::SetTicketAmount(int ticketAmount){
  this->ticketAmount = ticketAmount;
}
void Ticket::SetReason(string reason){
  this->reason = reason;
}
void Ticket::SetTicketStatus(string ticketStatus){
  this->ticketStatus = ticketStatus;
}
void Ticket::SetIssue(int issuerID){
  this->issuerID = issuerID;
}
void Ticket::SetOwnerName(string ownerName){
  this->ownerName = ownerName;
}
void Ticket::SetOwnerID(int ownerID){
  this->ownerID = ownerID;
}
void Ticket::SetMake(string make){
  this->make = make;
}
void Ticket::SetModel(string model){
  this->model = model;
}
void Ticket::SetYear(string year){
  this->year = year;
}
void Ticket::SetPlate(string plate){
  this->plate = plate;
}
void Ticket::SetAdminAppeal(int adminAppeal) {
  this->adminAppeal = adminAppeal;
}
void Ticket::SetAppealReason(string appealReason) {
  this->appealReason = appealReason;
}
void Ticket::SetAppealStatus(string appealStatus) {
  this->appealStatus = appealStatus;
}

int Ticket::GetID(){
  return id;
}
int Ticket::GetTicketAmount(){
  return ticketAmount;
}
string Ticket::GetReason(){
  return reason;
}
string Ticket::GetTicketStatus(){
  return ticketStatus;
}
int Ticket::GetIssue(){
  return issuerID;
}
string Ticket::GetOwnerName(){
  return ownerName;
}
int Ticket::GetOwnerID(){
  return ownerID;
}
string Ticket::GetMake(){
  return make;
}
string Ticket::GetModel(){
  return model;
}
string Ticket::GetYear(){
  return year;
}
string Ticket::GetPlate(){
  return plate;
}
int Ticket::GetAdminAppeal() {
  return adminAppeal;
}
string Ticket::GetAppealReason() {
  return appealReason;
}
string Ticket::GetAppealStatus() {
  return appealStatus;
}
