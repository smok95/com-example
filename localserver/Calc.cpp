// Calc.cpp : CCalc의 구현입니다.

#include "stdafx.h"
#include "Calc.h"


// CCalc



STDMETHODIMP CCalc::Add(LONG a, LONG b, LONG* ret)
{
	// TODO: 여기에 구현 코드를 추가합니다.
	*ret = a+b;
	return S_OK;
}
