#pragma once

#include "Component.h"
#include <string>

class DrawModelComponent : public Component
{
public:
	~DrawModelComponent()override;

	void Init()override;
	void Draw()override;

	void Load(std::string filePath);
private:
	class Model* m_model;

	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
	ID3D11InputLayout* m_vertexLayout = nullptr;
};