#include "simulator.h"

simulator::simulator() {
	for (int i = 0; i < 5; i++) {
		arrCamera[i] = new camera('a' + i);
		if (arrCamera[i]!=NULL)
			std::cout << i;
	}
}

void simulator::begin() {
	int a = 0;
	std::thread threades[5];
	for (int i = 0; i < 5; i++)
	{
		threades[i] = std::thread(&camera::run, (*(arrCamera[i])));
	}
	char x;
	std::cout << "enter something to stop";
	std::cin >> x;
	for (int i = 0; i < 5; i++)
	{
		(*(arrCamera[i])).stop();
	}
}
