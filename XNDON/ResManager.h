#pragma once
#include "main.h"

class ResManager
{
public:
	static Image* ResManager :: addImage(const wstring& _Path);

private:
	static map<wstring, Image* > image_map;

};


