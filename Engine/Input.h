#pragma once

#include <dInput.h>
#include <DirectXMath.h>
#include "XInput.h"


#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dInput8.lib")
#pragma comment(lib, "Xinput.lib")

#define SAFE_RELEASE(p) if(p != nullptr){ p->Release(); p = nullptr;}

using namespace DirectX;

namespace Input
{
	void Initialize(HWND hWnd);
	void Update();


	///////////////////////////�@�L�[�{�[�h�@//////////////////////////////////
	//�L�[��������Ă��邩���ׂ�
	//�����FkeyCode	���ׂ����L�[�̃R�[�h
	//�ߒl�F������Ă����true
	bool IsKey(int keyCode);
	bool IsKeyDown(int keyCode);
	bool IsKeyUp(int keyCode);

	///////////////////////////�@�}�E�X�@//////////////////////////////////
	//�}�E�X�̃{�^����������Ă��邩���ׂ�
	//�����FbuttonCode	���ׂ����{�^���̔ԍ�
	//�ߒl�F������Ă����true
	bool IsMouseButton(int buttonCode);


	//�}�E�X�̃{�^�����������������ׂ�i�������ςȂ��͖����j
	//�����FbuttonCode	���ׂ����{�^���̔ԍ�
	//�ߒl�F�������u�Ԃ�������true
	bool IsMouseButtonDown(int buttonCode);


	//�}�E�X�̃{�^�����������������ׂ�
	//�����FbuttonCode	���ׂ����{�^���̔ԍ�
	//�ߒl�F�������u�Ԃ�������true
	bool IsMouseButtonUp(int buttonCode);


	//�}�E�X�J�[�\���̈ʒu���擾
	//�ߒl�F�}�E�X�J�[�\���̈ʒu
	XMVECTOR GetMousePosition();

	//�}�E�X�J�[�\���̈ʒu���Z�b�g
	//�����F�}�E�X�J�[�\���̈ʒu
	void SetMousePosition(int x, int y);

	void Release();
};

