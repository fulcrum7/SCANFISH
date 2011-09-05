

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
*	that appear in net. In parallel in another thread it
*  	sends fixed frames. They are printed also on the screen as soon as appear
*	because vcan is loopback as default.
*
*/




/*
*
*	This class is named GUI because it shows the important properties
*	of the class that uses Scanfish Generic Classes.
*	This class inherits CanLIstener and	
* 	reimplement methods notify and errorInNet
*	It is recommended to use method receive to read from
*	queue in method notify. Notify is an element of observer template. 
*
*/


/*
*	Bitrates and NetID are not supported yet so default values are used 
*	Connect will return NetID.
*/





#define NETID 1
#define BITRATE 1000000

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
		if(cntr->connect(BITRATE,str,this)==-1)
		exit(0);
	}

	int disconnect()
	{
		cntr->disconnect(NETID);
	}

	int notify()
	{
		newMsgHandler();
		return 0;
	}

	int errorInNet(const char *str)
	{
		printf("ERROR: %s\n",str);
		return 0;
	}

	int newMsgHandler()
	{
		int i;
		printf("Notification is received! New message in NET!\n");
		Msg *msg;
		cntr->receive(&msg,NETID);

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

	int sendMsg(int ID,int Dlc,unsigned char *data)
	{
		int i;		
		// We allocate Msg only by means of Controller
		Msg *msg=cntr->allocMsg();

		// We prepare Msg for sending
		msg->setID(ID);
		msg->setDlc(Dlc);
		for(i=0;i<Dlc;i++)
			msg->setData(i,data[i]);

		// We are ready to send

		printf("SF has sent MSG with ID = %d\n",ID);
		cntr->send(msg,NETID);
		// We don't set allocated Msg free  when we send it
		
		return 0;

	}
	
};






/*
*	This thread sends every 3 sec a frame
*/
void* do_sending(void *mgui);


int main(int argc, char** argv)
{

	if(argc<2)
	{
		printf("Please, input the interface\n ./sf can0\n");
		exit(-1);
	}
	Controller *cnt;
	cnt=Controller::getController();
	GUI gui(cnt);
	gui.connect(*(argv+1));
	pthread_t sending_thread;
	pthread_create(&sending_thread,NULL,do_sending,&gui);
	pthread_join(sending_thread,NULL);

    return (EXIT_SUCCESS);
}


void* do_sending(void *mgui)
{
	GUI *gui=(GUI *)mgui;
	int ID=0;
	unsigned char data=0xFF;
	while(1)
	{
		ID++;
		data--;
	
		gui->sendMsg(ID,1,&data);
		sleep(3);

	}


}

