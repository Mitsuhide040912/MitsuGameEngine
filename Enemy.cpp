#include "Enemy.h"
#include "Engine/Model.h"
#include "SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel(-1)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets//Oden.fbx");
	transform_.position_.z = 5.0;
	transform_.position_.x = 0.0;
	SphereCollider* col = new SphereCollider(0.5f);
	this->AddCollider(col);
}

void Enemy::Update()
{
	//static int dt;
	//dt++;
	//float nTime = dt / (10.0f * 10.0f) - 2.0f;
	//transform_.position_.x = 4.0 * sin(nTime);
}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
}




