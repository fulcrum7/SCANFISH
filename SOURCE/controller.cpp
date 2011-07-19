#include "controller.h"



Controller::Controller()
{
	//

}

int Controller::connect(int bitrate,const char *interface,CanListener *lstn)
{
	// create low level IO class
	// TODO: CanIO implementation depends on type of driver
	// Created object will be deleted by cannet
	SocketCanIO *sc=new SocketCanIO(interface);
	// reate cannet
	// TODO: add it to map and create network ID
	cannet= new CanNet(sc,lstn);
	//  threads start
	cannet->start();
	// TODO: use bitrate
	// TODO: return network ID
	return 1;
	

}
int    Controller::disconnect(int netid)
{
	//TODO: using map and netid find exact CanNet
	cannet->stop();
	delete cannet;
	return 0;
}
int    Controller::send(Msg *msg,int netid)
{
	//TODO: using map and netid find exact CanNet
	cannet->write(msg);
	return 0;
}
int    Controller::receive(Msg **msg,int netid)
{
	//TODO: using map and netid find exact CanNet
	cannet->read(msg);
	return 0;

}


Msg *Controller::allocMsg()
{
	return msv.allocMsgContainer();

}
