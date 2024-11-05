#include "OdenBullet.h"
#include "Engine/FBX.h"
#include "Engine/Model.h"
OdenBullet::OdenBullet(GameObject* parent)
	:GameObject(parent,"OdenBullet")
{
}

OdenBullet::~OdenBullet()
{
}

void OdenBullet::Initialize()
{
	hModel = Model::Load("Assets//Oden.fbx");
	transform_.scale_.x = 0.4f;
	transform_.scale_.y = 0.4f;
	transform_.scale_.z = 0.4f;
	transform_.position_.y = 10.0f;
	transform_.position_.x = 10.0f;
}

void OdenBullet::Update()
{
	
	transform_.position_.z += 0.1;
}

void OdenBullet::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void OdenBullet::Release()
{
}
