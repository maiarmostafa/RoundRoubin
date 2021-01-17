#ifndef LINKEDLISTT_H
#define LINKEDLISTT_H
#include "Node.h"
#include "QueueCells.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

template<class T>
class LinkedListt
{
    Node<T> *Head,*Tail;


public:
    int counter=0;
    LinkedListt()
    {
        Head = Tail = NULL;
    }

    void  add_To_queue(LinkedListt<QueueCells> *qs,LinkedListt<Stack<QueueCells>> *LQSS,Queue<QueueCells> *q,int time)
    {

        int siz = qs->counter ;

        for(int i=0; i<siz; i++)
        {
//            cout<<"i    "<<i;
//            cout<<"time   "<<time<<endl;
            if(qs->counter != 0)
            {
                if(qs->getElementByIndex(0)->get_arival()==time)
                {
                    q->enqueue(qs->getElementByIndex(0));
                    qs->DeleteByIndex(0);
                    //cout<<" Add_To_queue"<<endl;
                }
            }


        }


//Check_interr(q,LQSS,time);
//cout<<"------";
//cout <<siz<<endl;

    }

    void out_pc(LinkedListt<QueueCells> *qs,Queue<QueueCells> *q,LinkedListt<Stack<QueueCells>> *LQSS,int minu)
    {
        for(int i=0; i<LQSS->counter; i++)
        {
            if(!LQSS->getElementByIndex(i)->IsEmpty())
            {
                if(LQSS->getElementByIndex(i)->Peek()->get_endTime()==minu)
                {
                    int x=LQSS->getElementByIndex(i)->Peek()->get_startTime();
                    int y=LQSS->getElementByIndex(i)->Peek()->get_arival();
                    int z=LQSS->getElementByIndex(i)->Peek()->get_endTime();
                    int o=LQSS->getElementByIndex(i)->Peek()->servic;
                    //LQSS->getElementByIndex(i)->Peek()->set_waiting_time(((x)-(y))+(minu-(z)));
                    LQSS->getElementByIndex(i)->Peek()->set_waiting_time(z-y-o);
                    //cout<<"user "<<LQSS->getElementByIndex(i)->Peek()->get_user()<<" wait: "<<LQSS->getElementByIndex(i)->Peek()->get_waiting_time()<<endl;
                    qs->Add(LQSS->getElementByIndex(i)->Peek());
                    for(int i=0;i<qs->counter;i++)
                    {
                        cout<<"                ----------------------------              "<<endl;
                        cout<<"                        Final     Report              "<<endl;
                        cout<<"                ----------------------------              "<<endl;
                        cout<<"User  "<<qs->getElementByIndex(i)->get_user()<<"   ";
                        cout<<"Start at  "<<qs->getElementByIndex(i)->get_startTime()<<"   ";
                        cout<<"End at    "<<qs->getElementByIndex(i)->get_endTime()<<"   ";
                        cout<<"Number of waiting time "<<qs->getElementByIndex(i)->get_waiting_time()<<"   ";
                        cout<<"Time in PC "<<(qs->getElementByIndex(i)->get_waiting_time()+o)<<"   ";
                        cout<<"Number of Enters is    "<<qs->getElementByIndex(i)->get_Enters()<<endl;
                        qs->DeleteByIndex(0);
                        cout<<"------------------------------------------------------"<<endl;
                    }

                    LQSS->getElementByIndex(i)->pop();
                    //cout<<"user out  "<<endl;
                }
            }
        }
    }
    void Check_interr(Queue<QueueCells> *q,LinkedListt<Stack<QueueCells>> *LQSS,int minu)
    {
        int j=0;
        //cout<<"interrrrr counter"<<LQSS->getElementByIndex(j)->Peek()->interruption2->counter<<endl;
        for(int w=0; w<LQSS->counter; w++)
            if(!LQSS->getElementByIndex(w)->IsEmpty())
                if(LQSS->getElementByIndex(w)->Peek()->interruption2->counter!=0)
                {

//                    cout<<"                                                  inter counter in if"<<LQSS->getElementByIndex(w)->Peek()->interruption2->counter<<endl;
//                    cout<<"j       "<<j<<endl;
//                    cout<<"w       "<<w<<endl;
                    if(minu==(LQSS->getElementByIndex(w)->Peek()->interruption2->GET(j)))
                    {
                        //cout<<"counterrrrrrrrrrrrrrrrrrrr iterrrrrrrrrr----------"<< LQSS->getElementByIndex(w)->Peek()->interruption2->counter <<endl;
                        LQSS->getElementByIndex(w)->Peek()->interruption2->Delete();
                        //cout<<"                                                  intert after peek"<<q->counter<<endl;
                        q->enqueue(LQSS->getElementByIndex(w)->Peek());
                        //cout<<"counter el interr  "<<LQSS->getElementByIndex(w)->Peek()->interruption2->counter<<endl;                        //cout<<" gg           "<<LQSS->getElementByIndex(j)->Peek()->interruption2->GET(j);
                        LQSS->getElementByIndex(w)->pop();
                        //cout<<"poped from interr fun"<<endl<<endl;
                    }
                }

    }

    void add_To_Pc(Queue<QueueCells> *q,LinkedListt<Stack<QueueCells>> *LQSS,int minu)
    {
        for(int i=0; i<LQSS->counter; i++)
        {
            if(!q->isempty())
            {
                if(LQSS->getElementByIndex(i)->IsEmpty())
                {
                    if(q->peak()->get_arival()<=minu)
                    {
                        q->peak()->set_endTime(minu+q->peak()->get_service_time());
                        q->peak()->set_Enters(q->peak()->get_Enters()+1);

                        if((q->peak()->get_startTime())==-1)
                        {
                            q->peak()->set_startTime(minu); // 0->5 5-0 = 5
                        }

                    }
                    //else{q->peak()->set_waiting_time(q->peak()->get_waiting_time()+1);}
                    int diff = minu - q->peak()->get_arival() ;//q->peak()->get_startTime() ;
                    int cou=q->peak()->interruption2->counter;
                    if(diff)
                    {
                        if(cou!=0)
                        {
                            for(int i=0; i<cou ; i++)
                            {
                                //cout<<"hnaaa                 add to pc :("<<i<<"  i  cou "<<cou<<"   "<<q->peak()->interruption2->GET(i)<<endl;
                                q->peak()->interruption2->SET(i,(diff+(q->peak()->interruption2->GET(i))));
                                //cout<<"inter new for "<<q->peak()->get_user()<<" is: "<<q->peak()->interruption2->GET(i)<<endl;
                            }
                        }
                    }
//                    else
//                    {
//                        for(int i=0; i<cou ; i++)
//                            cout<<"inter not change for "<<q->peak()->get_user()<<" is: "<<q->peak()->interruption2->GET(i)<<endl;
//                    }

                   // cout<<"end time after change "<<q->peak()->get_endTime()<<endl;
                    //cout<<"start time after change "<<q->peak()->get_startTime()<<endl;
                    //cout<<"first if "<<endl;

                    LQSS->getElementByIndex(i)->push(q->peak());
                    //cout<<"after push  "<<endl;

                    q->dequeue();
                    //cout<<"add-to-pc  "<<endl;
                }
//                else
//                {
//                    cout<<"PC is Full"<<endl;
//                }
            }
        }

        //cout<<"end pc exe";

    }


    void change_Service_time(LinkedListt<QueueCells> *qs,LinkedListt<Stack<QueueCells>> *LQSS,Queue<QueueCells> *q,int &flag,int &minu)
    {
        int countt=0;
        for(int i=0; i<LQSS->counter; i++)
        {
            if(LQSS->getElementByIndex(i)->IsEmpty())
            {
                if(qs->counter==0 && q->counter==0)
                {
                    countt++;
                }

            }
            else
            {
               LQSS->getElementByIndex(i)->Peek()->set_service_time(LQSS->getElementByIndex(i)->Peek()->get_service_time()-1);
            }
        }
        if(countt==(LQSS->counter))
        {
            minu--;
            flag=1;
            cout<<"Time System = "<<minu<<endl;
        }
    }


    void SelectionSort()
    {
        Node<T>* FIndex=Head;
        Node<T>* CURR;
        Node<T>* AFterCURR;
        for(int coun = 0; coun < counter - 1 && FIndex!=NULL; coun++)
        {
            CURR=FIndex;
            AFterCURR = FIndex->Next;

            for(int index=0 ; index < counter && AFterCURR !=NULL; index++)
            {
                if((CURR->Data->get_arival()) > (AFterCURR->Data->get_arival()))
                    CURR = AFterCURR;

                AFterCURR = AFterCURR->Next;
            }

            Swap(FIndex, CURR);
            FIndex=FIndex->Next;
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
            cout<<"User  "<<curr->Data->get_user()<<"   ";
            cout<<"arival is: "<<curr->Data->get_arival()<<"   ";
            cout<<"service time is: "<<curr->Data->get_service_time()<<"   ";
            //cout<<"interruption is: "<<curr->Data->get_interruption()<<"   ";
            for(int i=0; i<curr->Data->interruption2->counter; i++)
            {
                cout<<"counter "<<curr->Data->interruption2->counter<<endl;
                //if(curr->Data->interruption2.LAST->NEXT != NULL)
                {
                    cout<<"interruption List is: "<<curr->Data->interruption2->GET(i)<<"   ";
                }
            }

            cout<<"\n ------------"<<endl;
            curr=curr->Next;
        }

    }
    void Display_pc()
    {
        Node<Stack<QueueCells>> *curr=Head;
        while(curr!=NULL)
        {
            //cout<< curr->Qs->user<<endl;
            cout<<"PC  "<<curr->Data->pc<<"   ";
            cout<<"\n ------------"<<endl;
            curr=curr->Next;
        }
    }
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
            }
            else
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
        }
        else
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
        else
        {
            Node<T> *curr=Head;
            for(int i=0; i<index; i++)
            {
                if(index<=counter)
                {
                    curr=curr->Next;
                    //counter--;
                }
                else
                {
                    cout<<"index not found"<<endl;
                    return;
                }
            }
            Delete(curr->Data);
        }
    }

    T *getElementByIndex(int index)
    {

        Node<T> *  pDelete=Head;
        int counter = 0;
        if(index<0)
        {
            cout<<"invalid index. linked";
            cout<<endl;
            exit(0);
        }

        while(counter!=index)
        {
            pDelete=pDelete->Next;
            counter++;
            if(pDelete==NULL)
            {
                cout<<"invalid index. linkeddddd";
                cout<<endl;
                exit(0);
            }
        }

        return pDelete->Data;
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
    void Swap(Node<T>* fdata,Node<T>* Sdata)
    {
        T* temp;
        temp=fdata->Data;
        fdata->Data = Sdata->Data;
        Sdata->Data =  temp;

    }


};

#endif // LINKEDLISTT_H
