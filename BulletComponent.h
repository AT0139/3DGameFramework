#pragma once

#include "Component.h"

class BulletComponent :public Component
{
public:
	void Init() override;
	void Uninit()override;
	void Update()override;
	void Draw()override;

	void SetForward(D3DXVECTOR3 forward) { m_forward = forward; }

private:
	const float MOVE_SPEED = 0.3f;
	const int DESTROY_COUNT = 60;

	Transform* m_transform;

	D3DXVECTOR3 m_forward;

	int m_count;
};