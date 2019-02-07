/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: temperatureSensor.h                                                                                                                                                   **** 
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/




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
    vector<pair<char,float>>mproject;
    float mvalue;
    char mkey;
    vector<observer *> mMyobs;
    public:
    virtual void subscribe(observer *myobserver);
    virtual void unsubscribe(observer *myobserver);
    void getTemperature( );
    void displayData();	
    void notify();
};
#endif
