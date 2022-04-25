#include "buffer.h"

//#include "baseMessage.h"

buffer::buffer() {
	buffer1 = NULL;
	cnt = 0;
}

//void buffer::addToBuffer(baseMessage basemessage) {
//	if (buffer1 == NULL) {
//		buffer1 = (char**)malloc(sizeof(baseMessage));
//	}
//	else
//	{
//		buffer1 = (char**)realloc(buffer1,sizeof(baseMessage)*cnt);
//	}
//	strcmp(buffer1[cnt], (char*)basemessage.getMessageBuffer());
//	cnt = cnt + 1;
//}

void buffer::addToBuffer(char* basemessage) {
	if (buffer1 == NULL) {
		buffer1 = (char**)malloc(sizeof(char*));
	}
	else {
		buffer1 = (char**)realloc(buffer1, sizeof(char*) * (cnt + 1));
	}
	if (buffer1 == NULL) {
		std::cout << "alocation failed";
		exit(1);
	}
	strcpy(buffer1[cnt], basemessage);//העתקת תוכן הודעה
	cnt = cnt + 1;
}

char** buffer::getBuffer() {
	return buffer1;
}

void buffer::cleanBuffer() {
	for (int i = 0; i < cnt; i++)
		free(buffer1[cnt]);//???
	free(buffer1);
}