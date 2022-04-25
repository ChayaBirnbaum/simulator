#include "camera.h"

camera::camera(char id) {
	idCamera = id;
}

void camera::generate() {
	int type = rand() % 2 + 1;
	baseMessage* base;
	if (type == 2) {
		discovery* d = new discovery((float)(rand() % 1000), (float)(rand() % 1000), (float)(rand() % 1000), (int)(rand() % 1000));
		base = (baseMessage*)d;
	}
	else {
		status* s = new status((short)(rand() % 1000), (int)(rand() % 1000));
		base = (baseMessage*)s;
	}
	//הכנסה למערך
	if (arrMessage == NULL)
	{
		arrMessage = (baseMessage**)malloc(sizeof(baseMessage*));
	}
	else
	{
		arrMessage = (baseMessage**)realloc(arrMessage, sizeof(baseMessage*) * (countInArr + 1));
	}
	if (arrMessage == NULL) {
		std::cout << "alocation failed";
		exit(1);
	}
	arrMessage[countInArr] = base;
	countInArr++;
}

void camera::sendToBuffer() {
	for (int i = 0; i < countInArr; i++)
	{
		arrMessage[i]->parseMessage();
		buffer.addToBuffer((char*)(arrMessage[i]->getMessageBuffer()));
		free(arrMessage[i]);
	}
	free(arrMessage);
	arrMessage = NULL;
	countInArr = 0;
}

void camera::run() {
	while (isActive)
	{
		for (int i = 0; i < 5; i++)
			generate();
		sendToBuffer();
	}
	std::cout << "run\n";
}

void camera::stop() {
	isActive = false;
}