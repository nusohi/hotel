#pragma once
#include <qstring.h>
#include <ctime>



class Date
{
public:
	Date() {}
	~Date() {}

	void current() {
		time_t currentTime = time(NULL);
		tm tim = *localtime(&currentTime);
		day = tim.tm_mday;
		month = tim.tm_mon + 1;
		year = tim.tm_year + 1900;
		hour = tim.tm_hour;
		minute = tim.tm_min;
		second = tim.tm_sec;
	}

	QString Time() {
		return QString::number(hour) + ((minute < 10) ? ":0" : ":") + QString::number(minute);
	}
	QString Day() {
		return QString::number(month) + '-' + QString::number(day);
	}
	QString Time(int) {
		return QString::number(hour) + ((minute < 10) ? ":0" : ":") + QString::number(minute) + ((second < 10) ? ":0" : ":") + QString::number(second);
	}
	QString Day(int) {
		return QString::number(year) + '-' + QString::number(month) + '-' + QString::number(day);
	}
	QString Day_Time() {
		return Day() + "  " + Time();
	}

private:
	int year, month, day, hour, minute, second;
};