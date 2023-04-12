#include "Component.h"
#include "GameObject.h"

Component::Component(GameObject* gameObject)
{
	_gameObject = gameObject;
}