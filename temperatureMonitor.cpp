
#include<vector>
#include"temperatureMonitor.h"
#include<iostream>
#include<pthread.h>
#include"mainController.h"
using namespace std;

/************** value gets updated everytime a subscriber is attached and thread is being called ***************/

void cTemperatureMonitor::update(char a,float b)
{
 	unit=a;
	value=b;
	pthread_t t1;
	pthread_create(&t1,NULL,create,(void *)(this));
	pthread_join(t1,NULL);
}


/************ created thread will call the conversion function here *************/

void *cTemperatureMonitor::create(void *ptr)
{
	cTemperatureMonitor *ptr1=static_cast <cTemperatureMonitor *>(ptr);
//	ptr1->convert();
 cout << "................" << endl;
                cout << "updating in temperatureMonitor" << endl;

                std::cout << ptr1->unit << " " << ptr1->value << std::endl;
                if(ptr1->unit=='F' || ptr1->unit=='f')
                {
                        //cout << "..................." << endl;
                        cout << "changing to celsius " << endl;
                         ptr1->value=(ptr1->value-32)/1.8;
                        ptr1->unit ='C';
                       cout << ptr1->unit << " "  << ptr1->value << endl;
		       MainController:: displayTemp(ptr1->unit,ptr1->value);

                }

                else if(ptr1->unit=='c' || ptr1->unit=='C')
                {
                         //cout << "..................." << endl;
                        cout << "changing to fahrenheit " << endl;

                        ptr1->value=(ptr1->value*1.8)/32;
                        ptr1->unit ='F';
                        cout << ptr1->unit << " " << ptr1->value << endl;
                
		MainController::displayTemp(ptr1->unit,ptr1->value);
		}
               ptr1->tempMonitor.push_back(make_pair(ptr1->unit,ptr1->value));

	return 0;
}

/*********** conversion function to convert fahrenheit to celsius and vice-versa *******/

/*void cTemperatureMonitor::convert()
{	
	
	
	
	cout << "................" << endl;
                cout << "updating in temperatureMonitor" << endl;
	
		std::cout << unit << " " << value << std::endl;
                if(unit=='F' || unit=='f')
                {
                       	//cout << "..................." << endl;
			cout << "changing to celsius " << endl;
			 value=(value-32)/1.8;
			unit ='C';
			//cout << unit << " "  << value << endl;

                }

                else if(unit=='c' || unit=='C')
                {
                         //cout << "..................." << endl;
                        cout << "changing to fahrenheit " << endl;

			value=(value*1.8)/32;
			unit ='F';
			//cout << unit << " " << value << endl;
                }
		//writeTempData(unit,value);
               tempMonitor.push_back(make_pair(unit,value));
	       
}*/


 





