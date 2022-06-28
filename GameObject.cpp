#include "GameObject.h"
#include "Component.h"



GameObject::GameObject()
{
	m_transform.scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

void GameObject::Init()
{
	for (Component* comp : m_componentList)
	{
		comp->Init();
	}
}

void GameObject::Uninit()
{
	for (Component* comp : m_componentList)
	{
		comp->Uninit();
	}
}

void GameObject::Update()
{
	for (Component* comp : m_componentList)
	{
		comp->Update();
	}
}

void GameObject::Draw()
{
	for (Component* comp : m_componentList)
	{
		comp->Draw();
	}
}
