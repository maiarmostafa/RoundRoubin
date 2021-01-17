#include <iostream>
#include "LinkedListt.h"
#include "QueueCells.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main()
{
    ////////////// users ///////////////
    LinkedListt<QueueCells> LQS;
    LinkedListt<QueueCells> NLQS;
    Queue<QueueCells> q;
    QueueCells *QS;
    int siz,service_time,arrival,interruption,pc_number,minutes,sizofintterup,flag=0;
    string user;
    linked<int> *inters;
    char pc;
    minutes=0;
    cout<<"Enter number of users:   "<<endl;
    cin>>siz;
    for(int i=0 ;i<siz;i++)
    {
        cout<<"Enter user: "<<"    ";
        cin>>user;
        cout<<"Enter number of time: "<<"    ";
        cin>>service_time;
        cout<<"Enter number of arival: "<<"    ";
        cin>>arrival;
        cout<<"Enter number of interuptes accoured: "<<"    ";
        cin>>sizofintterup;
        inters=new linked<int>();
        for(int i=0;i<sizofintterup;i++)
        {

            cout<<"Enter number of interruption: "<<"    ";
            cin>>interruption;
             //QS->add_intrupts(interruption) ;
            inters->ADD(interruption);
        }

        QS=new QueueCells(inters,user,service_time,arrival);
        LQS.Add(QS);
    }

    /////////////// PC /////////////////
    LinkedListt<Stack<QueueCells>> LS;
    cout<<"Enter pc number    ";
    cin>>pc_number;


    for(int i=0;i<pc_number;i++)
    {
        cout<<"Enter pc name    ";
        cin>>pc;
        LS.Add(new Stack<QueueCells>(pc));
    }
    LQS.SelectionSort();
    LQS.Display();
    LS.Display_pc();
    while(flag==0)
    {
        LQS.add_To_queue(&LQS,&LS,&q,minutes);

        LQS.out_pc(&NLQS,&q,&LS,minutes);
        LQS.Check_interr(&q,&LS,minutes);
        LQS.add_To_Pc(&q,&LS,minutes);
        minutes++;
        LQS.change_Service_time(&LQS,&LS,&q,flag,minutes);
//        if(flag==0)
//        {
//            cout<<"min "<<minutes<<endl;
//            //cout<<"counter mn el main"<<NLQS.counter;
//            //NLQS.Display();
//        }

    }


    return 0;
}
