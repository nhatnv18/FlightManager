#pragma once
#include "ArrChar_Num.h"
#include <ctime>

struct DateTime{
	int hour,min;
	int day,month,year;
};

int yearDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

bool Check_Valid_Date(int dd, int mm, int yy)  
{
	int months[12]={  31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((yy%4==00 && yy%100!=0) || (yy%400==0))
	{
		months[1]=29;
	}
	if (mm >=1 && mm<=12)
	{
		if (dd>=1 && dd<=months[mm-1]) return true;
	}
	return false;
}

bool Check_Valid_Time(int hour, int min)  
{
	if (hour>=24)
	{
		return false;
	}
	if (min>=60)
	{
		return false;
	}
	return true;
}

DateTime CreateADateSet(int day, int month, int year, int hour, int min){
	
	DateTime tmp;
	tmp.day = day;
	tmp.month = month;
	tmp.year = year;
	tmp.hour = hour;
	tmp.min = min;
	
	return tmp;
}

void DateTimeToText(char*s, DateTime t){
	char dt[30]="";
	char day[5]="", month[5]="", year[5]="", hour[5]="", min[5]="";
	NumToCharArr(day, t.day);
	NumToCharArr(month, t.month);
	NumToCharArr(year, t.year);
	NumToCharArr(hour, t.hour);
	NumToCharArr(min, t.min);
	
	strcat(dt, day);
	strcat(dt, "/");
	strcat(dt, month);
	strcat(dt, "/");
	strcat(dt, year);
	strcat(dt, " ");
	strcat(dt, hour);
	strcat(dt, ":");
	strcat(dt, min);
	
	strcpy(s, dt);
}

DateTime *TextToDate(char *timeStart){
	int day=0, month=0, year=0, hour=0, min=0;
	int i=0;
	while(timeStart[i]==' ') i++;
	if(i>=strlen(timeStart)) return NULL;
	while(timeStart[i]!='/' && i<strlen(timeStart)){
		if(timeStart[i]<'0' || timeStart[i]>'9') return NULL;
		day = day*10 + (timeStart[i]-'0');
		i++;
	}
	i++;
	if(i>=strlen(timeStart)) return NULL;
	while(timeStart[i]!='/' && i<strlen(timeStart)){
		if(timeStart[i]<'0' || timeStart[i]>'9') return NULL;
		month = month*10 + (timeStart[i]-'0');
		i++;
	}
	i++;
	if(i>=strlen(timeStart)) return NULL;
	while(timeStart[i]!=' ' && i<strlen(timeStart)){
		if(timeStart[i]<'0' || timeStart[i]>'9') return NULL;
		year = year*10 + (timeStart[i]-'0');
		i++;
	}
	i++;
	if(i>=strlen(timeStart)) return NULL;
	while(timeStart[i]==' ') i++;
	if(i>=strlen(timeStart)) return NULL;
	while(timeStart[i]!=':' && i<strlen(timeStart)){
		if(timeStart[i]<'0' || timeStart[i]>'9') return NULL;
		hour = hour*10 + (timeStart[i]-'0');
		i++;
	}
	i++;
	if(i>=strlen(timeStart)) return NULL;
	if(timeStart[i]<'0' && timeStart[i]>'9') return NULL;
	while(timeStart[i]>='0' && timeStart[i]<='9' && i<strlen(timeStart)){
		min = min*10 + (timeStart[i]-'0');
		i++;
	}
	if(i<strlen(timeStart)) return NULL;
	if(!Check_Valid_Date(day, month, year)){
		return NULL;
	}
	if(!Check_Valid_Time(hour, min)){
		return NULL;
	}
	
	DateTime tmp = CreateADateSet(day, month, year, hour, min);
	return &tmp;
}

DateTime GetNow(){
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	
	DateTime tmp = CreateADateSet(now->tm_mday, now->tm_mon+1, now->tm_year+1900, now->tm_hour, now->tm_min);
	return tmp;
}

bool isLeapYear(int year){
	return (year%400==0 || (year%4==0 && year%100!=0));
}

unsigned long int DaysFromStartTime(int year){
	return 365*year+year/4-year/100+year/400;
}

unsigned long int DaysFromStartYear(int month, int year){
	int sumDay=0;
	for(int i=0; i<month; i++){
		sumDay+=yearDay[i];
	}
	if(isLeapYear(year) && month>=2){
		sumDay+=1;
	}
	return sumDay;
}

unsigned long int DayDiff(DateTime d){
	return DaysFromStartTime(d.year-1)+DaysFromStartYear(d.month-1,d.year)+(d.day-1);
}

unsigned long int MinDiff(DateTime d){
	return DayDiff(d)*1440+d.hour*60+d.min;
}

unsigned long int MinSub(DateTime dFrom, DateTime dTo){
	return MinDiff(dTo)-MinDiff(dFrom);
}

double MinToHour(int min){
	return (float)min/60;
}

int TimeCmp(DateTime d1, DateTime d2){
	unsigned long int m1 = MinDiff(d1);
	unsigned long int m2 = MinDiff(d2);
	if(m1<m2) return -1;
	if(m1==m2)return 0;
	return 1;
}
