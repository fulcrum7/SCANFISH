#include "cannet.h"
#include<stdio.h>
#include <unistd.h>



/*******************************************************************************
*				CanNet
*******************************************************************************/
 CanNet::CanNet(CanIO *mcanio,CanListener *mlstn)
{
	canio=mcanio;
	lstn=mlstn;	

}

 CanNet::~CanNet()
{
	delete canio;

}

int CanNet::start()
{
	canio->connect();
	pthread_create(&listenerThread,NULL,CanNet::readingthread,this);
	pthread_create(&writerThread,NULL,CanNet::writingthread,this);
	return 0;
}
int CanNet::stop()
{
	pthread_cancel(listenerThread);
	pthread_cancel(writerThread);

}
void *CanNet::readingthread(void *unused)
{	
	((CanNet*)unused)->reading();
	

}
void *CanNet::writingthread(void *unused)
{
	((CanNet*)unused)->writing();
}

void CanNet::reading()
{
	Msg *msg;
	while(1)
	{
		canio->receive(&msg);
		rqueue.put(msg);
	        // NOTIFY THE LISTENER
	        // listener->notify();
		lstn->notify();
	}
	pthread_exit(NULL);
}
void CanNet::writing()
{
	Msg *msg;
	while(1)
	{
		msg=wqueue.get();
		printf("There is smth in Queue");
		canio->send(msg);
	}	
	pthread_exit(NULL);
}


int CanNet::write(Msg *msg)
{
	wqueue.put(msg);

}
int CanNet::read(Msg *msg)
{
	msg=rqueue.get();

}


/*******************************************************************************
*				MsgQueue
*******************************************************************************/







MsgQueue::MsgQueue()
{
  sem_init(&semaph,0,1);
  sem_init(&s_empty,0,0);
}

MsgQueue::~MsgQueue()
{
  sem_destroy(&semaph);
  sem_destroy(&s_empty);	
}

Msg* MsgQueue::get()
{
  Msg*p;

  sem_wait(&s_empty);
  sem_wait(&semaph);
  p=mQueue.front();
  mQueue.pop();
  sem_post(&semaph);
  return p;
}

int MsgQueue::put(Msg* msg)
{
  sem_wait(&semaph); 
  mQueue.push(msg);
  sem_post(&s_empty);
  sem_post(&semaph);

  
  return 0;
}


