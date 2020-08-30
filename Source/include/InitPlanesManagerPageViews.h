#pragma once
#include "main_define.h"
#include "ButtonControl.h"
#include "TableControl.h"
#include "MouseListener.h"
#include "TextBoxControl.h"
#include "Planes.h"
#include "ArrChar_Num.h"
#include "Dialog.h"
#include "DataControl.h"
#include "StringDefine.h"

#define PLANES_TITLE_TOP 20

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

#define BUTTON_NEXT_LIST_PLANE_LEFT 1250
#define BUTTON_NEXT_LIST_PLANE_RIGHT 1280
#define BUTTON_NEXT_LIST_PLANE_TOP 530
#define BUTTON_NEXT_LIST_PLANE_BOTTOM 560

#define BUTTON_PREVIOUS_LIST_PLANE_LEFT 990
#define BUTTON_PREVIOUS_LIST_PLANE_RIGHT 1020
#define BUTTON_PREVIOUS_LIST_PLANE_TOP 530
#define BUTTON_PREVIOUS_LIST_PLANE_BOTTOM 560

#define PLANE_CLEAR_BUTTON_LEFT 900
#define PLANE_CLEAR_BUTTON_TOP 530
#define PLANE_CLEAR_BUTTON_BOTTOM 560
#define PLANE_CLEAR_BUTTON_RIGHT 930

#define RECORD_PLANE_HEIGHT 40
#define TABLE_PLANE_LEFT 50
#define TABLE_PLANE_RIGHT 1300
#define TABLE_PLANE_SIZE 10
#define TABLE_PLANE_TOP 80

#define PLANE_PANEL_LEFT 50
#define PLANE_PANEL_TOP 530
#define PLANE_PANEL_BOTTOM 670
#define PLANE_PANEL_RIGHT 900

void ReDrawPlaneManagerFirstStatus();
void ReDrawPlaneManagerFirstStatusWithoutTextBox();
void PlaneDoNothing(){
}

bool isBack;

Button btnBack = CreateAButton(charBtnBack.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_BACK_LEFT, BUTTON_BACK_TOP, BUTTON_BACK_RIGHT, BUTTON_BACK_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnNew = CreateAButton(charBtnNew.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_NEW_LEFT, BUTTON_NEW_TOP, BUTTON_NEW_RIGHT, BUTTON_NEW_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);
Button btnEdit = CreateAButton(charBtnSave.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_EDIT_LEFT, BUTTON_EDIT_TOP, BUTTON_EDIT_RIGHT, BUTTON_EDIT_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnRemove = CreateAButton(charBtnRemove.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_REMOVE_LEFT, BUTTON_REMOVE_TOP, BUTTON_REMOVE_RIGHT, BUTTON_REMOVE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnPlaneClear = CreateAButton("x", FONT_MAIN, 1, WHITE, BLUE, PLANE_CLEAR_BUTTON_LEFT, PLANE_CLEAR_BUTTON_TOP, PLANE_CLEAR_BUTTON_RIGHT, PLANE_CLEAR_BUTTON_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);

Table planeList;

TextBox txtPlaneID = CreateATextBox(charID.scontent[languageMode].content, "", 15, ' ', '~',PLANE_PANEL_LEFT+20, PLANE_PANEL_TOP+10, PLANE_PANEL_RIGHT-20, PLANE_PANEL_TOP+40, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtPlaneType = CreateATextBox(charType.scontent[languageMode].content, "", 50, ' ', '~', PLANE_PANEL_LEFT+20, PLANE_PANEL_TOP+50, PLANE_PANEL_RIGHT-20, PLANE_PANEL_TOP+80, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);
TextBox txtPlaneSeats = CreateATextBox(charSeats.scontent[languageMode].content, "", 10, ' ', '~', PLANE_PANEL_LEFT+20, PLANE_PANEL_TOP+90, PLANE_PANEL_RIGHT-20, PLANE_PANEL_TOP+120, 1, FONT_MAIN, WHITE, BLACK, LIGHTCYAN, BLUE, WHITE, LIGHTGRAY, DARKGRAY, WHITE, true);

SelectedRecord currentRecord;

void PlanesManagerTitle(){
	PrintText(WIDTH/2, PLANES_TITLE_TOP, titlePlanesManagerPage.scontent[languageMode].content, WHITE, BLUE, ALIGN_CENTER_TOP, SIZE_FONT_TITLE, FONT_MAIN);
}

void DoNothing(){}

void PlanesManagerBackButtonAction(){
	InitDialogAndShow(charConfirm.scontent[languageMode].content, charSaveAllChange.scontent[languageMode].content, 400, 200, 950, 500, YESNO, WritePlanesToFile, DoNothing, 0);
	isBack=true;
}

void PlaneManagerInitDataTable(){
	for(int i=0; i<10; i++){
		if(pageTableControl.currentPage*10+i<planeAddArray.size){
			AddCellTableContent(planeList, i, 0, planeAddArray.list[pageTableControl.currentPage*10+i]->planeID);
			AddCellTableContent(planeList, i, 1, planeAddArray.list[pageTableControl.currentPage*10+i]->planeKind);
			AddCellTableContent(planeList, i, 2, planeAddArray.list[pageTableControl.currentPage*10+i]->chrSeat);
		}
		else{
			AddCellTableContent(planeList, i, 0, "");
			AddCellTableContent(planeList, i, 1, "");
			AddCellTableContent(planeList, i, 2, "");
		}
	}
}

void ClearAllPlaneTextBox(){
	TextBoxSetTitle(txtPlaneID, charID.scontent[languageMode].content);
	TextBoxSetTitle(txtPlaneType, charType.scontent[languageMode].content);
	TextBoxSetTitle(txtPlaneSeats, charSeats.scontent[languageMode].content);
	
	ClearTextBox(txtPlaneID);
	ClearTextBox(txtPlaneType);
	ClearTextBox(txtPlaneSeats);
}

void AddPlaneToTextBoxs(int index){
	SetContentTextBox(txtPlaneID, planeAddArray.list[pageTableControl.currentPage*10+index]->planeID);
	SetContentTextBox(txtPlaneType, planeAddArray.list[pageTableControl.currentPage*10+index]->planeKind);
	SetContentTextBox(txtPlaneSeats, planeAddArray.list[pageTableControl.currentPage*10+index]->chrSeat);
}

void SetPlaneTextBoxEditMode(){
	TextBoxSetEnable(txtPlaneID, false);
	TextBoxSetEnable(txtPlaneType, true);
	TextBoxSetEnable(txtPlaneSeats, false);
}

void SetPlaneTextBoxNormalMode(){
	TextBoxSetEnable(txtPlaneID, true);
	TextBoxSetEnable(txtPlaneType, true);
	TextBoxSetEnable(txtPlaneSeats, true);
}

void SetPlanesButtonsInEditMode(){
	ButtonSetEnable(btnNew,false);
	ButtonSetEnable(btnEdit,true);
	ButtonSetEnable(btnRemove,true);
	ButtonSetEnable(btnPlaneClear,true);
}

void SetPlanesButtonsInNormalMode(){
	ButtonSetEnable(btnNew,true);
	ButtonSetEnable(btnEdit,false);
	ButtonSetEnable(btnRemove,false);
	ButtonSetEnable(btnPlaneClear,false);
}

void PlanesManagerNewButtonAction(){
	if(
		!isTextBoxEmpty(txtPlaneID) &&
		!isTextBoxEmpty(txtPlaneSeats) &&
		!isTextBoxEmpty(txtPlaneType)
	){
		if(isNum(txtPlaneSeats.content)){
			int seats = ArrtoNum(txtPlaneSeats.content);
			if(seats>=20){
				Planes *tmp = FindPlaneByID(txtPlaneID.content);
				if(tmp==NULL){
					PlaneAdd(PlaneCreate(txtPlaneID.content, txtPlaneType.content, seats));
					UpdatePageTableStatus(planeAddArray.size);
					PlaneManagerInitDataTable();
					ClearAllPlaneTextBox();
					TableShow(planeList);
				}
				else{
//					PrintText(txtPlaneID.right-5, txtPlaneID.bottom-2, "Plane ID has used", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
					InitDialogAndShow(charError.scontent[languageMode].content, charIDUsed.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
					ReDrawPlaneManagerFirstStatusWithoutTextBox();
				}
			}
			else{
//				PrintText(txtPlaneSeats.right-5, txtPlaneSeats.bottom-2, "Seats's value has to be greater than or equals to 20", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
				InitDialogAndShow(charError.scontent[languageMode].content, charSeat20.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
				ReDrawPlaneManagerFirstStatusWithoutTextBox();
			}
		}
		else{
//			PrintText(txtPlaneSeats.right-5, txtPlaneSeats.bottom-2, "Seats's value has to be a number", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charSeatNumberic.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
			ReDrawPlaneManagerFirstStatusWithoutTextBox();
		}
	}
	else{
		if(isTextBoxEmpty(txtPlaneID)){
//			PrintText(txtPlaneID.right-5, txtPlaneID.bottom-2, "Enter all data to create new", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
			ReDrawPlaneManagerFirstStatusWithoutTextBox();
		}
		else if(isTextBoxEmpty(txtPlaneType)){
//			PrintText(txtPlaneType.right-5, txtPlaneType.bottom-2, "Enter all data to create new", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
			ReDrawPlaneManagerFirstStatusWithoutTextBox();
		}
		else if(isTextBoxEmpty(txtPlaneSeats)){
//			PrintText(txtPlaneSeats.right-5, txtPlaneSeats.bottom-2, "Enter all data to create new", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
			InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
			ReDrawPlaneManagerFirstStatusWithoutTextBox();
		}
	}
}

void PlanesManagerEditButtonAction(){
	if(!isTextBoxEmpty(txtPlaneType)){
		PlaneEditByIndex(pageTableControl.currentPage*10+currentRecord.currentRecord, txtPlaneType.content);
		UpdatePageTableStatus(planeAddArray.size);
		PlaneManagerInitDataTable();
		ClearAllPlaneTextBox();
		TableShow(planeList);
		SetPlaneTextBoxNormalMode();
		SetPlanesButtonsInNormalMode();
	}
	else{
//		PrintText(txtPlaneType.right-5, txtPlaneType.bottom-2, "Enter all data to update", LIGHTCYAN, RED, ALIGN_RIGHT_BOTTOM, 1, FONT_ERROR);
		InitDialogAndShow(charError.scontent[languageMode].content, charAllData.scontent[languageMode].content, 400, 200, 950, 500, YES, PlaneDoNothing, 0, 0);
		ReDrawPlaneManagerFirstStatusWithoutTextBox();
		SetPlanesButtonsInEditMode();
		SetPlaneTextBoxEditMode();
	}
}

void RemovePlane(){
	PlaneRemoveByIndex(pageTableControl.currentPage*10+currentRecord.currentRecord);
//	UpdatePageTableStatus(planeAddArray.size);
//	PlaneManagerInitDataTable();
//	ClearAllPlaneTextBox();
//	TableShow(planeList);
	SetPlaneTextBoxNormalMode();
	SetPlanesButtonsInNormalMode();
}

void NoRemovePlane(){
	SetPlaneTextBoxNormalMode();
	SetPlanesButtonsInNormalMode();
}

void PlanesManagerRemoveButtonAction(){
	
	if(isPlaneInAnyRelationship(txtPlaneID.content)){
		InitDialogAndShow(charError.scontent[languageMode].content, charCannotRemove.scontent[languageMode].content, 400, 200, 950, 500, YES, NoRemovePlane, 0, 0);
	}
	else{
		InitDialogAndShow(charConfirm.scontent[languageMode].content, charConfirmRemove.scontent[languageMode].content, 400, 200, 950, 500, YESNO, RemovePlane, NoRemovePlane, 0);
	}
	
	
	ReDrawPlaneManagerFirstStatus();
}

void PlanesManagerPrevButtonAction(){
	pageTableControl.currentPage--;
	UpdatePageTableStatus(planeAddArray.size);
	PlaneManagerInitDataTable();
	TableShow(planeList);
}

void PlanesManagerNextButtonAction(){
	pageTableControl.currentPage++;
	UpdatePageTableStatus(planeAddArray.size);
	PlaneManagerInitDataTable();
	TableShow(planeList);
}

void AllPlaneManagerButtonsShow(){
	ButtonShow(btnBack,false);
	ButtonShow(btnNew,false);
	ButtonShow(btnEdit,false);
	ButtonShow(btnRemove,false);
	ButtonShow(btnPlaneClear, false);
	ButtonShow(btnPrev, false);
	ButtonShow(btnNext, false);
}

void PlanesManagerClearButtonAction(){
	ClearAllPlaneTextBox();
	SetPlanesButtonsInNormalMode();
	SetPlaneTextBoxNormalMode();
}

void PlanesManagerPageButtons(){
	
	ButtonChangeName(btnBack, charBtnBack.scontent[languageMode].content);
	ButtonChangeName(btnNew, charBtnNew.scontent[languageMode].content);
	ButtonChangeName(btnEdit, charBtnSave.scontent[languageMode].content);
	ButtonChangeName(btnRemove, charBtnRemove.scontent[languageMode].content);
	
	ButtonChangePosition(btnNext, BUTTON_NEXT_LIST_PLANE_LEFT, BUTTON_NEXT_LIST_PLANE_TOP, BUTTON_NEXT_LIST_PLANE_RIGHT, BUTTON_NEXT_LIST_PLANE_BOTTOM);
	ButtonChangePosition(btnPrev, BUTTON_PREVIOUS_LIST_PLANE_LEFT, BUTTON_PREVIOUS_LIST_PLANE_TOP, BUTTON_PREVIOUS_LIST_PLANE_RIGHT, BUTTON_PREVIOUS_LIST_PLANE_BOTTOM);
	
	ButtonSetEnable(btnBack, true);
	ButtonSetEnable(btnNew, true);
	ButtonSetEnable(btnEdit, false);
	ButtonSetEnable(btnRemove, false);
	
	SetButtonListener(&btnBack, PlanesManagerBackButtonAction);
	SetButtonListener(&btnNew, PlanesManagerNewButtonAction);
	SetButtonListener(&btnEdit, PlanesManagerEditButtonAction);
	SetButtonListener(&btnRemove, PlanesManagerRemoveButtonAction);
	SetButtonListener(&btnPlaneClear, PlanesManagerClearButtonAction);
	SetButtonListener(&btnPrev, PlanesManagerPrevButtonAction);
	SetButtonListener(&btnNext, PlanesManagerNextButtonAction);
	
	AllPlaneManagerButtonsShow();
	
}

void ListenItemPlaneList(int index){
	if(planeAddArray.list[pageTableControl.currentPage*10+index]!=NULL){
		if(planeAddArray.list[pageTableControl.currentPage*10+index]->planeID)
	//	std::cout<<"Chon "<<index<<std::endl;
		currentRecord.currentRecord = index;
	//	currentRecord.currentSelectedRecord = getRecord(planeList, index);
		AddPlaneToTextBoxs(index);
		SetPlaneTextBoxEditMode();
		SetPlanesButtonsInEditMode();
	}
}

void PlaneManagerPageTablePlane(){

	planeList = TableCreate(TABLE_PLANE_LEFT, TABLE_PLANE_TOP, TABLE_PLANE_RIGHT, 3, TABLE_PLANE_SIZE, RECORD_PLANE_HEIGHT, LIGHTCYAN, LIGHTBLUE, LIGHTGRAY, WHITE, WHITE, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemPlaneList);
	
	AddMenuContent(planeList, 0, charID.scontent[languageMode].content);
	AddMenuContent(planeList, 1, charType.scontent[languageMode].content);
	AddMenuContent(planeList, 2, charSeats.scontent[languageMode].content);
	
	PlaneManagerInitDataTable();
	UpdatePageTableStatus(planeAddArray.size);
	TableShow(planeList);
}

void PlaneManagerPageTextBoxRange(){
	
//	TextBoxSetTitle(txtPlaneID, charID.scontent[languageMode].content);
//	TextBoxSetTitle(txtPlaneType, charType.scontent[languageMode].content);
//	TextBoxSetTitle(txtPlaneSeats, charSeats.scontent[languageMode].content);
	
	DrawRecStroke(PLANE_PANEL_LEFT, PLANE_PANEL_TOP, PLANE_PANEL_RIGHT, PLANE_PANEL_BOTTOM, SOLID_LINE, BLACK, 3);
	
	TextBoxSetEnable(txtPlaneID, true);
	TextBoxSetEnable(txtPlaneType, true);
	TextBoxSetEnable(txtPlaneSeats, true);
	
	SetTextBoxListener(&txtPlaneID);
	SetTextBoxListener(&txtPlaneType);
	SetTextBoxListener(&txtPlaneSeats);
	
	TextBoxDraw(txtPlaneID);
	TextBoxDraw(txtPlaneType);
	TextBoxDraw(txtPlaneSeats);
}

void ReDrawPlaneManagerFirstStatusWithoutTextBox(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
//	ClearAllPlaneTextBox();
	PlanesManagerTitle();//Print Title
	PlanesManagerPageButtons();//Set Mouse Listener And Show Buttons
	PlaneManagerPageTablePlane(); //Init Table, Set Mouse Listener And Show Table
	PlaneManagerPageTextBoxRange(); //SetMouse Listener And Show TextBoxs
}

void ReDrawPlaneManagerFirstStatus(){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	ClearAllPlaneTextBox();
	PlanesManagerTitle();//Print Title
	PlanesManagerPageButtons();//Set Mouse Listener And Show Buttons
	PlaneManagerPageTablePlane(); //Init Table, Set Mouse Listener And Show Table
	PlaneManagerPageTextBoxRange(); //SetMouse Listener And Show TextBoxs
}

void CorrectForm(){
	CorrectIDForm(txtPlaneID.content);
	CorrectNameForm(txtPlaneType.content);
	TextBoxDraw(txtPlaneID);
	TextBoxDraw(txtPlaneType);
}

void PlanesManagerPageShow(){
	isBack=false;
	ReadPlanesFromFile();
	//Test
//		PlaneAdd(PlaneCreate("AP1","Type1",80));
//		PlaneAdd(PlaneCreate("AP2","Type2",90));
//		PlaneAdd(PlaneCreate("SH3","Loai1",70));
//		PlaneAdd(PlaneCreate("SH4","Loai1",70));
//		PlaneAdd(PlaneCreate("SH5","Loai1",70));
//		PlaneAdd(PlaneCreate("SH6","Loai1",70));
//		PlaneAdd(PlaneCreate("SH7","Loai1",70));
//		PlaneAdd(PlaneCreate("SH8","Loai1",70));
//		PlaneAdd(PlaneCreate("SH9","Loai1",70));
//		PlaneAdd(PlaneCreate("SH10","Loai1",70));
//		PlaneAdd(PlaneCreate("SH11","Loai1",70));
//		PlaneAdd(PlaneCreate("SH12","Loai1",70));
//		PlaneAdd(PlaneCreate("SH13","Loai1",70));
	//Test
//	while(!isBack){
	SetDefaultColor();
	cleardevice();
	ClearAllcells();
	ClearAllPlaneTextBox();
	PlanesManagerTitle();//Print Title
	PlanesManagerPageButtons();//Set Mouse Listener And Show Buttons
	PlaneManagerPageTablePlane(); //Init Table, Set Mouse Listener And Show Table
	PlaneManagerPageTextBoxRange();//Set Mouse Listener And Show TextBoxs
	while(!isBack){
		MouseWaitingClick();
		CorrectForm();
	}
}
