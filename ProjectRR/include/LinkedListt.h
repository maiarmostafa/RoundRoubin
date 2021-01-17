#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H
#include "Node.h"
#include "QueueCells.h"
//#include "Stack.h"
#include "Process.h"
#include "Queue.h"
using namespace std;

template<class T>
class LinkedListt
{
    Node<T> *Head,*Tail;

    //Stack<Process> S;
    int counter=0;
    public:
        QueueCells *Qs;
    LinkedListt()
    {
        Head = Tail = NULL;
    }
    void  add_To_queue(LinkedListt<QueueCells> *qs,int Size,int time)
{
    Queue<QueueCells> q;
LinkedListt<QueueCells> *curr=qs->Head;
while(curr!=NULL){
        for(int i=0;i<Size;i++)
        {
            if(qs->Qs->get_arival()==time)
            {
                q.enqueue(qs->Qs);
                //qs->DeleteByIndex(i);
               curr=curr->Next;
                cout<<"Done";
            }
        }
        time++;
}
}

    void Add(T *data)
    {
        //Node newnode(data); XXX we want to declare it in heap scope.
        Node<T> *newnode=new Node<T>(data);
        if(Head == NULL)
        {
            Head = Tail = newnode;
            counter++;
            //cout<<"insert on head"<<endl;
        }
        else
        {
            Tail->Next=newnode;
            newnode->Prev=Tail;
            Tail = newnode;
            counter++;
            //cout<<"insert after head"<<endl;
        }
       // cout<<"counter"<<counter<<endl;

    }
    void Display()
    {
        Node<QueueCells> *curr=Head;
        while(curr!=NULL)
        {
            //cout<< curr->Qs->user<<endl;
            cout<<"User  "<<curr->Qs->get_user()<<"   ";
            cout<<"arival is: "<<curr->Qs->get_arival()<<"   ";
            cout<<"service time is: "<<curr->Qs->get_service_time()<<"   ";
            cout<<"interruption is: "<<curr->Qs->get_interruption()<<"   ";
            cout<<"\n ------------"<<endl;
            curr=curr->Next;
        }

    }
//    void Display_pc()
//    {
//        Node<Stack<Process>> *curr=Head;
//        while(curr!=NULL)
//        {
//            //cout<< curr->Qs->user<<endl;
//            cout<<"PC  "<<curr->Data->get_pc()<<"   ";
//            cout<<"\n ------------"<<endl;
//            curr=curr->Next;
//        }
//    }
    void Delete(T *data)
    {
        Node<T> *pDelete=Search(data);
        if(pDelete==NULL)
            return;
        if(pDelete ==Head)
        {
            if(pDelete == Tail)
            {
                Head = Tail = NULL;
                counter--;
            }else
            {
                Head=Head->Next;
                Head->Prev=NULL;
                counter--;

            }

        }
        else if(pDelete == Tail)
        {
            Tail=Tail->Prev;
            Tail->Next=NULL;
            counter--;
        }else
        {
            pDelete->Next->Prev=pDelete->Prev;
            pDelete->Prev->Next=pDelete->Next;
            counter--;
        }
        delete pDelete;
    }
    void InsertAfter(T *afterData,T *newData)
    {
        Node<T> *pInsert=Search(afterData);
        Node<T> *pNew=new Node<T>(newData);
        if(afterData == Head->Data)
        {
            pInsert->Prev=pNew;
            pNew->Next=pInsert;
            Head=pNew;
            counter++;

        }
        else if(pInsert->Next==NULL)
        {
            Add(newData);
        }
        else
        {
            pNew->Next=pInsert->Next;
            pNew->Prev=pInsert;
            pInsert->Next->Prev=pNew;
            pInsert->Next=pNew;
            counter++;
        }

    }
    void Reverse()
    {
        Node<T> *pNew=Head;
            Head=Tail;
            Tail=pNew;
            Node<T> *newNode=Head;

            while(newNode !=NULL)
            {
                pNew=newNode->Next;
                newNode->Next=newNode->Prev;
                newNode->Prev=pNew;
                newNode=newNode->Next;
            }
    }
    void DeleteByIndex(int index)
    {
        if(Head==NULL)
            return;
        else if(index==0)
        {
            Head=Head->Next;
            counter--;
        }
        else{
            Node<T> *curr=Head;
            for(int i=0;i<index;i++)
            {
                if(index<=counter)
                {
                    curr=curr->Next;
                    //counter--;
                }
                else{
                    cout<<"index not found"<<endl;
                    return;
                }
            }
            Delete(curr->Data);
        }
    }
    private:
    Node<T> *Search(T *data)
    {
        Node<T> *curr=Head;
        while(curr !=NULL)
        {
            if(curr->Data == data)
                return curr;
            curr=curr->Next;
        }
        return NULL;
    }

};

#endif // LINKEDLISTT_H
