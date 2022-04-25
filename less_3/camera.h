#ifndef CAMERA_H
#define CAMERA_H

#pragma once
#include "baseMessage.h"
#include "buffer.h"
#include "discovery.h"
#include "status.h"

class camera
{
	private:
		char idCamera;
		baseMessage** arrMessage = NULL;
		int countInArr = 0;
		buffer buffer;
		bool isActive = true;
	public:
		camera(char);
		void generate();// ������� ������� ����� ������� ������� ������� �����  �������  ����� �� ����� ���� ������
		void sendToBuffer(); // ����� �� �� ���� �������, ����� �� ����� ������� ������� ������ �� ������� ������ �� ������� �buffer, ������ �� ���� �������
		void run1();
		void run(); // ����� � generate �  send  �������� ������ �� ��� isActive ��� � true ��� �� �������� ����
		void stop(); // ������ �� isActive � false


};

#endif