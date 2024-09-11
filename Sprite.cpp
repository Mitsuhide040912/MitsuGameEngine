//#include "Sprite.h"
//#include "Camera.h"
//Sprite::Sprite()
//	:pTexture_(nullptr), pVertexBuffer_(nullptr), pIndexBuffer_(nullptr), pConstantBuffer_(nullptr)
//{
//}
//
//Sprite::~Sprite()
//{
//}
//
//HRESULT Sprite::Initialize()
//{
//	HRESULT hr;
//	// ���_���
//	VERTEX vertices[] =
//	{
//		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 0.0, 0.0, 0.0)},	// �l�p�`�̒��_�i����j, UV
//		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 0.0, 0.0, 0.0)},	// �l�p�`�̒��_�i�E��j, UV
//		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 1.0, 0.0, 0.0)},	// �l�p�`�̒��_�i�E���j, UV
//		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 1.0, 0.0, 0.0)}	// �l�p�`�̒��_�i�����j, UV
//		//{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f) },   // �l�p�`�̒��_�i����j
//		//{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f) },   // �l�p�`�̒��_�i�E��j
//		//{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f) },   // �l�p�`�̒��_�i�E���j
//		//{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f) },   // �l�p
//		//XMVectorSet(-1.0f,    1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j
//		//XMVectorSet(1.0f,     1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j
//		//XMVectorSet(1.0f,    -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j
//		//XMVectorSet(-1.0f,   -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	
//		//XMVectorSet( 0.0f,    -2.0f, 0.0f, 0.0f),
//
//		//XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
//		//XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
//		//XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
//		//XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
//		//XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//�l�p���̒��_
//	};
//	//�C���f�b�N�X���
//	int index[] = { 0,2,3, 0,1,2 };
//	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
//	D3D11_BUFFER_DESC bd_vertex;
//	bd_vertex.ByteWidth = sizeof(vertices);
//	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
//	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	bd_vertex.CPUAccessFlags = 0;
//	bd_vertex.MiscFlags = 0;
//	bd_vertex.StructureByteStride = 0;
//
//	D3D11_SUBRESOURCE_DATA data_vertex;
//
//	data_vertex.pSysMem = vertices;
//	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//	// �C���f�b�N�X�o�b�t�@�𐶐�����
//	D3D11_BUFFER_DESC   bd;
//	bd.Usage = D3D11_USAGE_DEFAULT;
//	bd.ByteWidth = sizeof(index);
//	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
//	bd.CPUAccessFlags = 0;
//	bd.MiscFlags = 0;
//
//	D3D11_SUBRESOURCE_DATA InitData;
//	InitData.pSysMem = index;
//	InitData.SysMemPitch = 0;
//	InitData.SysMemSlicePitch = 0;
//
//	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
//
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"�C���f�b�N�X�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//
//	//�R���X�^���g�o�b�t�@�쐬
//	D3D11_BUFFER_DESC cb;
//	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
//	cb.Usage = D3D11_USAGE_DYNAMIC;
//	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//	cb.MiscFlags = 0;
//	cb.StructureByteStride = 0;
//
//	// �R���X�^���g�o�b�t�@�̍쐬
//	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//		return hr;
//	}
//	pTexture_ = new Texture;
//	pTexture_->Load("Assets\\dice.png");
//
//	return S_OK;
//}
//
//void Sprite::Draw()
//{
//	CONSTANT_BUFFER cb;
//	cb.matWVP = XMMatrixTranspose(Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
//	D3D11_MAPPED_SUBRESOURCE pdata;
//
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
//
//	//���_�o�b�t�@
//	UINT stride = sizeof(VERTEX);
//	UINT offset = 0;
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
//	stride = sizeof(int);
//	offset = 0;
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//�R���X�^���g�o�b�t�@
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
//
//	Direct3D::pContext->DrawIndexed(6, 0, 0);
//}
//
//void Sprite::Draw(XMMATRIX& worldMatrix)
//{
//	//�R���X�^���g�o�b�t�@�ɓn�����
//	//XMVECTOR position = { 0, 3, -10, 0 };	//�J�����̈ʒu
//	//XMVECTOR target = { 0, 0, 0, 0 };	//�J�����̏œ_
//	//XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//�r���[�s��
//	//XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
//	CONSTANT_BUFFER cb;
//	cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
//
//	D3D11_MAPPED_SUBRESOURCE pdata;
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));//�f�[�^�𑗂�
//	// �f�[�^��l�𑗂�
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
//
//	//���_�o�b�t�@
//	UINT stride = sizeof(VERTEX);
//	UINT offset = 0;
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
//	stride = sizeof(int);
//	offset = 0;
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//�R���X�^���g�o�b�t�@
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
//
//	//�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�ɃZ�b�g
//	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
//	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
//
//	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
//	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);
//
//	Direct3D::pContext->DrawIndexed(6, 0, 0);
//
//}
////void Quad::Draw(XMMATRIX& worldMatrix)
////{
////	//�R���X�^���g�o�b�t�@�ɓn�����
////
////	D3D11_MAPPED_SUBRESOURCE pdata;
////
////	CONSTANT_BUFFER cb;
////
////	cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
////}
////
//
//void Sprite::Release()
//{
//	/*Direct3D::pContext->Release();
//	Direct3D::pDevice->Release();*/
//
//	//pTexture_->Release();
//	//SAFE_DELETE(pTexture_);
//
//	SAFE_RELEASE(pConstantBuffer_);
//	SAFE_RELEASE(pIndexBuffer_);
//	SAFE_RELEASE(pVertexBuffer_);
//}
////#include "Quad.h"
////
////
////Quad::Quad()
////
////{
////
////}
////
////Quad::~Quad()
////
////{
////
////	SAFE_RELEASE(pConstantBuffer_);
////
////	SAFE_RELEASE(pIndexBuffer_);
////
////	SAFE_RELEASE(pVertexBuffer_);
////
////}
////
////HRESULT Quad::Initialize()
////
////{
////
////	// ���_���
////
////	XMVECTOR vertices[] =
////
////	{
////
////		//XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j
////
////		//XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j
////
////		//XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j
////
////		//XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j
////
////		//XMVectorSet(0.5f, -1.4f, 0.0f, 0.0f),//�܊p�`�̒��_�i������j
////
////		//XMVectorSet(-0.5f, -1.4f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�ǂ����j
////
////
////		XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
////
////		XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
////
////		XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
////
////		XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
////
////		XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//�l�p���̒��_
////
////	};
////
////	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
////
////	D3D11_BUFFER_DESC bd_vertex;
////
////	bd_vertex.ByteWidth = sizeof(vertices);
////
////	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
////
////	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
////
////	bd_vertex.CPUAccessFlags = 0;
////
////	bd_vertex.MiscFlags = 0;
////
////	bd_vertex.StructureByteStride = 0;
////
////	D3D11_SUBRESOURCE_DATA data_vertex;
////
////	data_vertex.pSysMem = vertices;
////
////	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_)))
////
////	{
////
////		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
////
////		return E_FAIL;
////
////	}
////
////	Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
////
////	//�C���f�b�N�X���
////
////	int index[] = { 0,2,3, 0,1,2,/* 3,2,4,*/ /*3,4,5*/ 0,1,4, 1,2,4, 4,3,2, 0,4,3 };
////
////	// �C���f�b�N�X�o�b�t�@�𐶐�����
////
////	D3D11_BUFFER_DESC   bd;
////
////	bd.Usage = D3D11_USAGE_DEFAULT;
////
////	bd.ByteWidth = sizeof(index);
////
////	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
////
////	bd.CPUAccessFlags = 0;
////
////	bd.MiscFlags = 0;
////
////	D3D11_SUBRESOURCE_DATA InitData;
////
////	InitData.pSysMem = index;
////
////	InitData.SysMemPitch = 0;
////
////	InitData.SysMemSlicePitch = 0;
////
////	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_)))
////
////	{
////
////		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
////
////		return E_FAIL;
////
////	}
////
////	Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
////
////	//�R���X�^���g�o�b�t�@�쐬
////
////	D3D11_BUFFER_DESC cb;
////
////	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
////
////	cb.Usage = D3D11_USAGE_DYNAMIC;
////
////	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
////
////	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
////
////	cb.MiscFlags = 0;
////
////	cb.StructureByteStride = 0;
////
////	// �R���X�^���g�o�b�t�@�̍쐬
////
////	if (Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_))
////
////	{
////
////		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
////
////		return E_FAIL;
////
////	}
////
////	Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
////
////}
////
////void Quad::Draw()
////
////{
////
////	//�R���X�^���g�o�b�t�@�ɓn�����
////
////	XMVECTOR position = { 0, 3, -10, 0 };	//�J�����̈ʒu
////
////	XMVECTOR target = { 0, 0, 0, 0 };	//�J�����̏œ_
////
////	XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//�r���[�s��
////
////	XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
////
////	CONSTANT_BUFFER cb;
////
////	cb.matWVP = XMMatrixTranspose(view * proj);
////
////	D3D11_MAPPED_SUBRESOURCE pdata;
////
////	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
////
////	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^�̒l�𑗂�
////
////	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
////
////	//���_�o�b�t�@
////
////	UINT stride = sizeof(XMVECTOR);
////
////	UINT offset = 0;
////
////	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
////
////	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
////
////	stride = sizeof(int);
////
////	offset = 0;
////
////	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
////
////	//�R���X�^���g�o�b�t�@
////
////	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
////
////	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
////
////	Direct3D::pContext->DrawIndexed(18, 0, 0);
////
////}
////
////void Quad::Release()
////
////{
////
////	Direct3D::pContext->Release();
////
////	Direct3D::pDevice->Release();
////
////}
#include "Direct3D.h"
#include "Sprite.h"
#include "Camera.h"
#include<filesystem>
#include "Transform.h"
Sprite::Sprite()
	:pTexture_(nullptr), pVertexBuffer_(nullptr), pIndexBuffer_(nullptr), pConstantBuffer_(nullptr),
	vertexNum_(0), indexNum_(0)
{

}

Sprite::~Sprite()
{
	Release();
}

HRESULT Sprite::Load(std::string fileName)
{
	//���_���
	InitVertexData();//�f�[�^�p��
	if (FAILED(CreateVertexBuffer()))//���_�o�b�t�@�쐬
	{
		return E_FAIL;
	}

	InitIndexData();//�f�[�^�p��
	if (FAILED(CreateIndexBuffer()))//�C���f�b�N�X�o�b�t�@�쐬
	{
		return E_FAIL;
	}

	if (FAILED(CreateConstantBuffer()))//�R���X�^���g�o�b�t�@�쐬
	{
		return E_FAIL;
	}
	if (FAILED(LoadTexture(fileName)))//���[�h
	{
		return E_FAIL;
	}

	return S_OK;
}

void Sprite::Draw(Transform& transform)
{
	Direct3D::SetShader(SHADER_TYPE::SHADER_2D);
	//
	transform.Calculation();

	//�R���X�^���g�o�b�t�@�ɏ���n��
	PassDataToCB(transform.GetWorldMatrix());
	//���_�o�b�t�@�A�C���f�b�N�X�o�b�t�@�A�R���X�g�o�b�t�@��
	SetBufferToPipeline();
	//�`��
	Direct3D::pContext->DrawIndexed(indexNum_, 0, 0);

}

//void Sprite::Draw(XMMATRIX& worldMatrix)
//{
//
//	PassDataToCB(worldMatrix);
//	//
//	SetBufferToPipeline();
//	//�`��
//	Direct3D::pContext->DrawIndexed(36, 0, 0);
//}

void Sprite::Release()
{
	SAFE_RELEASE(pTexture_);
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}

void Sprite::InitVertexData()
{
	// ���_���
	vertices_ =
	{
		//x,y,z,w
		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 0.0, 0.0, 0.0) },	// �l�p�`�̒��_�i����j, UV
		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 0.0, 0.0, 0.0) },	// �l�p�`�̒��_�i�E��j, UV
		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 1.0, 0.0, 0.0) },	// �l�p�`�̒��_�i�E���j, UV
		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 1.0, 0.0, 0.0) },	// �l�p�`�̒��_�i�����j, UV
	};
	vertexNum_ = vertices_.size();//���_�������邩 ��̏ꍇ�́A�S��


}

HRESULT Sprite::CreateVertexBuffer()
{
	HRESULT hr;
	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_.data();//�z��̃A�h���X�����炦��
	hr = Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
	//hr = E_FAIL;

	if (FAILED(hr))
	{
		//int MessageBox(
		//	[in, optional] HWND    hWnd,
		//	[in, optional] LPCTSTR lpText,
		//	[in, optional] LPCTSTR lpCaption,
		//	[in]           UINT    uType
		//);
		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

void Sprite::InitIndexData()//�C���f�b�N�X
{
	indices_ = { 0,2,3, 0,1,2 };
	indexNum_ = indices_.size();//�C���f�b�N�X��

}

HRESULT Sprite::CreateIndexBuffer()
{
	// �C���f�b�N�X�o�b�t�@�𐶐�����
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum_;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = indices_.data();//�z��A�h���X�͂����
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
	return S_OK;;
}

HRESULT Sprite::CreateConstantBuffer()
{
	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return hr;
	}
}

HRESULT Sprite::LoadTexture(std::string fileName)
{
	namespace fs = std::filesystem;

	pTexture_ = new Texture;
	assert(fs::is_regular_file(fileName));

	HRESULT hr;
	hr = pTexture_->Load(fileName);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"�e�N�X�`���̍쐬�Ɏ��s���܂���", L"�G���[", MB_OK);
		return hr;
	}
	return S_OK;
}

void Sprite::PassDataToCB(DirectX::XMMATRIX worldMatrix)
{
	CONSTANT_BUFFER cb;
	cb.matW = XMMatrixTranspose(worldMatrix); //MATRIX�̊|���Z�̂�����Dix�ƈႤ�̂œ]�u���Ƃ�
	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
	//�T���v���[�ƃV�F�[�_�[���\�[�X�r���[���V�F�[�_�[�ɃZ�b�g
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);

	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
}

void Sprite::SetBufferToPipeline()
{
	//���_�o�b�t�@
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
}