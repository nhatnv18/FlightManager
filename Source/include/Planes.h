#pragma once
#include "ArrChar_Num.h"
#include "FlightsStruct.h"
#include "PlaneStruct.h"

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
	Planes *tmp = FindPlaneByID(planeID);
	if(tmp->turnFlight>0) return true;
	return false;
}

void IncPlaneFlight(char *planeID){
	Planes *tmp = FindPlaneByID(planeID);
	tmp->turnFlight++;
	char tmpTurn[5]="";
	NumToCharArr(tmpTurn, tmp->turnFlight);
	strcpy(tmp->chrTurnFlight, tmpTurn);
}

void DecPlaneFlight(char *planeID){
	Planes *tmp = FindPlaneByID(planeID);
	tmp->turnFlight--;
	char tmpTurn[5]="";
	NumToCharArr(tmpTurn, tmp->turnFlight);
	strcpy(tmp->chrTurnFlight, tmpTurn);
}
