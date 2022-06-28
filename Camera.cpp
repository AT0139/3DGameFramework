#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "Camera.h"
#include "input.h"
#include "Scene.h"
#include "PlayerComponent.h"

void Camera::Init()
{
	m_transform.position = D3DXVECTOR3(0.0f, 5.0f, -5.0f);
	m_target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

void Camera::Uninit()
{
}

void Camera::Update()
{
	//プレイヤーの取得
	Scene* scene = Manager::GetInstance()->GetScene();
	GameObject* player = scene->GetComponentObject<PlayerComponent>(scene->OBJECT);
	D3DXVECTOR3 playerPos = player->GetTransform()->position;
	D3DXVECTOR3 playerForward = player->GetForward();
	D3DXVECTOR3 playerRight = player->GetRight();

	//トップビュー
	//m_target = playerPos;
	//m_position = playerPos + D3DXVECTOR3(0.0f, 5.0f, -5.0f);


	////サードパーソンビュー
	//m_target = playerPos;
	//m_position = playerPos - playerForward * 5.0f + D3DXVECTOR3(0.0f, 2.0f, 0.0f);

	//サードパーソンビュー(右寄り)
	m_target = playerPos + playerRight;
	m_transform.position = playerPos - playerForward * 5.0f + playerRight + D3DXVECTOR3(0.0f, 2.0f, 0.0f);

	////ファーストパーソンビュー
	//m_target = playerPos + playerForward;
	//m_position = playerPos;
}

void Camera::Draw()
{
	//ビューマトリクス設定
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&m_viewMatrix, &m_transform.position, &m_target, &up);

	Renderer::GetInstance()->SetViewMatrix(&m_viewMatrix);

	//プロジェクションマトリクス設定	
	D3DXMATRIX projectionMatrix;
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, 1.0f, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

	Renderer::GetInstance()->SetProjectionMatrix(&projectionMatrix);
}
