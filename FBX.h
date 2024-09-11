#pragma once
#include "Direct3D.h"
#include <fbxsdk.h>
#include <DirectXMath.h>
#include <string>
#include "Transform.h"
#include "Texture.h"
#include <filesystem>
#include <vector>

#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

class FBX
{
	struct  MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
	};
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matNormal;
		XMFLOAT4    diffuseColor;
		bool        isTextred;
	};

	struct VERTEX
	{
		XMVECTOR position;
		XMVECTOR uv;
	};

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	std::vector<MATERIAL>pMaterialList_;
	std::vector<int>indexCount_;

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;

	void InitVerTex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void InitConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};

//#pragma once
//#include "Direct3D.h"
//#include <d3d11.h>
//#include <fbxsdk.h>
//#include <string>
//#include "Camera.h"
//#include "Texture.h"
//#include <DirectXCollision.h>
//#include "Transform.h"
//
//#pragma comment(lib, "LibFbxSDK-MD.lib")
//#pragma comment(lib, "LibXml2-MD.lib")
//#pragma comment(lib, "zlib-MD.lib")
//
//using std::vector;
//class Fbx
//{
//	//マテリアル
//	struct MATERIAL
//	{
//		Texture* pTexture;
//		XMFLOAT4	diffuse;
//	};
//	struct CONSTANT_BUFFER
//	{
//		XMMATRIX	matWVP;
//		XMMATRIX	matNormal;
//		XMFLOAT4	diffuseColor;
//		int			isTextured;
//	};
//
//	struct VERTEX
//	{
//		XMVECTOR position;//位置
//		XMVECTOR uv; //テクスチャ座標
//		XMVECTOR normal; //法線ベクトル
//	};
//
//	int vertexCount_;	//頂点数
//	int polygonCount_;	//ポリゴン数
//	int materialCount_;	//マテリアルの個数
//
//	ID3D11Buffer* pVertexBuffer_;
//	ID3D11Buffer** pIndexBuffer_;
//	ID3D11Buffer* pConstantBuffer_;
//	MATERIAL* pMaterialList_;
//	int** ppIndex_;
//	vector <int> indexCount_;
//
//public:
//
//	Fbx();
//	HRESULT Load(std::string fileName);
//	void InitVertex(fbxsdk::FbxMesh* mesh);
//	void InitIndex(fbxsdk::FbxMesh* mesh);
//	void IntConstantBuffer();
//	void InitMaterial(fbxsdk::FbxNode* pNode);
//	void    Draw(Transform& transform);
//	void    Release();
//};