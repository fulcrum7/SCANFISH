#ifndef CONTROLLER_H
#define	CONTROLLER_H


#include "canio.h"
#include "cannet.h"
#include "msg.h"

/*
 *  Creates connections, manages table of nets, is the interface for I/O
 *
 */

class NetRecord
{
    int  netID;
    CanNet * net;
    NetRecord(int id,CanNet *net);

};

class NetList
{
    //manages table of NetRecord
};

class Controller
{
private:
    NetList table;   // list of nets

public:
    Controller();

// connect() creates new Net and couples it with I/O class, returns NetID
// returns NetID
int    connect(int bitrate,char *interface);
int    disconnect(int netid);// destroys Net
int    send(Msg *msg,int netid);      // is used by GUI to send frames
int    receive(Msg *msg,int netid);   // is used by GUI to receive frames

};



#endif	

