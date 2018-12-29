
// S0054027_hw2View.h : CS0054027_hw2View 類別的介面
//

#pragma once
#include "ModelessDlg.h"

class CS0054027_hw2View : public CView
{
protected: // 僅從序列化建立
	CS0054027_hw2View();
	DECLARE_DYNCREATE(CS0054027_hw2View)

// 屬性
public:
	CS0054027_hw2Doc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CModelessDlg m_modelessDlg;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CS0054027_hw2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32775();
	afx_msg void OnNewModelessdialog();
	afx_msg void OnColorB();
	afx_msg void OnColorG();
	afx_msg void OnColorR();
	afx_msg void OnType1();
	afx_msg void OnType2();
	afx_msg void OnType3();
};

#ifndef _DEBUG  // S0054027_hw2View.cpp 中的偵錯版本
inline CS0054027_hw2Doc* CS0054027_hw2View::GetDocument() const
   { return reinterpret_cast<CS0054027_hw2Doc*>(m_pDocument); }
#endif

