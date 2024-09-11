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
//	// 頂点情報
//	VERTEX vertices[] =
//	{
//		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 0.0, 0.0, 0.0)},	// 四角形の頂点（左上）, UV
//		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 0.0, 0.0, 0.0)},	// 四角形の頂点（右上）, UV
//		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 1.0, 0.0, 0.0)},	// 四角形の頂点（右下）, UV
//		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 1.0, 0.0, 0.0)}	// 四角形の頂点（左下）, UV
//		//{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f) },   // 四角形の頂点（左上）
//		//{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f) },   // 四角形の頂点（右上）
//		//{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	XMVectorSet(1.0f, 1.0f, 0.0f, 0.0f) },   // 四角形の頂点（右下）
//		//{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f) },   // 四角
//		//XMVectorSet(-1.0f,    1.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）
//		//XMVectorSet(1.0f,     1.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）
//		//XMVectorSet(1.0f,    -1.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）
//		//XMVectorSet(-1.0f,   -1.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）	
//		//XMVectorSet( 0.0f,    -2.0f, 0.0f, 0.0f),
//
//		//XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//四角錐の頂点
//		//XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//四角錐の頂点
//		//XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//四角錐の頂点
//		//XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//四角錐の頂点
//		//XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//四角錐の頂点
//	};
//	//インデックス情報
//	int index[] = { 0,2,3, 0,1,2 };
//	// 頂点データ用バッファの設定
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
//		MessageBox(NULL, L"頂点バッファの作成に失敗", NULL, MB_OK);
//		return hr;
//	}
//	// インデックスバッファを生成する
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
//		MessageBox(NULL, L"インデックスの作成に失敗", NULL, MB_OK);
//		return hr;
//	}
//
//	//コンスタントバッファ作成
//	D3D11_BUFFER_DESC cb;
//	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
//	cb.Usage = D3D11_USAGE_DYNAMIC;
//	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
//	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
//	cb.MiscFlags = 0;
//	cb.StructureByteStride = 0;
//
//	// コンスタントバッファの作成
//	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
//	if (FAILED(hr))
//	{
//		MessageBox(NULL, L"コンスタントバッファの作成に失敗", NULL, MB_OK);
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
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データを値を送る
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
//
//	//頂点バッファ
//	UINT stride = sizeof(VERTEX);
//	UINT offset = 0;
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// インデックスバッファーをセット
//	stride = sizeof(int);
//	offset = 0;
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//コンスタントバッファ
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
//
//	Direct3D::pContext->DrawIndexed(6, 0, 0);
//}
//
//void Sprite::Draw(XMMATRIX& worldMatrix)
//{
//	//コンスタントバッファに渡す情報
//	//XMVECTOR position = { 0, 3, -10, 0 };	//カメラの位置
//	//XMVECTOR target = { 0, 0, 0, 0 };	//カメラの焦点
//	//XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//ビュー行列
//	//XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//射影行列
//	CONSTANT_BUFFER cb;
//	cb.matWVP = XMMatrixTranspose(worldMatrix * Camera::GetViewMatrix() * Camera::GetProjectionMatrix());
//
//	D3D11_MAPPED_SUBRESOURCE pdata;
//	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
//	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));//データを送る
//	// データを値を送る
//	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
//
//	//頂点バッファ
//	UINT stride = sizeof(VERTEX);
//	UINT offset = 0;
//	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
//
//	// インデックスバッファーをセット
//	stride = sizeof(int);
//	offset = 0;
//	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
//
//	//コンスタントバッファ
//	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
//	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
//
//	//サンプラーとシェーダーリソースビューをシェーダにセット
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
////	//コンスタントバッファに渡す情報
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
////	// 頂点情報
////
////	XMVECTOR vertices[] =
////
////	{
////
////		//XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f),	// 四角形の頂点（左上）
////
////		//XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),	// 四角形の頂点（右上）
////
////		//XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（右下）
////
////		//XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f),	// 四角形の頂点（左下）
////
////		//XMVectorSet(0.5f, -1.4f, 0.0f, 0.0f),//五角形の頂点（中央上）
////
////		//XMVectorSet(-0.5f, -1.4f, 0.0f, 0.0f),//六角形の頂点（どっか）
////
////
////		XMVectorSet(-1.0f,  0.0f, 1.0f, 0.0f),//四角錐の頂点
////
////		XMVectorSet(1.0f,  0.0f, 1.0f, 0.0f),//四角錐の頂点
////
////		XMVectorSet(1.0f, 0.0f, -1.0f, 0.0f),//四角錐の頂点
////
////		XMVectorSet(-1.0f, 0.0f, -1.0f, 0.0f),//四角錐の頂点
////
////		XMVectorSet(0.0f, 1.3, 0.0f, 0.0f),//四角錐の頂点
////
////	};
////
////	// 頂点データ用バッファの設定
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
////		MessageBox(NULL, L"頂点バッファの作成に失敗", NULL, MB_OK);
////
////		return E_FAIL;
////
////	}
////
////	Direct3D::pDevice->CreateBuffer(&bd_vertex, &data_vertex, &pVertexBuffer_);
////
////	//インデックス情報
////
////	int index[] = { 0,2,3, 0,1,2,/* 3,2,4,*/ /*3,4,5*/ 0,1,4, 1,2,4, 4,3,2, 0,4,3 };
////
////	// インデックスバッファを生成する
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
////		MessageBox(NULL, L"インデックスバッファの作成に失敗", NULL, MB_OK);
////
////		return E_FAIL;
////
////	}
////
////	Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
////
////	//コンスタントバッファ作成
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
////	// コンスタントバッファの作成
////
////	if (Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_))
////
////	{
////
////		MessageBox(NULL, L"コンスタントバッファの作成に失敗", NULL, MB_OK);
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
////	//コンスタントバッファに渡す情報
////
////	XMVECTOR position = { 0, 3, -10, 0 };	//カメラの位置
////
////	XMVECTOR target = { 0, 0, 0, 0 };	//カメラの焦点
////
////	XMMATRIX view = XMMatrixLookAtLH(position, target, XMVectorSet(0, 1, 0, 0));	//ビュー行列
////
////	XMMATRIX proj = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800.0f / 600.0f, 0.1f, 100.0f);//射影行列
////
////	CONSTANT_BUFFER cb;
////
////	cb.matWVP = XMMatrixTranspose(view * proj);
////
////	D3D11_MAPPED_SUBRESOURCE pdata;
////
////	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
////
////	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データの値を送る
////
////	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
////
////	//頂点バッファ
////
////	UINT stride = sizeof(XMVECTOR);
////
////	UINT offset = 0;
////
////	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);
////
////	// インデックスバッファーをセット
////
////	stride = sizeof(int);
////
////	offset = 0;
////
////	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);
////
////	//コンスタントバッファ
////
////	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
////
////	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
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
	//頂点情報
	InitVertexData();//データ用意
	if (FAILED(CreateVertexBuffer()))//頂点バッファ作成
	{
		return E_FAIL;
	}

	InitIndexData();//データ用意
	if (FAILED(CreateIndexBuffer()))//インデックスバッファ作成
	{
		return E_FAIL;
	}

	if (FAILED(CreateConstantBuffer()))//コンスタントバッファ作成
	{
		return E_FAIL;
	}
	if (FAILED(LoadTexture(fileName)))//ロード
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

	//コンスタントバッファに情報を渡す
	PassDataToCB(transform.GetWorldMatrix());
	//頂点バッファ、インデックスバッファ、コンストバッファを
	SetBufferToPipeline();
	//描画
	Direct3D::pContext->DrawIndexed(indexNum_, 0, 0);

}

//void Sprite::Draw(XMMATRIX& worldMatrix)
//{
//
//	PassDataToCB(worldMatrix);
//	//
//	SetBufferToPipeline();
//	//描画
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
	// 頂点情報
	vertices_ =
	{
		//x,y,z,w
		{ XMVectorSet(-1.0f,  1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 0.0, 0.0, 0.0) },	// 四角形の頂点（左上）, UV
		{ XMVectorSet(1.0f,  1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 0.0, 0.0, 0.0) },	// 四角形の頂点（右上）, UV
		{ XMVectorSet(1.0f, -1.0f, 0.0f, 0.0f),  XMVectorSet(1.0, 1.0, 0.0, 0.0) },	// 四角形の頂点（右下）, UV
		{ XMVectorSet(-1.0f, -1.0f, 0.0f, 0.0f), XMVectorSet(0.0, 1.0, 0.0, 0.0) },	// 四角形の頂点（左下）, UV
	};
	vertexNum_ = vertices_.size();//頂点が何個あるか 上の場合は、４つ


}

HRESULT Sprite::CreateVertexBuffer()
{
	HRESULT hr;
	// 頂点データ用バッファの設定
	D3D11_BUFFER_DESC bd_vertex;
	bd_vertex.ByteWidth = sizeof(VERTEX) * vertexNum_;
	bd_vertex.Usage = D3D11_USAGE_DEFAULT;
	bd_vertex.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd_vertex.CPUAccessFlags = 0;
	bd_vertex.MiscFlags = 0;
	bd_vertex.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA data_vertex;
	data_vertex.pSysMem = vertices_.data();//配列のアドレスをもらえる
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
		MessageBox(NULL, L"頂点バッファの作成に失敗", NULL, MB_OK);
		return hr;
	}
	return S_OK;
}

void Sprite::InitIndexData()//インデックス
{
	indices_ = { 0,2,3, 0,1,2 };
	indexNum_ = indices_.size();//インデックス数

}

HRESULT Sprite::CreateIndexBuffer()
{
	// インデックスバッファを生成する
	D3D11_BUFFER_DESC   bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(int) * indexNum_;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = indices_.data();//配列アドレスはこれで
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&bd, &InitData, &pIndexBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"インデックスバッファの作成に失敗", NULL, MB_OK);
		return hr;
	}
	return S_OK;;
}

HRESULT Sprite::CreateConstantBuffer()
{
	//コンスタントバッファ作成
	D3D11_BUFFER_DESC cb;
	cb.ByteWidth = sizeof(CONSTANT_BUFFER);
	cb.Usage = D3D11_USAGE_DYNAMIC;
	cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	cb.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	cb.MiscFlags = 0;
	cb.StructureByteStride = 0;

	// コンスタントバッファの作成
	HRESULT hr;
	hr = Direct3D::pDevice->CreateBuffer(&cb, nullptr, &pConstantBuffer_);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"コンスタントバッファの作成に失敗", NULL, MB_OK);
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
		MessageBox(NULL, L"テクスチャの作成に失敗しました", L"エラー", MB_OK);
		return hr;
	}
	return S_OK;
}

void Sprite::PassDataToCB(DirectX::XMMATRIX worldMatrix)
{
	CONSTANT_BUFFER cb;
	cb.matW = XMMatrixTranspose(worldMatrix); //MATRIXの掛け算のやり方がDixと違うので転置をとる
	D3D11_MAPPED_SUBRESOURCE pdata;
	Direct3D::pContext->Map(pConstantBuffer_, 0, D3D11_MAP_WRITE_DISCARD, 0, &pdata);	// GPUからのデータアクセスを止める
	memcpy_s(pdata.pData, pdata.RowPitch, (void*)(&cb), sizeof(cb));	// データを値を送る
	//サンプラーとシェーダーリソースビューをシェーダーにセット
	ID3D11SamplerState* pSampler = pTexture_->GetSampler();
	Direct3D::pContext->PSSetSamplers(0, 1, &pSampler);
	ID3D11ShaderResourceView* pSRV = pTexture_->GetSRV();
	Direct3D::pContext->PSSetShaderResources(0, 1, &pSRV);

	Direct3D::pContext->Unmap(pConstantBuffer_, 0);	//再開
}

void Sprite::SetBufferToPipeline()
{
	//頂点バッファ
	UINT stride = sizeof(VERTEX);
	UINT offset = 0;
	Direct3D::pContext->IASetVertexBuffers(0, 1, &pVertexBuffer_, &stride, &offset);

	// インデックスバッファーをセット
	stride = sizeof(int);
	offset = 0;
	Direct3D::pContext->IASetIndexBuffer(pIndexBuffer_, DXGI_FORMAT_R32_UINT, 0);

	//コンスタントバッファ
	Direct3D::pContext->VSSetConstantBuffers(0, 1, &pConstantBuffer_);	//頂点シェーダー用	
	Direct3D::pContext->PSSetConstantBuffers(0, 1, &pConstantBuffer_);	//ピクセルシェーダー用
}