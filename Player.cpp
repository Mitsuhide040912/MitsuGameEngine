#include "Player.h"
#include "Engine/FBX.h"
#include "childOden.h"
#include "OdenBullet.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel = Model::Load("Assets//Oden.fbx");
	//pOden = new FBX;
	//pOden->Load("Assets//Oden.fbx");
	transform_.position_.x = 0.0f;
	transform_.position_.y = 0.0f;
	transform_.position_.z = -5.0;
	transform_.rotate_.y   = 0.0;
	transform_.rotate_.x   = 80.0;
	//transform_.scale_.x = 10.0;
}

void Player::Update()
{
	//transform_.rotate_.y += 2.0;
	//if (transform_.rotate_.y > 60 * 10)
	//{
	//	KillMe();
	//}
	//transform_.position_.x += 0.01;

	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x -= 0.3;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x += 0.3;
	}
	if (Input::IsKeyUp(DIK_B))
	{
		GameObject* ob = Instantiate<childOden>(this);
		ob->SetPosition(transform_.position_);
		ob->SetScale(0.3, 0.3, 0.3);
	}
	//if (Input::IsKey(DIK_SPACE))
	//{
	//	GameObject* p = Instantiate<childOden>(this);
	//	p->SetPosiiton(transform_.position_);
	//}
}

void Player::Draw()
{
	//pOden->Draw(transform_);
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
	//pOden->Release();
	//delete pOden;
}
