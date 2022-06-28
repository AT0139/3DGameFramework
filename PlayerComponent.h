#pragma once

#include "Component.h"

class PlayerComponent :public Component
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	const float MOVE_SPEED = 0.1f;
	Transform* m_transform;
};