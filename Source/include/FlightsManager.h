#pragma once
#include "main_define.h"
#include "MouseListener.h"
#include "TableControl.h"
#include "TextBoxControl.h"
#include "FlightsStruct.h"
#include "DataControl.h"
#include "TicketBuyPage.h"
#include "StringDefine.h"

#define FLIGHT_TITLE_TOP 20
#define BUTTON_BACK_LEFT 0
#define BUTTON_BACK_RIGHT 150
#define BUTTON_BACK_TOP 0
#define BUTTON_BACK_BOTTOM 70

#define BUTTON_NEW_LEFT 950
#define BUTTON_NEW_RIGHT 1050
#define BUTTON_NEW_TOP 600
#define BUTTON_NEW_BOTTOM 670

#define BUTTON_EDIT_LEFT 1060
#define BUTTON_EDIT_RIGHT 1160
#define BUTTON_EDIT_TOP 600
#define BUTTON_EDIT_BOTTOM 670

#define BUTTON_REMOVE_LEFT 1170
#define BUTTON_REMOVE_RIGHT 1300
#define BUTTON_REMOVE_TOP 600
#define BUTTON_REMOVE_BOTTOM 670

#define BUTTON_TICKET_LEFT 950
#define BUTTON_TICKET_RIGHT 1050
#define BUTTON_TICKET_TOP 520
#define BUTTON_TICKET_BOTTOM 590

#define BUTTON_CANCEL_LEFT 1060
#define BUTTON_CANCEL_RIGHT 1180
#define BUTTON_CANCEL_TOP 520
#define BUTTON_CANCEL_BOTTOM 590
//
//#define BUTTON_REMOVE_LEFT 1170
//#define BUTTON_REMOVE_RIGHT 1300
//#define BUTTON_REMOVE_TOP 600
//#define BUTTON_REMOVE_BOTTOM 670

#define BUTTON_NEXT_LIST_FLIGHT_LEFT 1250
#define BUTTON_NEXT_LIST_FLIGHT_RIGHT 1280
#define BUTTON_NEXT_LIST_FLIGHT_TOP 470
#define BUTTON_NEXT_LIST_FLIGHT_BOTTOM 500

#define BUTTON_PREVIOUS_LIST_FLIGHT_LEFT 990
#define BUTTON_PREVIOUS_LIST_FLIGHT_RIGHT 1020
#define BUTTON_PREVIOUS_LIST_FLIGHT_TOP 470
#define BUTTON_PREVIOUS_LIST_FLIGHT_BOTTOM 500

#define RECORD_FLIGHT_HEIGHT 35
#define TABLE_FLIGHT_LEFT 50
#define TABLE_FLIGHT_RIGHT 1300
#define TABLE_FLIGHT_SIZE 10
#define TABLE_FLIGHT_TOP 80

#define FLIGHT_PANEL_LEFT 50
#define FLIGHT_PANEL_TOP 500
#define FLIGHT_PANEL_BOTTOM 675
#define FLIGHT_PANEL_RIGHT 900
#define FLIGHT_PANEL_HEIGHT 35

#define FLIGHT_CLEAR_BUTTON_LEFT 900
#define FLIGHT_CLEAR_BUTTON_TOP 530
#define FLIGHT_CLEAR_BUTTON_BOTTOM 560
#define FLIGHT_CLEAR_BUTTON_RIGHT 930

void FirstInit();
void FirstInitWithoutClearTextBox();

bool isFlightBack=false;
Table flightsTable;

Button btnFlightBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_BACK_LEFT, BUTTON_BACK_TOP, BUTTON_BACK_RIGHT, BUTTON_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnFlightNew = CreateAButton(charBtnNew.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_NEW_LEFT, BUTTON_NEW_TOP, BUTTON_NEW_RIGHT, BUTTON_NEW_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnFlightEdit = CreateAButton(charBtnSave.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_EDIT_LEFT, BUTTON_EDIT_TOP, BUTTON_EDIT_RIGHT, BUTTON_EDIT_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnFlightRemove = CreateAButton(charBtnRemove.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_REMOVE_LEFT, BUTTON_REMOVE_TOP, BUTTON_REMOVE_RIGHT, BUTTON_REMOVE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnFlightTicket = CreateAButton(charBtnTicket.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_TICKET_LEFT, BUTTON_TICKET_TOP, BUTTON_TICKET_RIGHT, BUTTON_TICKET_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnFlightCancel = CreateAButton(charBtnCancel.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_CANCEL_LEFT, BUTTON_CANCEL_TOP, BUTTON_CANCEL_RIGHT, BUTTON_CANCEL_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnFlightClear = CreateAButton("x", FONT_MAIN, 1, WHITE, BLUE, FLIGHT_CLEAR_BUTTON_LEFT, FLIGHT_CLEAR_BUTTON_TOP, FLIGHT_CLEAR_BUTTON_RIGHT, FLIGHT_CLEAR_BUTTON_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);

TextBox txtFlightsID = CreateATextBox(charID.scontent[languageMode].content, "", 15, ' ', '~',FLIGHT_PANEL_LEFT+20, FLIGHT_PANEL_TOP+10, FLIGHT_PANEL_RIGHT-20, FLIGHT_PANEL_TOP+10+FLIGHT_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtFlightsStart = CreateATextBox(charStartTime.scontent[languageMode].content, "", 20, ' ', '~',FLIGHT_PANEL_LEFT+20, FLIGHT_PANEL_TOP+50, FLIGHT_PANEL_RIGHT-20, FLIGHT_PANEL_TOP+50+FLIGHT_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtFlightsTo = CreateATextBox(charTo.scontent[languageMode].content, "", 50, ' ', '~',FLIGHT_PANEL_LEFT+20, FLIGHT_PANEL_TOP+90, FLIGHT_PANEL_RIGHT-20, FLIGHT_PANEL_TOP+90+FLIGHT_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtFlightsPlane = CreateATextBox(charPlaneID.scontent[languageMode].content, "", 15, ' ', '~',FLIGHT_PANEL_LEFT+20, FLIGHT_PANEL_TOP+130, (FLIGHT_PANEL_RIGHT+FLIGHT_PANEL_LEFT)/2-20, FLIGHT_PANEL_TOP+130+FLIGHT_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtFlightsSTT = CreateATextBox(charStt.scontent[languageMode].content, "", 30, ' ', '~',(FLIGHT_PANEL_RIGHT+FLIGHT_PANEL_LEFT)/2, FLIGHT_PANEL_TOP+130, FLIGHT_PANEL_RIGHT-20, FLIGHT_PANEL_TOP+130+FLIGHT_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, false);

SelectedRecord currentFlightRecord;

void DrawFlightTextBoxs(){

//	TextBoxSetTitle(txtFlightsID, charID.scontent[languageMode].content);
//	TextBoxSetTitle(txtFlightsStart, charStartTime.scontent[languageMode].content);
//	TextBoxSetTitle(txtFlightsTo, charTo.scontent[languageMode].content);
//	TextBoxSetTitle(txtFlightsPlane, charPlaneID.scontent[languageMode].content);
//	TextBoxSetTitle(txtFlightsSTT, charStt.scontent[languageMode].content);
	
	DrawRecStroke(FLIGHT_PANEL_LEFT, FLIGHT_PANEL_TOP, FLIGHT_PANEL_RIGHT, FLIGHT_PANEL_BOTTOM, SOLID_LINE, BLACK, 3);
	
	TextBoxSetEnable(txtFlightsID, true);
	TextBoxSetEnable(txtFlightsStart, true);
	TextBoxSetEnable(txtFlightsTo, true);
	TextBoxSetEnable(txtFlightsPlane, true);
	TextBoxSetEnable(txtFlightsSTT, false);
	
	SetTextBoxListener(&txtFlightsID);
	SetTextBoxListener(&txtFlightsStart);
	SetTextBoxListener(&txtFlightsTo);
	SetTextBoxListener(&txtFlightsPlane);
	SetTextBoxListener(&txtFlightsSTT);
	
	TextBoxDraw(txtFlightsID);
	TextBoxDraw(txtFlightsStart);
	TextBoxDraw(txtFlightsTo);
	TextBoxDraw(txtFlightsPlane);
	TextBoxDraw(txtFlightsSTT);
}

void ClearFlightsTextBoxs(){
	
	TextBoxSetTitle(txtFlightsID, charID.scontent[languageMode].content);
	TextBoxSetTitle(txtFlightsStart, charStartTime.scontent[languageMode].content);
	TextBoxSetTitle(txtFlightsTo, charTo.scontent[languageMode].content);
	TextBoxSetTitle(txtFlightsPlane, charPlaneID.scontent[languageMode].content);
	TextBoxSetTitle(txtFlightsSTT, charStt.scontent[languageMode].content);
	
	ClearTextBox(txtFlightsID);
	ClearTextBox(txtFlightsStart);
	ClearTextBox(txtFlightsTo);
	ClearTextBox(txtFlightsPlane);
	ClearTextBox(txtFlightsSTT);
	
	SetContentTextBox(txtFlightsSTT, charStt1.scontent[languageMode].content);
	char nowTime[30]="";
	DateTimeToText(nowTime, GetNow());
	SetContentTextBox(txtFlightsStart, nowTime);
}

void AddFlightToTextBoxs(Flight f){
	SetContentTextBox(txtFlightsID, f.flightID);
	SetContentTextBox(txtFlightsStart, f.dtime);
	SetContentTextBox(txtFlightsTo, f.to);
	SetContentTextBox(txtFlightsPlane, f.planeID);
	char *stt;
	switch(f.status){
		case 0:
			stt = charStt0.scontent[languageMode].content;
			break;
		case 1:
			stt = charStt1.scontent[languageMode].content;
			break;
		case 2:
			stt = charStt2.scontent[languageMode].content;
			break;
		case 3:
			stt = charStt3.scontent[languageMode].content;
			break;
		case 4:
			stt = charStt4.scontent[languageMode].content;
			break;
	}
	SetContentTextBox(txtFlightsSTT, stt);
}

void SetFlightTextBoxEditModeComplete(){
	TextBoxSetEnable(txtFlightsID, false);
	TextBoxSetEnable(txtFlightsStart, false);
	TextBoxSetEnable(txtFlightsTo, false);
	TextBoxSetEnable(txtFlightsPlane, false);
	TextBoxSetEnable(txtFlightsSTT, false);
}

void SetFlightTextBoxEditMode(){
	TextBoxSetEnable(txtFlightsID, false);
	TextBoxSetEnable(txtFlightsStart, true);
	TextBoxSetEnable(txtFlightsTo, false);
	TextBoxSetEnable(txtFlightsPlane, false);
	TextBoxSetEnable(txtFlightsSTT, false);
}

void SetFlightTextBoxNormalMode(){
	TextBoxSetEnable(txtFlightsID, true);
	TextBoxSetEnable(txtFlightsStart, true);
	TextBoxSetEnable(txtFlightsTo, true);
	TextBoxSetEnable(txtFlightsPlane, true);
	TextBoxSetEnable(txtFlightsSTT, false);
}

void SetFlightButtonsInEditModeComplete(){
	ButtonSetEnable(btnFlightNew,false);
	ButtonSetEnable(btnFlightEdit,false);
	ButtonSetEnable(btnFlightRemove,false);
	ButtonSetEnable(btnFlightTicket,true);
	ButtonSetEnable(btnFlightCancel,false);
	ButtonSetEnable(btnFlightClear, true);
}

void SetFlightButtonsInEditMode(){
	ButtonSetEnable(btnFlightNew,false);
	ButtonSetEnable(btnFlightEdit,true);
	ButtonSetEnable(btnFlightRemove,true);
	ButtonSetEnable(btnFlightTicket,true);
	ButtonSetEnable(btnFlightCancel,true);
	ButtonSetEnable(btnFlightClear, true);
}

void SetFlightButtonsInNormalMode(){
	ButtonSetEnable(btnFlightNew,true);
	ButtonSetEnable(btnFlightEdit,false);
	ButtonSetEnable(btnFlightRemove,false);
	ButtonSetEnable(btnFlightTicket,false);
	ButtonSetEnable(btnFlightCancel,false);
	ButtonSetEnable(btnFlightClear, false);
}

void ListenItemFlightsList(int index){
	if(strlen(getValue(flightsTable, index, 0))>0){
		Flight flight = Find_Flight(flightList, getValue(flightsTable,index, 0))->data;
		currentFlightRecord.currentRecord = index;
		AddFlightToTextBoxs(flight);
		if(flight.status==0 || flight.status>=3){
			SetFlightTextBoxEditModeComplete();
			SetFlightButtonsInEditModeComplete();
		}
		else{
			SetFlightTextBoxEditMode();
			SetFlightButtonsInEditMode();
		}
	}
}

void FlightsManagerInitDataTable(){
	
	for(int i=0; i<10; i++){
		AddCellTableContent(flightsTable, i, 0, "");
		AddCellTableContent(flightsTable, i, 1, "");
		AddCellTableContent(flightsTable, i, 2, "");
		AddCellTableContent(flightsTable, i, 3, "");
		AddCellTableContent(flightsTable, i, 4, "");
	}
	
	NodeFlight *tmp = flightList.phead;
	int i=0, j=0;
	while(tmp!=NULL){
		if(i>pageTableControl.currentPage*10+10){
			break;
		}
		else if(i>=pageTableControl.currentPage*10 && i<=pageTableControl.currentPage*10+9){
			AddCellTableContent(flightsTable, j, 0, tmp->data.flightID);
			AddCellTableContent(flightsTable, j, 1, tmp->data.dtime);
			AddCellTableContent(flightsTable, j, 2, tmp->data.to);
			AddCellTableContent(flightsTable, j, 3, tmp->data.planeID);
			char *stt;
			switch(tmp->data.status){
				case 0:
					stt = charStt0.scontent[languageMode].content;
					break;
				case 1:
					stt = charStt1.scontent[languageMode].content;
					break;
				case 2:
					stt = charStt2.scontent[languageMode].content;
					break;
				case 3:
					stt = charStt3.scontent[languageMode].content;
					break;
				case 4:
					stt = charStt4.scontent[languageMode].content;
					break;
			}
			AddCellTableContent(flightsTable, j, 4, stt);
			j++;
		}
		
		tmp=tmp->pNext;
		i++;
	}
}

void TableFlightsManager(){
	flightsTable = TableCreate(TABLE_FLIGHT_LEFT, TABLE_FLIGHT_TOP, TABLE_FLIGHT_RIGHT, 5, TABLE_FLIGHT_SIZE, RECORD_FLIGHT_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemFlightsList);
	
	AddMenuContent(flightsTable, 0, charID.scontent[languageMode].content);
	AddMenuContent(flightsTable, 1, charStartTime.scontent[languageMode].content);
	AddMenuContent(flightsTable, 2, charTo.scontent[languageMode].content);
	AddMenuContent(flightsTable, 3, charPlaneID.scontent[languageMode].content);
	AddMenuContent(flightsTable, 4, charStt.scontent[languageMode].content);
	
	FlightsManagerInitDataTable();
	UpdatePageTableStatus(flightList.size);
	TableShow(flightsTable);
}

void DoFlightNothing(){
}

void WriteFiles(){
	WriteFlightsToFile();
	WritePlanesToFile();
}

void FlightManagerBackButtonAction(){
	InitDialogAndShow(charConfirm.scontent[languageMode].content, charSaveAllChange.scontent[languageMode].content, 400, 200, 950, 500, YESNO, WriteFiles, DoFlightNothing, 0);
	isFlightBack=true;
}

void FlightManagerNewButtonAction(){
	if(strlen(txtFlightsID.content)==0 || strlen(txtFlightsStart.content)==0 || strlen(txtFlightsTo.content)==0 || strlen(txtFlightsPlane.content)==0){
		if(strlen(txtFlightsID.content)==0){
//			PrintText(txtFlightsID.right-3, txtFlightsID.bottom-2, "Enter value to add new", txtFlightsID.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
		}
		else if(strlen(txtFlightsStart.content)==0){
//			PrintText(txtFlightsStart.right-3, txtFlightsStart.bottom-2, "Enter value to add new", txtFlightsStart.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
		}
		else if(strlen(txtFlightsTo.content)==0){
//			PrintText(txtFlightsTo.right-3, txtFlightsTo.bottom-2, "Enter value to add new", txtFlightsTo.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
		}
		else if(strlen(txtFlightsPlane.content)==0){
//			PrintText(txtFlightsPlane.right-3, txtFlightsPlane.bottom-2, "Enter value to add new", txtFlightsPlane.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
		}
		FirstInitWithoutClearTextBox();
	}
	else{
		
		NodeFlight *findFlight = NULL;
		findFlight = Find_Flight(flightList, txtFlightsID.content);

		if(findFlight==NULL){
			DateTime *startTime = TextToDate(txtFlightsStart.content);
			DateTime start = (startTime==NULL)?CreateADateSet(0, 0, 0, 0, 0):CreateADateSet(startTime->day, startTime->month, startTime->year, startTime->hour, startTime->min);
	
			if(startTime==NULL){
//				PrintText(txtFlightsStart.right-3, txtFlightsStart.bottom-2, "Wrong Input Mask", txtFlightsStart.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
				InitDialogAndShow(charError.scontent[languageMode].content, charWrongInputMask.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
				FirstInitWithoutClearTextBox();
			}
			else{
				Planes *tmp = FindPlaneByID(txtFlightsPlane.content);
				if(tmp==NULL){
//					PrintText(txtFlightsPlane.right-3, txtFlightsPlane.bottom-2, "Not found this plane", txtFlightsPlane.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
					InitDialogAndShow(charError.scontent[languageMode].content, charNotFoundPlane.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
					FirstInitWithoutClearTextBox();
				}
				else{
					if(TimeCmp(start, GetNow())<0){
						InitDialogAndShow(charError.scontent[languageMode].content, charTimeErrorNow.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
						FirstInitWithoutClearTextBox();
					}
					else{
						if(isPlaneUsedInTimeRange(flightList, txtFlightsPlane.content, start, "")){
							InitDialogAndShow(charError.scontent[languageMode].content, charPlanesUsedInTime.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
							FirstInitWithoutClearTextBox();
						}
						else{
							Insert_Tail_Flight(flightList, NewNodeFlight(CreateNewFlight(txtFlightsID.content, start, txtFlightsTo.content, txtFlightsPlane.content)));
							IncPlaneFlight(txtFlightsPlane.content);
							UpdatePageTableStatus(flightList.size);
							FlightsManagerInitDataTable();
							ClearFlightsTextBoxs();
							TableShow(flightsTable);
						}
					}
					
				}
			}
		}
		else{
//			PrintText(txtFlightsID.right-3, txtFlightsID.bottom-2, "This ID has used", txtFlightsID.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charIDUsed.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
			FirstInitWithoutClearTextBox();
		}
		
	}
}

void FlightManagerEditButtonAction(){
	if(strlen(txtFlightsStart.content)==0){
//		PrintText(txtFlightsStart.right-3, txtFlightsStart.bottom-2, "Enter value to save edit", txtFlightsStart.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
		InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
		FirstInitWithoutClearTextBox();
		SetFlightButtonsInEditMode();
		SetFlightTextBoxEditMode();
	}
	else{
		DateTime *editTime = TextToDate(txtFlightsStart.content);
		DateTime startTime = (editTime==NULL)?CreateADateSet(0, 0, 0, 0, 0):CreateADateSet(editTime->day, editTime->month, editTime->year, editTime->hour, editTime->min);
		
		if(editTime==NULL){
//			PrintText(txtFlightsStart.right-3, txtFlightsStart.bottom-2, "Wrong Input Mask", txtFlightsStart.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charWrongInputMask.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
			FirstInitWithoutClearTextBox();
			SetFlightButtonsInEditMode();
			SetFlightTextBoxEditMode();
		}
		else{
			if(TimeCmp(startTime, GetNow())<0){
				InitDialogAndShow(charError.scontent[languageMode].content, charTimeErrorNow.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
				FirstInitWithoutClearTextBox();
				SetFlightButtonsInEditMode();
				SetFlightTextBoxEditMode();
			}
			else{
				if(isPlaneUsedInTimeRange(flightList, txtFlightsPlane.content, startTime, txtFlightsID.content)){
					InitDialogAndShow(charError.scontent[languageMode].content, charPlanesUsedInTime.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
					FirstInitWithoutClearTextBox();
					SetFlightButtonsInEditMode();
					SetFlightTextBoxEditMode();
				}
				else{
					Edit_Flight(flightList, txtFlightsID.content, startTime);
					UpdatePageTableStatus(flightList.size);
					FlightsManagerInitDataTable();
					ClearFlightsTextBoxs();
					TableShow(flightsTable);
					SetFlightTextBoxNormalMode();
					SetFlightButtonsInNormalMode();
				}
			}
			
		}
	}
}

void CancelFlight(){
	Cancel_Flight(flightList, txtFlightsID.content);
	UpdatePageTableStatus(flightList.size);
	FlightsManagerInitDataTable();
	ClearFlightsTextBoxs();
	TableShow(flightsTable);
	SetFlightTextBoxNormalMode();
	SetFlightButtonsInNormalMode();
}

void FlightManagerCancelButtonAction(){
	InitDialogAndShow(charConfirm.scontent[languageMode].content, charConfirmCancel.scontent[languageMode].content, 400, 200, 950, 500, YESNO, CancelFlight, DoFlightNothing, 0);
	FirstInit();
}

void ButtonFlightsShow(){
	ButtonShow(btnFlightBack, false);
	ButtonShow(btnFlightNew, false);
	ButtonShow(btnFlightEdit, false);
	ButtonShow(btnFlightRemove, false);
	ButtonShow(btnFlightTicket, false);
	ButtonShow(btnFlightCancel, false);
	ButtonShow(btnFlightClear, false);
	ButtonShow(btnNext, false);
	ButtonShow(btnPrev, false);
}

void FlightManagerPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(flightList.size);
	FlightsManagerInitDataTable();
	TableShow(flightsTable);
}

void FlightManagerNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(flightList.size);
	FlightsManagerInitDataTable();
	TableShow(flightsTable);
}

void FlightManagerTicketButtonAction(){
	TicketBuyPageUIShow(txtFlightsID.content);
	FirstInit();
}

void RemoveFlight(){
	Delete_Any_Flight(flightList, txtFlightsID.content);
	DecPlaneFlight(txtFlightsPlane.content);
	UpdatePageTableStatus(flightList.size);
	FlightsManagerInitDataTable();
	ClearFlightsTextBoxs();
	TableShow(flightsTable);
	SetFlightTextBoxNormalMode();
	SetFlightButtonsInNormalMode();
}

void FlightManagerRemoveButtonAction(){
	if(isFlightSold(txtFlightsID.content)){
		InitDialogAndShow(charError.scontent[languageMode].content, charCannotRemove.scontent[languageMode].content, 400, 200, 950, 500, YES, DoFlightNothing, 0, 0);
	}
	else{
		InitDialogAndShow(charConfirm.scontent[languageMode].content, charConfirmRemove.scontent[languageMode].content, 400, 200, 950, 500, YESNO, RemoveFlight, DoFlightNothing, 0);
	}
	FirstInit();
}

void FlightManagerClearButtonAction(){
	ClearFlightsTextBoxs();
	TextBoxSetEnable(txtFlightsID, true);
	TextBoxSetEnable(txtFlightsStart, true);
	TextBoxSetEnable(txtFlightsTo, true);
	TextBoxSetEnable(txtFlightsPlane, true);
	TextBoxSetEnable(txtFlightsSTT, false);
	ButtonSetEnable(btnFlightBack, true);
	ButtonSetEnable(btnFlightNew, true);
	ButtonSetEnable(btnFlightEdit, false);
	ButtonSetEnable(btnFlightRemove, false);
	ButtonSetEnable(btnFlightTicket, false);
	ButtonSetEnable(btnFlightCancel, false);
	ButtonSetEnable(btnFlightClear, false);
}

void ButtonsFlightsManager(){
	
	ButtonChangeName(btnFlightBack, charBtnBack.scontent[languageMode].content);
	ButtonChangeName(btnFlightNew, charBtnNew.scontent[languageMode].content);
	ButtonChangeName(btnFlightEdit, charBtnSave.scontent[languageMode].content);
	ButtonChangeName(btnFlightRemove, charBtnRemove.scontent[languageMode].content);
	ButtonChangeName(btnFlightTicket, charBtnTicket.scontent[languageMode].content);
	ButtonChangeName(btnFlightCancel, charBtnCancel.scontent[languageMode].content);
	
	ButtonChangePosition(btnNext, BUTTON_NEXT_LIST_FLIGHT_LEFT, BUTTON_NEXT_LIST_FLIGHT_TOP, BUTTON_NEXT_LIST_FLIGHT_RIGHT, BUTTON_NEXT_LIST_FLIGHT_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_PREVIOUS_LIST_FLIGHT_LEFT, BUTTON_PREVIOUS_LIST_FLIGHT_TOP, BUTTON_PREVIOUS_LIST_FLIGHT_RIGHT, BUTTON_PREVIOUS_LIST_FLIGHT_BOTTOM);
	
	ButtonSetEnable(btnFlightBack, true);
	ButtonSetEnable(btnFlightNew, true);
	ButtonSetEnable(btnFlightEdit, false);
	ButtonSetEnable(btnFlightRemove, false);
	ButtonSetEnable(btnFlightTicket, false);
	ButtonSetEnable(btnFlightCancel, false);
	ButtonSetEnable(btnFlightClear, false);
	ButtonSetEnable(btnNext, false);
	ButtonSetEnable(btnPrev, false);
	
	SetButtonListener(&btnFlightBack, FlightManagerBackButtonAction);
	SetButtonListener(&btnFlightNew, FlightManagerNewButtonAction);
	SetButtonListener(&btnFlightEdit, FlightManagerEditButtonAction);
	SetButtonListener(&btnFlightTicket, FlightManagerTicketButtonAction);
	SetButtonListener(&btnFlightCancel, FlightManagerCancelButtonAction);
	SetButtonListener(&btnFlightRemove, FlightManagerRemoveButtonAction);
	SetButtonListener(&btnFlightClear, FlightManagerClearButtonAction);
	SetButtonListener(&btnNext, FlightManagerNextButtonAction);
	SetButtonListener(&btnPrev, FlightManagerPrevButtonAction);
	
	ButtonFlightsShow();
}

void PrintFlightsTitle(){
	PrintText(WIDTH/2, FLIGHT_TITLE_TOP, titleFlightsManagerPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE, FONT_MAIN);
}

void FirstInitWithoutClearTextBox(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
//	ClearFlightsTextBoxs();
	PrintFlightsTitle();
	ButtonsFlightsManager();
	TableFlightsManager();
	DrawFlightTextBoxs();
}

void FirstInit(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	ClearFlightsTextBoxs();
	PrintFlightsTitle();
	ButtonsFlightsManager();
	TableFlightsManager();
	DrawFlightTextBoxs();
}

void CorrectFlightForm(){
	CorrectIDForm(txtFlightsID.content);
	CorrectIDForm(txtFlightsPlane.content);
	CorrectNameForm(txtFlightsTo.content);
	TextBoxDraw(txtFlightsID);
	TextBoxDraw(txtFlightsPlane);
	TextBoxDraw(txtFlightsTo);
}

void FlightsManagerShow(){
	isFlightBack=false;
	ReadFlightsFromFile();
	UpdateCompletePerRead();
	FirstInit();
	
	while(!isFlightBack){
		MouseWaitingClick();
		CorrectFlightForm();
	}
}
