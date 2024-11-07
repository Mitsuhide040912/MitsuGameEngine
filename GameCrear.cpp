#include "GameCrear.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
GameCrear::GameCrear(GameObject* parent)
	:GameObject(parent,"GameCrear")
{
}

void GameCrear::Initialize()
{
	pSp = new Sprite();
	pSp->Load("Assets//GameClearScene.png");
}

void GameCrear::Update()
{
	if (Input::IsKey(DIK_T))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void GameCrear::Draw()
{
	pSp->Draw(transform_);
}

void GameCrear::Release()
{
}
