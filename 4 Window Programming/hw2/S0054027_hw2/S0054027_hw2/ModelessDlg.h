#pragma once
#include "afxwin.h"


// CModelessDlg ��ܤ��

class CModelessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModelessDlg)

public:
	CModelessDlg(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CModelessDlg();

// ��ܤ�����
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
public:
	// //������
	CButton m_but1;
	// //��u��
	CButton m_but2;
	afx_msg void On32775();
	afx_msg void OnBnClickedButton1();
	// //�����Χ�u
	int select;
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	CListBox m_listbox;
	afx_msg void OnLbnDblclkList1();
	// //���G��
	CButton m_but3;
	afx_msg void OnBnClickedButton3();
};
