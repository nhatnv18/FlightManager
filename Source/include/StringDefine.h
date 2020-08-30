#pragma once

struct Content{
	char *content;
};

struct StringContent{
	Content scontent[2];
};

StringContent titleApp1 = {"FLIGHTS", "QUAN LY"};
StringContent titleApp2 = {"MANAGER", "CHUYEN BAY"};
StringContent titleAppInfo1 = {"A project of:", "Mot du an cua:"};
StringContent titleAppInfo2 = {"Nguyen Van Nhat - N18DCCN139", "Nguyen Van Nhat - N18DCCN139"};
StringContent titleAppInfo3 = {"Le Nguyen Duc Tan - N18DCCN182", "Le Nguyen Duc Tan - N18DCCN182"};
StringContent charMenu = {"MENU", "BANG CHON"};
StringContent charHomeMenu1 = {"Planes Manager", "Quan Ly May Bay"};
StringContent charHomeMenu2 = {"Flights Manager", "Quan Ly Chuyen Bay"};
StringContent charHomeMenu3 = {"Tickets Manager", "Quan Ly Ban Ve"};
StringContent charHomeMenu4 = {"Customers Manager", "Quan Ly Hanh Khach"};
StringContent charHomeMenu5 = {"Plane's Flights Summary", "Thong Ke Chuyen Bay"};

StringContent titlePlanesManagerPage = {"PLANES MANAGER", "QUAN LY MAY BAY"};
StringContent titleFlightsManagerPage = {"FLIGHTS MANAGER", "QUAN LY CHUYEN BAY"};
StringContent titleTicketManagerPage = {"TICKET MANAGER", "QUAN LY VE"};
StringContent titleFindFLightPage = {"FIND FLIGHTS", "TIM KIEM CHUYEN BAY"};
StringContent titleCustomerManagerPage = {"CUSTOMER MANAGER", "QUAN LY HANH KHACH"};
StringContent titleTicketListPage = {"CUSTOMER LIST OF FLIGHT ", "DANH SACH HANH KHACH CHUYEN BAY "};
StringContent titleSummaryPage = {"SUMMARY OF FLIGHT TURN FOR EACH PLANE", "THONG KE LUOT BAY CUA MOI MAY BAY"};

StringContent charBtnBack = {"<BACK", "<TRUOC"};
StringContent charBtnNew = {"NEW", "MOI"};
StringContent charBtnSave = {"SAVE", "LUU"};
StringContent charBtnRemove = {"REMOVE", "XOA"};
StringContent charBtnCancel = {"CANCEL", "HUY"};
StringContent charBtnTicket = {"TICKET", "QL VE"};
StringContent charBtnSell = {"SELL", "DAT"};
StringContent charBtnCancelTicket = {"CANCEL TICKET", "HUY VE"};
StringContent charBtnListTicket = {"LIST VIEW MODE", "DANH SACH VE"};

StringContent charID = {"ID", "Ma"};
StringContent charPlaneID = {"Plane ID", "May Bay"};
StringContent charType = {"Type", "Kieu"};
StringContent charSeats = {"Seats", "So Ghe"};
StringContent charIndexSeats = {"Index", "Ghe"};
StringContent charStartTime = {"Start", "K. hanh"};
StringContent charTo = {"To", "Den"};
StringContent charStt = {"Status", "T. thai"};
StringContent charICNumber = {"ICN", "CMND"};
StringContent charICNumberFull = {"Identity Card", "CMND"};
StringContent charName = {"Name", "Ten"};
StringContent charGender = {"Gender", "G. Tinh"};
StringContent charInformation = {"Information", "Thong tin"};
StringContent charStartOn = {"Start on:", "Khoi hanh:"};
StringContent charFlightTo = {"Flight to:", "Bay den:"};
StringContent charTicketInfo = {"Ticket Info", "Thong tin dat ve"};
StringContent charDay = {"Day", "Ngay"};
StringContent charMonth = {"Month", "Thang"};
StringContent charYear = {"Year", "Nam"};
StringContent charFlights = {"Flights", "Chuyen bay"};
StringContent charTakeOff = {"Taking off on ", "Khoi hanh luc "};
StringContent charLandAt = {" - Landing at ", "- Ha canh tai "};
StringContent charOrdNumber = {"Ord Number", "STT"};

StringContent charStt0 = {"Cancelled", "Da Huy"};
StringContent charStt1 = {"Active", "Ban"};
StringContent charStt2 = {"Sold Out", "Day"};
StringContent charStt3 = {"Completed", "Hoan thanh"};
StringContent charStt4 = {"Took Off", "Khoi hanh"};

StringContent charConfirm = {"CONFIRM", "XAC NHAN"};
StringContent charError = {"ERROR", "LOI"};
StringContent charSaveAllChange = {"SAVE ALL CHANGE?", "LUU THAY DOI?"};
StringContent charIDUsed = {"THIS ID HAS USED", "ID NAY DA DUOC SU DUNG"};
StringContent charSeat20 = {"SEATS HAS TO >= 20", "SO GHE PHAI >= 20"};
StringContent charSeatNumberic = {"SEATS HAS TO BE NUMBERIC", "SO GHE PHAI DANG SO"};
StringContent charAllData = {"FILL ALL DATA TO CONTINUE", "KHONG DUOC BO TRONG"};
StringContent charCannotRemove = {"CAN NOT DELETE", "KHONG THE XOA"};
StringContent charConfirmRemove = {"REALLY WANNA REMOVE?", "THAT SU MUON XOA?"};
StringContent charConfirmCancel = {"REALLY WANNA CANCEL?", "THAT SU MUON HUY?"};
StringContent charWrongInputMask = {"WRONG INPUT MASK", "NHAP SAI KIEU"};
StringContent charNotFoundPlane = {"NOT FOUND PLANE", "KHONG TIM THAY MAY BAY"};
StringContent charTimeErrorNow = {"TIME IS NOT ALLOWED. BEFORE NOW", "TRUOC THOI DIEM HIEN TAI"};
StringContent charPlanesUsedInTime = {"THIS PLANE IS USED IN THIS TIME", "KHONG THE CHON VOI THOI DIEM NAY"};
StringContent charCustomerBusy = {"CUSTOMER IS BUSY IN THIS TIME", "KHACH DA BAY TAI THOI DIEM NAY"};

StringContent charDialogYes = {"YES", "DONG Y"};
StringContent charDialogNo = {"NO", "KHONG"};
StringContent charDialogCancel = {"CANCEL", "HUY"};

StringContent charLanguageMode = {"VIE", "ENG"};

enum Language{
	ENG,//0
	VIE//1
};

Language languageMode=ENG;

void SwitchMode(){
	if(languageMode==ENG) languageMode=VIE;
	else languageMode = ENG;
}


