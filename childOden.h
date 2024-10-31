#pragma once
#include "Engine/GameObject.h"

class FBX;
class childOden :
    public GameObject
{
	int hModel;
	//FBX* pFbx;
public:
	childOden(GameObject* parent);

	~childOden();

	void Initialize()override;
	void Update() override;
	void Draw()override;
	void Release()override;
};

