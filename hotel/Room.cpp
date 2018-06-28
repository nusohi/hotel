#include "Room.h"



RoomBase::RoomBase() {}
RoomBase::RoomBase(int ID, RoomType type)
	:ID(ID), type(type)
{
}

int RoomBase::getID() {
	return ID;
}
RoomType RoomBase::getType() {
	return type;
}




int Room::StaticSum = 0;

Room::Room(int ID, RoomType type)
	:RoomBase(ID, type)
	, status(VACANT)
{
}

RoomStatus Room::getStatus() {
	return status;
}
void Room::setStatus(RoomStatus roomStatus) {
	this->status = roomStatus;
}
