#pragma once
#include "TextBox.h"
#include "MouseListener.h"
#include "input.h"

//	DrawRecFillLine(txt.left+100, txt.top, txt.right, txt.bottom, txt.bkColor, SOLID_FILL, txt.lineColor, SOLID_LINE, 1);
//	PrintText(txt.left+110, (txt.top+txt.bottom)/2, txt.content, txt.bkColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
//	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.content, txt.bkTitColor, txt.textTitColor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
//}
//
//void DrawTextBoxFocus(TextBox txt){
//	DrawRecFillLine(txt.left+100, txt.top, txt.right, txt.bottom, txt.bkColor, SOLID_FILL, txt.lineColor, SOLID_LINE, 3);
//	PrintText(txt.left+110, (txt.top+txt.bottom)/2, txt.content, txt.bkColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
//	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.content, txt.bkTitColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
//}

void DrawTextBoxDis(TextBox txt){
	DrawRecFillLine(txt.left+100, txt.top, txt.right, txt.bottom, txt.bkColorDis, SOLID_FILL, txt.lineColorDis, SOLID_LINE, 1);
	PrintText(txt.left+110, (txt.top+txt.bottom)/2 + 5, txt.content, txt.bkColorDis, txt.textcolorDis, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.title, txt.bkTitColor, txt.textcolorDis, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
}

void TextBoxDraw(TextBox txt){
	if(txt.enable){
		DrawTextBox(txt);
	}
	else{
		DrawTextBoxDis(txt);
	}
}

TextBox CreateATextBox(char *title, char *content, int maxLength, char start_char, char end_char, int left, int top, int right, int bottom, int sizeText, int fontText, int bkTitColor, int textTitColor, int bkColor, int textcolor, int lineColor, int bkColorDis, int textcolorDis, int lineColorDis, bool enable){
	TextBox tmp;
	
	tmp.title = title;
//	tmp.content = content;
	strcpy(tmp.content,content);
	tmp.max_length = maxLength;
	tmp.start_char = start_char;
	tmp.end_char =  end_char;
	tmp.left = left;
	tmp.right = right;
	tmp.top = top;
	tmp.bottom = bottom;
	tmp.sizeText = sizeText;
	tmp.fontText = fontText;
	tmp.bkTitColor = bkTitColor;
	tmp.textTitColor = textTitColor;
	tmp.bkColor = bkColor;
	tmp.textcolor = textcolor;
	tmp.lineColor = lineColor;
	tmp.bkColorDis = bkColorDis;
	tmp.textcolorDis = textcolorDis;
	tmp.lineColorDis = lineColorDis;
	tmp.enable = enable;
	
	return tmp;
}

void SetTextBoxListener(TextBox *txt){
	SetFunctionInRangeTextBox(txt, Input);
}

bool isTextBoxEmpty(TextBox txt){
	return ((strlen(txt.content)==0)?true:false);
}

void ClearTextBox(TextBox &txt){
	strcpy(txt.content, "");
	TextBoxDraw(txt);
}

void SetContentTextBox(TextBox &txt, char *s){
	strcpy(txt.content, s);
	TextBoxDraw(txt);
}

void TextBoxSetEnable(TextBox &txt, bool enable){
	txt.enable=enable;
	TextBoxDraw(txt);
}

void TextBoxSetTitle(TextBox &txt, char* title){
	txt.title=title;
}
