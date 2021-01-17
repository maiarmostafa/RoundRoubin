#ifndef NODE_H
#define NODE_H
#include "QueueCells.h"
#include "Stack.h"
#include "LinkedListt.h"
using namespace std;

template<class T>
class Node
{
    public:
        public:
        T *Data;
        Node *Prev,*Next;
        T *Qs;

        //Stack<Process> *S;
        //int Index=0;
//        Node(T *data)
//        {
//            Data = data;
//            Next = Prev= NULL;
//            //Index++;
//        }
        Node(T *_Qs)
        {
            Qs=_Qs;
            Next = Prev= NULL;
        }

};

#endif // NODE_H
