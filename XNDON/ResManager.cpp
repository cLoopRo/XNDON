#include "ResManager.h"

Image* ResManager :: addImage(const wstring& _Path ){

	wstring tmpPath = _Path;
	
	if ( image_map[_Path] == NULL )
		return ( image_map[_Path] = new Image( _Path.c_str() ) );
	else
		return image_map[_Path];

}
