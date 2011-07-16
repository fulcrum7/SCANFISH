#include "cannet.h"
#include<stdio.h>

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


