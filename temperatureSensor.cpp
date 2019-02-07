/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: temperatureSensor.cpp                                                                                                                                                ****  
****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/


#include"temperatureSensor.h"
#include<cstring>
#include<iostream>
#include<fstream>


/********** function for making subscribers to get subscribed **********/

void ctemperatureSensor::subscribe(observer *myobserver)
{
    cout << "subscribed" << endl;
    mMyobs.push_back( myobserver);
}

/********* function for maiking subscribers to get unsybscribed *******/

void ctemperatureSensor::unsubscribe( observer *myobserver)
{
    cout << "removing subscriber" << endl;
    auto iterator =find(mMyobs.begin(),mMyobs.end(),myobserver);
    if(iterator!=mMyobs.end()) 
    mMyobs.erase(iterator);
  
}

/********* function to get the data from a file *************/

 void ctemperatureSensor::getTemperature()
{

    std::ifstream inFile{"file.txt"};
    if(inFile.fail())
    {
	    cout << "file is not present" << endl;
    }
    while (inFile)
    {
        string keyBefore,valueBefore;
	{
	    getline(inFile,valueBefore, ':') && getline(inFile, keyBefore);
	    if(inFile)
	    {
	        mvalue=stof(valueBefore);  //converting string to float 
                char duplicateStr[keyBefore.size() + 1];
		strcpy(duplicateStr, &keyBefore[0]);
		mkey=duplicateStr[0];      // converting string to char
		mproject.push_back(make_pair(mkey,mvalue));
	     }
	}
    }
}

/********* function to display the data stored in a vector ************/

void ctemperatureSensor::displayData()
{	
    vector<pair<char,float>>:: const_iterator itr;
    for (itr = mproject.begin(); itr != mproject.end(); itr++)
    {	
	    cout << itr->first << "\t" << itr->second << endl;

	
    }
    for(itr=mproject.begin();itr!=mproject.end();itr++)
    {
		mkey=itr->first;
		mvalue=itr->second;
		notify();
    }
}	

	
/********* function to notify the subscriber that change has happened *************/	

void ctemperatureSensor::notify()
{
    cout << "notifying" << endl;
    for(observer *myobserver : mMyobs) // notify all observers
    { 
        myobserver->update(mkey,mvalue);
    }
}


