#include "Global.h"

int COST[] = { 100,200,300 };

QString RoomTypeToQString(RoomType roomType) {
	switch (roomType)
	{
	case ALL:
		return u8"�������� error";
	case A:
		return u8"���";
	case B:
		return u8"����";
	case C:
		return u8"�׷�";
	default:
		return u8"roomType ����";
	}
}

QString RoomStatusToQString(RoomStatus roomStatus) {
	switch (roomStatus)
	{
	case VACANT:
		return u8"�շ�";
	case OCCUPIED:
		return u8"��ס";
	case BOOKED:
		return u8"Ԥ��";
	default:
		return u8"roomStatus ����";
	}
}

QString BillStatusToQString(BillStatus billStatus) {
	switch (billStatus)
	{
	case BOOKING:
		return u8"Ԥ��";
	case CHECKIN:
		return u8"��ס";
	case DONE:
		return u8"���";
	default:
		return u8"billStatus ����";
	}
}

