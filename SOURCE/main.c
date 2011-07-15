

#include <stdio.h>
#include <stdlib.h>
#include "canio.h"
#include "cannet.h"
#include "msg.h"
#include "controller.h"
/*
 * 
 */
int main(int argc, char** argv)
{

	MsgSuperviser msv;
	SocketCanIO sc("can0");
	Msg *ptr;

	sc.connect();
	ptr=msv.allocMsgContainer();
	
	ptr->setID(777);
	sc.send(ptr);
	//while(1) sc.receive(ptr);
	sc.disconnect();	
	ptr->setMsgFree();
    return (EXIT_SUCCESS);
}

