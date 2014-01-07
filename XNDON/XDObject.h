#pragma once
#include "main.h"

class XDObject
{

protected:
	void add_Image(wstring _Path){
		map<wstring, Image*>::iterator itr;
		if ( _images.end() == ( itr = _images.find(_Path) )  ) // 해당 image 가 존재하지 않으면
		{
			_pImage = new Image(_Path.c_str());
			_images.insert ( std::pair<wstring, Image* >(_Path, _pImage) );
		}
		else
		{
			_pImage = itr->second;
		}
	}


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
	Image* _pImage;

private:
	static list<XDObject*> _objects;
	static map<wstring, Image* >  _images;

protected:
	XDObject( )
	{	}

};

