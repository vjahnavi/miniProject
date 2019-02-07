/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: temperatureMonitor.cpp                                                                                                                                                **** 
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/



#include<vector>
#include"temperatureMonitor.h"
#include<iostream>
#include<pthread.h>
#include"mainController.h"
using namespace std;

/************** value gets updated everytime a subscriber is attached and thread is being called ***************/

void cTemperatureMonitor::update(char a,float b)
{
    munit=a;
    mvalue=b;
    pthread_t t1;
    pthread_create(&t1,NULL,create,(void *)(this));
    pthread_join(t1,NULL);
}


/************ created thread converts temperature from celsius to fahrenheit and vice-versa *************/

void *cTemperatureMonitor::create(void *ptr)
{
    cTemperatureMonitor *ptr1=static_cast <cTemperatureMonitor *>(ptr);
    cout << "................" << endl;
    cout << "updating in temperatureMonitor" << endl;
    std::cout << ptr1->munit << " " << ptr1->mvalue << std::endl;
    if(ptr1->munit=='F' || ptr1->munit=='f')
    {
         cout << "changing to celsius " << endl;
         ptr1->mvalue=(ptr1->mvalue-32)/1.8;
         ptr1->munit ='C';
         cout << ptr1->munit << " "  << ptr1->mvalue << endl;
	 MainController:: displayTemp(ptr1->munit,ptr1->mvalue);
    }
    else if(ptr1->munit=='c' || ptr1->munit=='C') 
    {
        cout << "changing to fahrenheit " << endl;
	ptr1->mvalue=(ptr1->mvalue*1.8)/32;
        ptr1->munit ='F';
        cout << ptr1->munit << " " << ptr1->mvalue << endl;
        MainController::displayTemp(ptr1->munit,ptr1->mvalue);
    }
    ptr1->mtempMonitor.push_back(make_pair(ptr1->munit,ptr1->mvalue));
    return 0;
}



 





