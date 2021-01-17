#ifndef QUEUECELLS_H
#define QUEUECELLS_H

using namespace std;
class QueueCells
{
    int arrival,service_time,interruption;
    string user;
    public:

        QueueCells(string _user="",int _service_time=0,int _arival=0,int _interruption=0)
        {
            arrival=_arival;
            service_time=_service_time;
            interruption=_interruption;
            user=_user;
        }
        int get_arival()
        {
            return arrival;
        }
        int get_service_time()
        {
            return service_time;
        }
        string get_user()
        {
            return user;
        }
        int get_interruption()
        {
            return interruption;
        }
};

#endif // QUEUECELLS_H
