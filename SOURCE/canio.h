#ifndef CANIO_H
#define	CANIO_H

#include "msg.h"

#define INTERFACE_NAME_SIZE 15

class CanIO
{
    int bitrate;
    char name[INTERFACE_NAME_SIZE];
public:
    CanIO(int bitrate,char *interface);
    virtual   int connect()=0;
    virtual   int disconnect()=0;
    virtual   int send(Msg *msg)=0;
    virtual   int receive(Msg *msg)=0;

};


class SocketCanIO : public CanIO
{
    //...
public:
    SocketCanIO();
    int connect();
    int disconnect();
    int send(Msg *msg);
    int receive(Msg *msg);
};

#endif	/* CANIO_H */

