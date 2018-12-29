
// S0054027_hw2.h : S0054027_hw2 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CS0054027_hw2App:
// 請參閱實作此類別的 S0054027_hw2.cpp
//

class CS0054027_hw2App : public CWinApp
{
public:
	CS0054027_hw2App();


// 覆寫
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnOpenf();
};

extern CS0054027_hw2App theApp;
