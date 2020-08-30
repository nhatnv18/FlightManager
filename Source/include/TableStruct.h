#pragma once
struct CellTable{
	char *content="";
	int fontText;
	int sizeText;
	int bkRecordColor;
	int textColor;
	int lineColor;
	int lineHighlightColor;
	int bkHighlightColor;
	int left, top, right, bottom;
};

struct Record{
	int index;
	int coloums;
	int left, top, right, bottom;
	CellTable *cellList;
	bool readOnly;
};

struct Table{
	int left;
	int right;
	int top;
	int height;
	int sizeCols;
	int sizeRows;
	Record *recordList;
};
