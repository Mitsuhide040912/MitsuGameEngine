#pragma once
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"
class GameCrear :
    public GameObject
{
    Sprite* pSp;
public:
    //�R���X�g���N�^
    //�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
    GameCrear(GameObject* parent);
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
};

