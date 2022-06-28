#pragma once

#include "Component.h"
#include <string>

class DrawPolygonComponent :public Component
{
public:
	void Init()override;
	void Uninit()override;
	void Draw()override;

	void Load(std::string filePath);
	void Load(std::string filePath, D3DXVECTOR3 size);
	void SetVertex(D3DXVECTOR3 size);

private:
	ID3D11ShaderResourceView* m_texture = nullptr;
	ID3D11Buffer* m_vertexBuffer = nullptr;

	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
	ID3D11InputLayout* m_vertexLayout = nullptr;
};