#ifndef DISCOVERY_H
#define DISCOVERY_H

#include "baseMessage.h"
#include <string.h>
#include <iostream>

class discovery:baseMessage
{
    public:
    	float distance;
    	float angle;
    	float speed;
        discovery(unsigned char*,int);
        discovery(float,float,float,int);
        virtual void  parseMessage();
        virtual void  parseBack();
        virtual void  print();
};

#endif