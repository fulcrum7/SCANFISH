

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "canio.h"
#include "cannet.h"
#include "msg.h"
#include "controller.h"
#include "pthread.h"
/*
* 
*	This is an example of using Scanfish Generic Classes
*	This simple application listens to the interface which 
*	is set in the first parameter. Program prints all messages
*	that appears in net. In parallel in another thread it
*  	sends fixed frames. They appear also on the screen as soon as appear
*	because vcan is loopback as default.
*
*/




/*
*
*	This class is name GUI because it shows the important properties
*	of the class that uses Scanfish Generic Classes.
*	This class inherits CanLIstener and	
* 	reimplement methods notify and errorInNet
*	It is recommended to use method receive to read from
*	queue in method notify. Notify is an element of observer template. 
*
*/


/*
*	Bitrates and NetID are not supported yet so default values are used 
*
*/



class GUI : public CanListener
{
private:
	Controller *cntr;
public:
	GUI(Controller *mcnrt)
	{
		cntr=mcnrt;
	}

	int connect(const char * str)
	{
		cntr->connect(1,str,this);
	}

	int notify()
	{
		int i;
		printf("Notification is received! New message!\n");
		Msg *msg;
		cntr->receive(&msg,1);

		printf("CAN FRAME: ID: %d DLC: %d DATA: ",
			msg->getID(),msg->getDlc());
		for(i=0;i<msg->getDlc();i++)
		{
			printf("%X",msg->getData(i));
		}
		printf("\n");
		// When you receive a message you are in charge to free it
		msg->setMsgFree();	
		return 0;
	}
	int errorInNet(const char *str)
	{
		return 0;
	}
};

/*
*	This thread sends every 3 sec a frame
*/

void* do_sending(void *unused)
{
	Controller *cntr=(Controller *)unused;
	Msg *msg;
	while(1)
	{
		sleep(3);
		// use this method to allocate Msg!!!
		msg=cntr->allocMsg();
		msg->setID(111);
		msg->setDlc(1);
		msg->setData(0,7);
		cntr->send(msg,1);

	}


}


int main(int argc, char** argv)
{

	if(argc<2)
	{
		printf("Please, input the interface\n ./sf can0\n");
		exit(-1);
	}
	Controller cnt;
	GUI gui(&cnt);
	gui.connect(*(argv+1));
	pthread_t sending_thread;
	pthread_create(&sending_thread,NULL,do_sending,&cnt);
	pthread_join(sending_thread,NULL);

    return (EXIT_SUCCESS);
}

