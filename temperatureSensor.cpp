#include"temperatureSensor.h"
#include<cstring>
#include<iostream>
#include<fstream>


/********** function for making subscribers to get subscribed **********/

void ctemperatureSensor::subscribe(observer *myobserver)

{
    	cout << "subscribed" << endl;
	myobs.push_back( myobserver);
    
}

/********* function for maiking subscribers to get unsybscribed *******/

void ctemperatureSensor::unsubscribe( observer *myobserver)
{
    	cout << "removing subscriber" << endl;
	auto iterator =find(myobs.begin(),myobs.end(),myobserver);
	    if(iterator!=myobs.end())
		   myobs.erase(iterator);
  
}

/********* function to get the data from a file *************/

 void ctemperatureSensor::getTemperature()
{

	std::ifstream inFile{"file.txt"};
	while (inFile)
	{
		string keyBefore,valueBefore;
		{
			getline(inFile,valueBefore, ':') && getline(inFile, keyBefore);
			if(inFile)
			{
				value=stof(valueBefore);  //converting string to float 

				char duplicateStr[keyBefore.size() + 1];
				strcpy(duplicateStr, &keyBefore[0]);
				key=duplicateStr[0];      // converting string to char
				project.push_back(make_pair(key,value));
		
				
	
			}

		}
	}
}

/********* function to display the data stored in a vector ************/

void ctemperatureSensor::displayData()
{	
vector<pair<char,float>>:: const_iterator itr;
	
	for (itr = project.begin(); itr != project.end(); itr++)
	{
		cout << itr->first << "\t" << itr->second << endl;

	
	}
	for(itr=project.begin();itr!=project.end();itr++)
	{
		key=itr->first;
		value=itr->second;
		notify();
	}
}	

	
/********* function to notify the subscriber that change has happened *************/	

void ctemperatureSensor::notify()
{
	cout << "notifying" << endl;
	for (observer *myobserver : myobs) { // notify all observers
        myobserver->update(key,value);
        }
}


