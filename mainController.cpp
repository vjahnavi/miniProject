/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: mainController.cpp                                                                                                                                                    ****     
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/



#include"mainController.h"
#include<fstream>
#include<iostream>
#include<ostream>
#include<iterator>
#include"temperatureMonitor.h"
#include"acMonitor.h"
using namespace std;

/**** Putting the ac level into file ****/

void MainController::displayAC(string status)
{
    ofstream fout;
    fout.open("output.txt",ios::out|ios::app);
    fout << "AC Level : " << status << endl;
}


/**** Putting the converted temperature data into file ****/

void MainController::displayTemp(char unit,float value)
{
    ofstream fout;
    fout.open("output.txt",ios::out|ios::app);
    fout  << "Degree : " << unit << "\t" << "Temperature : " <<value  << endl;
}





















