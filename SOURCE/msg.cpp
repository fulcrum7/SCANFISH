#include "msg.h"
#include <stdio.h>

/*******************************************************************************
*				class MsgSuperviser
*******************************************************************************/

MsgSuperviser::MsgSuperviser()
{
	pthread_mutex_init(&mutex,NULL);
}

MsgSuperviser::~MsgSuperviser()
{
	// free all allocated resources
	int i;

	for(i=0;i<valloc.size();i++)
		delete valloc[i];

	pthread_mutex_destroy(&mutex);
}

Msg *MsgSuperviser::allocMsgContainer()
{
	Msg *ptr;
	int size;
	// mutex down
	pthread_mutex_lock(&mutex);
	size=vfree.size();
	if(size>0)
	{	
		// we can take one of free containers
		ptr=vfree[size-1];
		vfree.pop_back();
	}
	else
	{
		// we should allocate new container
		ptr= new Msg(this);
		// add container to allocated resources
		valloc.push_back(ptr);
	}
	// mutex up
//	printf("Pointer:%p\n",this);
//	printf("VFREE = %d \n",vfree.size());
//	printf("VALLOC = %d \n",valloc.size());
	pthread_mutex_unlock(&mutex);


	return ptr;
}

void MsgSuperviser::setFree(Msg *msg)
{
	Msg *ptr=msg;
	// mutex down
	pthread_mutex_lock(&mutex);
	vfree.push_back(ptr);
//	printf("Pointer freeing:%p\n",this);
//	printf("VFREE = %d \n",vfree.size());
//	printf("VALLOC = %d \n",valloc.size());
	// mutex up
	pthread_mutex_unlock(&mutex);
}




/*******************************************************************************
*				class Msg
*******************************************************************************/



Msg::Msg(MsgSuperviser *msv)
{
	// Msg knows its superviser
	sv=msv;
}


int Msg::setID(unsigned int mid)
{
	id=mid;
	return 0;
}

unsigned int Msg::getID()
{
	return id;
}

int Msg::setDlc(unsigned int mdlc)
{
	dlc=mdlc;
	return 0;
}

unsigned int Msg::getDlc()
{
	return dlc;
}

int Msg::setData(unsigned int num,unsigned char mdata)
{
	if(num>7)
	{
		return -1;
	}

	data[num]=mdata;
	return 0;
}

unsigned char Msg::getData(unsigned int num)
{
	if(num>7)
	{
		return -1;
	}
	
	return data[num];
}

int Msg::getStatus()
{
	return status;
}

void Msg::setStatus(int st)
{
	status=st;
}

void Msg::setMsgFree()
{
	sv->setFree(this);
}
