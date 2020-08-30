#pragma once

void NumToCharArr(char *s, int num){
	if(num==0){
		s[0]='0';
		s[1]=0;
		return;
	}
	char tmp[50]="";
	while(num>0){
		int tmpN = num%10;
		char tmpC = (char) (tmpN+48);
		char tmpS[5];
		tmpS[0]=tmpC;
		tmpS[1]=0;
		strcat(tmp,tmpS);
		num/=10;
	}
//	std::cout << "tmp: "<<tmp;
	for(int i=strlen(tmp)-1; i>=0; i--){
		char tmpS[5];
		tmpS[0]=tmp[i];
		tmpS[1]=0;
//		std::cout << "i: "<<i;
//		system("pause");
		strcat(s, tmpS);
	}
//	system("pause");
}

int ArrtoNum(char *arrNum){
	int tmpNum=0;
	for(int i=0; i<strlen(arrNum); i++){
		tmpNum=tmpNum*10+(arrNum[i]-'0');
	}
	return tmpNum;
}

bool isNum(char *arr){
	for(int i=0; i<strlen(arr); i++){
		if(arr[i]<'0' || arr[i]>'9') return false;
	}
	return true;
}

void SplitName(char *fullName, char *fName, char *name){
	int spacePos = strlen(fullName)-1;
	while(fullName[spacePos]!=' '){
		spacePos--;
	}
	strcpy(fName,"");
	strncat(fName, fullName, spacePos);
	
	strcpy(name,"");
	strcat(name, fullName+spacePos+1);
}

void CorrectIDForm(char *s1)
{
	s1=strupr(s1);
}

void RemoveAt(char* s, int vt)
{
	int n= strlen(s);
	for(int i=vt;i<n;i++) s[i]=s[i+1];
	s[n-1]='\0';
}
void RemoveSpace(char* s1)
{
	for (int i=0;i<strlen(s1) ;i++)
	{
		if (s1[i]==' ' && s1[i+1]==' ')
		{
			RemoveAt(s1,i);
			i--;
		}
	}
	if (s1[0]==' ') RemoveAt(s1,0);
	if (s1[strlen(s1)-1]==' ') RemoveAt(s1,strlen(s1)-1);
}
void CorrectNameForm(char *s)
{
	RemoveSpace(s);
	if ((s[0]>=97) && (s[0]<=122)) s[0]=s[0]-32;
	for (int i=0;i<strlen(s);i++)
	{
//		if ((s[i]<65) || (s[i]>90 && s[i]<96) || s[i]>122 )
		if ( (s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) ||s[i]==' ')
		{
			if ((s[i]>=97) && (s[i]<=122) && (s[i-1]==' ') ) s[i]=s[i]-32;
		}
		else RemoveAt(s,i);
		if (s[i]>=65 && s[i]<=90 && s[i-1]!=' ' &&i!=0) s[i]=s[i]+32;
	}
}

bool isSubString(char *mainStr, char *subStr){
	if(strlen(subStr)==0) return true;
	for(int i=0; i<strlen(mainStr); i++){
		if(mainStr[i]==subStr[0]){
			bool isSub=true;
			for(int j=0; j<strlen(subStr); j++){
				if(subStr[j]!=mainStr[j+i]){
					isSub=false;
					break;
				}
			}
			if(isSub) return true;
		}
	}
	return false;
}
