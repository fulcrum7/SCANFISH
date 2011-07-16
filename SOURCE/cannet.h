#ifndef CANNET_H
#define	CANNET_H


#include "msg.h"
#include "canio.h"
#include <queue>
#include <semaphore.h>

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
public:
    CanNet(CanIO *mcanio);
    int start();
    int stop();
    void readingthread(void);
    void writingthread(void);
    int write(Msg *msg);
    int read(Msg *msg);
};



#endif	/* CANNET_H */

