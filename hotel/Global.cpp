#include "Global.h"

int COST[] = { 100,200,300 };

QString RoomTypeToQString(RoomType roomType) {
	switch (roomType)
	{
	case ALL:
		return u8"所有类型 error";
	case A:
		return u8"标间";
	case B:
		return u8"单间";
	case C:
		return u8"套房";
	default:
		return u8"roomType 错误！";
	}
}

QString RoomStatusToQString(RoomStatus roomStatus) {
	switch (roomStatus)
	{
	case VACANT:
		return u8"空房";
	case OCCUPIED:
		return u8"入住";
	case BOOKED:
		return u8"预订";
	default:
		return u8"roomStatus 错误！";
	}
}

QString BillStatusToQString(BillStatus billStatus) {
	switch (billStatus)
	{
	case BOOKING:
		return u8"预订";
	case CHECKIN:
		return u8"入住";
	case DONE:
		return u8"完成";
	default:
		return u8"billStatus 错误！";
	}
}

