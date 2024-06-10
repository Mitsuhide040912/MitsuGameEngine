#include "Texture.h"
#include "Direct3D.h"
#include <DirectXTex.h>
#include <wincodec.h>

using namespace DirectX;
Texture::Texture()
    :pSampler_(nullptr),pSRV_(nullptr)
{
}

Texture::~Texture()
{
}

HRESULT Texture::Load(std::string filename)
{
    TexMetadata matdata;//画像の付属情報
    ScratchImage image; //画像本体

    HRESULT hr = S_OK;

    std::wstring wstr(filename.begin(), filename.end());
    hr = LoadFromWICFile(wstr.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, &matdata, image);//←エラーメッセージ
    if (FAILED(hr))
    {
        return S_FALSE;
    }

    D3D11_SAMPLER_DESC  SamDesc;
    ZeroMemory(&SamDesc, sizeof(D3D11_SAMPLER_DESC));
    SamDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    SamDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    SamDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    SamDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    Direct3D::pDevice->CreateSamplerState(&SamDesc, &pSampler_);
    if (FAILED(hr))
    {
        return S_FALSE;
    }


    D3D11_SHADER_RESOURCE_VIEW_DESC srv = {};
    srv.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srv.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srv.Texture2D.MipLevels = 1;
    hr = CreateShaderResourceView(Direct3D::pDevice,image.GetImages(),image.GetImageCount(),matdata, &pSRV_);
    if (FAILED(hr))
    {
        return S_FALSE;
    }

    return hr;
}

void Texture::Release()
{
    SAFE_RELEASE(pSampler_);
    SAFE_RELEASE(pSRV_);
}
