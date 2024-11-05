#include "childOden.h"
#include "Engine/FBX.h"
#include "Engine/Model.h"
childOden::childOden(GameObject* parent)
	:GameObject(parent, "childOden"), hModel(-1)
{
	int z = 0;
}

childOden::~childOden()
{
}

void childOden::Initialize()
{
	
	hModel = Model::Load("Assets//Oden.fbx");
	transform_.scale_.x = 0.4f;
	transform_.scale_.y = 0.4f;
	transform_.scale_.z = 0.4f;

	transform_.rotate_.y = -70.0;
	transform_.position_.y = 100.0;
	//transform_.position_.x = 3.0f;
	//transform_.position_.y = 1.0f;
}

void childOden::Update()
{
	
	if (transform_.position_.z > 20)
	{
		KillMe();
	}
	transform_.position_.z += 0.1;
	//transform_.rotate_.y += 2.5;
}

void childOden::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
	//pFbx->Draw(transform_);
}

void childOden::Release()
{
}
