#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP



#include<iostream>
#include<pthread.h>
#include"temperatureMonitor.h"
#include"acMonitor.h"
using namespace std;
class MainController
{
	/*private:
	cTemperatureMonitor *mTempMonPtr;
	cAcMonitor *mAcMonPtr;
	pthread_t p1;
	pthread_t p2;
	public:*/
	
/********* Parameterised Constructor *********/

	//MainController(cTemperatureMonitor *t_temp,cAcMonitor *t_ac):mTempMonPtr(t_temp),mAcMonPtr(t_ac)
	//{

	//}
///	static void *createForTemp(void *);
//	static void *createForAc(void *);

/**********  Creating threads to write output  data into the file *************/

	//void GenerateOutput();
	
	//void writeTempData();
	//void writeAcData();
	public:
	 static void displayTemp(char,float);	
	 static void displayAC(string );

	

};

#endif
