#include "GameObject.h"
#include "PlayerComponent.h"
#include "main.h"
#include "input.h"
#include "Scene.h"
#include "manager.h"
#include "ShotBullet.h"
#include "DrawModelComponent.h"

void PlayerComponent::Init()
{
	m_owner->AddComponent<DrawModelComponent>()->Load("asset\\model\\torus.obj");
	m_transform = m_owner->GetTransform();

	m_transform->position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_transform->rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_transform->scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

void PlayerComponent::Uninit()
{
}

void PlayerComponent::Update()
{
	//ROTATION
	if (Input::GetKeyPress('Q'))
		m_transform->rotation.y -= 0.1f;
	if (Input::GetKeyPress('E'))
		m_transform->rotation.y += 0.1f;

	D3DXVECTOR3 forward = m_owner->GetForward();
	D3DXVECTOR3 right = m_owner->GetRight();

	//MOVE
	if (Input::GetKeyPress('W'))
		m_transform->position += forward * MOVE_SPEED;
	if (Input::GetKeyPress('A'))
		m_transform->position -= right * MOVE_SPEED;
	if (Input::GetKeyPress('S'))
		m_transform->position -= forward * MOVE_SPEED;
	if (Input::GetKeyPress('D'))
		m_transform->position += right * MOVE_SPEED;

	//SHOT
	if (Input::GetKeyTrigger(VK_SPACE))
	{
		m_owner->GetComponent<ShotBullet>()->Shot();
	}
}

void PlayerComponent::Draw()
{
}
