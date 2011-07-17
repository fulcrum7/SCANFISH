

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "canio.h"
#include "cannet.h"
#include "msg.h"
#include "controller.h"
/*
 * 
 */
class GUI : public CanListener
{
public:
	GUI()
	{

	}
	int notify(Msg *msg)
	{
		printf("Notification is received!\n");
		return 0;
	}
	int errorInNet()
	{
		return 0;
	}
};


int main(int argc, char** argv)
{

	Controller cnt;
	GUI gui;
	cnt.connect(1,"can0",&gui);
	Msg *ptr=cnt.allocMsg();
	

	
	sleep(150);

    return (EXIT_SUCCESS);
}

