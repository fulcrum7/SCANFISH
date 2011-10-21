#include "controller.h"

Controller *Controller::singleton = NULL;

Controller::Controller()
{
    imap=0;
	//	for the future use

}

Controller *Controller::getController()
{
	if(singleton==NULL)
	{
		singleton=new Controller();
	}
	return singleton;
}

int Controller::connect(int bitrate,const char *interface,CanListener *lstn)
{
        std::map <int,CanNet*> netTable;
	// create low level IO class
	// TODO: CanIO implementation depends on type of driver
	// Created object will be deleted by cannet
	SocketCanIO *sc=new SocketCanIO(interface);
	// create cannet
	// TODO: add it to map and create network ID

	netTable[imap]=singleton->cannet= new CanNet(sc,lstn);
        imap++;

	//  threads start
	if(singleton->cannet->start()<0)
	{
		return -1;
	}
	// TODO: use bitrate
	// TODO: return network ID
	return 3;
}

int    Controller::disconnect(int netid)
{
	//TODO: using map and netid find exact CanNet
	singleton->cannet->stop();
	delete singleton->cannet;
	return 0;
}

int    Controller::send(Msg *msg,int netid)
{
	//TODO: using map and netid find exact CanNet
	singleton->cannet->write(msg);
	return 0;
}

int    Controller::receive(Msg **msg,int netid)
{
	//TODO: using map and netid find exact CanNet
	singleton->cannet->read(msg);
	return 0;

}


Msg *Controller::allocMsg()
{
	return singleton->msv.allocMsgContainer();

}
