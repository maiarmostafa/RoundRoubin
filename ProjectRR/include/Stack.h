#ifndef STACK_H
#define STACK_H
#include "Process.h"
using namespace std;

template<class T>
class Nod
{
    public:
        Process *Data;
        Nod *Prev;
        //int Index=0;
        Nod(T *data)
        {
            Data = data;
            Prev= NULL;
            //Index++;
        }


};
template <class T>
class Stack
{

    Nod<T> *Top;
    int counter;
    public:
        Stack()
        {
            Top = NULL;
            counter=0;
        }
        void push(T *data)
        {
            Nod<T> *newnode=new Nod<T>(data);
            if(Top==NULL)
            {
                //newnode->Data=data;
                Top=newnode;
                counter++;
                //cout<<*newnode->Data<<"   "<<counter<<endl;
            }
            else
            {
                newnode->Prev=Top;
                Top=newnode;
                Top->Data=data;
                counter++;
                //cout<<*Top->Data<<"   "<<counter<<endl;
            }
        }
        void pop()
        {
            Nod<T> *CURR=Top;
            if(Top != NULL)
            {
                cout<<*CURR->Data<<"Done"<<endl;
                Top=Top->Prev;
                CURR->Prev=NULL;
                counter--;
            }
            else
            {
                cout<<"No data"<<endl;
                return;
            }
            delete CURR;
        }
        int get_length()
        {
            return counter;
        }
        void Display()
        {
            Nod<T> *CURR=Top;
            while(CURR != NULL)
            {
                cout<<"pc name   "<< CURR->Data->get_pc();
                cout<< " counter  " <<CURR->Data->get_minC()<<endl;
                //Data=CURR->Data;
                CURR = CURR->Prev;
            }
            if (Top == NULL)
            {
                cout << "\nStack Underflow" << endl;
                return;
            }
        }
};
#endif // STACK_H
