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

    public:    Nodee<T> *Head,*Tail;
int counter;


        Queue()
        {
            Head=Tail=NULL;
            counter=0;
        }
        void enqueue(T *data)
        {
            Nodee<T> *newNode = new Nodee<T>(data);

            if(Head == NULL)
            {
                Head = Tail = newNode;
                //cout<<"enque first      "<<newNode->Data->get_user()<<endl;
            }
            else
            {
                Tail->Next = newNode;
                newNode->Prev = Tail;
                Tail = newNode;
                //cout<<"enque sec      "<<newNode->Data->get_user()<<endl;
            }
            counter++;
        }


    void dequeue()
    {
        Nodee<T> *pCurrent = Head;
        if(Head == NULL)
            return;
        if(pCurrent == Tail)
        {
            Head = Tail = NULL;
        }
        else
        {
            pCurrent->Next->Prev=NULL;
            Head = pCurrent->Next;
        }
        counter--;
        delete pCurrent;
    }
    bool isempty()
    {
        if(Tail==NULL)
            return true;
        return false;
    }
    T *peak()
    {
        if(Head!=NULL)
        return Head->Data;
        else
        {
            cout<<"exit from queue";
            exit(0);
        }

    }
        void Display()
        {
            Nodee<T> *CURR=Head;
            if(CURR!=NULL)
            {
                for(int i=0;i<counter;i++)
                {
                    cout<<CURR->Data->user<<endl;
                    CURR=CURR->Next;

                }
            }
            else
                {
                    cout<<"No element to display";
                }
        }
};
#endif // QUEUE_H
