#pragma once
#include <iostream>

class GameObject;
class Component
{
public:
	GameObject* _gameObject;

	Component(GameObject* gameObject);

	virtual void Update() = 0; //abstract 

private:
	bool _isEnabled = true;
};