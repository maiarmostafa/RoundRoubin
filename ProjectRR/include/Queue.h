#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

using namespace std;

template<class T>
class Nodee
{
    public:
        T *Data;
        Nodee *Prev,*Next;
        //int Index=0;
        Nodee(T *data)
        {
            Data = data;
            Next = Prev= NULL;
            //Index++;
        }


};




template<class T>
class Queue
{
    Nodee<T> *Head,*Tail;
    int counter;
    public:
        Queue()
        {
            Head=Tail=NULL;
            counter=0;
        }
        void enqueue(T *data)
        {
            Nodee<T> *newnode=new Nodee<T>(data);
            if(Head==NULL)
            {
                Head=Tail=newnode;
                counter++;
            }
            else
            {
                Tail->Next=newnode;
                newnode->Prev=Tail;
                Tail=newnode;
                counter++;
            }
        }
        void dequeue()
        {
            if(Head!=NULL)
            {
                Head=Head->Next;
                Head->Prev=NULL;
                counter--;
            }
            else
            {
                cout<<"No elements";
            }
        }
        void Display()
        {
            Nodee<T> *CURR=Head;
            for(int i=0;i<counter;i++)
            {
                cout<<*CURR->Data<<endl;
                CURR=CURR->Next;

            }
        }
};
#endif // QUEUE_H
