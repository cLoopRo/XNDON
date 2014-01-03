#include "GameObject.h"

void GameObject :: setImage(WCHAR* _Path){
	pImage = ResManager :: addImage(_Path);
}

GameObject::GameObject(void)
{


}


GameObject::~GameObject(void)
{


}
