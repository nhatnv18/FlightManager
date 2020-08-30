#pragma once
#include "ButtonControl.h"
#include "StringDefine.h"

#define BUTTON_DIALOG_WDITH 130
#define BUTTON_DIALOG_HEIGHT 50

enum typeDialog{
	YES,
	YESNO,
	YESNOCANCEL
};

struct Dialog{
	char *title;
	char *content;
	int left, top, right, bottom;
	Button btnYes;
	Button btnNo;
	Button btnCancel;
	typeDialog type;
};

Dialog InitDialogYes(char *title, char *content, int left, int top, int right, int bottom, typeDialog type, void funcClickYes()){
	ClearAllcells();
	Dialog yesDialog;
	yesDialog.title = title;
	yesDialog.content = content;
	yesDialog.left = left;
	yesDialog.top = top;
	yesDialog.right = right;
	yesDialog.bottom = bottom;
	yesDialog.type = type;
	int leftbtnYes = (left+right)/2-BUTTON_DIALOG_WDITH/2;
	int rightbtnYes = (left+right)/2+BUTTON_DIALOG_WDITH/2;
	int bottombtnYes = bottom-30;
	int topbtnYes = bottombtnYes-BUTTON_DIALOG_HEIGHT;
	yesDialog.btnYes = CreateAButton(charDialogYes.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnYes, topbtnYes, rightbtnYes, bottombtnYes, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesDialog.btnYes,funcClickYes);
	
	return yesDialog;
}

Dialog InitDialogYesNo(char *title, char *content, int left, int top, int right, int bottom, typeDialog type, void funcClickYes(), void funcClickNo()){
	ClearAllcells();
	Dialog yesNoDialog;
	yesNoDialog.title = title;
	yesNoDialog.content = content;
	yesNoDialog.left = left;
	yesNoDialog.top = top;
	yesNoDialog.right = right;
	yesNoDialog.bottom = bottom;
	yesNoDialog.type = type;
	
	int leftbtnYes = left+30;
	int rightbtnYes = leftbtnYes+BUTTON_DIALOG_WDITH;
	int bottombtnYes = bottom-30;
	int topbtnYes = bottombtnYes-BUTTON_DIALOG_HEIGHT;
	
	int rightbtnNo = right-30;
	int leftbtnNo = rightbtnNo-BUTTON_DIALOG_WDITH;
	int bottombtnNo = bottom-30;
	int topbtnNo = bottombtnNo-BUTTON_DIALOG_HEIGHT;
	
	yesNoDialog.btnYes = CreateAButton(charDialogYes.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnYes, topbtnYes, rightbtnYes, bottombtnYes, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesNoDialog.btnYes,funcClickYes);
	
	yesNoDialog.btnNo = CreateAButton(charDialogNo.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnNo, topbtnNo, rightbtnNo, bottombtnNo, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesNoDialog.btnNo,funcClickNo);
	
	return yesNoDialog;
}

Dialog InitDialogYesNoCancel(char *title, char *content, int left, int top, int right, int bottom, typeDialog type, void funcClickYes(), void funcClickNo(), void funcClickCancel()){
	ClearAllcells();
	Dialog yesNoDialog;
	yesNoDialog.title = title;
	yesNoDialog.content = content;
	yesNoDialog.left = left;
	yesNoDialog.top = top;
	yesNoDialog.right = right;
	yesNoDialog.bottom = bottom;
	yesNoDialog.type = type;
	
	int leftbtnYes = left+30;
	int rightbtnYes = leftbtnYes+BUTTON_DIALOG_WDITH;
	int bottombtnYes = bottom-30;
	int topbtnYes = bottombtnYes-BUTTON_DIALOG_HEIGHT;
	
	int rightbtnNo = right-30;
	int leftbtnNo = rightbtnNo-BUTTON_DIALOG_WDITH;
	int bottombtnNo = bottom-30;
	int topbtnNo = bottombtnNo-BUTTON_DIALOG_HEIGHT;
	
	int leftbtnCancel = (left+right)/2-BUTTON_DIALOG_WDITH/2;
	int rightbtnCancel = (left+right)/2+BUTTON_DIALOG_WDITH/2;
	int bottombtnCancel = bottom-30;
	int topbtnCancel = bottombtnCancel-BUTTON_DIALOG_HEIGHT;
	
	yesNoDialog.btnYes = CreateAButton(charDialogYes.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnYes, topbtnYes, rightbtnYes, bottombtnYes, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesNoDialog.btnYes,funcClickYes);
	
	yesNoDialog.btnNo = CreateAButton(charDialogNo.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnNo, topbtnNo, rightbtnNo, bottombtnNo, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesNoDialog.btnNo,funcClickNo);
	
	yesNoDialog.btnCancel = CreateAButton(charDialogCancel.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, leftbtnCancel, topbtnCancel, rightbtnCancel, bottombtnCancel, BLUE, YELLOW, BLUE, YELLOW, true);
	SetButtonListener(&yesNoDialog.btnCancel,funcClickCancel);
	
	return yesNoDialog;
}

void DialogShow(Dialog dialog){
//	DrawRecFill(0, 0, WIDTH, HEIGHT, CLOSE_DOT_FILL, BLACK);
	DrawRecFill(dialog.left+20, dialog.top+20, dialog.right+20, dialog.bottom+20, SOLID_FILL, BLACK);
	DrawRecFill(dialog.left, dialog.top, dialog.right, dialog.bottom, SOLID_FILL, LIGHTGRAY);
	DrawRecStroke(dialog.left+20, dialog.top+20, dialog.right-20, dialog.bottom-20, SOLID_LINE, BLUE, 3);
	PrintText((dialog.left+dialog.right)/2, dialog.top+10, dialog.title, LIGHTGRAY, BLUE, ALIGN_CENTER_TOP, 1, FONT_MAIN);
	PrintText((dialog.left+dialog.right)/2, dialog.top+100, dialog.content, LIGHTGRAY, BLUE, ALIGN_CENTER_TOP, 1, FONT_MAIN);
	ButtonShow(dialog.btnYes, false);
	if(dialog.type==YESNO){
		ButtonShow(dialog.btnNo, false);
	}
	else if(dialog.type==YESNOCANCEL){
		ButtonShow(dialog.btnCancel, false);
	}
}

void InitDialogAndShow(char *title, char *content, int left, int top, int right, int bottom, typeDialog type, void funcClickYes(), void funcClickNo(), void funcClickCancel()){
	Dialog dialog;
	if(type == YES){
		dialog = InitDialogYes(title, content, left, top, right, bottom, type, funcClickYes);
	}
	else if(type == YESNO){
		dialog = InitDialogYesNo(title, content, left, top, right, bottom, type, funcClickYes, funcClickNo);
	}
	else if(type == YESNOCANCEL){
		dialog = InitDialogYesNoCancel(title, content, left, top, right, bottom, type, funcClickYes, funcClickNo, funcClickCancel);
	}
	
	DialogShow(dialog);
	
	MouseWaitingClick();
}
