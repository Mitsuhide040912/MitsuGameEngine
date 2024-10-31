#pragma once
#include <DirectXMath.h>
#include "Direct3D.h"
#include "Texture.h"
#include "Transform.h"
#include <vector>
using namespace DirectX;

//�R���X�^���g�o�b�t�@�[

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
	XMMATRIX    matW;
};

//���_���
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal;
};

class Quad
{
private:
	HRESULT CreateVertexBuffer();
	virtual void InitVertexData();
	virtual void InitIndexData();
	HRESULT CreateConstantBuffer();
	HRESULT CreateIndexBuffer();
	HRESULT LoadTexture();
	void SetBufferToPipeline();
	void PassDataToCB(XMMATRIX worldMatrix);
protected:
	int vertexNum_;
	std::vector<VERTEX>vertices_;
	int indexNum_;
	std::vector<int>index_;
	
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@

	Texture* pTexture_;
public:
	Quad();
	virtual ~Quad();
	HRESULT Initialize();
	//void Draw();
	void Draw(Transform& transform);
	void Release();
};

