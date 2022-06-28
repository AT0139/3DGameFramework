#include "ExplosionComponent.h"
#include "GameObject.h"
#include "DrawBillBoard.h"

void ExplosionComponent::Init()
{
	DrawBillBoard* billboard = m_owner->AddComponent<DrawBillBoard>();
	billboard->Load("asset/texture/explosion.png");
}

void ExplosionComponent::Uninit()
{
}

void ExplosionComponent::Update()
{
	m_count++;

	if (m_count >= 16)
	{
		m_owner->SetDestroy();
		return;
	}

	//テクスチャ座標産出
	float x = m_count % 4 * (1.0f / 4);
	float y = m_count / 4 * (1.0f / 4);

	m_owner->GetComponent<DrawBillBoard>()->SetUV(x, y, 4, 4);
}
