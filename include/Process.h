#ifndef PROCESS_H
#define PROCESS_H

using namespace std;
class Process
{
    int min_counter;
    char pc;


    public:
          bool flag;
    Process(char p_n)
    {
        min_counter=0;
        pc=p_n;
        flag = false;
    }
    int get_minC()
    {
        return min_counter;
    }
    char get_pc()
    {
        return pc;
    }

};

#endif // PROCESS_H
