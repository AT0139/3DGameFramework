#pragma once

#include "Component.h"

class EnemyComponent :public Component
{
public:
	void Init() override;
	void Uninit()override {}
	void Update()override {}
	void Draw()override {}

private:
	Transform* m_transform;
};