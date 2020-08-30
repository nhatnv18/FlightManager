#pragma once

#include "FlightsStruct.h"
#include "ButtonControl.h"
#include "TableControl.h"
#include "CustomerStruct.h"
#include "Query.h"
#include "StringDefine.h"

#define LIST_MODE_TITLE_TOP 20

#define BUTTON_TICKET_LIST_BACK_LEFT 0
#define BUTTON_TICKET_LIST_BACK_RIGHT 150
#define BUTTON_TICKET_LIST_BACK_TOP 0
#define BUTTON_TICKET_LIST_BACK_BOTTOM 70

#define BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_LEFT 1250
#define BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_RIGHT 1280
#define BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_TOP 570
#define BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_BOTTOM 600

#define BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_LEFT 990
#define BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_RIGHT 1020
#define BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_TOP 570
#define BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_BOTTOM 600

#define RECORD_TICKET_LIST_HEIGHT 35
#define TABLE_TICKET_LIST_LEFT 50
#define TABLE_TICKET_LIST_RIGHT 1300
#define TABLE_TICKET_LIST_SIZE 10
#define TABLE_TICKET_LIST_TOP 150

void TicketListModeManagerInitDataTable();

bool isTicketListModeBack=false;
Flight *currentFlightShow;
Table ticketListModeTable;

Button btnListModeBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_TICKET_LIST_BACK_LEFT, BUTTON_TICKET_LIST_BACK_TOP, BUTTON_TICKET_LIST_BACK_RIGHT, BUTTON_TICKET_LIST_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);

void PrintTicketListModeTitle(){
	char title[100]="", flightInfo[200]="";
	strcat(title, titleTicketListPage.scontent[languageMode].content);
	strcat(title, currentFlightShow->flightID);
	strcat(flightInfo, charTakeOff.scontent[languageMode].content);
	strcat(flightInfo, currentFlightShow->dtime);
	strcat(flightInfo, charLandAt.scontent[languageMode].content);
	strcat(flightInfo, currentFlightShow->to);
	PrintText(WIDTH/2, LIST_MODE_TITLE_TOP, title, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE-1, FONT_MAIN);
	PrintText(WIDTH/2, LIST_MODE_TITLE_TOP+50, flightInfo, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE-2, FONT_MAIN);
}

void TicketListModeBackClickedAction(){
	delete[] queryCustomerOnFlight;
	isTicketListModeBack=true;
}

void TicketListManagerNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(currentFlightShow->ticket.sold);
	TicketListModeManagerInitDataTable();
	TableShow(ticketListModeTable);
}

void TicketListManagerPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(currentFlightShow->ticket.sold);
	TicketListModeManagerInitDataTable();
	TableShow(ticketListModeTable);
}

void ButtonsTicketListModeManager(){
	ButtonChangeName(btnListModeBack, charBtnBack.scontent[languageMode].content);
	//ChangePos
	ButtonChangePosition(btnNext, BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_LEFT, BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_TOP, BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_RIGHT, BUTTON_TICKET_LIST_NEXT_LIST_FLIGHT_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_LEFT, BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_TOP, BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_RIGHT, BUTTON_TICKET_LIST_PREVIOUS_LIST_FLIGHT_BOTTOM);
	//Enable
	ButtonSetEnable(btnListModeBack, true);
	//Listener
	SetButtonListener(&btnListModeBack, TicketListModeBackClickedAction);
	SetButtonListener(&btnNext, TicketListManagerNextButtonAction);
	SetButtonListener(&btnPrev, TicketListManagerPrevButtonAction);
	//show
	ButtonShow(btnListModeBack, false);
	ButtonShow(btnNext, false);
	ButtonShow(btnPrev, false);
}

void TicketListModeManagerInitDataTable(){
	QueryCustomerOnFlightInit(currentFlightShow->ticket);
	for(int k=0; k<10; k++){
		AddCellTableContent(ticketListModeTable, k, 0, "");
		AddCellTableContent(ticketListModeTable, k, 1, "");
		AddCellTableContent(ticketListModeTable, k, 2, "");
		AddCellTableContent(ticketListModeTable, k, 3, "");
		AddCellTableContent(ticketListModeTable, k, 4, "");
	}
	
	int j=0;
	for(int i=0; i<currentFlightShow->ticket.sold; i++){
		if(i>=pageTableControl.currentPage*10+10){
			break;
		}
		if(i>=pageTableControl.currentPage*10 && i<=pageTableControl.currentPage*10+9){
			AddCellTableContent(ticketListModeTable, j, 0, queryCustomerOnFlight[i].ordNumber);
			AddCellTableContent(ticketListModeTable, j, 1, queryCustomerOnFlight[i].index);
			AddCellTableContent(ticketListModeTable, j, 2, queryCustomerOnFlight[i].ICNumber);
			AddCellTableContent(ticketListModeTable, j, 3, queryCustomerOnFlight[i].fullName);
			AddCellTableContent(ticketListModeTable, j, 4, queryCustomerOnFlight[i].gender);
			j++;
		}
	}
//	int i=0,j=0;
//	for(int k=0; k<currentFlightShow->ticket.size; k++){
//		if(j>=pageTableControl.currentPage*10+10){
//			break;
//		}
//		if(strlen(currentFlightShow->ticket.tickets[k].idPersonalNumber)>0){
//			if(j>=pageTableControl.currentPage*10 && j<=pageTableControl.currentPage*10+9){
//				Customer tmpCus = FindNodeByICNumber(customerList, currentFlightShow->ticket.tickets[k].idPersonalNumber)->data;
//				std::cout<<tmpCus.fullName<<std::endl;
//				char ordNumber[5]="";
//				NumToCharArr(ordNumber, i+1);
//				AddCellTableContent(ticketListModeTable,i, 0, (char*)ordNumber);
//				AddCellTableContent(ticketListModeTable,i, 1, currentFlightShow->ticket.tickets[k].index);
//				AddCellTableContent(ticketListModeTable,i, 2, currentFlightShow->ticket.tickets[k].idPersonalNumber);
//				AddCellTableContent(ticketListModeTable,i, 3, tmpCus.fullName);
//				AddCellTableContent(ticketListModeTable,i, 4, tmpCus.gender);
//				i++;
//			}
//			j++;
//		}
//	}
}

void ListenItemTicketListMode(int index){
//	if(strlen(getValue(ticketListModeTable, index, 0))>0){
////		Flight flight = Find_Flight(flightList, getValue(flightsTable,index, 0))->data;
////		currentFlightRecord.currentRecord = index;
////		AddFlightToTextBoxs(flight);
////		SetFlightTextBoxEditMode();
////		SetFlightButtonsInEditMode();
//	}
}

void TableListModeManager(){
	ticketListModeTable = TableCreate(TABLE_TICKET_LIST_LEFT, TABLE_TICKET_LIST_TOP, TABLE_TICKET_LIST_RIGHT, 5, TABLE_TICKET_LIST_SIZE, RECORD_TICKET_LIST_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemTicketListMode);
	
	AddMenuContent(ticketListModeTable, 0, charOrdNumber.scontent[languageMode].content);
	AddMenuContent(ticketListModeTable, 1, charIndexSeats.scontent[languageMode].content);
	AddMenuContent(ticketListModeTable, 2, charICNumberFull.scontent[languageMode].content);
	AddMenuContent(ticketListModeTable, 3, charName.scontent[languageMode].content);
	AddMenuContent(ticketListModeTable, 4, charGender.scontent[languageMode].content);
	
	TicketListModeManagerInitDataTable();
	UpdatePageTableStatus(currentFlightShow->ticket.sold);
	TableShow(ticketListModeTable);
}

void FirstListModeInit(char *flightIDShow){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	currentFlightShow = &Find_Flight(flightList, flightIDShow)->data;
	PrintTicketListModeTitle();
	ButtonsTicketListModeManager();
	TableListModeManager();
}

void TicketListModeView(char *flightIDShow){
	isTicketListModeBack=false;
//	ReadFlightsFromFile();
	FirstListModeInit(flightIDShow);
	
	while(!isTicketListModeBack){
		MouseWaitingClick();
	}
}
