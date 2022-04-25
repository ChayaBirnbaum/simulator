#ifndef STATUS_H
#define STATUS_H

#include "baseMessage.h"
#include <string.h>
#include <iostream>

class status:baseMessage
{
	public:
	    short status1;
		status(unsigned char*,int);
		status(short,int);
		virtual void  parseMessage();
		virtual void  parseBack();
		virtual void  print();
};

#endif