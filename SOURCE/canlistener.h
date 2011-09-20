#ifndef CANLISTENER_H
#define	CANLISTENER_H


#include "msg.h"

class CanListener
{
private:
	

public:

	virtual int notify()=0;
	virtual int errorInNet(const char *str)=0;


};



#endif	

