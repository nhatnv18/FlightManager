#pragma once
#include <windows.h>
#include "Planes.h"
#include "FlightsStruct.h"
#include "CustomerStruct.h"

void DeleteMemory(){
    ClearAllPlaneList();
	ClearAllFlightsList(flightList);
	ClearAllDataFromTree(customerList);
	
    std::cout << "Deleted All Memory";
}
