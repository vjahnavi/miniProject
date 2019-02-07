#ifndef SUBJECT_H
#define SUBJECT_H
class observer;
class subject
{
public:
   
	virtual void subscribe(observer *myobserver)=0;
   virtual  void unsubscribe( observer *myobserver)=0;
 };
#endif

