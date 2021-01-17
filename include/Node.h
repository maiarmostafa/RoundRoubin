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
        Node(T *_Qs)
        {
            Data=_Qs;
            Next = Prev= NULL;
        }

};

#endif // NODE_H
