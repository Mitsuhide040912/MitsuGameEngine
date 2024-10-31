#pragma once
#include <string>
#include "FBX.h"

namespace Model
{
	struct ModelData
	{
		FBX* pFbx_;
		Transform transform_;
		std::string filename_;
		ModelData()
			:pFbx_(nullptr),filename_(""){}
	};
	int Load(std::string filename);
	void SetTransform(int hModel, Transform transform);
	void Draw(int hModel);
	void Release();
}
