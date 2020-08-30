#pragma once
#include "MouseListener.h"

Button currentBtn;

void ButtonDraw(Button btn){
	if(btn.enable){
//		currentBtn = NULL;
		DrawRecFillLine(btn.left, btn.top, btn.right, btn.bottom, btn.bkColor, SOLID_FILL, btn.lineColor, SOLID_LINE, 1);
		PrintText((btn.left+btn.right)/2, (btn.top+btn.bottom)/2, btn.caption, btn.bkColor, btn.capColor, ALIGN_CENTER_CENTER, btn.sizeCap, btn.fontCap);
	}
}

void ButtonHoverDraw(Button btn){
	if(btn.enable){
		currentBtn = btn;
		DrawRecFillLine(btn.left, btn.top, btn.right, btn.bottom, btn.bkColorOp, SOLID_FILL, btn.lineColorOp, SOLID_LINE, 1);
		PrintText((btn.left+btn.right)/2, (btn.top+btn.bottom)/2, btn.caption, btn.bkColorOp, btn.capColorOp, ALIGN_CENTER_CENTER, btn.sizeCap, btn.fontCap);
	}
}

void ButtonDisDraw(Button btn){
	DrawRecFillLine(btn.left, btn.top, btn.right, btn.bottom, LIGHTGRAY, SOLID_FILL, LIGHTGRAY, SOLID_LINE, 1);
	PrintText((btn.left+btn.right)/2, (btn.top+btn.bottom)/2, btn.caption, LIGHTGRAY, DARKGRAY, ALIGN_CENTER_CENTER, btn.sizeCap, btn.fontCap);
}

void ButtonShow(Button btn, bool hover){
	if(btn.enable){
		if(hover){
			ButtonHoverDraw(btn);
		}
		else{
			ButtonDraw(btn);
		}
	}
	else{
		ButtonDisDraw(btn);
	}
}

Button CreateAButton(char *caption,int fontCap, int sizeCap, int capColor, int capColorOp, int left, int top, int right, int bottom, int bkColor, int bkColorOp, int lineColor, int lineColorOp, bool enable){
	Button tmp;
	tmp.caption = caption;
	tmp.fontCap = fontCap;
	tmp.sizeCap = sizeCap;
	tmp.capColor = capColor;
	tmp.capColorOp = capColorOp;
	tmp.left = left;
	tmp.top = top;
	tmp.right = right;
	tmp.bottom = bottom;
	tmp.bkColor = bkColor;
	tmp.bkColorOp = bkColorOp;
	tmp.lineColor = lineColor;
	tmp.lineColorOp = lineColorOp;
	tmp.enable = enable;
	return tmp;
}

void SetButtonListener(Button *btn, void funcClick()){
	SetFunctionInRangeButton(btn, funcClick, ButtonHoverDraw, ButtonDraw);
}

void ButtonEnableSwitch(Button &btn){
	btn.enable = !btn.enable;
	ButtonShow(btn, false);
}

void ButtonSetEnable(Button &btn, bool enable){
	btn.enable = enable;
	ButtonShow(btn, false);
}

void ButtonChangePosition(Button &btn, int left, int top, int right, int bottom){
	btn.left=left;
	btn.top=top;
	btn.right=right;
	btn.bottom=bottom;
}

void ButtonChangeColor(Button &btn, int capColor, int capColorOp, int bkColor, int bkColorOp, int lineColor, int lineColorOp){
	btn.capColor = capColor;
	btn.capColorOp = capColorOp;
	btn.bkColor = bkColor;
	btn.bkColorOp = bkColorOp;
	btn.lineColor = lineColor;
	btn.lineColorOp = lineColorOp;
}

void ButtonChangeName(Button &btn, char *name){
	btn.caption = name;
}
