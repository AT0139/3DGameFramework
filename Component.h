#pragma once

class GameObject;


class Component
{
public:
	Component() {}
	virtual ~Component() {}

	virtual void Init() {}
	virtual void Uninit() {}
	virtual void Update() {}
	virtual void Draw() {}

	void SetOwner(GameObject* owner) { m_owner = owner; }
	GameObject* GetOwner() { return m_owner; }
protected:
	class GameObject* m_owner = nullptr;
};