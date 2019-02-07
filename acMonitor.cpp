#ifndef ACMONITOR_CPP
#define ACMONITOR_CPP
#include"acMonitor.h"
#include<iostream>
#include<string>
#include"mainController.h"
using namespace std;

/************** value gets updated everytime a subscriber is attached and thread is being called ***************/


void cAcMonitor :: update(char a,float b)
{
	unit=a;
	value=b;
	pthread_t t1;
	pthread_create(&t1,NULL,create,(void *)(this));
	pthread_join(t1,NULL);
}


/************ created thread will call the conversion function here *************/


void* cAcMonitor::create(void *ptr)
{
        cAcMonitor *ptr1=static_cast <cAcMonitor *>(ptr);
        ptr1->convert();
        return 0;
}

	
	
/*********** function which checks the status of ac *******/
	
	
	
	
	
void cAcMonitor :: convert()
{
	cout << "............................." << endl;
	cout << "updating in AC monitor" << endl;
	if(value > 40)
	{
		status="hot";
		cout << "hot " << endl;
		MainController::displayAC(status);
	}
	else if(value > 30 && value <= 40)
	{
	
		status="medium";
		cout << "medium" << endl;
		MainController::displayAC(status);
	}
	else if(value > 0 && value <=30)
	{
		
		status="cold";
		cout << "cold " << endl;
		MainController::displayAC(status);

	}
	acMonitor.push_back(status);

/*	for(ac=acMonitor.begin();ac!=acMonitor.end();++ac)
	{
		cout << *ac << endl;
	}*/

}
#endif

