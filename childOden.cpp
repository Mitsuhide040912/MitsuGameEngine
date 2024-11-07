#include "childOden.h"
#include "Engine/FBX.h"
#include "Engine/Model.h"
#include "Enemy.h"
#include "SphereCollider.h"
childOden::childOden(GameObject* parent)
	:GameObject(parent, "childOden"), hModel(-1)
{
	
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
	transform_.position_.y = 0.0;

	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);
}

void childOden::Update()
{
	transform_.position_.z += 0.1;
	Enemy* enemy = (Enemy*)FindObject("Enemy");

	if (transform_.position_.z > 20.0)
	{
		KillMe();
	}

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

void childOden::OnCollision(GameObject* pTarget)
{
	KillMe();
	pTarget->KillMe();
}


