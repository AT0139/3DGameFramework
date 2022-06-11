#pragma once

class Component
{
public:
	Component() {}
	~Component() {}

	virtual void Update();


protected:
	class GameObject* m_Owner;
};