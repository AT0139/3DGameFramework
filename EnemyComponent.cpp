#include "GameObject.h"
#include "DrawModelComponent.h"
#include "EnemyComponent.h"

void EnemyComponent::Init()
{
	m_transform = m_owner->GetTransform();
	m_owner->AddComponent<DrawModelComponent>()->Load("asset\\model\\torus.obj");

	m_transform->scale = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
}
