#pragma once
#include <string>
#include <list>
#include "Transform.h"
class GameObject
{
	bool isDead_;
protected:
	std::list<GameObject *> childList_;
	Transform	transform_;
	GameObject*	pParent_;
	std::string	objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

	void UpdateSub();
	void DrawSub();
	void ReleaseSub();

	void KillMe();

	void SetPosition(XMFLOAT3 position)
	{
		transform_.position_ = position;
	}

	void SetPosiiton(float x, float y, float z)
	{
		SetPosition(XMFLOAT3(x, y, z));
	}

	template<class T>
	GameObject* Instantiate(GameObject* pParent)
	{
		T* pObject;
		pObject = new T(pParent);
		pObject->Initialize();
		childList_.push_back(pObject);
		return(pObject);
		//T* pTmp = new T(pParent);
		//if (pTmp != nullptr)
		//{
		//	pTmp->Initialize();
		//	childList_.push_back(pTmp);
		//}
		//return pTmp;
	}
};

