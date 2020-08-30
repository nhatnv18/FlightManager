#pragma once
#include "TextBox.h"
#include "main_define.h"

int MAX_INPUT_LENGTH;

//bool isTrueContinue(int left, int top, int right, int bottom){
//	int mouse_x;
//	int mouse_y;
//	if(ismouseclick(WM_LBUTTONDOWN)){
//		getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
//		if(mouse_x>=left && mouse_x<=right && mouse_y>=top && mouse_y<=bottom){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	return true;
//}

void DrawTextBox(TextBox txt){
	DrawRecFillLine(txt.left+100, txt.top, txt.right, txt.bottom, txt.bkColor, SOLID_FILL, txt.lineColor, SOLID_LINE, 3);
	PrintText(txt.left+110, (txt.top+txt.bottom)/2  + 5, txt.content, txt.bkColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.title, txt.bkTitColor, txt.textTitColor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
}

void DrawTextBoxFocus(TextBox txt){
	DrawRecFillLine(txt.left+100, txt.top, txt.right, txt.bottom, txt.bkColor, SOLID_FILL, txt.textcolor, SOLID_LINE, 3);
	PrintText(txt.left+110, (txt.top+txt.bottom)/2  + 5, txt.content, txt.bkColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.title, txt.bkTitColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
}

void DrawTextBoxOutFocus(TextBox txt){
	DrawRecStroke(txt.left+100, txt.top, txt.right, txt.bottom, SOLID_LINE, txt.lineColor, 3);
	PrintText(txt.left+110, (txt.top+txt.bottom)/2  + 5, txt.content, txt.bkColor, txt.textcolor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
	PrintText(txt.left, (txt.top+txt.bottom)/2, txt.title, txt.bkTitColor, txt.textTitColor, ALIGN_LEFT_CENTER, txt.sizeText, txt.fontText);
}

void Input(char *str, char *oldStr, int x, int y, char start_char, char end_char, int maxLength, int left, int top, int right, int bottom, TextBox *txt){
	
	DrawTextBoxFocus(*txt);
	
	MAX_INPUT_LENGTH=maxLength;
	
	char tmpStr[MAX_INPUT_LENGTH+2]="";
	strcpy(tmpStr,oldStr);
	
	int pos=strlen(tmpStr);
	
	bool inpFlag = true;
	
	while(inpFlag){
		
		if(inpFlag==false){
			break;
		}
		
		while(!kbhit()){
			int mouse_x, mouse_y;
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
				if(!(mouse_x>=left && mouse_x<=right && mouse_y>=top && mouse_y<=bottom)){
					tmpStr[pos]=0;
					inpFlag=false;
					break;
				}
			}
			delay(0.0001);
		}
		
		if(inpFlag==false){
			break;
		}
		
		char c = getch();
		
		switch((int)c){
			case 8:
				if(pos>0){
					tmpStr[--pos]=0;
				}
				break;
			case 13:
				tmpStr[pos]=0;
				inpFlag=false;
				break;
//			case 27:
//				tmpStr[0]=0;
//				inpFlag=true;
//				break;
			default:
				if (pos < MAX_INPUT_LENGTH-1 && c >= start_char && c <= end_char)
		        {
		            tmpStr[pos] = c;
		            pos++;
		            tmpStr[pos] = 0;
		        }
		        
		}
		if(pos<MAX_INPUT_LENGTH){
//			strcat(tmpStr,(char*)" ");
	//		std::cout<<tmpStr<<std::endl;
			char tmpShow[MAX_INPUT_LENGTH+7];
			strcpy(tmpShow, tmpStr);
			strcat(tmpShow,(char*)"      ");
	//		outtextxy(x,y,tmpShow);
	//		std::cout<<tmpShow<<std::endl;
			PrintText(x,y+5,tmpShow, txt->bkColor, txt->textcolor, ALIGN_LEFT_CENTER, txt->sizeText, txt->fontText);
		}
		
		delay(0.0001);
	}
	if(strlen(tmpStr)!=0){
//		str = tmpStr;
		strcpy(str,tmpStr);
	}
	else{
//		str = "";
		strcpy(str,"");
	}
	
//	txt->content = str;
//	std::cout<<"aaa"<<txt->content<<"aaa"<<std::endl;
	DrawTextBoxOutFocus(*txt);
}
