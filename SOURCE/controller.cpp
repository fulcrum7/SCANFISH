#include "controller.h"

Controller *Controller::singleton = NULL;

Controller::Controller()
{
    netCount=0;
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
	// create low level IO class
	// TODO: CanIO implementation depends on type of driver
	// Created object will be deleted by cannet
	SocketCanIO *sc=new SocketCanIO(interface);
	// create cannet
	// TODO: add it to map and create network ID
        netTable::iterator it;
        netCount++;
        singleton->nettab.insert(std::pair<int,CanNet*>(netCount,new CanNet(sc,lstn)));
        if ((it=nettab.find(netCount))==nettab.end())
        {
            return -1;
        }
	//  threads start
        if(it->second->start()<0)
	{
		return -1;
	}
	// TODO: use bitrate
	// TODO: return network ID
	return it->first;
}

int    Controller::disconnect(int netid)
{
        CanNet *cannet;
        netTable::iterator it;
        if ((it=nettab.find(netid))==nettab.end())
        {
            return -1;
        }
//	//TODO: using map and netid find exact CanNet
	it->second->stop();
        cannet=it->second;
        nettab.erase(it);
	delete cannet;
        netCount--;
	return 0;
}

int    Controller::send(Msg *msg,int netid)
{
        netTable::iterator it;
        if ((it=nettab.find(netid))==nettab.end())
        {
            return -1;
        }
	//TODO: using map and netid find exact CanNet
	it->second->write(msg);
	return 0;
}

int    Controller::receive(Msg **msg,int netid)
{
        netTable::iterator it;
        if ((it=nettab.find(netid))==nettab.end())
        {
            return -1;
        }
	//TODO: using map and netid find exact CanNet
	it->second->read(msg);
	return 0;
}


Msg *Controller::allocMsg()
{
	return singleton->msv.allocMsgContainer();

}
