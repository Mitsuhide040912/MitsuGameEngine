#include "GameCrear.h"

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
}

void GameCrear::Draw()
{
	pSp->Draw(transform_);
}

void GameCrear::Release()
{
}
