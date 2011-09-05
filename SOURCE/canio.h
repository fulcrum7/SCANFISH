#ifndef CANIO_H
#define	CANIO_H

#include "msg.h"
#include "sferror.h"

#define INTERFACE_NAME_SIZE 15

class CanIO
{

protected:
    int bitrate;
    char name[INTERFACE_NAME_SIZE];
    MsgSuperviser msv;
public:
    CanIO(int bitrate,const char *interface);
    virtual   int connect()=0;
    virtual   int disconnect()=0;
    virtual   int send(Msg *msg)=0;
    virtual   int receive(Msg **msg)=0;

};


class SocketCanIO : public CanIO
{

private:
	int sdw;	// socket descriptor write
	int sdr;	// socket descriptor read
public:
    SocketCanIO(const char *name);
    int connect();
    int disconnect();
    int send(Msg *msg);
    int receive(Msg **msg); 

};

#endif	/* CANIO_H */

