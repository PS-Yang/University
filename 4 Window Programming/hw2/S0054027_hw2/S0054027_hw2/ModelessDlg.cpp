// ModelessDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "S0054027_hw2.h"
#include "ModelessDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "S0054027_hw2Doc.h"


// CModelessDlg 對話方塊

IMPLEMENT_DYNAMIC(CModelessDlg, CDialogEx)

CModelessDlg::CModelessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModelessDlg::IDD, pParent)
	, select(0)
{

}

CModelessDlg::~CModelessDlg()
{
}

void CModelessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_but1);
	DDX_Control(pDX, IDC_BUTTON2, m_but2);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Control(pDX, IDC_BUTTON3, m_but3);
}


BEGIN_MESSAGE_MAP(CModelessDlg, CDialogEx)
	//ON_COMMAND(ID_32775, &CModelessDlg::On32775)
	ON_BN_CLICKED(IDC_BUTTON1, &CModelessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CModelessDlg::OnBnClickedButton2)
	ON_LBN_DBLCLK(IDC_LIST1, &CModelessDlg::OnLbnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CModelessDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CModelessDlg 訊息處理常式


/*void CModelessDlg::On32775()
{
	
}*/


void CModelessDlg::OnBnClickedButton1()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	//MessageBox(_T("1"));
	select = 1;
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();

	UpdateData(true);
	pDoc->m_Data = _T("1");
	pDoc->select_paint = select;
	(pChildFrm->GetActiveView())->Invalidate();
	
}


void CModelessDlg::OnBnClickedButton2()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	//MessageBox(_T("2"));
	select = 2;
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();

	UpdateData(true);
	pDoc->m_Data = _T("2");
	pDoc->select_paint = select;
	(pChildFrm->GetActiveView())->Invalidate();
}


BOOL CModelessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此加入額外的初始化
	m_listbox.AddString(_T("紅  色"));
	m_listbox.AddString(_T("橙  色"));
	m_listbox.AddString(_T("黃  色"));
	m_listbox.AddString(_T("綠  色"));
	m_listbox.AddString(_T("藍  色"));
	m_listbox.AddString(_T("青  色"));
	m_listbox.AddString(_T("紫  色"));
	m_listbox.AddString(_T("棕  色"));
	m_listbox.AddString(_T("粉紅色"));
	m_listbox.AddString(_T("天藍色"));
	//m_listbox.SetCurSel(5);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION:  OCX 屬性頁應傳回 FALSE
}


void CModelessDlg::OnLbnDblclkList1()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	int index = m_listbox.GetCurSel();
	if (index == 0)
	{
		pDoc->color[0] = 255;
		pDoc->color[1] = 0;
		pDoc->color[2] = 0;
	}
	else if (index == 1)
	{
		pDoc->color[0] = 255;
		pDoc->color[1] = 127;
		pDoc->color[2] = 0;
	}
	else if (index == 2)
	{
		pDoc->color[0] = 255;
		pDoc->color[1] = 255;
		pDoc->color[2] = 0;
	}
	else if (index == 3)
	{
		pDoc->color[0] = 0;
		pDoc->color[1] = 255;
		pDoc->color[2] = 0;
	}
	else if (index == 4)
	{
		pDoc->color[0] = 0;
		pDoc->color[1] = 0;
		pDoc->color[2] = 255;
	}
	else if (index == 5)
	{
		pDoc->color[0] = 0;
		pDoc->color[1] = 255;
		pDoc->color[2] = 255;
	}
	else if (index == 6)
	{
		pDoc->color[0] = 160;
		pDoc->color[1] = 32;
		pDoc->color[2] = 240;
	}
	else if (index == 7)
	{
		pDoc->color[0] = 165;
		pDoc->color[1] = 42;
		pDoc->color[2] = 42;
	}
	else if (index == 8)
	{
		pDoc->color[0] = 255;
		pDoc->color[1] = 105;
		pDoc->color[2] = 180;
	}
	else if (index == 9)
	{
		pDoc->color[0] = 135;
		pDoc->color[1] = 206;
		pDoc->color[2] = 255;
	}
	
	(pChildFrm->GetActiveView())->Invalidate();
}


void CModelessDlg::OnBnClickedButton3()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	select = 3;
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();

	UpdateData(true);
	pDoc->m_Data = _T("3");
	pDoc->select_paint = select;
	(pChildFrm->GetActiveView())->Invalidate();
}
