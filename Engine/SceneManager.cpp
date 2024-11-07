#include "SceneManager.h"
#include "../TestScene.h"
#include "../PlayScene.h"
#include "../GameCrear.h"
#include "Direct3D.h"
#include "Model.h"
SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent,"SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	nextSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
	if (currentSceneID_ != nextSceneID_)
	{
		auto delScene = childList_.begin();
		(*delScene)->ReleaseSub();
		SAFE_DELETE(*delScene);
		childList_.clear();
		Model::Release();

		switch (nextSceneID_)
		{
		case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
		case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
		case SCENE_ID_CREAR: Instantiate<GameCrear>(this); break;
		}
		//無事シーンを生成出来たら、カレントシーンを更新
		currentSceneID_ = nextSceneID_;

	}
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
