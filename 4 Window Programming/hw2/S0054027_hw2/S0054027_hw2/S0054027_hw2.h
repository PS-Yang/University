
// S0054027_hw2.h : S0054027_hw2 ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CS0054027_hw2App:
// �аѾ\��@�����O�� S0054027_hw2.cpp
//

class CS0054027_hw2App : public CWinApp
{
public:
	CS0054027_hw2App();


// �мg
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �{���X��@
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnOpenf();
};

extern CS0054027_hw2App theApp;
