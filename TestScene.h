#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

class TestScene :
    public GameObject
{
    Sprite* pSp;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    TestScene(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

