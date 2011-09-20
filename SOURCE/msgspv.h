#ifndef MSGSPV_H
#define	MSGSPV_H
#include "msg.h"

class MsgSuperviser
{
	// mutex
	// vector of free resources
	// vector of allocated resources
public:
	MsgSuperviser();
	~MsgSuperviser();
	Msg *allocMsgContainer();
	void freeMsg(Msg *msg);

};



#endif	// MSGSPV_H
