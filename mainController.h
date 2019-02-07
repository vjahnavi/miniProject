/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: mainController.h                                                                                                                                                      ****    
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/



#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP



#include<iostream>
#include<pthread.h>
#include"temperatureMonitor.h"
#include"acMonitor.h"
using namespace std;
class MainController
{
    public:
    static void displayTemp(char,float);
    static void displayAC(string );
};

#endif
