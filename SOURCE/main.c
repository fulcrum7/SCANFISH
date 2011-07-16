

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	CanNet cn(&sc);	
	sc.connect();
	ptr=msv.allocMsgContainer();

	ptr->setID(777);
	ptr->setDlc(3);
	//cn.write(ptr);
	sc.send(ptr);	
	//while(1) sc.receive(ptr);
	//sc.disconnect();	
	//ptr->setMsgFree();

	sleep(15);

    return (EXIT_SUCCESS);
}

