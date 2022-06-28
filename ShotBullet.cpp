#include "ShotBullet.h"
#include "Scene.h"
#include "manager.h"
#include "BulletComponent.h"
#include "DrawModelComponent.h"

void ShotBullet::Init()
{
}

void ShotBullet::Uninit()
{
}

void ShotBullet::Update()
{
}

void ShotBullet::Shot()
{
	//Bullet作成
	Scene* scene = Manager::GetInstance()->GetScene();
	GameObject* gameObject = new GameObject;
	gameObject->AddComponent<BulletComponent>()->SetForward(m_owner->GetForward());
	gameObject->AddComponent<DrawModelComponent>()->Load("asset\\model\\torus.obj");
	gameObject->SetPosition(m_owner->GetTransform()->position);
	//オブジェクトリストに追加
	scene->AddGameObject(gameObject, scene->OBJECT);

	gameObject = new GameObject;

	delete gameObject;
}
