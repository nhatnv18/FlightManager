#pragma once

struct CharArr{
	char *text="";
};

struct ListCharArr{
	CharArr *list;
	int size;
};

struct ContentTable{
	ListCharArr *listOfRecord;
	int size;
};


