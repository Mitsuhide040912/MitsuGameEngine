//インクルード
#include <Windows.h>
#include "Direct3D.h"

#include "Quad.h"
//#include<tchar.h>
#include "Camera.h"

#pragma comment(lib,"d3d11.lib")

//定数宣言
const wchar_t* WIN_CLASS_NAME = L"SampleGame";  //ウィンドウクラス名
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


//エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウクラス（設計図）を作成
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
	wc.hInstance = hInstance;                   //インスタンスハンドル
	wc.lpszClassName = WIN_CLASS_NAME;          //ウィンドウクラス名
	wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
	wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //マウスカーソル
	wc.lpszMenuName = NULL;                     //メニュー（なし）
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）
	RegisterClassEx(&wc); //クラスを登録

	//ウィンドウサイズの計算
	// (表示領域をWINDOW_WINDOWxHEIGHT_HEIGHTに指定するための計算 )
	RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
	int winW = winRect.right - winRect.left;     //ウィンドウ幅
	int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

  //ウィンドウを作成
	HWND hWnd = CreateWindow(
		WIN_CLASS_NAME,      //ウィンドウクラス名
		L"サンプルゲーム",   //タイトルバーに表示する内容
		WS_OVERLAPPEDWINDOW, //スタイル（普通のウィンドウ）
		CW_USEDEFAULT,       //表示位置左（おまかせ）
		CW_USEDEFAULT,       //表示位置上（おまかせ）
		winW,                //ウィンドウ幅
		winH,                //ウィンドウ高さ
		NULL,                //親ウインドウ（なし）
		NULL,                //メニュー（なし）
		hInstance,           //インスタンス
		NULL                 //パラメータ（なし）
	);

  //ウィンドウを表示
	ShowWindow(hWnd, nCmdShow);

	HRESULT hr = Direct3D::Initialize(winW, winH, hWnd);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"DirectXの初期化に失敗", NULL, MB_OK);
		return 0;
	}

	//Canera::Initialize({ 5,10,-10 }, { 0,0,0 });
	Camera::Initialize();

	Quad* q;
	q = new Quad();
	hr = q->Initialize();

	

	//メッセージループ（何か起きるのを待つ）
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		//メッセージあり
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


		//メッセージなし
		else
		{
			//ゲームの処理
			Direct3D::BeginDraw();
			//カメラ更新
			Camera::Update();
			//↓1度ずつ回転するための変数
			static float rot = 0;
			rot += 0.01;
			XMMATRIX rmat = XMMatrixRotationY(rot);
			static float factor = 0.0;
			factor += 0.001;
			XMMATRIX mat = XMMatrixIdentity();
			XMMATRIX tmat = XMMatrixTranslation(2.0*sin(factor), 2.0*cos(factor), 0.0f);
			mat = rmat * tmat;
			q->Draw(mat);
			//描画処理
			Direct3D::EndDraw();

			
		}
	}

	
	SAFE_DELETE(q);
	//if (q != nullptr) { delete q; }
	Direct3D::Release();
	
	return 0;
}

//ウィンドウプロシージャ（何かあった時によばれる関数）

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);  //プログラム終了
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

