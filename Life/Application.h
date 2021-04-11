#pragma once
#include "Location.h"

class Application
{
	Location* newLocation;
public:
	Application();
	~Application();
	void startLife();
	bool runApp();
};

