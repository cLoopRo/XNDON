#pragma once
#include "main.h"
#include<iostream>
#include<cassert>
using std::vector;

class XDObject
{


protected:
	static XDObject* Create_Object(XDObject* _Object)
	{
		_objects.push_back(_Object);
		return _Object;
	}

	static void Clear_Objects( )
	{
		for( list<XDObject*>::iterator itr = _objects.begin(); itr != _objects.end(); itr++ )
			delete (*itr); // Important delete (*itr)
		_objects.clear( );
	}

private:
	
	static list<XDObject*> _objects;
	

protected:
	XDObject( ) {
	}

};
