#include "Quad.h"
#include "Canera.h"
Quad::Quad()
{
}

Quad::~Quad()
{
	SAFE_RELEASE(pConstantBuffer_);
	SAFE_RELEASE(pIndexBuffer_);
	SAFE_RELEASE(pVertexBuffer_);
}

HRESULT Quad::Initialize()
{
	// ���_���
	XMVECTOR vertices[] =
	{
		XMVectorSet(-1.0f,    1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j
 
		XMVectorSet(1.0f,     1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j
 
		XMVectorSet(1.0f,    -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j
 
		XMVectorSet(-1.0f,   -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j	

		XMVectorSet( 0.0f,    -2.0f, 0.0f, 0.0f),
		 
		//XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_

		//XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_

		//XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_

		//XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_

		//XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//�l�p���̒��_
	};

	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
	D3D11_BUFFER_DESC bd_vertex;
 
	bd_vertex.ByteWidth = sizeof(vertices);
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
 
	D3D11_SUBRESOURCE_DATA data_vertex;
 
	data_vertex.pSysMem = vertices;
 
	if(FAILED(Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_)))
	{
		MessageBox(NULL, L"�̍쐬�Ɏ��s", NULL, MB_OK);
		return E_FAIL;
	}
 
	Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);

	//�C���f�b�N�X���
	int index[] = { 0,1,2, 0,2,3, 4,2,3 ,0,4,3 ,1,4,0 ,2,4,1};
	//int index[] = { 0,1,2, 0,2,3, 3,2,4 };
	// �C���f�b�N�X�o�b�t�@�𐶐�����

	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(index);
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = index;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_)))
	{
		MessageBox(NULL, L"���_�̍쐬�Ɏ��s", NULL, MB_OK);
		return E_FAIL;
	}
	Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);

	//�R���X�^���g�o�b�t�@�쐬
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// �R���X�^���g�o�b�t�@�̍쐬
	if (FAILED(Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_)))
	{
		MessageBox(NULL, L"�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
		return E_FAIL;
	}
	Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	
}

void Quad::Draw(XMMATRIX& worldMatrix)
{
	
	//�R���X�^���g�o�b�t�@�ɓn�����
	//XMVECTOR position = { 0, 3, -10, 0 };	//�J�����̈ʒu
	//XMVECTOR target = { 0, 0, 0, 0 };	//�J�����̏œ_
	//XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//�r���[�s��
	//XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
	D3D11_MAPPED_SUBRESOURCE pdata;
	CONSTANT_BUFFER cb;
	cb.matWVP = XMMatrixTranspose(worldMatrix * Canera::GetViewMatrix() * Canera::GetProjectionMatrix());

	
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
    memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^��l�𑗂�
	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ

	//���_�o�b�t�@
	UINT stride = sizeof(XMVECTOR);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//�R���X�^���g�o�b�t�@
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
	Direct3D::pContext->DrawIndexed(100, 0, 0);
}

//void Quad::Draw(XMMATRIX& worldMatrix)
//{
//	//�R���X�^���g�o�b�t�@�ɓn�����
//
//	D3D11_MAPPED_SUBRESOURCE pdata;
//
//	CONSTANT_BUFFER cb;
//
//	cb.matWVP = XMMatrixTranspose(worldMatrix * Canera::GetViewMatrix() * Canera::GetProjectionMatrix());
//}

void Quad::Release()
{
	Direct3D::pContext->Release();
    Direct3D::pDevice->Release();
}
//#include "Quad.h"
//
//
//Quad::Quad()
//
//{
//
//}
//
//Quad::~Quad()
//
//{
//
//	SAFE_RELEASE(pConstantBuffer_);
//
//	SAFE_RELEASE(pIndexBuffer_);
//
//	SAFE_RELEASE(pVertexBuffer_);
//
//}
//
//HRESULT Quad::Initialize()
//
//{
//
//	// ���_���
//
//	XMVECTOR vertices[] =
//
//	{
//
//		//XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i����j
//
//		//XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E��j
//
//		//XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�E���j
//
//		//XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),	// �l�p�`�̒��_�i�����j
//
//		//XMVectorSet(0.5f, -1.4f, 0.0f, 0.0f),//�܊p�`�̒��_�i������j
//
//		//XMVectorSet(-0.5f, -1.4f, 0.0f, 0.0f),//�Z�p�`�̒��_�i�ǂ����j
//
//
//		XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
//
//		XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//�l�p���̒��_
//
//		XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
//
//		XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//�l�p���̒��_
//
//		XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//�l�p���̒��_
//
//	};
//
//	// ���_�f�[�^�p�o�b�t�@�̐ݒ�
//
//	D3D11_BUFFER_DESC bd_vertex;
//
//	bd_vertex.ByteWidth = sizeof(vertices);
//
//	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
//
//	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//
//	bd_vertex.CPUAccessFlags = 0;
//
//	bd_vertex.MiscFlags = 0;
//
//	bd_vertex.StructureByteStride = 0;
//
//	D3D11_SUBRESOURCE_DATA data_vertex;
//
//	data_vertex.pSysMem = vertices;
//
//	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_)))
//
//	{
//
//		MessageBox(NULL, L"���_�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//
//		return E_FAIL;
//
//	}
//
//	Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
//
//	//�C���f�b�N�X���
//
//	int index[] = { 0,2,3, 0,1,2,/* 3,2,4,*/ /*3,4,5*/ 0,1,4, 1,2,4, 4,3,2, 0,4,3 };
//
//	// �C���f�b�N�X�o�b�t�@�𐶐�����
//
//	D3D11_BUFFER_DESC   bd;
//
//	bd.Usage = D3D11_USAGE_DEFAULT;
//
//	bd.ByteWidth = sizeof(index);
//
//	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
//
//	bd.CPUAccessFlags = 0;
//
//	bd.MiscFlags = 0;
//
//	D3D11_SUBRESOURCE_DATA InitData;
//
//	InitData.pSysMem = index;
//
//	InitData.SysMemPitch = 0;
//
//	InitData.SysMemSlicePitch = 0;
//
//	if (FAILED(Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_)))
//
//	{
//
//		MessageBox(NULL, L"�C���f�b�N�X�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//
//		return E_FAIL;
//
//	}
//
//	Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
//
//	//�R���X�^���g�o�b�t�@�쐬
//
//	D3D11_BUFFER_DESC cb;
//
//	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
//
//	cb.Usage = D3D11_USAGE_DYNAMIC;
//
//	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//
//	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//
//	cb.MiscFlags = 0;
//
//	cb.StructureByteStride = 0;
//
//	// �R���X�^���g�o�b�t�@�̍쐬
//
//	if (Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_))
//
//	{
//
//		MessageBox(NULL, L"�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s", NULL, MB_OK);
//
//		return E_FAIL;
//
//	}
//
//	Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
//
//}
//
//void Quad::Draw()
//
//{
//
//	//�R���X�^���g�o�b�t�@�ɓn�����
//
//	XMVECTOR position = { 0, 3, -10, 0 };	//�J�����̈ʒu
//
//	XMVECTOR target = { 0, 0, 0, 0 };	//�J�����̏œ_
//
//	XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//�r���[�s��
//
//	XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//�ˉe�s��
//
//	CONSTANT_BUFFER cb;
//
//	cb.matWVP = XMMatrixTranspose(view * proj);
//
//	D3D11_MAPPED_SUBRESOURCE pdata;
//
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPU����̃f�[�^�A�N�Z�X���~�߂�
//
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// �f�[�^�̒l�𑗂�
//
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//�ĊJ
//
//	//���_�o�b�t�@
//
//	UINT stride = sizeof(XMVECTOR);
//
//	UINT offset = 0;
//
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// �C���f�b�N�X�o�b�t�@�[���Z�b�g
//
//	stride = sizeof(int);
//
//	offset = 0;
//
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//�R���X�^���g�o�b�t�@
//
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//���_�V�F�[�_�[�p	
//
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//�s�N�Z���V�F�[�_�[�p
//
//	Direct3D::pContext->DrawIndexed(18, 0, 0);
//
//}
//
//void Quad::Release()
//
//{
//
//	Direct3D::pContext->Release();
//
//	Direct3D::pDevice->Release();
//
//}