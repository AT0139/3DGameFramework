#pragma once

#include "main.h"
#include <list>
#include <typeinfo>

class Component;

struct Transform
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;
};

class GameObject
{
public:
	enum State
	{
		ACTIVE,
		PAUSE,
		DEAD
	};

	GameObject();
	virtual ~GameObject() {}

	//èÉêàâºëzä÷êî
	virtual void Init();
	virtual void Uninit();
	virtual void Update();
	virtual void Draw();

	void SetPosition(D3DXVECTOR3 position) { m_transform.position = position; }
	void SetScale(D3DXVECTOR3 scale) { m_transform.scale = scale; }

	Transform* GetTransform() { return &m_transform; }
	D3DXVECTOR3 GetForward()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_transform.rotation.y, m_transform.rotation.x, m_transform.rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}
	D3DXVECTOR3 GetRight()
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_transform.rotation.y, m_transform.rotation.x, m_transform.rotation.z);

		D3DXVECTOR3 right;
		right.x = rot._11;
		right.y = rot._12;
		right.z = rot._13;

		return right;
	}

	void SetDestroy() { m_state = DEAD; }
	bool Destroy()
	{
		if (m_state == State::DEAD)
		{
			Uninit();
			delete this;
			return true;
		}
		else
			return false;
	}

	template<typename T>
	T* AddComponent()
	{
		T* component = new T();
		component->SetOwner(this);
		m_componentList.push_back(component);
		component->Init();
		return component;
	}


	template<typename T>
	T* GetComponent()
	{
		for (Component* comp : m_componentList)
		{
			if (typeid(*comp) == typeid(T))
			{
				return (T*)comp;
			}
		}
		return nullptr;
	}

	
protected:
	Transform m_transform;

private:
	State m_state = ACTIVE;

	std::list<Component*> m_componentList;
};