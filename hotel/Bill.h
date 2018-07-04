/***********************************************************

		HYX

***********************************************************/
#pragma once
#include "Client.h"
#include "Date.h"
#include "Room.h"



class Bill
{
public:
	Bill();
	Bill(RoomBase* room, Client& clientA, int days, bool checkIn);
	Bill(RoomBase* room, Client& clientA, Client& clientB, int days, bool checkIn);

	void checkIn();
	double checkOut();
	double calMoney();

	long getID();
	int getStayDays();
	int getRoomID();

	bool isTwo();
	BillStatus getStatus();

	const static int getBillSum();

public:
	RoomBase room;
	Date checkInTime;
	Date checkOutTime;
	Client clientA;
	Client clientB;
private:
	long ID;
	int  stayDays;
	double money;	//也许没有用

	bool two;
	BillStatus billStatus;
public:
	static int StaticSum;
};