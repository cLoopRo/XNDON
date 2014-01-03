#pragma once

#include "main.h"

class ResManager
{
public:
	static Image* ResManager :: addImage(WCHAR* _Path);


	ResManager(void);
	virtual ~ResManager(void);

private:
	static std::map<wstring, Image* > image_Map;

};

