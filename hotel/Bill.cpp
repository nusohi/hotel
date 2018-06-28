#include "Bill.h"



int Bill::StaticSum = 0;

const int Bill::getBillSum() { return StaticSum; }


//构造函数们
Bill::Bill() {}
Bill::Bill(RoomBase* room, Client& clientA, int days, bool checkIn)
	: ID(++StaticSum)
	, room(room->getID(), room->getType())
	, clientA(clientA), two(false)
	, checkInTime()
	, checkOutTime()
	, stayDays(days)
	, money(0)
{
	if (checkIn) {
		checkInTime.current();
		billStatus = CHECKIN;
	}
	else {
		billStatus = BOOKING;
	}
}
Bill::Bill(RoomBase* room, Client& clientA, Client& clientB, int days, bool checkIn)
	: ID(++StaticSum)
	, room(room->getID(), room->getType())
	, clientA(clientA), clientB(clientB), two(true)
	, checkInTime()
	, checkOutTime()
	, stayDays(days)
	, money(0)
{
	if (checkIn) {
		checkInTime.current();
		billStatus = CHECKIN;
	}
	else {
		billStatus = BOOKING;
	}
}


void Bill::checkIn() {
	checkInTime.current();
	billStatus = CHECKIN;
}
double Bill::checkOut() {
	checkOutTime.current();
	billStatus = DONE;
	return money ? money : calMoney();
}

double Bill::calMoney() {
	int typeIndex = room.getType();
	money = stayDays * COST[typeIndex];
	return money;
}


long Bill::getID() {
	return ID;
}
int  Bill::getStayDays() {
	return stayDays;
}
int	 Bill::getRoomID() {
	return room.getID();
}


bool Bill::isTwo() {
	return two;
}
BillStatus Bill::getStatus() {
	return billStatus;
}

