#include "main.h"
#include "renderer.h"
#include "model.h"
#include "Item.h"

void Item::Init()
{	
	//モデル読み込み
	m_model = new Model();
	m_model->Load((char*)"asset\\model\\torus.obj");


	Renderer::GetInstance()->CreateVertexShader(&m_vertexShader, &m_vertexLayout, "unlitTextureVS.cso");

	Renderer::GetInstance()->CreatePixelShader(&m_pixelShader, "unlitTexturePS.cso");

	m_transform.position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_transform.rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_transform.scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

void Item::Uninit()
{
	//m_model->Unload();
	//delete m_model;

	m_vertexLayout->Release();
	m_vertexShader->Release();
	m_pixelShader->Release();
}

void Item::Update()
{
}

void Item::Draw()
{
	//入力レイアウト設定
	Renderer::GetInstance()->GetDeviceContext()->IASetInputLayout(m_vertexLayout);

	//シェーダー設定
	Renderer::GetInstance()->GetDeviceContext()->VSSetShader(m_vertexShader, NULL, 0);
	Renderer::GetInstance()->GetDeviceContext()->PSSetShader(m_pixelShader, NULL, 0);

	//ワールドマトリクス設定
	D3DXMATRIX world, scale, rot, trans;
	D3DXMatrixScaling(&scale, m_transform.scale.x, m_transform.scale.y, m_transform.scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_transform.rotation.y, m_transform.rotation.x, m_transform.rotation.z);
	D3DXMatrixTranslation(&trans, m_transform.position.x, m_transform.position.y, m_transform.position.z);
	world = scale * rot * trans;
	Renderer::GetInstance()->SetWorldMatrix(&world);

	m_model->Draw();

}
