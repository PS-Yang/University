
// S0054027_hw2View.h : CS0054027_hw2View ���O������
//

#pragma once
#include "ModelessDlg.h"

class CS0054027_hw2View : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CS0054027_hw2View();
	DECLARE_DYNCREATE(CS0054027_hw2View)

// �ݩ�
public:
	CS0054027_hw2Doc* GetDocument() const;

// �@�~
public:

// �мg
public:
	virtual void OnDraw(CDC* pDC);  // �мg�H�yø���˵�
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CModelessDlg m_modelessDlg;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �{���X��@
public:
	virtual ~CS0054027_hw2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
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

#ifndef _DEBUG  // S0054027_hw2View.cpp ������������
inline CS0054027_hw2Doc* CS0054027_hw2View::GetDocument() const
   { return reinterpret_cast<CS0054027_hw2Doc*>(m_pDocument); }
#endif

