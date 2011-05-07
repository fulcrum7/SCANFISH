
#ifndef MSG_H
#define	MSG_H

#define STATUS_OK 0

class Msg
{
    unsigned int id; // should be 32 bit 
    unsigned int dlc;
    unsigned char data[8];
    int status;     //  Any errors in frames?
public:
    Msg();
    int setid(unsigned int mid);
    unsigned int getid();
    int setdlc(unsigned int mdlc);
    unsigned int getdlc();
    int setdata(int num,unsigned char data);
    unsigned char getdata(int num);
    int getstatus();

};


#endif	/* MSG_H */

