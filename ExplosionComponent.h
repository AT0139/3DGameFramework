#pragma once

#include "Component.h"

class ExplosionComponent :public Component
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;

private:
	int m_count;
};