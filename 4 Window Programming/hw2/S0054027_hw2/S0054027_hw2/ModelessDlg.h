#pragma once
#include "afxwin.h"


// CModelessDlg 對話方塊

class CModelessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModelessDlg)

public:
	CModelessDlg(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~CModelessDlg();

// 對話方塊資料
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	// //長條圖
	CButton m_but1;
	// //折線圖
	CButton m_but2;
	afx_msg void On32775();
	afx_msg void OnBnClickedButton1();
	// //長條或折線
	int select;
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	CListBox m_listbox;
	afx_msg void OnLbnDblclkList1();
	// //散佈圖
	CButton m_but3;
	afx_msg void OnBnClickedButton3();
};
