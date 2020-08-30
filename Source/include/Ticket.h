#pragma once
#include "ArrChar_Num.h"

struct Ticket{
	char index[5]="";
	char idPersonalNumber[10]="";
};

struct TicketsList{
	Ticket *tickets;
	int size=0;
	int sold=0;
	char soldTicket[10]="";
};

void UpdateSoldTickets(TicketsList &tList){
	char sold[5]="";
	NumToCharArr(sold, tList.sold);
	strcpy(tList.soldTicket, sold);
	strcat(tList.soldTicket, "/");
	char s[5]="";
	NumToCharArr(s, tList.size);
	strcat(tList.soldTicket, s);
}

void InitNewTicketList(TicketsList &tList, int size){
	
	tList.tickets = new Ticket[size];
	tList.size = size;
	for (int i=0; i<size;i++)
	{
		char chIndex[5]="";
		NumToCharArr(chIndex, i+1);
		strcpy(tList.tickets[i].index,chIndex);
		strcpy(tList.tickets[i].idPersonalNumber,"");
	}
	UpdateSoldTickets(tList);
}

void InsertVe(TicketsList &list, int index, char* pID)
{
	if (strlen(list.tickets[index].idPersonalNumber) > 0){
		
	}
	else
	{
		strcpy(list.tickets[index].idPersonalNumber,pID);
		list.sold++;
		UpdateSoldTickets(list);
	}
}

bool isSold(TicketsList &list, int i)
{
	if (strlen(list.tickets[i].idPersonalNumber)>0) return true;
	return false;
}

void DeleteVe(TicketsList &list, int index)
{
	if (strlen(list.tickets[index].idPersonalNumber) > 0)
	{
		strcpy(list.tickets[index].idPersonalNumber,"");
		list.sold--;
		UpdateSoldTickets(list);
	}
}
