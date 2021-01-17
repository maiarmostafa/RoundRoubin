#ifndef QUEUECELLS_H
#define QUEUECELLS_H
#include "linked.h"
#include "LinkedListt.h"
using namespace std;
class QueueCells
{
  int arrival,service_time;
  int interruption;
  string user;
  int startTime=-1; // if condition if hya et8yrt
  int endTime=-1 ;
  int Enters=0;
  int waiting_time=0;
  int siz;
     public:
         int servic;
        // LinkedListt<int> t;
        linked<int> *interruption2 ;
        QueueCells(linked<int> *_interruption2,string _user="",int _service_time=0,int _arival=0 , int sizInterr=0 )
        {
            servic=_service_time;
            arrival=_arival;
            service_time=_service_time;
            //interruption=_interruption;
            user=_user;
            siz=sizInterr;
            interruption2 = new linked<int>();

            for(int i= 0  ; _interruption2->counter!=0 ; i++)
            {
             interruption2->ADD(_interruption2->GET(i));
             _interruption2->counter=_interruption2->counter-1;

            //_interruption2[i].HEAD=_interruption2[i].HEAD->NEXT;
            }
              _interruption2->HEAD =_interruption2->LAST=NULL;

        }

        void set_arrival(int a){arrival=a;}
        int get_arival()
        {
            return arrival;
        }
        void set_service_time(int s){service_time=s;}
        int get_service_time()
        {
            return service_time;
        }
        void set_user(string u){user=u;}
        string get_user()
        {
            return user;
        }
        void set_endTime(int e){endTime=e;}
        int get_endTime()
        {
            return endTime;
        }
        void set_startTime(int e){startTime=e;}
        int get_startTime()
        {
            return startTime;
        }
        void set_waiting_time(int e){waiting_time=e;}
        int get_waiting_time()
        {
            return waiting_time;
        }
        int get_interruption()
        {
           return interruption;
        }
        void set_Enters(int e){Enters=e;}
        int get_Enters(){return Enters;}
};

#endif // QUEUECELLS_H
