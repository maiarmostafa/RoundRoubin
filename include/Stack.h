#ifndef STACK_H
#define STACK_H

using namespace std;

template<class T>
class Nod
{
    public:
        T *Data;
        Nod *Prev;
        //int Index=0;
        Nod(T *data )
        {

            Data = data;
            Prev= NULL;

            //Index++;
        }



};
template <class T>
class Stack
{


    int counter;
    public: Nod<T> *Top;
        char pc ;
        Stack()
        {
            Top = NULL;
            counter=0;
        }
        Stack(char _pc)
        {
            pc= _pc;
            Top = NULL;
            counter=0;

        }
        bool IsEmpty()
        {
            if(Top == NULL){
            return true;
            }
            return false;

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
                //cout<<CURR->Data->get_user()<<" Done"<<endl;
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

        T* Peek(){
            //Nod<T> *CURR= Top-1;
            if(Top!=NULL)
            return Top->Data;
            else{
                cout<<"exit from stack";
                exit(0);
            }

        }


        void Display()
        {
            Nod<T> *CURR=Top;
            while(CURR != NULL)
            {
                cout<<"pc name   "<< CURR->pc;
                //cout<< " counter  " <<CURR->Data->get_minC()<<endl;
           //  Data=CURR->Data;
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
