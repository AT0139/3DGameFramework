#pragma once

#include "Component.h"
#include <string>

class DrawBillBoard :public Component
{
public:
	void Init()override;
	void Uninit()override;
	void Draw()override;

	void Load(std::string filePath);
	void Load(std::string filePath,D3DXVECTOR3 size);

	void SetUV(float x, float y, float spritX, float spritY);
private:
	ID3D11Buffer* m_vertexBuffer = nullptr;
	ID3D11ShaderResourceView* m_texture = nullptr;

	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
	ID3D11InputLayout* m_vertexLayout = nullptr;

	float m_x = 0, m_y = 0;
	float m_spritX = 1, m_spritY = 1;
};