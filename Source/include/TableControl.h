#pragma once
#include "main_define.h"
#include "MouseListener.h"
#include "ButtonControl.h"
#include "ArrChar_Num.h"

#define BUTTON_NEXT_LIST_PLANE_LEFT 1250
#define BUTTON_NEXT_LIST_PLANE_RIGHT 1280
#define BUTTON_NEXT_LIST_PLANE_TOP 530
#define BUTTON_NEXT_LIST_PLANE_BOTTOM 560

#define BUTTON_PREVIOUS_LIST_PLANE_LEFT 990
#define BUTTON_PREVIOUS_LIST_PLANE_RIGHT 1020
#define BUTTON_PREVIOUS_LIST_PLANE_TOP 530
#define BUTTON_PREVIOUS_LIST_PLANE_BOTTOM 560

Button btnPrev = CreateAButton("<", FONT_MAIN, 1, WHITE, BLUE, BUTTON_PREVIOUS_LIST_PLANE_LEFT, BUTTON_PREVIOUS_LIST_PLANE_TOP, BUTTON_PREVIOUS_LIST_PLANE_RIGHT, BUTTON_PREVIOUS_LIST_PLANE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);
Button btnNext = CreateAButton(">", FONT_MAIN, 1, WHITE, BLUE, BUTTON_NEXT_LIST_PLANE_LEFT, BUTTON_NEXT_LIST_PLANE_TOP, BUTTON_NEXT_LIST_PLANE_RIGHT, BUTTON_NEXT_LIST_PLANE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, false);

struct SelectedRecord{
	int currentRecord=-1;
//	Record *currentSelectedRecord = NULL;
};

struct PageTableManager{
	int currentPage = 0;
	int maxPage = 0;
	int last = 0;
} pageTableControl;

void PageTableInfoShow(int size){
	char pageInfo[50]="";
	if(size>0){
		if(pageTableControl.currentPage<pageTableControl.maxPage-1){
			char fPage[50]="", lPage[50]="", sizePage[50]="";
			NumToCharArr(fPage,(pageTableControl.currentPage)*10 +1);
			NumToCharArr(lPage,(pageTableControl.currentPage)*10 +10);
			NumToCharArr(sizePage,size);
			strcat(pageInfo,fPage);
			strcat(pageInfo,"-");
			strcat(pageInfo,lPage);
			strcat(pageInfo,"/");
			strcat(pageInfo,sizePage);
		}
		else{
			char fPage[50]="", lPage[50]="", sizePage[50]="";
			NumToCharArr(fPage,(pageTableControl.currentPage)*10 +1);
			NumToCharArr(lPage,(pageTableControl.currentPage)*10 +((pageTableControl.last==0)?10:pageTableControl.last));
			NumToCharArr(sizePage,size);
//			std::cout<<"fp: "<<fPage<<std::endl;
//			std::cout<<"lp: "<<lPage<<std::endl;
//			std::cout<<"size: "<<sizePage<<std::endl;
			strcat(pageInfo,fPage);
			strcat(pageInfo,"-");
			strcat(pageInfo,lPage);
			strcat(pageInfo,"/");
			strcat(pageInfo,sizePage);
		}
	}
	else{
		char fPage[50]="", lPage[50]="", sizePage[50]="";
		NumToCharArr(fPage,0);
		NumToCharArr(lPage,0);
		NumToCharArr(sizePage,0);
		strcat(pageInfo,fPage);
		strcat(pageInfo,"-");
		strcat(pageInfo,lPage);
		strcat(pageInfo,"/");
		strcat(pageInfo,sizePage);
	}
	
	PrintText((btnNext.right+btnPrev.left)/2, btnPrev.bottom, "                           ", WHITE, BLACK, ALIGN_CENTER_BOTTOM, 1,FONT_MAIN);
	PrintText((btnNext.right+btnPrev.left)/2, btnPrev.bottom, pageInfo, WHITE, BLACK, ALIGN_CENTER_BOTTOM, 1,FONT_MAIN);
}

void UpdatePageTableStatus(int size){
	pageTableControl.maxPage = size/10;
	int last = size%10;
	pageTableControl.last = last;
//	std::cout<<"Current: "<<pageTableControl.currentPage<<std::endl;
//	std::cout<<"Max Page: "<<pageTableControl.maxPage<<std::endl;
//	std::cout<<"Size: "<<size<<std::endl;
//	std::cout<<"Last: "<<last<<std::endl;
	if(last>0){
		pageTableControl.maxPage++;
	}
	if(pageTableControl.currentPage<pageTableControl.maxPage){
		ButtonSetEnable(btnNext, true);
	}
	if(pageTableControl.currentPage>0){
		ButtonSetEnable(btnPrev, true);
	}
	if(pageTableControl.currentPage==0){
		ButtonSetEnable(btnPrev, false);
	}
	if(pageTableControl.currentPage==pageTableControl.maxPage-1){
		ButtonSetEnable(btnNext, false);
	}
	PageTableInfoShow(size);
}

void DrawCellTable(CellTable currCell){
	DrawRecFillLine(currCell.left, currCell.top, currCell.right, currCell.bottom, currCell.bkRecordColor, SOLID_FILL, currCell.lineColor, SOLID_LINE, 1);
	PrintText(currCell.left+20, (currCell.top+currCell.bottom)/2, currCell.content, currCell.bkRecordColor, currCell.textColor, ALIGN_LEFT_CENTER, currCell.sizeText, currCell.fontText);
}

void DrawHoverCellTable(CellTable currCell){
	DrawRecFillLine(currCell.left, currCell.top, currCell.right, currCell.bottom, currCell.bkHighlightColor, SOLID_FILL, currCell.lineHighlightColor, SOLID_LINE, 1);
	PrintText(currCell.left+20, (currCell.top+currCell.bottom)/2, currCell.content, currCell.bkHighlightColor, currCell.textColor, ALIGN_LEFT_CENTER, currCell.sizeText, currCell.fontText);
}

void RecordHoverAction(Record r){
	for(int i=0; i<r.coloums; i++){
		DrawHoverCellTable(r.cellList[i]);
	}
}

void RecordNoHoverAction(Record r){
	for(int i=0; i<r.coloums; i++){
		DrawCellTable(r.cellList[i]);
	}
}

CellTable CellCreate(int font, int textSize, int bkColor, int textColor, int lineColor, int lineHightLight, int bkHightlightColor, int left, int top, int right, int bottom){
	CellTable tmp;
	tmp.fontText = font;
	tmp.sizeText = textSize;
	tmp.bkRecordColor = bkColor;
	tmp.textColor = textColor;
	tmp.lineColor = lineColor;
	tmp.lineHighlightColor = lineHightLight;
	tmp.bkHighlightColor = bkHightlightColor;
	tmp.left = left;
	tmp.top = top;
	tmp.right = right;
	tmp.bottom = bottom;
	
	return tmp;
}

Record RecordCreate(int index, int cols, int left, int top, int right, int bottom, int bkColor, int textColor, int lineColor, int lineHightlightColor, int bkHightlightColor, int font, int sizeText, bool readOnly){
	Record tmp;
	tmp.index = index;
	tmp.coloums =cols;
	tmp.left = left;
	tmp.right = right;
	tmp.top = top;
	tmp.bottom = bottom;
	tmp.readOnly = readOnly;
	
	tmp.cellList = new CellTable[cols];
	int widthCell = (left+right)/cols;
	int leftPos=left;
	for(int i=0; i<cols; i++){
		tmp.cellList[i] = CellCreate(font, sizeText, bkColor, textColor, lineColor, lineHightlightColor, bkHightlightColor, leftPos, top, ((leftPos+widthCell<=right)?leftPos+widthCell:right), bottom);
		leftPos = leftPos+widthCell;
	}
	
	return tmp;
}


void TableShow(Table table){
	for(int i=0; i<=table.sizeRows; i++){
		for(int j=0; j<table.sizeCols; j++){
			CellTable currCell = table.recordList[i].cellList[j];
			DrawCellTable(currCell);
		}
	}
}

void ClearPageInfo(){
	pageTableControl.currentPage=0;
	pageTableControl.last=0;
	pageTableControl.maxPage;
}

Table TableCreate(int left, int top, int right, int cols, int rows, int heightRows, int bkColor1, int bkColor2, int bkTitColor, int lineColor, int lineTitColor, int lineHightlightColor, int bkHightlightColor, int textColor, int textTitColor, int font, int sizeText, void funcRcClick(int)){
	Table tmp;
	tmp.left = left;
	tmp.top = top;
	tmp.right = right;
	tmp.sizeCols = cols;
	tmp.sizeRows = rows;
	tmp.height = heightRows;
	
	tmp.recordList = new Record[rows+1];
	tmp.recordList[0] = RecordCreate(-1,cols, left, top, right, top+heightRows, bkTitColor, textTitColor, lineTitColor, lineTitColor, bkTitColor, font, sizeText, true);
	int topPos = top+heightRows;
	for(int i=0; i<tmp.sizeRows; i++){
		tmp.recordList[i+1] = RecordCreate(i,cols, left, topPos, right, topPos+heightRows, ((i%2==0)?bkColor1:bkColor2), textColor, lineColor, lineHightlightColor, bkHightlightColor, font, sizeText, false);
		SetFunctionInRangeRecord(&tmp.recordList[i+1], funcRcClick, RecordHoverAction, RecordNoHoverAction);
		topPos += heightRows;
	}
	
	ClearPageInfo();
	return tmp;
}

void AddMenuContent(Table &tb, int pos, char *text){
	if(pos<tb.sizeCols){
		tb.recordList[0].cellList[pos].content = text;
	}
}

char *getValue(Table tb, int rcdPos, int cellPos){
	if(rcdPos<tb.sizeRows){
		if(cellPos<tb.sizeCols){
			return tb.recordList[rcdPos+1].cellList[cellPos].content;
		}
	}
	return 0;
}

Record *getRecord(Table tb, int rcdPos){
	return &tb.recordList[rcdPos+1];
}

void AddCellTableContent(Table &tb, int recordPos, int coloumPos, char *text){
	if(recordPos<tb.sizeRows){
		if(coloumPos<tb.sizeCols){
			tb.recordList[recordPos+1].cellList[coloumPos].content = text;
		}
	}
}
