#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string NAMECLASSLINE[] = { "TrainId", "DepartureStationId", "ArrivalStationId", "Price", "ArrivalTimeString", "DepartureTimeString" };

class TrainLeg
{
	string DepartureTimeString;
	string ArrivalTimeString;
	float Price;
	int ArrivalStationId;
	int DepartureStationId;
	int TrainId;
public:
	//setter
	void setTrainId(string);
	void setDepartureStationId(string);
	void setArrivalStationId(string);
	void setPrice(string);
	void setArrivalTimeString(string);
	void setDepartureTimeString(string);

	//getter
	int getArrivalStationId();
	int getDepartureStationId();
	float getPrice();
	void ShowAll();
};

//setter
void TrainLeg::setTrainId(string st)
{
	int num = atoi(st.c_str());
	TrainId = num;
}
void TrainLeg::setDepartureStationId(string st)
{
	int num = atoi(st.c_str());
	DepartureStationId = num;
}
void TrainLeg::setArrivalStationId(string st)
{
	int num = atoi(st.c_str());
	ArrivalStationId = num;
}
void TrainLeg::setPrice(string st)
{
	double num = stod(st.c_str());//проверить
	Price = num;
}
void TrainLeg::setArrivalTimeString(string st)
{

	ArrivalTimeString = st;
}
void TrainLeg::setDepartureTimeString(string st)
{
	DepartureTimeString = st;
}
void TrainLeg::ShowAll()
{
	cout << "TrainId: " << TrainId << " DepartureStationId: " << DepartureStationId <<
		" ArrivalStationId: " << ArrivalStationId << " Price: " << Price << " ArrivalTimeString" <<
		ArrivalTimeString << " DepartureTimeString" << DepartureTimeString<<endl;
}
//getter

int TrainLeg::getArrivalStationId()
{
	return ArrivalStationId;
}
int TrainLeg::getDepartureStationId()
{
	return DepartureStationId;
}
float TrainLeg::getPrice()
{
	return Price;
}