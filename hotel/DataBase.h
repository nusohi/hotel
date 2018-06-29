#pragma once
#include "Global.h"
#include <map>
#include <string>
#include <fstream>
using namespace std;


template<class T>
class DataBase
{
public:
	DataBase(string filePath);
	~DataBase();

	T* query(long ID);
	T* query(string QName);
	T** query(RoomType roomType);
	T** query(BillStatus billStatus);
	long* queryID(RoomType roomType);
	int querySum(RoomType roomType);
	int querySum(BillStatus billType);
	T** showAll();

	bool isEmpty();
	int calSum();

	void insert(T& data);
	bool Delete(long ID);
	void saveMap();

	static int typeSum[3];
protected:
	fstream file;
	string filePath;
	long fileLen;
	long size;
	typedef map<long, T> maptype;
	maptype dataMap;
};




template<class T>
DataBase<T>::DataBase(string filePath) {
	this->filePath = filePath;
	file.open(filePath, ios::in | ios::binary);
	size = sizeof(T);

	if (!file.is_open()) {
		ofstream createFile(filePath);
		createFile.close();
		file.open(filePath, ios::in | ios::binary);
	}

	file.seekg(0, ios::end);
	fileLen = file.tellg();

	if (fileLen > 0) {
		T data;
		file.seekg(0, ios::beg);

		do {
			file.read((char*)&data, size);
			dataMap.insert(maptype::value_type(data.getID(), data));
			T::StaticSum++;
		} while (file.tellg() < fileLen);
	}
	file.close();
}

template<class T>
DataBase<T>::~DataBase() {
	saveMap();
}

template<class T>
T* DataBase<T>::query(long ID) {
	maptype::iterator iter;
	iter = dataMap.find(ID);
	if (iter == dataMap.end())
		return NULL;
	else
		return &(iter->second);
}

template<class T>
T* DataBase<T>::query(string QName) {
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		string name((iter->second).getName());
		if (QName.compare(name) == 0) {
			return &(iter->second);
		}
	}
}

template<class T>
T** DataBase<T>::query(RoomType roomType) {
	if ((int)roomType == -1) {
		return showAll();
	}
	int sum = calSum();
	T ** rooms = new T*[sum];

	int i = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		if (iter->second.getType() == roomType) {
			rooms[i++] = &(iter->second);
		}
	}
	for (int j = i; j < sum; j++)
		rooms[j] = NULL;

	return rooms;
}

template<class T>
T** DataBase<T>::query(BillStatus billStatus) {
	
	if ((int)billStatus == -1) {
		return showAll();
	}
	int sum = calSum();
	T ** bills = new T*[sum];

	int i = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		if (iter->second.getStatus() == billStatus) {
			bills[i++] = &(iter->second);
		}
	}
	for (int j = i; j < sum; j++) {
		delete bills[j];
		bills[j] = NULL;
	}
	return bills;
}

template<class T>
int DataBase<T>::querySum(RoomType roomType) {
	int sum = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		if (iter->second.getType() == roomType) {
			sum++;
		}
	}
	return sum;
}

template<class T>
int DataBase<T>::querySum(BillStatus billStatus) {
	int sum = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		if (iter->second.getStatus() == billStatus) {
			sum++;
		}
	}
	return sum;
}

template<class T>
long* DataBase<T>::queryID(RoomType roomType) {
	int sum = calSum();
	long * roomID = new long[sum] {0};

	int rightSum = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		RoomType type = iter->second.getType();
		if (type == roomType) {
			roomID[rightSum++] = (iter->second).getID();
		}
	}
	for (int i = rightSum; i < sum; i++)
		roomID[i] = NULL;
	return roomID;	//待错
}

template<class T>
T** DataBase<T>::showAll() {

	int sum = calSum();
	T ** data = new T*[sum];	//此函数中未释放才能正确返回数组

	int i = 0;
	maptype::iterator iter;
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++) {
		data[i++] = &(iter->second);
	}
	return data;
}






template<class T>
void DataBase<T>::insert(T& data) {
	long test_ID = data.getID();
	dataMap.insert(maptype::value_type(data.getID(), data));
	fileLen += size;
}

template<class T>
bool DataBase<T>::Delete(long ID) {
	if (query(ID) != NULL) {
		dataMap.erase(ID);
		fileLen -= size;
		return true;
	}
	return false;
}

template<class T>
void DataBase<T>::saveMap() {
	maptype::iterator iter;
	T data;
	file.open(filePath, ios::out | ios::binary | ios::trunc);
	for (iter = dataMap.begin(); iter != dataMap.end(); iter++)
		file.write((char*)&iter->second, size);
	file.close();

}

template<class T>
bool DataBase<T>::isEmpty() {
	return fileLen ? false : true;
}

template<class T>
int DataBase<T>::calSum() {
	return fileLen / size;
}



