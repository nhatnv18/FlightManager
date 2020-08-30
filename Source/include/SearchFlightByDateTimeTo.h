#pragma once
#include "MouseListener.h"
#include "ButtonControl.h"
#include "TextBoxControl.h"
#include "TableControl.h"
#include "FlightsStruct.h"
#include "TicketBuyPage.h"
#include "StringDefine.h"

#define SEARCH_FLIGHT_TITLE_TOP 20
#define BUTTON_SEARCH_FLIGHT_BACK_LEFT 0
#define BUTTON_SEARCH_FLIGHT_BACK_RIGHT 150
#define BUTTON_SEARCH_FLIGHT_BACK_TOP 0
#define BUTTON_SEARCH_FLIGHT_BACK_BOTTOM 70

#define SEARCH_FLIGHT_PANEL_LEFT 50
#define SEARCH_FLIGHT_PANEL_TOP 100
#define SEARCH_FLIGHT_PANEL_BOTTOM 150
#define SEARCH_FLIGHT_PANEL_RIGHT 1300

#define RECORD_SEARCH_FLIGHT_HEIGHT 35
#define TABLE_SEARCH_FLIGHT_LEFT 50
#define TABLE_SEARCH_FLIGHT_RIGHT 1300
#define TABLE_SEARCH_FLIGHT_SIZE 10
#define TABLE_SEARCH_FLIGHT_TOP 200

#define BUTTON_NEXT_FOUND_FLIGHT_LEFT 1250
#define BUTTON_NEXT_FOUND_FLIGHT_RIGHT 1280
#define BUTTON_NEXT_FOUND_FLIGHT_TOP 600
#define BUTTON_NEXT_FOUND_FLIGHT_BOTTOM 650

#define BUTTON_PREVIOUS_FOUND_FLIGHT_LEFT 990
#define BUTTON_PREVIOUS_FOUND_FLIGHT_RIGHT 1020
#define BUTTON_PREVIOUS_FOUND_FLIGHT_TOP 600
#define BUTTON_PREVIOUS_FOUND_FLIGHT_BOTTOM 650

bool isSearchFlightBack;

Button btnSearchFlightBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_SEARCH_FLIGHT_BACK_LEFT, BUTTON_SEARCH_FLIGHT_BACK_TOP, BUTTON_SEARCH_FLIGHT_BACK_RIGHT, BUTTON_SEARCH_FLIGHT_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);

TextBox txtSearchFlightsID = CreateATextBox(charID.scontent[languageMode].content, "", 15, ' ', '~',SEARCH_FLIGHT_PANEL_LEFT+10, SEARCH_FLIGHT_PANEL_TOP+10, SEARCH_FLIGHT_PANEL_LEFT+260, SEARCH_FLIGHT_PANEL_BOTTOM-10, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtSearchFlightsDayStart = CreateATextBox(charDay.scontent[languageMode].content, "", 3, ' ', '~',SEARCH_FLIGHT_PANEL_LEFT+270, SEARCH_FLIGHT_PANEL_TOP+10, SEARCH_FLIGHT_PANEL_LEFT+460, SEARCH_FLIGHT_PANEL_BOTTOM-10, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtSearchFlightsMonthStart = CreateATextBox(charMonth.scontent[languageMode].content, "", 3, ' ', '~',SEARCH_FLIGHT_PANEL_LEFT+470, SEARCH_FLIGHT_PANEL_TOP+10, SEARCH_FLIGHT_PANEL_LEFT+660, SEARCH_FLIGHT_PANEL_BOTTOM-10, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtSearchFlightsYearStart = CreateATextBox(charYear.scontent[languageMode].content, "", 5, ' ', '~',SEARCH_FLIGHT_PANEL_LEFT+670, SEARCH_FLIGHT_PANEL_TOP+10, SEARCH_FLIGHT_PANEL_LEFT+900, SEARCH_FLIGHT_PANEL_BOTTOM-10, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtSearchFlightsTo = CreateATextBox(charFlightTo.scontent[languageMode].content, "", 50, ' ', '~',SEARCH_FLIGHT_PANEL_LEFT+910, SEARCH_FLIGHT_PANEL_TOP+10, SEARCH_FLIGHT_PANEL_LEFT+1240, SEARCH_FLIGHT_PANEL_BOTTOM-10, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);

Table foundFlights;

FlightList foundList;

void SearchFlightsInitDataTable();
void FirstSearchFlightInit();

void ButtonSearchFlightBackClickAction(){
	isSearchFlightBack = true;
	ClearAllFlightsList(foundList);
}


void ClearSearchFlightTextBox(){
	TextBoxSetTitle(txtSearchFlightsID, charID.scontent[languageMode].content);
	TextBoxSetTitle(txtSearchFlightsDayStart, charDay.scontent[languageMode].content);
	TextBoxSetTitle(txtSearchFlightsMonthStart, charMonth.scontent[languageMode].content);
	TextBoxSetTitle(txtSearchFlightsYearStart, charYear.scontent[languageMode].content);
	TextBoxSetTitle(txtSearchFlightsTo, charFlightTo.scontent[languageMode].content);
	
	SetContentTextBox(txtSearchFlightsID,"");
	SetContentTextBox(txtSearchFlightsDayStart,"");
	SetContentTextBox(txtSearchFlightsMonthStart,"");
	SetContentTextBox(txtSearchFlightsYearStart,"");
	SetContentTextBox(txtSearchFlightsTo,"");
}

void SearchFlightTextBoxManager(){
	
//	TextBoxSetTitle(txtSearchFlightsID, charID.scontent[languageMode].content);
//	TextBoxSetTitle(txtSearchFlightsDayStart, charDay.scontent[languageMode].content);
//	TextBoxSetTitle(txtSearchFlightsMonthStart, charMonth.scontent[languageMode].content);
//	TextBoxSetTitle(txtSearchFlightsYearStart, charYear.scontent[languageMode].content);
//	TextBoxSetTitle(txtSearchFlightsTo, charFlightTo.scontent[languageMode].content);
	
	DrawRecStroke(SEARCH_FLIGHT_PANEL_LEFT, SEARCH_FLIGHT_PANEL_TOP, SEARCH_FLIGHT_PANEL_RIGHT, SEARCH_FLIGHT_PANEL_BOTTOM, SOLID_LINE, BLACK, 2);
	
	TextBoxSetEnable(txtSearchFlightsID, true);
	TextBoxSetEnable(txtSearchFlightsDayStart, true);
	TextBoxSetEnable(txtSearchFlightsMonthStart, true);
	TextBoxSetEnable(txtSearchFlightsYearStart, true);
	TextBoxSetEnable(txtSearchFlightsTo, true);
	
	SetTextBoxListener(&txtSearchFlightsID);
	SetTextBoxListener(&txtSearchFlightsDayStart);
	SetTextBoxListener(&txtSearchFlightsMonthStart);
	SetTextBoxListener(&txtSearchFlightsYearStart);
	SetTextBoxListener(&txtSearchFlightsTo);
	
	TextBoxDraw(txtSearchFlightsID);
	TextBoxDraw(txtSearchFlightsDayStart);
	TextBoxDraw(txtSearchFlightsMonthStart);
	TextBoxDraw(txtSearchFlightsYearStart);
	TextBoxDraw(txtSearchFlightsTo);
}

void ButtonSearchFlightsShow(){
	ButtonShow(btnSearchFlightBack, false);
	ButtonShow(btnNext, false);
	ButtonShow(btnPrev, false);
}

void SearchFlightManagerPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(foundList.size);
	SearchFlightsInitDataTable();
	TableShow(foundFlights);
}

void SearchFlightManagerNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(foundList.size);
	SearchFlightsInitDataTable();
	TableShow(foundFlights);
}

void SearchFlightButtonManager(){
	
	ButtonChangeName(btnSearchFlightBack, charBtnBack.scontent[languageMode].content);
	
	ButtonChangePosition(btnNext, BUTTON_NEXT_FOUND_FLIGHT_LEFT, BUTTON_NEXT_FOUND_FLIGHT_TOP, BUTTON_NEXT_FOUND_FLIGHT_RIGHT, BUTTON_NEXT_FOUND_FLIGHT_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_PREVIOUS_FOUND_FLIGHT_LEFT, BUTTON_PREVIOUS_FOUND_FLIGHT_TOP, BUTTON_PREVIOUS_FOUND_FLIGHT_RIGHT, BUTTON_PREVIOUS_FOUND_FLIGHT_BOTTOM);
	
	ButtonSetEnable(btnSearchFlightBack, true);
	
	SetButtonListener(&btnSearchFlightBack, ButtonSearchFlightBackClickAction);
	SetButtonListener(&btnNext, SearchFlightManagerNextButtonAction);
	SetButtonListener(&btnPrev, SearchFlightManagerPrevButtonAction);
	
	ButtonSearchFlightsShow();
}

void PrintSearchFlightsTitle(){
	PrintText(WIDTH/2, SEARCH_FLIGHT_TITLE_TOP, titleFindFLightPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE, FONT_MAIN);
}

void ListenItemSearchFlightsList(int index){
	if(strlen(getValue(foundFlights, index, 0))>0){
//		std::cout <<"Sold in search: "<<foundList.phead->data.ticket.sold<<std::endl;
		TicketBuyPageUIShow(getValue(foundFlights, index, 0));
		FirstSearchFlightInit();
	}
}

void SearchFlightsInitDataTable(){
	
	for(int i=0; i<10; i++){
		AddCellTableContent(foundFlights, i, 0, "");
		AddCellTableContent(foundFlights, i, 1, "");
		AddCellTableContent(foundFlights, i, 2, "");
		AddCellTableContent(foundFlights, i, 3, "");
	}
	
	NodeFlight *tmp = foundList.phead;
	int i=0, j=0;
	while(tmp!=NULL){
		if(i>pageTableControl.currentPage*10+10){
			break;
		}
		else if(i>=pageTableControl.currentPage*10 && i<=pageTableControl.currentPage*10+9){
			AddCellTableContent(foundFlights, j, 0, tmp->data.flightID);
			AddCellTableContent(foundFlights, j, 1, tmp->data.dtime);
			AddCellTableContent(foundFlights, j, 2, tmp->data.to);
			AddCellTableContent(foundFlights, j, 3, tmp->data.ticket.soldTicket);
			j++;
		}
		
		tmp=tmp->pNext;
		i++;
	}
}

void SearchFlightsTableManager(){
	foundFlights = TableCreate(TABLE_SEARCH_FLIGHT_LEFT, TABLE_SEARCH_FLIGHT_TOP, TABLE_SEARCH_FLIGHT_RIGHT, 4, TABLE_SEARCH_FLIGHT_SIZE, RECORD_SEARCH_FLIGHT_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemSearchFlightsList);
	
	AddMenuContent(foundFlights, 0, charID.scontent[languageMode].content);
	AddMenuContent(foundFlights, 1, charStartTime.scontent[languageMode].content);
	AddMenuContent(foundFlights, 2, charTo.scontent[languageMode].content);
	AddMenuContent(foundFlights, 3, charStt.scontent[languageMode].content);
	
	SearchFlightsInitDataTable();
	UpdatePageTableStatus(foundList.size);
	TableShow(foundFlights);
}

void FirstSearchFlightInit(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	ClearAllFlightsList(foundList);
	ClearSearchFlightTextBox();
	PrintSearchFlightsTitle();
	SearchFlightButtonManager();
	SearchFlightsTableManager();
	SearchFlightTextBoxManager();
}

void SearchFoundFlightsList(){
	if(strlen(txtSearchFlightsID.content)==0 && strlen(txtSearchFlightsDayStart.content)==0 && strlen(txtSearchFlightsMonthStart.content)==0 && strlen(txtSearchFlightsYearStart.content)==0 && strlen(txtSearchFlightsMonthStart.content)==0 && strlen(txtSearchFlightsYearStart.content)==0 && strlen(txtSearchFlightsTo.content)==0){
		ClearAllFlightsList(foundList);
	}
	else{
//		std::cout << "Hello"<<std::endl;
		int day=0, month=0, year=0;
		if(strlen(txtSearchFlightsDayStart.content)!=0){
			day=ArrtoNum(txtSearchFlightsDayStart.content);
		}
		if (strlen(txtSearchFlightsMonthStart.content)!=0){
			month=ArrtoNum(txtSearchFlightsMonthStart.content);
		}
		if(strlen(txtSearchFlightsYearStart.content)!=0){
			year=ArrtoNum(txtSearchFlightsYearStart.content);
		}
//		std::cout << "Day: "<<day<<" Month: "<<month<<" Year: "<<year<<std::endl;
		searchFlightByData(flightList, foundList, txtSearchFlightsID.content, day, month, year, txtSearchFlightsTo.content);
	}
}

void SearchFoundFlightsTableUpdate(){
	SearchFoundFlightsList();
	SearchFlightsInitDataTable();
	UpdatePageTableStatus(foundList.size);
	TableShow(foundFlights);
}

void CorrectSearchFlightsForm(){
	CorrectIDForm(txtSearchFlightsID.content);
	CorrectNameForm(txtSearchFlightsTo.content);
	TextBoxDraw(txtSearchFlightsID);
	TextBoxDraw(txtSearchFlightsTo);
}

void SearchFlightUIShow(){
	isSearchFlightBack=false;
	//readData
	FirstSearchFlightInit();
	
	while(!isSearchFlightBack){
		MouseWaitingClick();
		CorrectSearchFlightsForm();
		SearchFoundFlightsTableUpdate();
	}
}
