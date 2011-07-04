
#ifndef MSG_H
#define	MSG_H


#include <vector>
#include <pthread.h>



#define STATUS_OK 0


class MsgSuperviser;


class Msg 
{
    unsigned int id; // should be 32 bit 
    unsigned int dlc;
    unsigned char data[8];
    int status;     //  Any errors in frames?
    MsgSuperviser *sv;
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
    //	set this Msg container as free
    void setMsgFree();

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

