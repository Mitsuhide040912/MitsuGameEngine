#pragma once
#include "Engine/GameObject.h"
//�O���錾
class FBX;
class Player :
    public GameObject
{
	int hModel;
//	FBX* pOden;
public:
	Player(GameObject* parent);

	~Player();

	void Initialize()override;
	void Update() override;
	void Draw()override;
	void Release()override;
};

