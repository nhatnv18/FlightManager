#include <winbgim.h>
#include <iostream>
#include "include/InitHomePageViews.h"
#include "include/DataControl.h"
#include "include/StringDefine.h"
#include <cstdlib>
#include "include/ClosingEvent.h"

int main()
{
	std::atexit(DeleteMemory);
	
	ReadPlanesFromFile();
	ReadFlightsFromFile();
	UpdateCompletePerRead();
	ReadCustomersFromFile();
	initwindow(WIDTH, HEIGHT);
//	while(1){
	HomePageViewShow();
//	}
	
	while(!kbhit()) delay(1);
	return 0;
}
