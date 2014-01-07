#pragma once
#include "main.h"
#include<iostream>
#include<cassert>
using std::vector;

class XDObject
{

protected:
	void add_Image(wstring _Path){
		map<wstring, Image*>::iterator itr;
		if ( _images.end() == ( itr = _images.find(_Path) )  ) // 해당 image 가 존재하지 않으면
		{
			Image* tmpImage = new Image(_Path.c_str());
			_pImages.push_back(tmpImage);
			_images.insert ( std::pair<wstring, Image* >(_Path, _pImage) );
		}
		else
		{
			_pImage = itr->second;
		}
	}

	void set_Image_Size(int _Width, int _Height)
	{
		_width = _Width;
		_height = _Height;
	}

//	virtual void draw( ) ;

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

protected:
	/*
	Image* set_Image (int _anum) {
			int _deterX, _deterY;
		int _vecmax = _pImages.size();
		_deterX = (_anum % 10) - 1;
		_deterY = (_anum / 10) - 1;
		assert(_deterX + _deterY * 10 < _vecmax);
		return _pImages[_deterX + _deterY * 10];	
		
	}
	*/

	void set_Image(int _N)
	{
		assert(_N < _pImages.size() ); 
		_pImage = _pImages[_N];	
	}

protected:
	vector< Image* > _pImages;
	Image* _pImage;
	int _width, _height;

private:
	
	static list<XDObject*> _objects;
	static map<wstring, Image* >  _images;

protected:
	XDObject( ) {
	}

};
