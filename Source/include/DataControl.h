#pragma once

#include <fstream>
#include "Planes.h"
#include "FlightsStruct.h"
#include "CustomerStruct.h"

#define PATH_PLANE_FILE "data/Planes.CTDL"
#define PATH_FLIGHT_FILE "data/Flights.CTDL"
#define PATH_CUSTOMER_FILE "data/Customers.CTDL"

void WritePlanesToFile(){
	
	std::fstream bw;
	
	bw.open(PATH_PLANE_FILE, std::ios::out | std::ios::binary);
	
	for(int i=0; i<planeAddArray.size; i++){
		bw.write((const char*) planeAddArray.list[i], sizeof(Planes));
	}
	
	bw.close();
	
}

void ReadPlanesFromFile(){
	
	std::fstream br;
	
	br.open(PATH_PLANE_FILE, std::ios::in | std::ios::binary);
	
	ClearAllPlaneList();
	
	planeAddArray.size=0;
	Planes plane;
	while(br.read((char*) &plane, sizeof(Planes))){
		PlaneAdd(plane);
	}
	
	br.close();
	
}

void WriteFlightsToFile(){
	
	std::fstream bw;
	
	bw.open(PATH_FLIGHT_FILE, std::ios::out);
	
	NodeFlight *tmp = flightList.phead;
	while(tmp!=NULL){
		bw<<tmp->data.flightID<<std::endl;
		bw<<tmp->data.timeStart.day<<std::endl;
		bw<<tmp->data.timeStart.month<<std::endl;
		bw<<tmp->data.timeStart.year<<std::endl;
		bw<<tmp->data.timeStart.hour<<std::endl;
		bw<<tmp->data.timeStart.min<<std::endl;
		bw<<tmp->data.to<<std::endl;
		bw<<tmp->data.planeID<<std::endl;
		bw<<tmp->data.status<<std::endl;
		//Test
		TicketsList tmpList = tmp->data.ticket;
//		bw.write((const char*) &tmpList.size, sizeof(int));
		bw<<tmpList.sold<<std::endl;
		bw<<tmpList.soldTicket<<std::endl;
		for(int i=0; i<tmpList.size; i++){
//			std::cout << i << std::endl;
//			system("pause");
//			bw<<tmpList.tickets[i].index<<std::endl;
			bw<<tmpList.tickets[i].idPersonalNumber<<std::endl;
		}
		//Test
		tmp=tmp->pNext;
	}
	
	bw.close();
	
}

//void WriteFlightsToFile(){
//	
//	std::fstream bw;
//	
//	bw.open(PATH_FLIGHT_FILE, std::ios::out | std::ios::binary);
//	
//	NodeFlight *tmp = flightList.phead;
//	while(tmp!=NULL){
//		bw.write((const char*) &tmp->data, sizeof(Flight));
//		//Test
//		TicketsList tmpList = tmp->data.ticket;
////		bw.write((const char*) &tmpList.size, sizeof(int));
//		bw.write((const char*) &tmpList.sold, sizeof(int));
//		bw.write((const char*) &tmpList.soldTicket, sizeof(char[10]));
//		for(int i=0; i<tmpList.size; i++){
////			std::cout << i << std::endl;
////			system("pause");
//			bw.write((const char *) &tmpList.tickets[i], sizeof(Ticket));
//		}
//		//Test
//		tmp=tmp->pNext;
//	}
//	
//	bw.close();
//	
//}

void ReadFlightsFromFile(){
	
	std::fstream br;
	
	br.open(PATH_FLIGHT_FILE, std::ios::in);
	
	ClearAllFlightsList(flightList);
	
	flightList.size = 0;
	Flight flight;
	while(br.getline(flight.flightID, sizeof(flight.flightID), '\n')){
		//Test
		if(strlen(flight.flightID)==0) break;
//		br.getline(flight.flightID, sizeof(flight.flightID), '\n');
		char day[5], month[5], year[5], hour[5], min[5];
		br.getline(day, sizeof(day), '\n');
		br.getline(month, sizeof(month), '\n');
		br.getline(year, sizeof(year), '\n');
		br.getline(hour, sizeof(hour), '\n');
		br.getline(min, sizeof(min), '\n');
		flight.timeStart = CreateADateSet(ArrtoNum(day), ArrtoNum(month), ArrtoNum(year), ArrtoNum(hour), ArrtoNum(min));
		br.getline(flight.to, sizeof(flight.to), '\n');
		br.getline(flight.planeID, sizeof(flight.planeID), '\n');
		char stt[5];
		br.getline(stt, sizeof(stt), '\n');
		flight.status = ArrtoNum(stt);
		Flight tmpflight = ReCreateFlight(flight.flightID, flight.timeStart, flight.to, flight.planeID, flight.status);
//		int /*listSize,*/ listSold;
//		char tmpSoldChar[10]="";
//		br.read((char*) &listSize, sizeof(int));
		char sold[5]="";
		br.getline(sold, sizeof(sold), '\n');
		tmpflight.ticket.sold=ArrtoNum(sold);
		br.getline(tmpflight.ticket.soldTicket, sizeof(tmpflight.ticket.soldTicket), '\n');
//		std::cout <<"Sold in file: "<<tmpflight.ticket.sold<<std::endl;
//		std::cout <<"Load from file. Sold: "<<tmpflight.ticket.soldTicket<<std::endl;
//		char buffer[10]="";
//		long long buffer;
//		br.getline(buffer, sizeof(buffer), '\n');
//		br.getline(tmpflight.ticket.tickets[0].idPersonalNumber, sizeof(tmpflight.ticket.tickets[0].idPersonalNumber), '\n');
//			std::cout<<"CMND: "<<buffer<<std::endl;
//		tmpflight.ticket.sold = listSold;
		for(int i=0;i<tmpflight.ticket.size; i++){
//			char index[5]="";
//			br.getline(index, sizeof(index), '\n');
//			strcpy(tmpflight.ticket.tickets[i].index,index);
			br.getline(tmpflight.ticket.tickets[i].idPersonalNumber, sizeof(tmpflight.ticket.tickets[i].idPersonalNumber), '\n');
//			std::cout<<"CMND: "<<tmpflight.ticket.tickets[i].idPersonalNumber<<std::endl;
		}
		//Test
		Insert_Tail_Flight(flightList, NewNodeFlight(tmpflight));
	}
	
	br.close();
	
}

//void ReadFlightsFromFile(){
//	
//	std::fstream br;
//	
//	br.open(PATH_FLIGHT_FILE, std::ios::in | std::ios::binary);
//	
//	ClearAllFlights();
//	
//	flightList.size = 0;
//	Flight flight;
//	while(br.read((char*) &flight, sizeof(Flight))){
//		//Test
//		Flight tmpflight = CreateNewFlight(flight.flightID, flight.timeStart, flight.to, flight.planeID);
////		int /*listSize,*/ listSold;
////		char tmpSoldChar[10]="";
////		br.read((char*) &listSize, sizeof(int));
//		br.read((char*) &tmpflight.ticket.sold, sizeof(int));
//		br.read((char*) &tmpflight.ticket.soldTicket, sizeof(char[10]));
////		tmpflight.ticket.sold = listSold;
//		for(int i=0;i<tmpflight.ticket.size; i++){
//			br.read((char*) &tmpflight.ticket.tickets[i], sizeof(Ticket));
////			std::cout<<tmpflight.ticket.tickets[i].index<<std::endl;
//		}
//		//Test
//		Insert_Tail_Flight(flightList, NewNodeFlight(tmpflight));
//	}
//	
//	br.close();
//	
//}

void WriteCustomerNode(std::fstream &bw, Node *node){
	if(node!=NULL){
		WriteCustomerNode(bw, node->leftChild);
		
		bw.write((const char*) &node->data, sizeof(Customer));
		
		WriteCustomerNode(bw, node->rightChild);
	}
}

void WriteCustomersToFile(){
	
	std::fstream bw;
	
	bw.open(PATH_CUSTOMER_FILE, std::ios::out | std::ios::binary);
	
	WriteCustomerNode(bw, customerList.root);
	
	bw.close();
	
}

void ReadCustomersFromFile(){
	
	std::fstream br;
	
	br.open(PATH_CUSTOMER_FILE, std::ios::in | std::ios::binary);
	
	ClearAllDataFromTree(customerList);
	
	Customer tmpCustomer;
	while(br.read((char*) &tmpCustomer, sizeof(Customer))){
		InsertNodeIntoAVL(customerList, CreateNewCustomerNode(tmpCustomer));
	}
	
	br.close();
	
}
