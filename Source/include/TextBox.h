#pragma once

struct TextBox{
	char *title;
	char content[100]="";
	char start_char, end_char;
	int max_length;
	int left, top,right, bottom;
	int sizeText;
	int fontText;
	int bkTitColor;
	int textTitColor;
	int bkColor;
	int textcolor;
	int lineColor;
	int bkColorDis;
	int textcolorDis;
	int lineColorDis;
	bool enable;
};
