/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: temperatureMonitor.h                                                                                                                                                  *** 

****   Date: 7 February 2019                                                                                                                                                      ****
 
**********************************    END    *****************************************************************************************************************************************/



#ifndef temperatureMonitor_HPP
#define temperatureMonitor_HPP


#include<iostream>
#include"vector"
#include"observer.h"
//#include"mainController.h"
class cTemperatureMonitor : public observer
{
    public:
    std::vector <std::pair<char,float> > mtempMonitor;
    float mvalue;
    char munit;
    public:
    static void convert();
    virtual void update(char,float) override;
    static void *create(void *);
};
#endif


