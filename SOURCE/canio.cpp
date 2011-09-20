#include "canio.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>

#include <linux/can.h>
#include <linux/can/raw.h>


CanIO::CanIO(int bitrate,const char *interface)
{
	// bitrate for the future use

	// if interface string is long we will cut it
	if(strlen(interface)>INTERFACE_NAME_SIZE)
	{
		memcpy(name,interface,INTERFACE_NAME_SIZE);
		name[INTERFACE_NAME_SIZE-1]='\0';
	}
	else
	{
    	strcpy(name,interface);	
	}
}


SocketCanIO::SocketCanIO(const char *mname) : CanIO(0,mname)
{


	// for the future use

}

int SocketCanIO::connect()
{


	struct sockaddr_can addr;
	struct ifreq ifr;

	// SOCKET FOR READING

	if ((sdr = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
	{
		//perror("socket");
		return SOCKET_ERROR;
	}

	addr.can_family = AF_CAN;

	strcpy(ifr.ifr_name, name);
	if (ioctl(sdr, SIOCGIFINDEX, &ifr) < 0)
	{
		//perror("SIOCGIFINDEX");
		return SOCK_IOCTL_ERROR;
	}
       
	addr.can_ifindex = ifr.ifr_ifindex;


	if (bind(sdr, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		//perror("bind");
		return SOCK_BINDING_ERROR;
	}

	// SOCKET FOR WRITING

	if ((sdw = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
	{
		//perror("socket");
		return SOCKET_ERROR;
	}
	addr.can_family = AF_CAN;

	strcpy(ifr.ifr_name, name);
	if (ioctl(sdw, SIOCGIFINDEX, &ifr) < 0)
	{
		//perror("SIOCGIFINDEX");
		return SOCK_IOCTL_ERROR;
	}
	addr.can_ifindex = ifr.ifr_ifindex;


	if (bind(sdw, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		//perror("bind");
		return SOCK_BINDING_ERROR;
	}

	return 0;
}

int SocketCanIO::disconnect()
{
	close(sdw);
	close(sdr);
	return 0;
}

int SocketCanIO::send(Msg *msg)
{

	struct can_frame frame;
	int nbytes;
	int i;
	frame.can_id=msg->getID();
	frame.can_dlc=msg->getDlc();
	for(i=0;i<frame.can_dlc;i++)
	{
		frame.data[i]=msg->getData(i);
	}	
	if ((nbytes = write(sdw, &frame, sizeof(frame))) != sizeof(frame))
	{
		//perror("write");
		return SOCK_WRITING_ERROR;
	}
	msg->setMsgFree();
	return 0;
}
int SocketCanIO::receive(Msg **msg)
{
	struct can_frame frame;
	(*msg)=msv.allocMsgContainer();
	int nbytes;
	int i;
	if ((nbytes = read(sdr, &frame, sizeof(frame))) != sizeof(frame))
	{
		//perror("read");
		return SOCK_READING_ERROR;
	}
	(*msg)->fixTime();

	(*msg)->setID(frame.can_id);
	(*msg)->setDlc(frame.can_dlc);
	for(i=0;i<frame.can_dlc;i++)
	{
		(*msg)->setData(i,frame.data[i]);
	}

	// debugging

	/*printf("CAN FRAME: ID: %d DLC: %d DATA: ",frame.can_id,frame.can_dlc);
	for(i=0;i<frame.can_dlc;i++)
	{
		printf("%X",frame.data[i]);
	}
	printf("\n");	*/

	// debugging

	return 0;
}






