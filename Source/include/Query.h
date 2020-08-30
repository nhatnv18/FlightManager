#pragma once

#include "Ticket.h"
#include "CustomerStruct.h"

struct QueryCustomerOnFlight{
	char ordNumber[5]="";
	char index[5]="";
	char ICNumber[10]="";
	char fullName[50]="";
	char gender[10]="";
};

QueryCustomerOnFlight *queryCustomerOnFlight;

void QueryCustomerOnFlightInit(TicketsList &list){
	queryCustomerOnFlight = new QueryCustomerOnFlight[list.sold];
	int j=0;
	for(int i=0; i<list.size; i++){
		if(strlen(list.tickets[i].idPersonalNumber)>0){
			Customer tmpCus = FindNodeByICNumber(customerList, list.tickets[i].idPersonalNumber)->data;
			NumToCharArr(queryCustomerOnFlight[j].ordNumber, j+1);
			strcpy(queryCustomerOnFlight[j].index, list.tickets[i].index);
			strcpy(queryCustomerOnFlight[j].ICNumber, tmpCus.ICNumber);
			strcpy(queryCustomerOnFlight[j].fullName, tmpCus.fullName);
			strcpy(queryCustomerOnFlight[j].gender, tmpCus.gender);
			j++;
		}
	}
}
