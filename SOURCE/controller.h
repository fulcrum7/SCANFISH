#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include <map>
#include <algorithm>

#include "canio.h"
#include "cannet.h"
#include "msg.h"
#include "canlistener.h"



/*
 *  Creates connections, manages table of nets, is the interface for I/O
 *
 */

class Controller
{

private:
    MsgSuperviser msv; // for msg allocation
	static Controller *singleton; // for Singleton template

private:
    Controller();
public:
// connect() creates new Net and couples it with I/O class, returns NetID
static Controller *getController();
int    connect(int bitrate,const char *interface, CanListener *lstn);
int    disconnect(int netid);// destroys Net
int    send(Msg *msg,int netid);      // is used by GUI to send frames
int    receive(Msg **msg,int netid);   // is used by GUI to receive frames
Msg *allocMsg(); // all Msg objects must be created with this method!!!

typedef std::map <int,CanNet*> netTable;
netTable nettab;
int netCount;
int contrNum;

};

#endif	

