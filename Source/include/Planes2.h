#pragma once
#include "ArrChar_Num.h"
#include "FlightsStruct.h"
#include "PlaneStruct.h"
//#define MAX_PLANES 300

//struct Planes{
//	char planeID[15]="";
//	char planeKind[40]="";
//	char chrSeat[10]="";
//	int seat=0;
//};
//
//struct PlaneLists{
//	Planes *list[MAX_PLANES];
//	int size=0;
//};

PlaneLists planeAddArray;

Planes PlaneCreate(char *id, char *kind, int seat){
	Planes tmp;
	strcpy(tmp.planeID,id);
	strcpy(tmp.planeKind,kind);
	tmp.seat = seat;
	NumToCharArr(tmp.chrSeat, seat);
	return tmp;
}

void PlaneAdd(Planes plane){
	planeAddArray.list[planeAddArray.size] = new Planes;
	*planeAddArray.list[planeAddArray.size] = plane;
	planeAddArray.size++;
}

void PlaneRemoveByIndex(int index){
	delete planeAddArray.list[index];
	for(int i=index; i<planeAddArray.size-1; i++){
		planeAddArray.list[i]=planeAddArray.list[i+1];
	}
	planeAddArray.size--;
}

void PlaneEditByIndex(int index, char *kind){
	strcpy(planeAddArray.list[index]->planeKind, kind);
}

void ClearAllPlaneList(){
	for(int i=0; i<planeAddArray.size; i++){
		delete planeAddArray.list[i];
		planeAddArray.size--;
	}
}

Planes *FindPlaneByID(char *id){
	for(int i=0; i<planeAddArray.size; i++){
		if(strcmp(planeAddArray.list[i]->planeID, id)==0){
			return planeAddArray.list[i];
		}
	}
	return NULL;
}

bool isPlaneInAnyRelationship(char *planeID){
	NodeFlight *tmp = flightList.phead;
	while(tmp!=NULL){
		if(strcmp(tmp->data.planeID, planeID)==0){
			return true;
		}
		tmp=tmp->pNext;
	}
	return false;
}

void IncPlaneFlight(PlaneLists &list, char *planeID){
	for(int i=0; i<list.size; i++){
		if(strcmp(list.list[i]->planeID, planeID)==0){
			list.list[i]->turnFlight++;
			char tmpTurn[5]="";
			NumToCharArr(tmpTurn, list.list[i]->turnFlight);
			strcpy(list.list[i]->chrTurnFlight, tmpTurn);
			break;
		}
	}
}
