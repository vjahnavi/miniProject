#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP
#include<vector>
#include<algorithm>
#include<iostream>
#include"subject.h"
#include"observer.h"
using namespace std;
class ctemperatureSensor: public subject
{
	vector<pair<char,float>>project;

	float value;
	char key;
	vector<observer *> myobs;
	public:
	virtual void subscribe(observer *myobserver);
	virtual void unsubscribe(observer *myobserver);
	void getTemperature( );
	void displayData();	
	
	 void notify();
	//void* Notification();
//	pthread_t *ThreadIds();
};
#endif
