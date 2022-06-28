#include "Result.h"
#include "main.h"
#include "Polygon2D.h"
#include "input.h"
#include "manager.h"
#include "Title.h"
#include "ResourceManager.h"

void Result::Init()
{
	AddGameObject<Polygon2D>(UI);
}

void Result::Uninit()
{
	Scene::Uninit();
	ResourceManager::GetInstance()->Release();
}

void Result::Update()
{
	Scene::Update();

	if (Input::GetKeyTrigger(VK_RETURN))
	{
		Manager::SetScene<Title>();
	}
}
