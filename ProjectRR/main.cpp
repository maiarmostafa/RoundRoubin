#include <iostream>
#include "LinkedListt.h"
#include "QueueCells.h"
#include "Process.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;



int main()
{
    ////////////// users ///////////////
    LinkedListt<QueueCells> LQS;
    QueueCells *QS;
    int siz,service_time,arrival,interruption,pc_number,minutes;
    string user;
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
        cout<<"Enter number of interruption: "<<"    ";
        cin>>interruption;
        QS=new QueueCells(user,service_time,arrival,interruption);
        LQS.Add(QS);
    }
    LQS.Display();
    /////////////// PC /////////////////
    Process *p;
    Stack<Process> s;
    //LinkedListt<Stack> LS;
    cout<<"Enter pc number    ";
    cin>>pc_number;

    for(int i=0;i<pc_number;i++)
    {
        cout<<"Enter pc name    ";
        cin>>pc;
        p=new Process(pc);
        s.push(p);
        //LS.Add(s);
    }
   LQS.add_To_queue(&LQS,siz,minutes);
    //s.Display();
    return 0;
}
