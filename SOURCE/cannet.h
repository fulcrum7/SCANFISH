#ifndef CANNET_H
#define	CANNET_H


#include "msg.h"
#include "canio.h"


// Should implement buffer between network and software
class MsgQueue
{
    int size;
public:
    MsgQueue(int size);
    int get(Msg *msg);
    int put(Msg *msg);
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

