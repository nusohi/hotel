#pragma once
#include "Global.h"



class RoomBase
{
public:
	RoomBase();
	RoomBase(int ID, RoomType type);

	int getID();
	RoomType getType();
protected:
	int ID;
	RoomType type;
};



class Room :public RoomBase
{
public:
	Room() {}

	Room(int ID, RoomType type);

	RoomStatus getStatus();
	void setStatus(RoomStatus roomStatus);

	static int StaticSum;
private:
	RoomStatus status;
};

