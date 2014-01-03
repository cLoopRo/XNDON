#include "ResManager.h"

/// 256 * 256 
Image* ResManager :: addImage( WCHAR* _Path ){
	if ( image_Map[_Path] == NULL )
		return ( image_Map[_Path] = new Image(_Path) );
	else
		return image_Map[_Path];
}

ResManager::ResManager(void)
{
}


ResManager::~ResManager(void)
{
}
