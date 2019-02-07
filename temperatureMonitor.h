#ifndef temperatureMonitor_HPP
#define temperatureMonitor_HPP


#include<iostream>
#include"vector"
#include"observer.h"
//#include"mainController.h"
class cTemperatureMonitor : public observer
{
	public:
	std::vector <std::pair<char,float> > tempMonitor;
	float value;
	char unit;

	public:
	//staic void* convertToDegree(char,float);
	static void convert();
	virtual void update(char,float) override;
	static void *create(void *);
//	virtual void writeTempData(char,float) ;
};
#endif


