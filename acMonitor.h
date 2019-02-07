#ifndef ACMONITOR_HPP
#define ACMONITOR_HPP

#include<iostream>
#include"observer.h"
#include<vector>
class cAcMonitor : public observer
{
	std::string status;
	std::vector<std::string> acMonitor;
	std:: vector< std:: string > ::iterator ac;
	
	char unit;
	float value;
	public:
	virtual void update(char,float) override;
	void convert();
        static void *create(void *);
};


#endif
