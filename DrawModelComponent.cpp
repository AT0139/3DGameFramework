#include "main.h"
#include "model.h"
#include "DrawModelComponent.h"
#include "renderer.h"
#include "GameObject.h"
#include "ResourceManager.h"

DrawModelComponent::~DrawModelComponent()
{
	m_vertexLayout->Release();
	m_vertexShader->Release();
	m_pixelShader->Release();
}

void DrawModelComponent::Init()
{
	Renderer::GetInstance()->CreateVertexShader(&m_vertexShader, &m_vertexLayout, "unlitTextureVS.cso");

	Renderer::GetInstance()->CreatePixelShader(&m_pixelShader, "unlitTexturePS.cso");
}

void DrawModelComponent::Draw()
{
	//入力レイアウト設定
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(m_vertexLayout);

	//シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(m_vertexShader, NULL, 0);
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(m_pixelShader, NULL, 0);

	//ワールドマトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	Transform* transform = m_owner->GetTransform();
	D3DXMatrixScaling(&scale,transform->scale.x, transform->scale.y, transform->scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, transform->rotation.y, transform->rotation.x, transform->rotation.z);
	D3DXMatrixTranslation(&trans, transform->position.x, transform->position.y, transform->position.z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	m_model->Draw();
}

void DrawModelComponent::Load(std::string filePath)
{
	m_model = ResourceManager::GetInstance()->GetModelData(filePath);
}
