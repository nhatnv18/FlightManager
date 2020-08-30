#pragma once

#define WIDTH 1350
#define HEIGHT 700

#define FONT_MAIN 9
#define FONT_ERROR 0

#define SIZE_FONT_TITLE 5

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define DEFAULT_DARK_COLOR 1
#define DEFAULT_LIGHT_COLOR 15
#define DEFAULT_OPP_DARK_COLOR 14
#define DEFAULT_OPP_LIGHT_COLOR 0
#define DEFAULT_DISABLE_DARK_COLOR 8
#define DEFAULT_DISABLE_LIGHT_COLOR 7
#define DEFAULT_TEXTBOX_BACKGROUND_LIGHT_COLOR 11
#define DEFAULT_TEXTBOX_BACKGROUND_DARK_COLOR 9

enum AlignmentText{
	ALIGN_LEFT_TOP,
	ALIGN_LEFT_CENTER,
	ALIGN_LEFT_BOTTOM,
	ALIGN_CENTER_TOP,
	ALIGN_CENTER_CENTER,
	ALIGN_CENTER_BOTTOM,
	ALIGN_RIGHT_TOP,
	ALIGN_RIGHT_CENTER,
	ALIGN_RIGHT_BOTTOM
};

void SetColorSet(int bk, int c){
	setbkcolor(bk);
	setcolor(c);
}

void SetTextStyle(int font, int size){
	settextstyle(font, 0, size);
}

void SetLineStyle(int style, int thick){
	setlinestyle(style,1,thick);
}

void SetTextJustify(AlignmentText align){
	switch(align){
		case ALIGN_LEFT_TOP:
			settextjustify(0,2);
			break;
		case ALIGN_LEFT_CENTER:
			settextjustify(0,1);
			break;
		case ALIGN_LEFT_BOTTOM:
			settextjustify(0,0);
			break;
		case ALIGN_CENTER_TOP:
			settextjustify(1,2);
			break;
		case ALIGN_CENTER_CENTER:
			settextjustify(1,1);
			break;
		case ALIGN_CENTER_BOTTOM:
			settextjustify(1,0);
			break;
		case ALIGN_RIGHT_TOP:
			settextjustify(2,2);
			break;
		case ALIGN_RIGHT_CENTER:
			settextjustify(2,1);
			break;
		case ALIGN_RIGHT_BOTTOM:
			settextjustify(2,0);
			break;
	}
}

void SetDefaultColor(){
	SetColorSet(DEFAULT_LIGHT_COLOR, DEFAULT_DARK_COLOR);
}

void DrawLine(int x1, int y1, int x2, int y2, int lineStyle, int color, int thickLine){
	setcolor(color);
	SetLineStyle(lineStyle, thickLine);
	line(x1, y1, x2, y2);
}

void DrawRecStroke(int left, int top, int right, int bottom, int lineStyle, int color, int thickLine){
	setcolor(color);
	SetLineStyle(lineStyle, thickLine);
	rectangle(left, top, right, bottom);
}

void DrawRecFill(int left, int top, int right, int bottom, int fillStyle, int color){
	setfillstyle(fillStyle,color);
	bar(left, top, right, bottom);
}

void DrawRecFillLine(int left, int top, int right, int bottom, int bkColor, int fillStyle, int lineColor, int lineStyle, int thickLine){
	DrawRecFill(left, top, right, bottom, fillStyle, bkColor);
	DrawRecStroke(left, top, right, bottom, lineStyle, lineColor, thickLine);
}

void PrintText(int x, int y, char* text, int fillColor, int textColor, AlignmentText align, int size, int font){
	SetColorSet(fillColor, textColor);
	SetTextStyle(font, size);
	SetTextJustify(align);
	outtextxy(x,y,text);
}

void DrawEllipse(int x, int y, int rx, int ry, int lineColor, int thick){
	setcolor(lineColor);
	SetLineStyle(SOLID_LINE, thick);
	ellipse(x, y, 0, 360, rx, ry);
}
