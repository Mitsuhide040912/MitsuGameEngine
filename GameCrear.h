#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"
class GameCrear :
    public GameObject
{
    Sprite* pSp;
public:
    //コンストラクタ
    //引数：parent  親オブジェクト（SceneManager）
    GameCrear(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

