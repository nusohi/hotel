#pragma once
#include "Date.h"
#include <qstring.h>



class Client
{
public:
	Client() {}
	Client(const char* IDC, const char* name)
	{
		strcpy_s(this->IDC, IDC);
		strcpy_s(this->name, name);
	}

	QString getIDC() { return IDC; }
	QString getName() { return name; }
private:
	char IDC[20];		//…Ì∑›÷§∫≈¬Î
	char name[20];

};

