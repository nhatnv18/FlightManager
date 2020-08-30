#pragma once
#include "main_define.h"
#include "FlightsStruct.h"
#include "ButtonControl.h"
#include "DataControl.h"
#include "CustomerStruct.h"
#include "TextBoxControl.h"
#include "TicketListMode.h"
#include "StringDefine.h"

#define TICKET_MANAGER_TITLE_TOP 20

#define TICKET_MANAGER_INFO_TOP 100
#define TICKET_MANAGER_INFO_LEFT 50
#define TICKET_MANAGER_INFO_RIGHT 1300
#define TICKET_MANAGER_INFO_BOTTOM 150

#define BUTTON_SEAT_WIDTH 30
#define BUTTON_SEAT_HEIGHT 30
#define BUTTON_SEAT_HSPACE 10
#define BUTTON_SEAT_VSPACE 5
#define BUTTON_SEAT_HEAD 250
#define BUTTON_SEAT_TOP 220
#define BUTTON_SEAT_NROWS 6

#define BUTTON_TICKET_BUY_BACK_LEFT 0
#define BUTTON_TICKET_BUY_BACK_RIGHT 150
#define BUTTON_TICKET_BUY_BACK_TOP 0
#define BUTTON_TICKET_BUY_BACK_BOTTOM 70

#define BUTTON_SOLD_TICKET_BUY_LEFT 950
#define BUTTON_SOLD_TICKET_BUY_RIGHT 1050
#define BUTTON_SOLD_TICKET_BUY_TOP 600
#define BUTTON_SOLD_TICKET_BUY_BOTTOM 670

#define BUTTON_REMOVE_TICKET_BUY_LEFT 1060
#define BUTTON_REMOVE_TICKET_BUY_RIGHT 1300
#define BUTTON_REMOVE_TICKET_BUY_TOP 600
#define BUTTON_REMOVE_TICKET_BUY_BOTTOM 670

#define BUTTON_LISTMODE_TICKET_BUY_LEFT 950
#define BUTTON_LISTMODE_TICKET_BUY_RIGHT 1300
#define BUTTON_LISTMODE_TICKET_BUY_TOP 510
#define BUTTON_LISTMODE_TICKET_BUY_BOTTOM 590

#define TICKET_BUY_PANEL_LEFT 50
#define TICKET_BUY_PANEL_TOP 500
#define TICKET_BUY_PANEL_BOTTOM 675
#define TICKET_BUY_PANEL_RIGHT 900
#define TICKET_BUY_PANEL_HEIGHT 35

bool isTicketBuyBack;
Flight *currentSelectedFlight;
bool isExistCustomer=false;
void TicketBuyInit(char *selectedFlightID);
void DoTicketNothing();
void TicketBuyInitWithoutClearTextBox();

Button *btnSeat;

Button btnTicketBuyBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_TICKET_BUY_BACK_LEFT, BUTTON_TICKET_BUY_BACK_TOP, BUTTON_TICKET_BUY_BACK_RIGHT, BUTTON_TICKET_BUY_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnTicketBuySold = CreateAButton(charBtnSell.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_SOLD_TICKET_BUY_LEFT, BUTTON_SOLD_TICKET_BUY_TOP, BUTTON_SOLD_TICKET_BUY_RIGHT, BUTTON_SOLD_TICKET_BUY_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnTicketRemove = CreateAButton(charBtnCancelTicket.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_REMOVE_TICKET_BUY_LEFT, BUTTON_REMOVE_TICKET_BUY_TOP, BUTTON_REMOVE_TICKET_BUY_RIGHT, BUTTON_REMOVE_TICKET_BUY_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnTicketListMode = CreateAButton(charBtnListTicket.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_LISTMODE_TICKET_BUY_LEFT, BUTTON_LISTMODE_TICKET_BUY_TOP, BUTTON_LISTMODE_TICKET_BUY_RIGHT, BUTTON_LISTMODE_TICKET_BUY_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);

TextBox txtTicketBuySeatIndex = CreateATextBox(charIndexSeats.scontent[languageMode].content, "", 5, ' ', '~',TICKET_BUY_PANEL_LEFT+20, TICKET_BUY_PANEL_TOP+10, TICKET_BUY_PANEL_RIGHT-20, TICKET_BUY_PANEL_TOP+10+TICKET_BUY_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, false);
TextBox txtTicketBuyCustomerID = CreateATextBox(charICNumber.scontent[languageMode].content, "", 10, ' ', '~',TICKET_BUY_PANEL_LEFT+20, TICKET_BUY_PANEL_TOP+50, TICKET_BUY_PANEL_RIGHT-20, TICKET_BUY_PANEL_TOP+50+TICKET_BUY_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtTicketBuyCustomerName = CreateATextBox(charName.scontent[languageMode].content, "", 50, ' ', '~',TICKET_BUY_PANEL_LEFT+20, TICKET_BUY_PANEL_TOP+90, TICKET_BUY_PANEL_RIGHT-20, TICKET_BUY_PANEL_TOP+90+TICKET_BUY_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtTicketBuyCustomerGender = CreateATextBox(charGender.scontent[languageMode].content, "", 10, ' ', '~',TICKET_BUY_PANEL_LEFT+20, TICKET_BUY_PANEL_TOP+130, TICKET_BUY_PANEL_RIGHT-20, TICKET_BUY_PANEL_TOP+130+TICKET_BUY_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);


void PrintTicketBuyTitle(){
	PrintText(WIDTH/2, TICKET_MANAGER_TITLE_TOP, titleTicketManagerPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE, FONT_MAIN);
}

void PrintTicketBuyInfo(){
	DrawRecStroke(TICKET_MANAGER_INFO_LEFT, TICKET_MANAGER_INFO_TOP, TICKET_MANAGER_INFO_RIGHT, TICKET_MANAGER_INFO_BOTTOM, SOLID_LINE, BLACK, 2);
	PrintText(TICKET_MANAGER_INFO_LEFT+15, TICKET_MANAGER_INFO_TOP, charInformation.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_CENTER, 2, FONT_MAIN);
	PrintText(TICKET_MANAGER_INFO_LEFT+105, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, charID.scontent[languageMode].content, WHITE, LIGHTBLUE, ALIGN_LEFT_CENTER, 2, FONT_ERROR);
	PrintText(TICKET_MANAGER_INFO_LEFT+170, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, currentSelectedFlight->flightID, WHITE, BLUE, ALIGN_LEFT_CENTER, 2, FONT_MAIN);
	PrintText(TICKET_MANAGER_INFO_LEFT+400, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, charStartOn.scontent[languageMode].content, WHITE, LIGHTBLUE, ALIGN_LEFT_CENTER, 2, FONT_ERROR);
	PrintText(TICKET_MANAGER_INFO_LEFT+550, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, currentSelectedFlight->dtime, WHITE, BLUE, ALIGN_LEFT_CENTER, 2, FONT_MAIN);
	PrintText(TICKET_MANAGER_INFO_LEFT+880, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, charFlightTo.scontent[languageMode].content, WHITE, LIGHTBLUE, ALIGN_LEFT_CENTER, 2, FONT_ERROR);
	PrintText(TICKET_MANAGER_INFO_LEFT+1050, (TICKET_MANAGER_INFO_TOP+TICKET_MANAGER_INFO_BOTTOM)/2+5, currentSelectedFlight->to, WHITE, BLUE, ALIGN_LEFT_CENTER, 2, FONT_MAIN);
}

void DrawPlaneLine(){
	DrawEllipse(300, 325, 250, 125, BLACK, 2);
	DrawEllipse(1250, 325, 50, 125, BLACK, 2);
	DrawRecFill(300, 200, 1250, 450, SOLID_FILL, WHITE);
	DrawLine(300, 200, 1250, 200, SOLID_LINE, BLACK, 2);
	DrawLine(300, 450, 1250, 450, SOLID_LINE, BLACK, 2);
}

void TicketBuyPageButtonInit(){
	
	ButtonChangeName(btnTicketBuyBack, charBtnBack.scontent[languageMode].content);
	ButtonChangeName(btnTicketBuySold, charBtnSell.scontent[languageMode].content);
	ButtonChangeName(btnTicketRemove, charBtnCancelTicket.scontent[languageMode].content);
	ButtonChangeName(btnTicketListMode, charBtnListTicket.scontent[languageMode].content);
	
	btnSeat = new Button[currentSelectedFlight->ticket.size];
	
	int ncol = (currentSelectedFlight->ticket.size%BUTTON_SEAT_NROWS==0)?currentSelectedFlight->ticket.size/BUTTON_SEAT_NROWS:currentSelectedFlight->ticket.size/BUTTON_SEAT_NROWS+1;
	
	int leftIndex=0;
	int rowIndex=0;
	int leftPos=BUTTON_SEAT_HEAD;
	int rowPos=BUTTON_SEAT_TOP;
	for(int i=0; i<currentSelectedFlight->ticket.size; i++){
		btnSeat[i] = CreateAButton(currentSelectedFlight->ticket.tickets[i].index, FONT_ERROR, 1, WHITE, BLUE, leftPos, rowPos, leftPos+BUTTON_SEAT_WIDTH, rowPos+BUTTON_SEAT_HEIGHT, BLUE, YELLOW, BLUE, YELLOW, true);
		if(rowIndex<BUTTON_SEAT_NROWS-1){
			rowIndex++;
			rowPos += BUTTON_SEAT_HEIGHT+BUTTON_SEAT_VSPACE;
		}
		else{
			rowIndex=0;
			rowPos=BUTTON_SEAT_TOP;
			leftIndex++;
			leftPos += BUTTON_SEAT_WIDTH+BUTTON_SEAT_HSPACE;
		}
	}
}

void TicketBuyPageButtonSetEnable(){
	
	ButtonSetEnable(btnTicketBuyBack, true);
	ButtonSetEnable(btnTicketBuySold, false);
	ButtonSetEnable(btnTicketRemove, false);
	ButtonSetEnable(btnTicketListMode, true);
	
	for(int i=0; i<currentSelectedFlight->ticket.size; i++){
		if(isSold(currentSelectedFlight->ticket, i)){
			ButtonChangeColor(btnSeat[i], BLUE, BLUE, LIGHTCYAN, LIGHTBLUE, LIGHTCYAN, LIGHTBLUE);
		}
		ButtonSetEnable(btnSeat[i], true);
	}
}

void SetTextBoxClickedMode(){
//	std::cout<<currentBtn.caption<<std::endl;
	if(currentSelectedFlight->status==0 || currentSelectedFlight->status>=3){
		
		ClearTextBox(txtTicketBuyCustomerID);
		ClearTextBox(txtTicketBuyCustomerName);
		ClearTextBox(txtTicketBuyCustomerGender);
		
		TextBoxSetEnable(txtTicketBuySeatIndex, false);
		TextBoxSetEnable(txtTicketBuyCustomerID, false);
		TextBoxSetEnable(txtTicketBuyCustomerName, false);
		TextBoxSetEnable(txtTicketBuyCustomerGender, false);
		
		SetContentTextBox(txtTicketBuySeatIndex, currentBtn.caption);
		SetContentTextBox(txtTicketBuyCustomerID, currentSelectedFlight->ticket.tickets[ArrtoNum(currentBtn.caption)-1].idPersonalNumber);
		
		TextBoxDraw(txtTicketBuySeatIndex);
	}
	else{
		if(isSold(currentSelectedFlight->ticket, ArrtoNum(currentBtn.caption)-1)){
			TextBoxSetEnable(txtTicketBuySeatIndex, false);
			TextBoxSetEnable(txtTicketBuyCustomerID, false);
			TextBoxSetEnable(txtTicketBuyCustomerName, false);
			TextBoxSetEnable(txtTicketBuyCustomerGender, false);
			
			SetContentTextBox(txtTicketBuySeatIndex, currentBtn.caption);
			SetContentTextBox(txtTicketBuyCustomerID, currentSelectedFlight->ticket.tickets[ArrtoNum(currentBtn.caption)-1].idPersonalNumber);
					
			TextBoxDraw(txtTicketBuySeatIndex);
		}
		else{
			
			ClearTextBox(txtTicketBuyCustomerID);
			ClearTextBox(txtTicketBuyCustomerName);
			ClearTextBox(txtTicketBuyCustomerGender);
			
			TextBoxSetEnable(txtTicketBuySeatIndex, false);
			TextBoxSetEnable(txtTicketBuyCustomerID, true);
			TextBoxSetEnable(txtTicketBuyCustomerName, false);
			TextBoxSetEnable(txtTicketBuyCustomerGender, false);
			
			SetContentTextBox(txtTicketBuySeatIndex, currentBtn.caption);
					
			TextBoxDraw(txtTicketBuySeatIndex);
		}
	}
		
}

void SetTextBoxNormalMode(){
	ClearTextBox(txtTicketBuySeatIndex);
	ClearTextBox(txtTicketBuyCustomerID);
	ClearTextBox(txtTicketBuyCustomerName);
	ClearTextBox(txtTicketBuyCustomerGender);
	
	TextBoxSetEnable(txtTicketBuySeatIndex, false);
	TextBoxSetEnable(txtTicketBuyCustomerID, false);
	TextBoxSetEnable(txtTicketBuyCustomerName, false);
	TextBoxSetEnable(txtTicketBuyCustomerGender, false);
}

void SetButtonClickedMode(){
	if(currentSelectedFlight->status==0 || currentSelectedFlight->status>=3){
		ButtonSetEnable(btnTicketBuySold, false);
		ButtonSetEnable(btnTicketRemove, false);
	}
	else{
		if(isSold(currentSelectedFlight->ticket, ArrtoNum(currentBtn.caption)-1)){
			ButtonSetEnable(btnTicketBuySold, false);
			ButtonSetEnable(btnTicketRemove, true);
		}
		else{
			ButtonSetEnable(btnTicketBuySold, true);
			ButtonSetEnable(btnTicketRemove, false);
		}
	}
}

//void SetButtonNormalMode(){
//	ButtonSetEnable(btnTicketBuySold, false);
//}

void ClickSeatAction(){
	SetTextBoxClickedMode();
	SetButtonClickedMode();
}

void TicketBuyBackClickAction(){
	WriteFlightsToFile();
	isTicketBuyBack=true;
}

void TicketBuySellClickedAction(){
	if(strlen(txtTicketBuyCustomerID.content)==0 || strlen(txtTicketBuyCustomerName.content)==0 || strlen(txtTicketBuyCustomerGender.content)==0){
		if(strlen(txtTicketBuyCustomerID.content)==0){
//			PrintText(txtTicketBuyCustomerID.right-3, txtTicketBuyCustomerID.bottom-2, "Personal ID is Empty", txtTicketBuyCustomerID.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoTicketNothing, 0, 0);
		}
		else if(strlen(txtTicketBuyCustomerName.content)==0){
//			PrintText(txtTicketBuyCustomerName.right-3, txtTicketBuyCustomerName.bottom-2, "Name is Empty", txtTicketBuyCustomerName.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoTicketNothing, 0, 0);
		}
		else if(strlen(txtTicketBuyCustomerGender.content)==0){
//			PrintText(txtTicketBuyCustomerGender.right-3, txtTicketBuyCustomerGender.bottom-2, "Gender is Empty", txtTicketBuyCustomerGender.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoTicketNothing, 0, 0);
		}
		TicketBuyInitWithoutClearTextBox();
		ButtonSetEnable(btnTicketBuySold, true);
		ButtonSetEnable(btnTicketRemove, false);
		TextBoxSetEnable(txtTicketBuySeatIndex, false);
		TextBoxSetEnable(txtTicketBuyCustomerID, true);
		TextBoxSetEnable(txtTicketBuyCustomerName, false);
		TextBoxSetEnable(txtTicketBuyCustomerGender, false);
//		SetButtonClickedMode();
//		SetTextBoxClickedMode();
		
	}
	else{
		
		if(!isExistCustomer){
			char firstName[40]="", lastName[10]="";
			SplitName(txtTicketBuyCustomerName.content, firstName, lastName);
			InsertNodeIntoAVL(customerList, CreateNewCustomerNode(CreateNewCustomer(txtTicketBuyCustomerID.content, firstName, lastName, txtTicketBuyCustomerName.content, txtTicketBuyCustomerGender.content)));
//			WriteCustomersToFile();

			ActiveCustomer(customerList, txtTicketBuyCustomerID.content);
			WriteCustomersToFile();
			InsertVe(currentSelectedFlight->ticket, ArrtoNum(txtTicketBuySeatIndex.content)-1, txtTicketBuyCustomerID.content);
			if(currentSelectedFlight->ticket.size==currentSelectedFlight->ticket.sold){
				currentSelectedFlight->status=2;
			}
			WriteFlightsToFile();
	//		SetButtonNormalMode();
			SetTextBoxNormalMode();
			TicketBuyPageButtonSetEnable();
		}
		else{
			if(isCustomerInTimeRange(flightList, currentSelectedFlight->timeStart, txtTicketBuyCustomerID.content)){
				InitDialogAndShow(charError.scontent[languageMode].content, charCustomerBusy.scontent[languageMode].content, 400, 200, 950, 500, YES, DoTicketNothing, 0, 0);
				TicketBuyInitWithoutClearTextBox();
				ButtonSetEnable(btnTicketBuySold, true);
				ButtonSetEnable(btnTicketRemove, false);
				TextBoxSetEnable(txtTicketBuySeatIndex, false);
				TextBoxSetEnable(txtTicketBuyCustomerID, true);
				TextBoxSetEnable(txtTicketBuyCustomerName, false);
				TextBoxSetEnable(txtTicketBuyCustomerGender, false);
			}
			else{
				ActiveCustomer(customerList, txtTicketBuyCustomerID.content);
				WriteCustomersToFile();
				InsertVe(currentSelectedFlight->ticket, ArrtoNum(txtTicketBuySeatIndex.content)-1, txtTicketBuyCustomerID.content);
				if(currentSelectedFlight->ticket.size==currentSelectedFlight->ticket.sold){
					currentSelectedFlight->status=2;
				}
				WriteFlightsToFile();
		//		SetButtonNormalMode();
				SetTextBoxNormalMode();
				TicketBuyPageButtonSetEnable();
			}
		}

	}
}

void RemoveTicket(){
	UpdateActiveCustomer(customerList, txtTicketBuyCustomerID.content);
	WriteCustomersToFile();
	DeleteVe(currentSelectedFlight->ticket, ArrtoNum(txtTicketBuySeatIndex.content)-1);
	if(currentSelectedFlight->ticket.size>currentSelectedFlight->ticket.sold){
		currentSelectedFlight->status=1;
	}
	WriteFlightsToFile();
	SetTextBoxNormalMode();
	TicketBuyPageButtonSetEnable();
}

void DoTicketNothing(){
}

void TicketBuyRemoveClickedAction(){
	InitDialogAndShow(charConfirm.scontent[languageMode].content, charConfirmRemove.scontent[languageMode].content, 400, 200, 950, 500, YESNO, RemoveTicket, DoTicketNothing, 0);
	TicketBuyInit(currentSelectedFlight->flightID);
}

void TicketBuyListModeClickedAction(){
	TicketListModeView(currentSelectedFlight->flightID);
	TicketBuyInit(currentSelectedFlight->flightID);
}

void TicketBuyPageButtonSetLitener(){
	
	SetButtonListener(&btnTicketBuyBack, TicketBuyBackClickAction);
	SetButtonListener(&btnTicketBuySold, TicketBuySellClickedAction);
	SetButtonListener(&btnTicketRemove, TicketBuyRemoveClickedAction);
	SetButtonListener(&btnTicketListMode, TicketBuyListModeClickedAction);
	
	for(int i=0; i<currentSelectedFlight->ticket.size; i++){
		SetButtonListener(&btnSeat[i], ClickSeatAction);
	}
}

void TicketBuyPageButtonShow(){
	
	ButtonShow(btnTicketBuyBack, false);
	ButtonShow(btnTicketBuySold, false);
	ButtonShow(btnTicketRemove, false);
	ButtonShow(btnTicketListMode, false);
	
	for(int i=0; i<currentSelectedFlight->ticket.size; i++){
		ButtonShow(btnSeat[i], false);
	}
}

void TicketBuyPageButtonManager(){
	TicketBuyPageButtonInit();
	TicketBuyPageButtonSetEnable();
	TicketBuyPageButtonSetLitener();
	TicketBuyPageButtonShow();
}

void TicketButtonClearList(){
	delete []btnSeat;
}

void ClearTicketBuyTextBox(){
	TextBoxSetTitle(txtTicketBuySeatIndex, charIndexSeats.scontent[languageMode].content);
	TextBoxSetTitle(txtTicketBuyCustomerID, charICNumber.scontent[languageMode].content);
	TextBoxSetTitle(txtTicketBuyCustomerName, charName.scontent[languageMode].content);
	TextBoxSetTitle(txtTicketBuyCustomerGender, charGender.scontent[languageMode].content);
	
	ClearTextBox(txtTicketBuySeatIndex);
	ClearTextBox(txtTicketBuyCustomerID);
	ClearTextBox(txtTicketBuyCustomerName);
	ClearTextBox(txtTicketBuyCustomerGender);
}

void TicketBuyTextBoxManager(){
	
//	TextBoxSetTitle(txtTicketBuySeatIndex, charIndexSeats.scontent[languageMode].content);
//	TextBoxSetTitle(txtTicketBuyCustomerID, charICNumber.scontent[languageMode].content);
//	TextBoxSetTitle(txtTicketBuyCustomerName, charName.scontent[languageMode].content);
//	TextBoxSetTitle(txtTicketBuyCustomerGender, charGender.scontent[languageMode].content);
	
	PrintText(TICKET_BUY_PANEL_LEFT, TICKET_BUY_PANEL_TOP-3, charTicketInfo.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_BOTTOM, 1, FONT_MAIN);
	DrawRecStroke(TICKET_BUY_PANEL_LEFT, TICKET_BUY_PANEL_TOP, TICKET_BUY_PANEL_RIGHT, TICKET_BUY_PANEL_BOTTOM, SOLID_LINE, BLACK, 3);
	
	TextBoxSetEnable(txtTicketBuySeatIndex, false);
	TextBoxSetEnable(txtTicketBuyCustomerID, false);
	TextBoxSetEnable(txtTicketBuyCustomerName, false);
	TextBoxSetEnable(txtTicketBuyCustomerGender, false);
	
	SetTextBoxListener(&txtTicketBuySeatIndex);
	SetTextBoxListener(&txtTicketBuyCustomerID);
	SetTextBoxListener(&txtTicketBuyCustomerName);
	SetTextBoxListener(&txtTicketBuyCustomerGender);
	
	TextBoxDraw(txtTicketBuySeatIndex);
	TextBoxDraw(txtTicketBuyCustomerID);
	TextBoxDraw(txtTicketBuyCustomerName);
	TextBoxDraw(txtTicketBuyCustomerGender);
}

void TicketBuyInitWithoutClearTextBox(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
//	currentSelectedFlight = &Find_Flight(flightList, selectedFlightID)->data;
//	ClearTicketBuyTextBox();
	PrintTicketBuyTitle();
	PrintTicketBuyInfo();
	DrawPlaneLine();
//	TicketButtonClearList();
	TicketBuyPageButtonManager();
//	SearchFlightsTableManager();
	TicketBuyTextBoxManager();
}

void TicketBuyInit(char *selectedFlightID){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	currentSelectedFlight = &Find_Flight(flightList, selectedFlightID)->data;
	ClearTicketBuyTextBox();
	PrintTicketBuyTitle();
	PrintTicketBuyInfo();
	DrawPlaneLine();
//	TicketButtonClearList();
	TicketBuyPageButtonManager();
//	SearchFlightsTableManager();
	TicketBuyTextBoxManager();
}

void FindCustomer(){
	if(strlen(txtTicketBuyCustomerID.content)>0){
		Node *tmpCustomer = FindNodeByICNumber(customerList, txtTicketBuyCustomerID.content);
		if(tmpCustomer==NULL){
			isExistCustomer=false;
			TextBoxSetEnable(txtTicketBuyCustomerName, true);
			TextBoxSetEnable(txtTicketBuyCustomerGender, true);
		}
		else{
			isExistCustomer=true;
			SetContentTextBox(txtTicketBuyCustomerName, tmpCustomer->data.fullName);
			SetContentTextBox(txtTicketBuyCustomerGender, tmpCustomer->data.gender);
			TextBoxSetEnable(txtTicketBuyCustomerName, false);
			TextBoxSetEnable(txtTicketBuyCustomerGender, false);
		}
	}
}

void CorrectTicketForm(){
	CorrectNameForm(txtTicketBuyCustomerName.content);
	CorrectNameForm(txtTicketBuyCustomerGender.content);
	TextBoxDraw(txtTicketBuyCustomerName);
	TextBoxDraw(txtTicketBuyCustomerGender);
}

void TicketBuyPageUIShow(char *selectedFlightID){
	
	isTicketBuyBack=false;
	//readData
	TicketBuyInit(selectedFlightID);
	
	while(!isTicketBuyBack){
		MouseWaitingClick();
		CorrectTicketForm();
		FindCustomer();
	}
}
