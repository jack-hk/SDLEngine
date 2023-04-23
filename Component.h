#pragma once

class GameObject;
class Component
{
public:
	GameObject* _gameObject;

	Component(GameObject* gameObject);

	virtual void Update() = 0;

private:
	bool _isEnabled = true;
};