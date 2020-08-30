#pragma once

#include "ButtonControl.h"
#include "TableControl.h"
#include "InitPlanesManagerPageViews.h"
#include "FlightsManager.h"
#include "SearchFlightByDateTimeTo.h"
#include "CustomerManagerUI.h"
#include "PlaneFlightTurns.h"
#include "StringDefine.h"

#define LEFT_NAME WIDTH/3
#define TOP_NAME 200
#define NAME_FONT 7
#define TOP_NAME2 270
#define NAME2_FONT 6

#define TOP_INFO 350

#define LEFT_FRAME_NAME LEFT_NAME+15
#define LEFT_FRAME_NAME2 LEFT_NAME+25
#define TOP_FRAME_NAME 240
#define TOP_FRAME_NAME2 230
#define RIGHT_FRAME_NAME 1060
#define RIGHT_FRAME_NAME2 1050
#define BOTTOM_FRAME_NAME 3*HEIGHT/4
#define BOTTOM_FRAME_NAME2 3*HEIGHT/4+10

#define MENU_LEFT 0
#define MENU_TOP 0
#define MENU_RIGHT 350
#define MENU_HEIGHT 50
#define MENU_SIZE 5

#define BUTTON_LANGUAGE_MODE_LEFT 1250
#define BUTTON_LANGUAGE_MODE_RIGHT 1350
#define BUTTON_LANGUAGE_MODE_TOP 0
#define BUTTON_LANGUAGE_MODE_BOTTOM 70

bool isExit;

Button btnLanguageMode = CreateAButton(charLanguageMode.scontent[languageMode].content, FONT_MAIN, 1, WHITE, BLUE, BUTTON_LANGUAGE_MODE_LEFT, BUTTON_LANGUAGE_MODE_TOP, BUTTON_LANGUAGE_MODE_RIGHT, BUTTON_LANGUAGE_MODE_BOTTOM, BLUE, YELLOW, BLUE, YELLOW, true);

void HomePageName(){
	DrawRecStroke(LEFT_FRAME_NAME, TOP_FRAME_NAME, RIGHT_FRAME_NAME, BOTTOM_FRAME_NAME, SOLID_LINE, BLUE, 2);
	DrawRecStroke(LEFT_FRAME_NAME2, TOP_FRAME_NAME2, RIGHT_FRAME_NAME2, BOTTOM_FRAME_NAME2, SOLID_LINE, BLUE, 2);
	PrintText(LEFT_NAME, TOP_NAME,titleApp1.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_TOP,NAME_FONT,FONT_MAIN);
	PrintText(LEFT_NAME, TOP_NAME2,titleApp2.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_TOP,NAME2_FONT,FONT_MAIN);
}

void HomePageInfo(){
	PrintText(LEFT_NAME+50, TOP_INFO, titleAppInfo1.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_TOP, 1, FONT_MAIN);
	DrawLine(LEFT_NAME+50, TOP_INFO+20, LEFT_NAME+185, TOP_INFO+20,SOLID_LINE, BLUE, 1);
	PrintText(LEFT_NAME+80, TOP_INFO+50, titleAppInfo2.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_TOP, 1, FONT_MAIN);
	PrintText(LEFT_NAME+80, TOP_INFO+100, titleAppInfo3.scontent[languageMode].content, WHITE, BLUE, ALIGN_LEFT_TOP, 1, FONT_MAIN);
}

void ListenItemMenu(int index){
	switch(index){
		case 0:
//			std:: cout << "chon Planes Manager"<<std::endl;
			PlanesManagerPageShow();
			break;
		case 1:
//			std:: cout << "chon Flights Manager"<<std::endl;
			FlightsManagerShow();
			break;
		case 2:
//			std:: cout << "chon Tickets Manager"<<std::endl;
			SearchFlightUIShow();
			break;
		case 3:
//			std:: cout << "chon Customers Manager"<<std::endl;
			CustomerManagerShow();
			break;
		case 4:
			PlaneFlightTurnsView();
			break;
	}
}

void HomePageMenuShow(){
	Table menuHomePageControl = TableCreate(MENU_LEFT,MENU_TOP,MENU_RIGHT,1, MENU_SIZE, MENU_HEIGHT, WHITE, WHITE, LIGHTGRAY, BLUE, LIGHTGRAY, BLUE, YELLOW, BLUE, BLACK, FONT_MAIN, 1, ListenItemMenu);
	AddMenuContent(menuHomePageControl,0,charMenu.scontent[languageMode].content);
	AddCellTableContent(menuHomePageControl, 0, 0, charHomeMenu1.scontent[languageMode].content);
	AddCellTableContent(menuHomePageControl, 1, 0, charHomeMenu2.scontent[languageMode].content);
	AddCellTableContent(menuHomePageControl, 2, 0, charHomeMenu3.scontent[languageMode].content);
	AddCellTableContent(menuHomePageControl, 3, 0, charHomeMenu4.scontent[languageMode].content);
	AddCellTableContent(menuHomePageControl, 4, 0, charHomeMenu5.scontent[languageMode].content);
	TableShow(menuHomePageControl);
}

void LanguageModeSwitch(){
	SwitchMode();
}

void HomePageButtonManager(){
	ButtonChangeName(btnLanguageMode, charLanguageMode.scontent[languageMode].content);
	
	ButtonSetEnable(btnLanguageMode, true);
	
	SetButtonListener(&btnLanguageMode, LanguageModeSwitch);
	
	ButtonShow(btnLanguageMode, false);
}

void HomePageViewShow(){
	
	isExit = false;
	while(!isExit){
		SetDefaultColor();
		cleardevice();
		ClearAllcells();
		HomePageName();
		HomePageInfo();
		HomePageMenuShow();
		HomePageButtonManager();

		MouseWaitingClick();

	}
	
}
