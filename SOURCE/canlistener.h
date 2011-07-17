#ifndef CANLISTENER_H
#define	CANLISTENER_H


#include "msg.h"

class CanListener
{
private:
	

public:

	virtual int notify(Msg *msg)=0;
	virtual int errorInNet()=0;


};



#endif	

