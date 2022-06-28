#include "main.h"
#include "renderer.h"
#include "Game.h"
#include "Polygon2D.h"
#include "Camera.h"
//#include "Stair.h"
#include "SkyDome.h"
#include "input.h"
#include "manager.h"
#include "Result.h"
#include "DrawPolygonComponent.h"
#include "ResourceManager.h"
#include "DrawModelComponent.h"
#include "DrawBillBoard.h"
#include "PlayerComponent.h"
#include "ShotBullet.h"
#include "EnemyComponent.h"

#define FIELD_X 30.0f
#define FIELD_Z 30.0f

void Game::Init()
{
	//カメラ
	AddGameObject<Camera>(CAMERA);

	//3Dオブジェクト
	AddGameObject<SkyDome>(OBJECT);
	//AddGameObject<Stair>(OBJECT)->SetPosition(D3DXVECTOR3(10.0f, 0.0f, 10.0f));
	//AddGameObject<Tree>(OBJECT)->SetPosition(D3DXVECTOR3(-8.0f, 2.0f, 5.0f));

	//2Dオブジェクト
	//AddGameObject<Polygon2D>(UI);

	GameObject* gameObject = new GameObject;
	//プレイヤー
	gameObject->AddComponent<PlayerComponent>();
	gameObject->AddComponent<ShotBullet>();
	AddGameObject(gameObject, OBJECT);
	gameObject = new GameObject;
	//エネミー
	gameObject->AddComponent<EnemyComponent>();
	gameObject->SetPosition(D3DXVECTOR3(0.0f, 1.0f, 3.0f));
	AddGameObject(gameObject, OBJECT);
	gameObject = new GameObject;
	//フィールド
	gameObject->AddComponent<DrawPolygonComponent>()
		->Load("asset/texture/field000.jpg", D3DXVECTOR3(FIELD_X, 0.0f, FIELD_Z));
	AddGameObject(gameObject, OBJECT);
	gameObject = new GameObject;
	//木
	for (int i = 0; i < 50; i++)
	{
		gameObject->AddComponent<DrawBillBoard>()
			->Load("asset/texture/Tree.png", D3DXVECTOR3(1.0f, 2.0f, 0.0f));
		float x, z;
		x = rand() % (int)FIELD_X * 2;
		z = rand() % (int)FIELD_Z * 2;
		gameObject->SetPosition(D3DXVECTOR3(x - FIELD_X, 2.0f, z - FIELD_X));
		gameObject->SetScale(D3DXVECTOR3(2.0f, 2.0f, 2.0f));
		AddGameObject(gameObject, OBJECT);
		gameObject = new GameObject;
	}

	delete gameObject;
}

void Game::Uninit()
{
	Scene::Uninit();
	ResourceManager::GetInstance()->Release();
}

void Game::Update()
{
	Scene::Update();

	if (Input::GetKeyTrigger(VK_RETURN))
	{
		Manager::GetInstance()->SetScene<Result>();
	}
}
