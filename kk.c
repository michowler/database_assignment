#include<stdio.h>
#include<stdlib.h>

struct Traveller {
  int Ticket_ID;
  char Destination;
  float Price;
};

void CreateTicket(struct Traveller*);
void PrintTicket(struct Traveller*);

int main(void) {

   struct Traveller * str;

   CreateTicket(str);
   PrintTicket(str);

   return 0;

 }

void CreateTicket(struct Traveller* ptr) {

 printf("Please enter your ticket ID.\n");
 scanf("%d", &ptr->Ticket_ID);
 printf("\n\nPlease enter your destination.\n");
 scanf("%s",&ptr->Destination);
 printf("\n\nPlease enter the price.\n");
 scanf("%f", &ptr->Price);

 }

void PrintTicket(struct Traveller* ptr) {
  printf("\n\n%d\n", ptr->Ticket_ID);
  printf("%s\n", &ptr->Destination);
  printf("%.2f\n", ptr->Price);
}