#ifndef LINKED_H
#define LINKED_H

template<class L>
struct NODE {
  NODE<L>* NEXT;
  L DATA;
};

template<class L>
class linked
{
public:
  NODE<L>* HEAD;
  NODE<L>* LAST;
  int counter=0;
  linked<L>() {
    HEAD = NULL;
    LAST = NULL;
    counter=0;
  }
  void ADD(L DATA) {
    if(!HEAD) {
      // WHEN THERE IS NO ELEMENT IN THE LIST
      HEAD = new NODE<L>;
      HEAD->DATA = DATA;
      HEAD->NEXT = NULL;
      LAST = HEAD;
      counter++;
    } else {
      // WHEN THE LIST IS NOT EMPTY
      if(LAST == HEAD) {
        // WHEN THE LIST HAS ONE ELEMENT
        LAST = new NODE<L>;
        LAST->DATA = DATA;
        LAST->NEXT = NULL;
        HEAD->NEXT = LAST;
      } else {
        // WHEN THE LIST HAS MORE THAN ONE ELEMENT
        NODE<L>* INSDATA = new NODE<L>;
        INSDATA->DATA = DATA;
        INSDATA->NEXT = NULL;
        LAST->NEXT = INSDATA;
        LAST = INSDATA;
      }
      counter++;
    }
  }
  L GET(int INDEX) {
    if(INDEX == 0) {
      // RETURNING THE HEAD ELEMENT
      return this->HEAD->DATA;
    } else {
      // GET THE INDEX'TH ELEMENT
      NODE<L>* CURR = this->HEAD;
      for(int I = 0; I < INDEX; ++I) {
        CURR = CURR->NEXT;
      }
      return CURR->DATA;
    }
  }
  L operator[](int INDEX) {
    return GET(INDEX);
  }

  void SET(int INDEX,int Data) {
    if(INDEX == 0) {
      // RETURNING THE HEAD ELEMENT
      this->HEAD->DATA=Data;
    } else {
      // GET THE INDEX'TH ELEMENT
      NODE<L>* CURR = this->HEAD;
      for(int I = 0; I < INDEX; ++I) {
        CURR = CURR->NEXT;
      }
      CURR->DATA=Data;
    }
  }

    void Delete()
    {
        NODE<L> *pCurrent = HEAD;
      //  NODE<L> *prev=NULL;
        if(HEAD == NULL)
            return;
        if(pCurrent == LAST)
        {
            HEAD = LAST = NULL;

        }
        else
        {
           //pCurrent->NEXT=NULL;
            HEAD = pCurrent->NEXT;
        }
        //cout<< "linked data eli hya interrupt w 3la allah ::"<< pCurrent->DATA<<endl ;
        counter--;

        delete pCurrent;
    }


};
#endif // LINKED_H


// DECLARING LINKED LIST CLASS


