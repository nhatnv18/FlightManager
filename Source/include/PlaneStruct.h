#pragma once
#define MAX_PLANES 300

struct Planes{
	char planeID[15]="";
	char planeKind[40]="";
	char chrSeat[10]="";
	int seat=0;
	char chrTurnFlight[10]="0";
	int turnFlight=0;
};

struct PlaneLists{
	Planes *list[MAX_PLANES];
	int size=0;
};

Planes *FindPlaneByID(char *id);
