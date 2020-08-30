#pragma once

#include "main_define.h"
#include "TableControl.h"
#include "Planes.h"
#include "StringDefine.h"

#define TURN_TITLE_TOP 20

#define BUTTON_TURNS_BACK_LEFT 0
#define BUTTON_TURNS_BACK_RIGHT 150
#define BUTTON_TURNS_BACK_TOP 0
#define BUTTON_TURNS_BACK_BOTTOM 70

#define BUTTON_TURN_NEXT_LEFT 1250
#define BUTTON_TURN_NEXT_RIGHT 1280
#define BUTTON_TURN_NEXT_TOP 570
#define BUTTON_TURN_NEXT_BOTTOM 600

#define BUTTON_TURN_PREVIOUS_LEFT 990
#define BUTTON_TURN_PREVIOUS_RIGHT 1020
#define BUTTON_TURN_PREVIOUS_TOP 570
#define BUTTON_TURN_PREVIOUS_BOTTOM 600

#define RECORD_TURN_HEIGHT 35
#define TABLE_TURN_LEFT 50
#define TABLE_TURN_RIGHT 1300
#define TABLE_TURN_SIZE 10
#define TABLE_TURN_TOP 150

void TurnInitDataTable();

bool isPlaneFlightTurnBack=false;
int *planeIndex;

Table turnTable;

Button btnTurnBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_TURNS_BACK_LEFT, BUTTON_TURNS_BACK_TOP, BUTTON_TURNS_BACK_RIGHT, BUTTON_TURNS_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);

void PrintTurnsTitle(){
	PrintText(WIDTH/2, TURN_TITLE_TOP, titleSummaryPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE-2, FONT_MAIN);
}

void TurnsBackClickedAction(){
	isPlaneFlightTurnBack=true;
}

void TurnNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(planeAddArray.size);
	TurnInitDataTable();
	TableShow(turnTable);
}

void TurnPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(planeAddArray.size);
	TurnInitDataTable();
	TableShow(turnTable);
}

void ButtonsTurnsManager(){
	ButtonChangeName(btnTurnBack, charBtnBack.scontent[languageMode].content);
	//ChangePos
	ButtonChangePosition(btnNext, BUTTON_TURN_NEXT_LEFT, BUTTON_TURN_NEXT_TOP, BUTTON_TURN_NEXT_RIGHT, BUTTON_TURN_NEXT_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_TURN_PREVIOUS_LEFT, BUTTON_TURN_PREVIOUS_TOP, BUTTON_TURN_PREVIOUS_RIGHT, BUTTON_TURN_PREVIOUS_BOTTOM);
	//Enable
	ButtonSetEnable(btnTurnBack, true);
	//Listener
	SetButtonListener(&btnTurnBack, TurnsBackClickedAction);
	SetButtonListener(&btnNext, TurnNextButtonAction);
	SetButtonListener(&btnPrev, TurnPrevButtonAction);
	//show
	ButtonShow(btnTurnBack, false);
	ButtonShow(btnNext, false);
	ButtonShow(btnPrev, false);
}

void ListenItemTurn(int index){}

void DecSort(int left, int right){
	int i=left;
	int j=right;
	int midValue=planeAddArray.list[planeIndex[(i+j)/2]]->turnFlight;
	while(i<=j){
		while(planeAddArray.list[planeIndex[i]]->turnFlight>midValue) i++;
		while(planeAddArray.list[planeIndex[j]]->turnFlight<midValue) j--;
		if(i<=j){
			int tmp = planeIndex[i];
			planeIndex[i]=planeIndex[j];
			planeIndex[j]=tmp;
			i++;
			j--;
		}
	}
	if(left<j) DecSort(left, j);
	if(i<right) DecSort(i, right);
}

void TurnInitDataTable(){
	if(planeAddArray.size>0){
		planeIndex=new int[planeAddArray.size];
		for(int i=0; i<planeAddArray.size; i++){
			planeIndex[i]=i;
		}
		DecSort(0, planeAddArray.size-1);
		
		for(int i=0; i<10; i++){
			AddCellTableContent(turnTable, i, 0, "");
			AddCellTableContent(turnTable, i, 1, "");
		}
		
		int j=0;
		for(int i=0; i<planeAddArray.size; i++){
			if(i>=pageTableControl.currentPage*10+10){
				break;
			}
			if(i>=pageTableControl.currentPage*10 && i<=pageTableControl.currentPage*10+9){
				AddCellTableContent(turnTable, j, 0, planeAddArray.list[planeIndex[i]]->planeID);
				AddCellTableContent(turnTable, j, 1, planeAddArray.list[planeIndex[i]]->chrTurnFlight);
				j++;
			}
		}
	}
	
}

void TableTurnManager(){
	turnTable = TableCreate(TABLE_TURN_LEFT, TABLE_TURN_TOP, TABLE_TURN_RIGHT, 2, TABLE_TURN_SIZE, RECORD_TURN_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemTurn);
	
	AddMenuContent(turnTable, 0, charPlaneID.scontent[languageMode].content);
	AddMenuContent(turnTable, 1, charFlights.scontent[languageMode].content);
	
	TurnInitDataTable();
	UpdatePageTableStatus(planeAddArray.size);
	TableShow(turnTable);
}

void FirstPlaneFlightTurnsInit(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	PrintTurnsTitle();
	ButtonsTurnsManager();
	TableTurnManager();
}

void PlaneFlightTurnsView(){
	isPlaneFlightTurnBack=false;
//	ReadFlightsFromFile();
	FirstPlaneFlightTurnsInit();
	
	while(!isPlaneFlightTurnBack){
		MouseWaitingClick();
	}
}
