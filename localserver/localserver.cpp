// localserver.cpp : WinMain의 구현입니다.


#include "stdafx.h"
#include "resource.h"
#include "localserver_i.h"



class ClocalserverModule : public ATL::CAtlExeModuleT< ClocalserverModule >
	{
public :
	DECLARE_LIBID(LIBID_localserverLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LOCALSERVER, "{3306F865-17D0-47EC-BC29-BAD4F6E22C8C}")
	};

ClocalserverModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

