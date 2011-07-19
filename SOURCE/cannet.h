#ifndef CANNET_H
#define	CANNET_H


#include "msg.h"
#include "canio.h"
#include <queue>
#include <semaphore.h>
#include <pthread.h>
#include "canlistener.h"


class CanListener;

// Should implement buffer between network and software
class MsgQueue
{
    std::queue<Msg*> mQueue;
    sem_t semaph;
    sem_t s_empty;
public:
    MsgQueue();
    ~MsgQueue();

    Msg* get();
    int put(Msg* msg);

}; 

class CanNet
{
private:
    CanIO *canio;
    MsgQueue rqueue; //reading queue
    MsgQueue wqueue; //writing queue
    pthread_t listenerThread;
    pthread_t writerThread;
    CanListener *lstn;

public:
    CanNet(CanIO *mcanio,CanListener *mlstn);
    ~CanNet();
    int start();
    int stop();
    static void *readingthread(void *unused);
    static void *writingthread(void *unused);
    virtual void reading();
    virtual void writing();
    int write(Msg *msg);
    int read(Msg **msg);
};



#endif	/* CANNET_H */

