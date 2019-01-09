#pragma once
#include "JM.h"
#include "Scripting/LuaScript.h"
#include "Scripting/Luna.h"
#include "Graphics/Camera/MayaCamera.h"
#include "CameraBinding.h"

namespace jm
{
	class JM_EXPORT CameraMayaBinding : public CameraBinding
	{
	public:
		static const char className[];
		static Luna<CameraMayaBinding>::FunctionType methods[];
		static Luna<CameraMayaBinding>::PropertyType properties[];

		explicit CameraMayaBinding(MayaCamera* camera);
		CameraMayaBinding(lua_State* L);
		~CameraMayaBinding();

		static void Bind();
	};
}

