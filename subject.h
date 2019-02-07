/**************************************************************************************************************************************************************************************

****   Author: Jahnavi Vennapusa                                                                                                                                                   ****

****   File: subject.h                                                                                                                                                           ****

****   Date: 7 February 2019                                                                                                                                                       ****
 
**********************************    END    *****************************************************************************************************************************************/



#ifndef SUBJECT_H
#define SUBJECT_H
class observer; //forward declaration of class 
class subject
{
    public:
    virtual void subscribe(observer *myobserver)=0;
    virtual  void unsubscribe( observer *myobserver)=0;
 };
#endif

