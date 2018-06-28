#pragma once
#include <qstring.h>


int COST[];

enum RoomType { ALL = -1, A = 0, B, C };

enum RoomStatus { VACANT, OCCUPIED, BOOKED };

enum BillStatus { BOOKING, CHECKIN, DONE };

QString RoomTypeToQString(RoomType roomType);

QString RoomStatusToQString(RoomStatus roomStatus);

QString BillStatusToQString(BillStatus billStatus);