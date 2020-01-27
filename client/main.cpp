#include <Windows.h>
#include <ShObjIdl.h>
#include "../localserver/localserver_i.h"
#include "../localserver/localserver_i.c"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;


void ShowErrorMessage(wchar_t* header, HRESULT hr) {
	_wsetlocale(LC_ALL, L"Korean");
	wchar_t* pMsg;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,NULL,hr, MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPTSTR)&pMsg,0,NULL);	
	wprintf(L"%s: Error(0x%08x):%s\n", header, hr, pMsg);
	LocalFree(pMsg);
}

int main(int argc, char** argv) {

	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED|COINIT_DISABLE_OLE1DDE);
	if(SUCCEEDED(hr)) {
		ICalc* pCalc = nullptr;

		hr = CoCreateInstance(CLSID_Calc, nullptr, CLSCTX_ALL, IID_ICalc, (void**)&pCalc);
		if(SUCCEEDED(hr)) {
			LONG a=10, b=20, ret=0;
			pCalc->Add(a, b, &ret);

			printf("%d + %d = %d\n", a, b, ret);

			pCalc->Release();
		}
		else 
			ShowErrorMessage(L"CoCreateInstance", hr);
	}
	else
		ShowErrorMessage(L"CoInitializeEx", hr);

	system("pause");
	return 0;
}