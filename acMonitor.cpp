/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: acMonitor.cpp                                                                                                                                                         ****
	
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/




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
    munit=a;
    mvalue=b;
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
    if(mvalue > 40)
    {
        mstatus="hot";
	cout << "hot " << endl;
	MainController::displayAC(mstatus);
    }
    else if(mvalue > 30 && mvalue <= 40)
    {
        mstatus="medium";
	cout << "medium" << endl;
	MainController::displayAC(mstatus);
    }
    else if(mvalue > 0 && mvalue <=30)
    {
	mstatus="cold";
	cout << "cold " << endl;
	MainController::displayAC(mstatus);

    }
    acMonitor.push_back(mstatus);

}
#endif

