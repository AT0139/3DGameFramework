#pragma once

#include "Component.h"

class ShotBullet :public Component
{
public:
	void Init()override;
	void Uninit()override;
	void Update()override;
	void Draw()override {}

	void Shot();

private:

};