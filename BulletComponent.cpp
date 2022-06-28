#include "GameObject.h"
#include "BulletComponent.h"
#include "Scene.h"
#include "manager.h"
#include "EnemyComponent.h"
#include "ExplosionComponent.h"

void BulletComponent::Init()
{
	m_transform = m_owner->GetTransform();

	m_transform->scale = D3DXVECTOR3(0.2f, 0.2f, 0.2f);

	m_count = 0;
}

void BulletComponent::Uninit()
{
}

void BulletComponent::Update()
{
	Scene* scene = Manager::GetInstance()->GetScene();
	m_transform->position += m_forward * MOVE_SPEED;

	if (m_count > DESTROY_COUNT)
	{
		m_owner->SetDestroy();
		return;
	}


	//“G“–‚½‚è”»’è
	std::vector<GameObject*> enemyList = scene->GetComponentObjects<EnemyComponent>(scene->OBJECT);

	for (GameObject* enemy : enemyList)
	{
		D3DXVECTOR3 enemyPosition = enemy->GetTransform()->position;
		D3DXVECTOR3 direction = m_transform->position - enemyPosition;
		float length = D3DXVec3Length(&direction);

		if (length < 2.0f)
		{
			enemy->SetDestroy();
			m_owner->SetDestroy();
			//”š”­¶¬
			GameObject* gameObject = new GameObject;
			gameObject->AddComponent<ExplosionComponent>();
			scene->AddGameObject(gameObject, scene->OBJECT);
			gameObject->SetPosition(enemy->GetTransform()->position);
			gameObject = new GameObject;

			delete gameObject;
			return;
		}

	}

	m_count++;
}

void BulletComponent::Draw()
{
}