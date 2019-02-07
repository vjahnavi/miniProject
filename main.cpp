#ifndef OBSERVER_H
#define OBSERVER_H
#include<iostream>

#include"temperatureMonitor.h"
#include"acMonitor.h"
#include"temperatureSensor.h"
#include"mainController.h"
using namespace std;
int main()
{
	ctemperatureSensor *sensor=new ctemperatureSensor;
	cTemperatureMonitor *temperature=new cTemperatureMonitor;
	sensor->subscribe(temperature);
	cAcMonitor *ac=new cAcMonitor;
	//cAcMonitor *jan=new cAcMonitor;
	sensor->subscribe(ac);
	//sensor->subscribe(jan);
	//sensor->unsubscribe(jan);
	sensor->getTemperature();
	sensor->displayData();
//	MainController *mainCntrlPtr=new MainController();
//	mainCntrlPtr->GenerateOutput();
	return 0;
}
#endif
