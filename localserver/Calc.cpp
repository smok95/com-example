// Calc.cpp : CCalc�� �����Դϴ�.

#include "stdafx.h"
#include "Calc.h"


// CCalc



STDMETHODIMP CCalc::Add(LONG a, LONG b, LONG* ret)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	*ret = a+b;
	return S_OK;
}
