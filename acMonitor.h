/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: acMonitor.h                                                                                                                                                           ****

****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/


#ifndef ACMONITOR_HPP
#define ACMONITOR_HPP

#include<iostream>
#include"observer.h"
#include<vector>
class cAcMonitor : public observer
{
    std::string mstatus;
    std::vector<std::string> acMonitor;
    std:: vector< std:: string > ::iterator ac;
    char munit;
    float mvalue;
    public:
    virtual void update(char,float) override;
    void convert();
    static void *create(void *);
};


#endif
