#pragma once
#include "main.h"

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

	static list<XDObject*> getObjects(){
			
	}

private:
	static list<XDObject*> _objects;
	
protected:
	XDObject( ){	}

};
