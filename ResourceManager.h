#pragma once

//モデルデータを管理するクラス

//テクスチャcom ptr

#include <unordered_map>
#include <string>
#include <memory>
#include "model.h"

class ResourceManager
{
public:
	static ResourceManager* GetInstance();

	Model* GetModelData(std::string filePath);
	ID3D11ShaderResourceView* GetTextureData(std::string filePath);

	void Release();

private:
	ResourceManager() {}
	~ResourceManager();

	static ResourceManager* m_singleton;

	std::unordered_map <std::string, std::unique_ptr<Model>> m_modelList;
	std::unordered_map <std::string, ID3D11ShaderResourceView*> m_textureList;
};