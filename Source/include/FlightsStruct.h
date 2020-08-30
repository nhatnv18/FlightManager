#pragma once
#include "DateTime.h"
#include "Ticket.h"
#include "PlaneStruct.h"

struct Flight{
	char flightID[15];
	DateTime timeStart;
	char to[50];
	int status;     //0: cancel | 1: tickets selling | 2: out of tickets | 3: complete | 4: took off
	char planeID[15];
	TicketsList ticket;
	char dtime[30]="";
};

struct NodeFlight{
	Flight data;
	NodeFlight *pNext;
};

struct FlightList{
	NodeFlight* phead=NULL;
	NodeFlight* ptail=NULL;
	int size=0;
};

FlightList flightList;

Flight CreateNewFlight(char *flightID, DateTime start, char *to, char *planeID){
	
	Flight tmp;
	strcpy(tmp.flightID, flightID);
	tmp.timeStart = start;
	char startTime[30]="";
	DateTimeToText(startTime, start);
	strcpy(tmp.dtime, startTime);
	strcpy(tmp.to, to);
	tmp.status = 1;
	strcpy(tmp.planeID, planeID);
	
	Planes *plane = FindPlaneByID(planeID);
	InitNewTicketList(tmp.ticket, plane->seat);

	return tmp;
}

Flight ReCreateFlight(char *flightID, DateTime start, char *to, char *planeID, int stt){
	
	Flight tmp;
	strcpy(tmp.flightID, flightID);
	tmp.timeStart = start;
	char startTime[30]="";
	DateTimeToText(startTime, start);
	strcpy(tmp.dtime, startTime);
	strcpy(tmp.to, to);
	tmp.status = stt;
	strcpy(tmp.planeID, planeID);
	
	Planes *plane = FindPlaneByID(planeID);
	InitNewTicketList(tmp.ticket, plane->seat);

	return tmp;
}

NodeFlight *NewNodeFlight(Flight x)
{
	NodeFlight *p = new NodeFlight;
	if (p==NULL) return NULL;
		
	p->data =x;
	p->pNext = NULL;
	return p;
}
void Insert_Tail_Flight(FlightList &l, NodeFlight *p)
{
	if (l.phead==NULL){
		l.phead=l.ptail=p;
	}
	else{
		l.ptail->pNext=p;
		l.ptail=p;
	}
	l.size++;
}

void DeleteHead(FlightList &l)
{
	NodeFlight *p = l.phead;
	l.phead = p->pNext;
	delete p;
	l.size--;
}

void DeleteTail(FlightList &l)
{
	for(NodeFlight *k = l.phead; k != NULL; k = k->pNext)
	{
		if(k->pNext == l.ptail)
		{
			delete l.ptail;
			k->pNext=NULL;
			l.ptail=k;
			l.size--;
			return;
		}
	}
}

//Xoa chuyen bay theo ma chuyenbay
void Delete_Any_Flight(FlightList &l, char* flightID)
{
	NodeFlight* p = l.phead;
	if (l.phead==NULL) return;
	else 
	if (strcmp(l.phead->data.flightID,flightID)==0) DeleteHead(l);
	else
	if (strcmp(l.ptail->data.flightID,flightID)==0) DeleteTail(l);
	else
	for (p=l.phead; p->pNext!=NULL;p=p->pNext)
	{
		if (strcmp(p->pNext->data.flightID,flightID)==0) {
			NodeFlight* t = p->pNext;
			p->pNext= t->pNext;
			delete t;
			l.size--;
			return ;
		}
	}
}

NodeFlight *Find_Flight(FlightList &l, char* flightID)
{
	NodeFlight* p= l.phead;
	for (p=l.phead;p!=NULL;p=p->pNext)
	{
		if(strcmp(p->data.flightID,flightID)==0){
			return p;
		}
	}
	return NULL;
};

void Edit_Flight(FlightList &l, char* flightID, DateTime d)
{
	NodeFlight* p = Find_Flight(l,flightID);
	
	p->data.timeStart=d;
	char s[30]="";
	DateTimeToText(s, d);
	strcpy(p->data.dtime, s);
}	

void Cancel_Flight(FlightList &l, char* flightID)
{
	NodeFlight* p = Find_Flight(l,flightID);
	p->data.status=0;
}


void ClearAllFlightsList(FlightList &l){
	NodeFlight *tmp = l.phead;
	while(tmp!=NULL){
		NodeFlight *pretmp = tmp;
		tmp=tmp->pNext;
		delete pretmp;
	}
	l.phead=NULL;
	l.ptail=NULL;
	l.size=0;
}

void searchFlightByData(FlightList list, FlightList &oldList, char *flightID, int day, int month, int year, char *To){
	ClearAllFlightsList(oldList);
	NodeFlight *tmp = list.phead;
	while(tmp!=NULL){

		if(isSubString(tmp->data.flightID, flightID) && isSubString(tmp->data.to, To) && 
			(
			(day==0 && month==0 && year==0) ||
			(tmp->data.timeStart.day==day && month==0 && year==0) ||
			(day==0 && tmp->data.timeStart.month==month && year==0) ||
			(day==0 && month==0 && tmp->data.timeStart.year==year) ||
			(tmp->data.timeStart.day==day && tmp->data.timeStart.month==month && year==0) ||
			(tmp->data.timeStart.day==day && month==0 && tmp->data.timeStart.year==year) ||
			(day==0 && tmp->data.timeStart.month==month && tmp->data.timeStart.year==year) ||
			(tmp->data.timeStart.day==day && tmp->data.timeStart.month==month && tmp->data.timeStart.year==year)
			)
		){
			Insert_Tail_Flight(oldList, NewNodeFlight(tmp->data));
		}
		tmp=tmp->pNext;
	}
}

bool isFlightSold(char *flightID){
	NodeFlight *tmp = Find_Flight(flightList, flightID);
	if(tmp->data.ticket.sold==0) return false;
	return true;
}

void UpdateCompletePerRead(){
	NodeFlight *tmp = flightList.phead;
	while(tmp!=NULL){
		if((tmp->data.status==1 || tmp->data.status==2 || tmp->data.status==4) && MinToHour(MinSub(tmp->data.timeStart, GetNow()))>=3){
			tmp->data.status=3;
		}
		else if((tmp->data.status==1 || tmp->data.status==2) && MinToHour(MinSub(tmp->data.timeStart, GetNow()))>0){
			tmp->data.status=4;
		}
		tmp = tmp->pNext;
	}
}

bool isPlaneUsedInTimeRange(FlightList list, char *planeID, DateTime tmpStartTime, char *flightID){
	NodeFlight *tmp = list.phead;
	while(tmp!=NULL){
		if(strlen(flightID)==0 || strcmp(tmp->data.flightID, flightID)!=0){
			if(tmp->data.status==0 || tmp->data.status==3){
			}
			else{
				if(strcmp(tmp->data.planeID, planeID)==0){
					unsigned long int minFlightStart = MinDiff(tmp->data.timeStart);
					unsigned long int minFlightEnd = minFlightStart+180;
					unsigned long int minNewStart = MinDiff(tmpStartTime);
					unsigned long int minNewEnd = minNewStart+180;
					
					if((minNewStart>=minFlightStart && minNewStart<=minFlightEnd) ||
					(minNewEnd>=minFlightStart && minNewEnd<=minFlightEnd)
					){
						return true;
					}
					
				}
			}
		}
		
		tmp=tmp->pNext;
	}
	return false;
}
