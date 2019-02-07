#include"mainController.h"
#include<fstream>
#include<iostream>
#include<ostream>
#include<iterator>
#include"temperatureMonitor.h"
#include"acMonitor.h"
using namespace std;

  /*void MainController::GenerateOutput()
         {
                 cout << "                                " << endl;
                  cout << "................................" << endl;
                  cout << "                                " << endl;
                  //cout << "threads for output" << endl;
                  //pthread_create(&p1,createForTemp,(void*)(this));
                  //pthread_join(p1,NULL);
          //      pthread_create(&p_id[1],NULL,createForAc,(void *)(this));
                  // pthread_join(p_id[1],NULL);
          }*/





/******** function for creating thread to write temperature Monitor data into a file ***********/

/*void *MainController::createForTemp(void *ptr)
{
	MainController *ptr1=static_cast <MainController *>(ptr);
//	ptr1->writeTempData();
	 fstream output;
        vector<pair<float,char>>::iterator it;
	//ptr1->t_temp->tempMonitor;
        output.open("example.txt",fstream :: app | fstream :: out);
        for(it=ptr1->mTempMonPtr->tempMonitor.begin();it!=ptr1->mTempMonPtr->tempMonitor.end();it++)
        {
                output<<(*(it)).first << "...";
                if(((*(it)).second)=='f'||((*(it)).second)=='F')
                output << "converted from F to C" << endl;
                else
                output << "converted from C to F" << endl;
        }


	return 0;
}*/


/******** function for creating thread to write AC Monitor data into a file ***********/

/*void *MainController::createForAc(void *ptr)
{
	 MainController *ptr1=static_cast <MainController *>(ptr);
        ptr1->writeAcData();
        return 0;
}*/

/********** function for writing temperature Monitor data into a file ****************/

/*void MainController::writeTempData( )
{
	 fstream output;
        vector<pair<float,char>>::iterator it=t_temp->tempMonitor;
        output.open("example.txt",fstream :: app | fstream :: out);
        for(it=t_temp->tempMonitor.begin();it!=t_temp->tempMonitor.end();it++)
        {
                output<<(*(it)).first << "...";
                if(((*(it)).second)=='f'||((*(it)).second)=='F')
                output << "converted from F to C" << endl;
                else
                output << "converted from C to F" << endl;
        }

	
}*/

/********** function for writing AC Monitor data into a file ****************/

/*void MainController::writeAcData()
{
	vector<string> :: const_iterator itr;
	
	for (itr=acMonitor.begin();itr!=acMonitor.end();itr++)
	{
		cout << *itr << endl;
	}
}*/

   
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





















