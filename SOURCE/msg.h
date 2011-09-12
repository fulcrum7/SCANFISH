
#ifndef MSG_H
#define	MSG_H


#include <vector>
#include <pthread.h>
#include "sferror.h"
#include "sys/time.h" /* Linux only (Posix functions) */

#define STATUS_OK 0


class MsgSuperviser;


class Msg 
{

private:
    unsigned int id; // should be 32 bit 
    unsigned int dlc;
    unsigned char data[8];
    int status;     //  any errors in frames? for the future use
    MsgSuperviser *sv; // looks for the Msg resources
	struct timeval timestamp;
public:
     Msg(MsgSuperviser *msv);

    // accessors
    int setID(unsigned int mid);
    unsigned int getID();
    int setDlc(unsigned int mdlc);
    unsigned int getDlc();
    int setData(unsigned int num,unsigned char mdata);
    unsigned char getData(unsigned int num);
    int getStatus();
    void setStatus(int st);
    //	set this Msg container  free
    void setMsgFree();
	void fixTime();
	time_t getTimestampSec();
	int    getTimestampMS();
};



class MsgSuperviser
{
	// mutex
	pthread_mutex_t mutex;
	// vector of free resources
	std::vector<Msg *> vfree;
	// vector of allocated resources
	std::vector<Msg *> valloc;
public:
	MsgSuperviser();
	~MsgSuperviser();
	Msg *allocMsgContainer();
	void setFree(Msg *msg);

};



#endif	/* MSG_H */

