#pragma once
#include "Engine/GameObject.h"
class OdenBullet :
    public GameObject
{
	int hModel;
	//FBX* pFbx;
public:
	OdenBullet(GameObject* parent);

	~OdenBullet();

	void Initialize()override;
	void Update() override;
	void Draw()override;
	void Release()override;
};

