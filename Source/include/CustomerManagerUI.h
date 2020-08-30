#pragma once

#include "main_define.h"
#include "ButtonControl.h"
#include "CustomerStruct.h"
#include "DataControl.h"
#include "TextBoxControl.h"
#include "StringDefine.h"

#define CUSTOMER_TITLE_TOP 20

#define BUTTON_CUSTOMER_BACK_LEFT 0
#define BUTTON_CUSTOMER_BACK_RIGHT 150
#define BUTTON_CUSTOMER_BACK_TOP 0
#define BUTTON_CUSTOMER_BACK_BOTTOM 70

#define BUTTON_CUSTOMER_NEW_LEFT 950
#define BUTTON_CUSTOMER_NEW_RIGHT 1050
#define BUTTON_CUSTOMER_NEW_TOP 600
#define BUTTON_CUSTOMER_NEW_BOTTOM 670

#define BUTTON_CUSTOMER_LIST_LEFT 1060
#define BUTTON_CUSTOMER_LIST_RIGHT 1160
#define BUTTON_CUSTOMER_LIST_TOP 600
#define BUTTON_CUSTOMER_LIST_BOTTOM 670

#define BUTTON_CUSTOMER_REMOVE_LEFT 1170
#define BUTTON_CUSTOMER_REMOVE_RIGHT 1300
#define BUTTON_CUSTOMER_REMOVE_TOP 600
#define BUTTON_CUSTOMER_REMOVE_BOTTOM 670

#define BUTTON_NEXT_LIST_CUSTOMER_LEFT 1250
#define BUTTON_NEXT_LIST_CUSTOMER_RIGHT 1280
#define BUTTON_NEXT_LIST_CUSTOMER_TOP 470
#define BUTTON_NEXT_LIST_CUSTOMER_BOTTOM 500

#define BUTTON_PREVIOUS_LIST_CUSTOMER_LEFT 990
#define BUTTON_PREVIOUS_LIST_CUSTOMER_RIGHT 1020
#define BUTTON_PREVIOUS_LIST_CUSTOMER_TOP 470
#define BUTTON_PREVIOUS_LIST_CUSTOMER_BOTTOM 500

#define RECORD_CUSTOMER_HEIGHT 35
#define TABLE_CUSTOMER_LEFT 50
#define TABLE_CUSTOMER_RIGHT 1300
#define TABLE_CUSTOMER_SIZE 10
#define TABLE_CUSTOMER_TOP 80

#define CUSTOMER_PANEL_LEFT 50
#define CUSTOMER_PANEL_TOP 530
#define CUSTOMER_PANEL_BOTTOM 675
#define CUSTOMER_PANEL_RIGHT 900
#define CUSTOMER_PANEL_HEIGHT 35

#define CUSTOMER_CLEAR_BUTTON_LEFT 900
#define CUSTOMER_CLEAR_BUTTON_TOP 530
#define CUSTOMER_CLEAR_BUTTON_BOTTOM 560
#define CUSTOMER_CLEAR_BUTTON_RIGHT 930

void CustomersManagerInitDataTable();
void ClearCustomerTextBoxs();
void CustomerFirstInit();
void CustomerFirstInitWithoutClearTextBoxContent();

bool isCustomerBack;

Table customersTable;

Button btnCustomerBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_CUSTOMER_BACK_LEFT, BUTTON_CUSTOMER_BACK_TOP, BUTTON_CUSTOMER_BACK_RIGHT, BUTTON_CUSTOMER_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnCustomerNew = CreateAButton(charBtnNew.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_CUSTOMER_NEW_LEFT, BUTTON_CUSTOMER_NEW_TOP, BUTTON_CUSTOMER_NEW_RIGHT, BUTTON_CUSTOMER_NEW_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnCustomerList = CreateAButton(charBtnSave.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_CUSTOMER_LIST_LEFT, BUTTON_CUSTOMER_LIST_TOP, BUTTON_CUSTOMER_LIST_RIGHT, BUTTON_CUSTOMER_LIST_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnCustomerRemove = CreateAButton(charBtnRemove.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_CUSTOMER_REMOVE_LEFT, BUTTON_CUSTOMER_REMOVE_TOP, BUTTON_CUSTOMER_REMOVE_RIGHT, BUTTON_CUSTOMER_REMOVE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnCustomerClear = CreateAButton("x", FONT_MAIN, 1, WHITE, BLUE, CUSTOMER_CLEAR_BUTTON_LEFT, CUSTOMER_CLEAR_BUTTON_TOP, CUSTOMER_CLEAR_BUTTON_RIGHT, CUSTOMER_CLEAR_BUTTON_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);

TextBox txtCustomerICNumber = CreateATextBox(charICNumber.scontent[languageMode].content, "", 10, ' ', '~',CUSTOMER_PANEL_LEFT+20, CUSTOMER_PANEL_TOP+10, CUSTOMER_PANEL_RIGHT-20, CUSTOMER_PANEL_TOP+10+CUSTOMER_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtCustomerFullName = CreateATextBox(charName.scontent[languageMode].content, "", 50, ' ', '~',CUSTOMER_PANEL_LEFT+20, CUSTOMER_PANEL_TOP+50, CUSTOMER_PANEL_RIGHT-20, CUSTOMER_PANEL_TOP+50+CUSTOMER_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtCustomerGender = CreateATextBox(charGender.scontent[languageMode].content, "", 10, ' ', '~',CUSTOMER_PANEL_LEFT+20, CUSTOMER_PANEL_TOP+90, CUSTOMER_PANEL_RIGHT-20, CUSTOMER_PANEL_TOP+90+CUSTOMER_PANEL_HEIGHT, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);

void PrintCustomerManagerTitle(){
	PrintText(WIDTH/2, CUSTOMER_TITLE_TOP, titleCustomerManagerPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE, FONT_MAIN);
}

void DoCusNothing(){
}

void CustomersManagerBackButtonAction(){
	InitDialogAndShow(charConfirm.scontent[languageMode].content, charSaveAllChange.scontent[languageMode].content, 400, 200, 950, 500, YESNO, WriteCustomersToFile, DoCusNothing, 0);
	isCustomerBack=true;
}

void CustomerManagerNewButtonAction(){
	if(strlen(txtCustomerICNumber.content)==0 || strlen(txtCustomerFullName.content)==0 || strlen(txtCustomerGender.content)==0){
		if(strlen(txtCustomerICNumber.content)==0){
//			PrintText(txtCustomerICNumber.right-3, txtCustomerICNumber.bottom-2, "Enter value to add new", txtCustomerICNumber.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
		}
		else if(strlen(txtCustomerFullName.content)==0){
//			PrintText(txtCustomerFullName.right-3, txtCustomerFullName.bottom-2, "Enter value to add new", txtCustomerFullName.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
		}
		else if(strlen(txtCustomerGender.content)==0){
//			PrintText(txtCustomerGender.right-3, txtCustomerGender.bottom-2, "Enter value to add new", txtCustomerGender.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
		}
		CustomerFirstInitWithoutClearTextBoxContent();
	}
	else{
		
		Node *findCustomer = NULL;
		findCustomer = FindNodeByICNumber(customerList, txtCustomerICNumber.content);

		if(findCustomer==NULL){
			char firstName[40]="", lastName[10]="";
			SplitName(txtCustomerFullName.content, firstName, lastName);
			InsertNodeIntoAVL(customerList, CreateNewCustomerNode(CreateNewCustomer(txtCustomerICNumber.content, firstName, lastName, txtCustomerFullName.content, txtCustomerGender.content)));
			UpdatePageTableStatus(customerList.size);
			CustomersManagerInitDataTable();
			ClearCustomerTextBoxs();
			TableShow(customersTable);
		}
		else{
//			PrintText(txtCustomerICNumber.right-3, txtCustomerICNumber.bottom-2, "This ID has used", txtCustomerICNumber.bkColor, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charIDUsed.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
			CustomerFirstInitWithoutClearTextBoxContent();
		}
		
	}
}

void CustomerManagerPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(customerList.size);
	CustomersManagerInitDataTable();
	TableShow(customersTable);
}

void CustomerManagerNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(customerList.size);
	CustomersManagerInitDataTable();
	TableShow(customersTable);
}

void RemoveCustomer(){
	DeleteNodeFromAVL(customerList, FindNodeByICNumber(customerList, txtCustomerICNumber.content));
//	WriteCustomersToFile();
}

void CustomerManagerRemoveButtonAction(){
	if(!isActive(customerList, txtCustomerICNumber.content)){
		InitDialogAndShow(charConfirm.scontent[languageMode].content, charConfirmRemove.scontent[languageMode].content, 400, 200, 950, 500, YESNO, RemoveCustomer, DoCusNothing, 0);
	}
	else{
		InitDialogAndShow(charError.scontent[languageMode].content, charCannotRemove.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
	}
	CustomerFirstInit();
}

void CustomerManagerClearButtonAction(){
	ClearCustomerTextBoxs();
	TextBoxSetEnable(txtCustomerICNumber, true);
	TextBoxSetEnable(txtCustomerFullName, true);
	TextBoxSetEnable(txtCustomerGender, true);
	ButtonSetEnable(btnCustomerNew, true);
	ButtonSetEnable(btnCustomerClear, false);
	ButtonSetEnable(btnCustomerList, false);
	ButtonSetEnable(btnCustomerRemove, false);
}

void CustomerEditButtonAction(){
	if(strlen(txtCustomerFullName.content)==0){
		InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
		CustomerFirstInitWithoutClearTextBoxContent();
		TextBoxSetEnable(txtCustomerICNumber, false);
		TextBoxSetEnable(txtCustomerFullName, true);
		TextBoxSetEnable(txtCustomerGender, true);
		ButtonSetEnable(btnCustomerNew, false);
		ButtonSetEnable(btnCustomerClear, true);
		ButtonSetEnable(btnCustomerList, true);
		ButtonSetEnable(btnCustomerRemove, true);
	}
	else if(strlen(txtCustomerGender.content)==0){
		InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, DoCusNothing, 0, 0);
		CustomerFirstInitWithoutClearTextBoxContent();
		TextBoxSetEnable(txtCustomerICNumber, false);
		TextBoxSetEnable(txtCustomerFullName, true);
		TextBoxSetEnable(txtCustomerGender, true);
		ButtonSetEnable(btnCustomerNew, false);
		ButtonSetEnable(btnCustomerClear, true);
		ButtonSetEnable(btnCustomerList, true);
		ButtonSetEnable(btnCustomerRemove, true);
	}
	else{
		char cusFName[40]="", cusLName[10]="";
		SplitName(txtCustomerFullName.content, cusFName, cusLName);
		EditCustomerByICNumber(customerList, txtCustomerICNumber.content, cusFName, cusLName, txtCustomerFullName.content, txtCustomerGender.content);
		CustomerFirstInit();
	}
}

void ButtonsCustomersManager(){
	
	ButtonChangeName(btnCustomerBack, charBtnBack.scontent[languageMode].content);
	ButtonChangeName(btnCustomerNew, charBtnNew.scontent[languageMode].content);
	ButtonChangeName(btnCustomerList, charBtnSave.scontent[languageMode].content);
	ButtonChangeName(btnCustomerRemove, charBtnRemove.scontent[languageMode].content);
	
	ButtonChangePosition(btnNext, BUTTON_NEXT_LIST_CUSTOMER_LEFT, BUTTON_NEXT_LIST_CUSTOMER_TOP, BUTTON_NEXT_LIST_CUSTOMER_RIGHT, BUTTON_NEXT_LIST_CUSTOMER_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_PREVIOUS_LIST_CUSTOMER_LEFT, BUTTON_PREVIOUS_LIST_CUSTOMER_TOP, BUTTON_PREVIOUS_LIST_CUSTOMER_RIGHT, BUTTON_PREVIOUS_LIST_CUSTOMER_BOTTOM);
	
	//Enable
	ButtonSetEnable(btnCustomerBack, true);
	ButtonSetEnable(btnCustomerNew, true);
	ButtonSetEnable(btnCustomerList, false);
	ButtonSetEnable(btnCustomerRemove, false);
	ButtonSetEnable(btnCustomerClear, false);
	ButtonSetEnable(btnNext, false);
	ButtonSetEnable(btnPrev, false);
	
	//Listener
	SetButtonListener(&btnCustomerBack, CustomersManagerBackButtonAction);
	SetButtonListener(&btnCustomerNew, CustomerManagerNewButtonAction);
	SetButtonListener(&btnCustomerList, CustomerEditButtonAction);
	SetButtonListener(&btnCustomerRemove, CustomerManagerRemoveButtonAction);
	SetButtonListener(&btnNext, CustomerManagerNextButtonAction);
	SetButtonListener(&btnPrev, CustomerManagerPrevButtonAction);
	SetButtonListener(&btnCustomerClear, CustomerManagerClearButtonAction);
	
	//Show
	ButtonShow(btnCustomerBack, false);
	ButtonShow(btnCustomerNew, false);
	ButtonShow(btnCustomerList, false);
	ButtonShow(btnCustomerRemove, false);
	ButtonShow(btnCustomerClear, false);
	ButtonShow(btnNext, false);
	ButtonShow(btnPrev, false);
	
}

void AddCusInfoToTextBoxs(Customer cus){
	SetContentTextBox(txtCustomerICNumber, cus.ICNumber);
	SetContentTextBox(txtCustomerFullName, cus.fullName);
	SetContentTextBox(txtCustomerGender, cus.gender);
}

void SetCustomerTextBoxEditMode(){
	if(!isActive(customerList, txtCustomerICNumber.content)){
		TextBoxSetEnable(txtCustomerICNumber, false);
		TextBoxSetEnable(txtCustomerFullName, true);
		TextBoxSetEnable(txtCustomerGender, true);
	}
	else{
		TextBoxSetEnable(txtCustomerICNumber, false);
		TextBoxSetEnable(txtCustomerFullName, false);
		TextBoxSetEnable(txtCustomerGender, false);
	}
}

void SetCustomerButtonsInEditMode(){
	if(!isActive(customerList, txtCustomerICNumber.content)){
		ButtonSetEnable(btnCustomerNew, false);
		ButtonSetEnable(btnCustomerList, true);
		ButtonSetEnable(btnCustomerRemove, true);
	}
	else{
		ButtonSetEnable(btnCustomerNew, false);
		ButtonSetEnable(btnCustomerList, false);
		ButtonSetEnable(btnCustomerRemove, false);
	}
	ButtonSetEnable(btnCustomerClear, true);
}

void ListenItemCustomersList(int index){
	if(strlen(getValue(customersTable, index, 0))>0){
		Customer tmpCus = FindNodeByICNumber(customerList, getValue(customersTable,index, 0))->data;
//		currentFlightRecord.currentRecord = index;
		AddCusInfoToTextBoxs(tmpCus);
		SetCustomerTextBoxEditMode();
		SetCustomerButtonsInEditMode();
	}
}

void CustomersManagerInitDataTable(){
	
	for(int i=0; i<10; i++){
		AddCellTableContent(customersTable, i, 0, "");
		AddCellTableContent(customersTable, i, 1, "");
		AddCellTableContent(customersTable, i, 2, "");
	}
	
	Node *tmp = customerList.root;
	int i=0, j=0;
	
	GetAllDataInTree(customerList.root, i, j, customersTable);
	
}

void TableCustomersManager(){
	customersTable = TableCreate(TABLE_CUSTOMER_LEFT, TABLE_CUSTOMER_TOP, TABLE_CUSTOMER_RIGHT, 3, TABLE_CUSTOMER_SIZE, RECORD_CUSTOMER_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemCustomersList);
	
	AddMenuContent(customersTable, 0, charICNumberFull.scontent[languageMode].content);
	AddMenuContent(customersTable, 1, charName.scontent[languageMode].content);
	AddMenuContent(customersTable, 2, charGender.scontent[languageMode].content);
	
	CustomersManagerInitDataTable();
	UpdatePageTableStatus(customerList.size);
	TableShow(customersTable);
}

void ClearCustomerTextBoxs(){
	
	TextBoxSetTitle(txtCustomerICNumber, charICNumber.scontent[languageMode].content);
	TextBoxSetTitle(txtCustomerFullName, charName.scontent[languageMode].content);
	TextBoxSetTitle(txtCustomerGender, charGender.scontent[languageMode].content);
	
	ClearTextBox(txtCustomerICNumber);
	ClearTextBox(txtCustomerFullName);
	ClearTextBox(txtCustomerGender);
}

void DrawCustomerTextBoxs(){
	
//	TextBoxSetTitle(txtCustomerICNumber, charICNumber.scontent[languageMode].content);
//	TextBoxSetTitle(txtCustomerFullName, charName.scontent[languageMode].content);
//	TextBoxSetTitle(txtCustomerGender, charGender.scontent[languageMode].content);
	
	DrawRecStroke(CUSTOMER_PANEL_LEFT, CUSTOMER_PANEL_TOP, CUSTOMER_PANEL_RIGHT, CUSTOMER_PANEL_BOTTOM, SOLID_LINE, BLACK, 3);
	
	TextBoxSetEnable(txtCustomerICNumber, true);
	TextBoxSetEnable(txtCustomerFullName, true);
	TextBoxSetEnable(txtCustomerGender, true);
	
	SetTextBoxListener(&txtCustomerICNumber);
	SetTextBoxListener(&txtCustomerFullName);
	SetTextBoxListener(&txtCustomerGender);
	
	TextBoxDraw(txtCustomerICNumber);
	TextBoxDraw(txtCustomerFullName);
	TextBoxDraw(txtCustomerGender);
}

void CustomerFirstInitWithoutClearTextBoxContent(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
//	ClearCustomerTextBoxs();
	PrintCustomerManagerTitle();
	ButtonsCustomersManager();
	TableCustomersManager();
	DrawCustomerTextBoxs();
}

void CustomerFirstInit(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	ClearCustomerTextBoxs();
	PrintCustomerManagerTitle();
	ButtonsCustomersManager();
	TableCustomersManager();
	DrawCustomerTextBoxs();
}

void CorrectCustomerForm(){
	CorrectNameForm(txtCustomerFullName.content);
	CorrectNameForm(txtCustomerGender.content);
	TextBoxDraw(txtCustomerFullName);
	TextBoxDraw(txtCustomerGender);
}

void CustomerManagerShow(){
	isCustomerBack=false;
	ReadCustomersFromFile();
	CustomerFirstInit();
	
	while(!isCustomerBack){
		MouseWaitingClick();
		CorrectCustomerForm();
	}
}

