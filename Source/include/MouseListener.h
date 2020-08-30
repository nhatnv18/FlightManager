#pragma once
#include "main_define.h"
#include "ButtonStruct.h"
#include "TableStruct.h"
#include "TextBox.h"
#include "input.h"

enum TypeHover{
	NONE,
	BUTTON,
	RECORD,
	TEXTBOX
};

struct Cell{
	TypeHover typeHvr;
	void (*funcClick)();
	void (*funcRcClick)(int);
	void (*funcTxtClick)(char *str, char *oldStr, int x, int y, char start_char, char end_char, int maxLength, int left, int top, int right, int bottom, TextBox *txt);
	void (*funcHover)(Button);
	void (*funcNoHover)(Button);
	void (*funcRcHover)(Record);
	void (*funcRcNoHover)(Record);
	Button *btn;
	Record *rcd;
	TextBox *txt;
};

Cell cell[HEIGHT+1][WIDTH+1];

void ClearAllcells(){
	for(int i=0; i<=HEIGHT; i++){
		for(int j=0; j<=WIDTH; j++){
			cell[i][j].typeHvr = NONE;
			cell[i][j].funcClick = 0;
			cell[i][j].funcRcClick = 0;
			cell[i][j].funcTxtClick = 0;
			cell[i][j].funcHover = 0;
			cell[i][j].funcNoHover = 0;
			cell[i][j].funcRcHover = 0;
			cell[i][j].funcRcNoHover = 0;
			cell[i][j].btn = 0;
			cell[i][j].rcd = 0;
		}
	}
}

void SetFunctionInRangeButton(Button* btn, void funcClick() , void funcHover(Button), void funcNoHover(Button)){
	for(int i=btn->top; i<=btn->bottom; i++){
		for(int j=btn->left; j<=btn->right; j++){
			cell[i][j].typeHvr = BUTTON;
			cell[i][j].funcClick = funcClick;
			cell[i][j].funcHover = funcHover;
			cell[i][j].funcNoHover = funcNoHover;
			cell[i][j].btn = btn;
		}
	}
}

void SetFunctionInRangeTextBox(TextBox* txt, void (*funcTxtClick)(char *str, char *oldStr, int x, int y, char start_char, char end_char, int maxLength, int left, int top, int right, int bottom, TextBox *txt)){
	for(int i=txt->top; i<=txt->bottom; i++){
		for(int j=txt->left+100; j<=txt->right; j++){
			cell[i][j].typeHvr = TEXTBOX;
			cell[i][j].funcTxtClick = funcTxtClick;
			cell[i][j].txt = txt;
		}
	}
}

void SetFunctionInRangeRecord(Record* rcd, void funcClick(int) , void funcRcHover(Record), void funcRcNoHover(Record)){
	for(int i=rcd->top; i<rcd->bottom; i++){
		for(int j=rcd->left; j<=rcd->right; j++){
			cell[i][j].typeHvr = RECORD;
			cell[i][j].funcRcClick = funcClick;
			cell[i][j].funcRcHover = funcRcHover;
			cell[i][j].funcRcNoHover = funcRcNoHover;
			cell[i][j].rcd = rcd;
		}
	}
}

//void SetClickInRangeRecord(Record* rcd, void funcClick()){
//	for(int i=rcd->top; i<rcd->bottom; i++){
//		for(int j=rcd->left; j<=rcd->right; j++){
//			cell[i][j].funcClick = funcClick;
//		}
//	}
//}

void MouseWaitingClick(){
//	while(true){
//		std::cout<<"Start"<<std::endl;
		int mouse_x=-1, mouse_y=-1;
		int mouse_prex=-1, mouse_prey=-1;
		TypeHover preType=NONE;
		Record *preRcd=0;
		Button *preBtn=0;
		bool loopHover=true;
		bool loopClick=true;
		
		while(loopHover){
			if(ismouseclick(WM_MOUSEMOVE)){
				getmouseclick(WM_MOUSEMOVE, mouse_x, mouse_y);
				
				if(cell[mouse_y][mouse_x].typeHvr==BUTTON){
					
					if(preBtn!=cell[mouse_y][mouse_x].btn && preBtn!=0){
						cell[mouse_prey][mouse_prex].funcNoHover(*preBtn);
						preBtn=0;
						preType=NONE;
						mouse_prex = -1;
						mouse_prey = -1;
					}
//					if(cell[mouse_y][mouse_x].funcHover>0){
					if(preBtn!=cell[mouse_y][mouse_x].btn){
						
						cell[mouse_y][mouse_x].funcHover(*cell[mouse_y][mouse_x].btn);
						mouse_prex = mouse_x;
						mouse_prey = mouse_y;
						preType = BUTTON;
						preBtn = cell[mouse_y][mouse_x].btn;
					}
//					else{
//						if(mouse_prex>=0 && mouse_prey>=0){
//							cell[mouse_prey][mouse_prex].funcNoHover(*cell[mouse_prey][mouse_prex].btn);
//							mouse_prex = -1;
//							mouse_prey = -1;
//						}
//					}
				}
				else if(cell[mouse_y][mouse_x].typeHvr==RECORD){
					if(preRcd!=cell[mouse_y][mouse_x].rcd && preRcd!=0){
						cell[mouse_prey][mouse_prex].funcRcNoHover(*preRcd);
						preRcd=0;
						preType=NONE;
						mouse_prex = -1;
						mouse_prey = -1;
					}
//					if(cell[mouse_y][mouse_x].funcRcHover>0){
					if(preRcd!=cell[mouse_y][mouse_x].rcd){
						cell[mouse_y][mouse_x].funcRcHover(*cell[mouse_y][mouse_x].rcd);
						mouse_prex = mouse_x;
						mouse_prey = mouse_y;
						preType = RECORD;
						preRcd = cell[mouse_y][mouse_x].rcd;
					}
//					else{
//						if(mouse_prex>=0 && mouse_prey>=0){
//							cell[mouse_prey][mouse_prex].funcRcNoHover(*cell[mouse_prey][mouse_prex].rcd);
//							mouse_prex = -1;
//							mouse_prey = -1;
//						}
//					}
				}
				else if(cell[mouse_y][mouse_x].typeHvr==NONE){
					if(preType==BUTTON){
						cell[mouse_prey][mouse_prex].funcNoHover(*cell[mouse_prey][mouse_prex].btn);
					}
					else if(preType==RECORD){
						cell[mouse_prey][mouse_prex].funcRcNoHover(*cell[mouse_prey][mouse_prex].rcd);
					}
					preType=NONE;
					preRcd=0;
					preBtn=0;
					mouse_prex = -1;
					mouse_prey = -1;
				}
				
			}
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
				if(cell[mouse_y][mouse_x].typeHvr!=NONE){
					break;
				}
			}
			delay(0.0001);
		}
		while(loopClick){
			if(/*ismouseclick(WM_LBUTTONDOWN)*/true){
//				getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
//				if(cell[mouse_y][mouse_x].funcClick>0 || cell[mouse_y][mouse_x].funcRcClick>0){
					if(cell[mouse_y][mouse_x].typeHvr==BUTTON && cell[mouse_y][mouse_x].btn->enable==true){
						if(preType==BUTTON && preBtn!=cell[mouse_y][mouse_x].btn){
							cell[mouse_prey][mouse_prex].funcNoHover(*cell[mouse_prey][mouse_prex].btn);
						}
						cell[mouse_y][mouse_x].funcClick();
						break;
					}
					else if(cell[mouse_y][mouse_x].typeHvr==RECORD){
						if(preType==RECORD && preRcd!=cell[mouse_y][mouse_x].rcd){
							cell[mouse_prey][mouse_prex].funcRcNoHover(*cell[mouse_prey][mouse_prex].rcd);
						}
						cell[mouse_y][mouse_x].funcRcClick(cell[mouse_y][mouse_x].rcd->index);
						break;
					}
					else if(cell[mouse_y][mouse_x].typeHvr==TEXTBOX){
//						if(preType==TEXTBOX && preRcd!=cell[mouse_y][mouse_x].rcd){
//							cell[mouse_prey][mouse_prex].funcRcNoHover(*cell[mouse_prey][mouse_prex].rcd);
//						}
						if(cell[mouse_y][mouse_x].txt->enable==true){
//							char tmpContent[50];
//							strcpy(tmpContent, cell[mouse_y][mouse_x].txt->content);
							cell[mouse_y][mouse_x].funcTxtClick(
//								tmpContent,
								cell[mouse_y][mouse_x].txt->content,
								cell[mouse_y][mouse_x].txt->content,
								cell[mouse_y][mouse_x].txt->left+110,
								(cell[mouse_y][mouse_x].txt->top+cell[mouse_y][mouse_x].txt->bottom)/2,
								cell[mouse_y][mouse_x].txt->start_char,
								cell[mouse_y][mouse_x].txt->end_char,
								cell[mouse_y][mouse_x].txt->max_length,
								cell[mouse_y][mouse_x].txt->left+100,
								cell[mouse_y][mouse_x].txt->top,
								cell[mouse_y][mouse_x].txt->right,
								cell[mouse_y][mouse_x].txt->bottom,
								cell[mouse_y][mouse_x].txt
							);
//							cell[mouse_y][mouse_x].txt->content = tmpContent;
							break;
						}
					}
//					break;
//				}
			}
			delay(0.0001);
		}
		delay(0.0001);
//	}
}
