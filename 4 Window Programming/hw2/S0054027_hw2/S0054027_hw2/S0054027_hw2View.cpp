
// S0054027_hw2View.cpp : CS0054027_hw2View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "S0054027_hw2.h"
#endif

#include "S0054027_hw2Doc.h"
#include "S0054027_hw2View.h"
#include "ModelessDlg.h"

#include "MainFrm.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// CS0054027_hw2View

IMPLEMENT_DYNCREATE(CS0054027_hw2View, CView)

BEGIN_MESSAGE_MAP(CS0054027_hw2View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32775, &CS0054027_hw2View::On32775)
	ON_COMMAND(ID_NEW_MODELESSDIALOG, &CS0054027_hw2View::OnNewModelessdialog)
	ON_COMMAND(ID_COLOR_B, &CS0054027_hw2View::OnColorB)
	ON_COMMAND(ID_COLOR_G, &CS0054027_hw2View::OnColorG)
	ON_COMMAND(ID_COLOR_R, &CS0054027_hw2View::OnColorR)
	ON_COMMAND(ID_TYPE1, &CS0054027_hw2View::OnType1)
	ON_COMMAND(ID_TYPE2, &CS0054027_hw2View::OnType2)
	ON_COMMAND(ID_TYPE3, &CS0054027_hw2View::OnType3)
END_MESSAGE_MAP()

// CS0054027_hw2View 建構/解構

CS0054027_hw2View::CS0054027_hw2View()
{
	// TODO:  在此加入建構程式碼

}

CS0054027_hw2View::~CS0054027_hw2View()
{
}

BOOL CS0054027_hw2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CS0054027_hw2View 描繪

void CS0054027_hw2View::OnDraw(CDC* pDC)
{
	CS0054027_hw2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO:  在此加入原生資料的描繪程式碼
	//pDC->TextOutW(0, 0, pDoc->m_Data);
	/*CString test;
	test.Format(_T("%d"), pDoc->data_number[0]);
	pDC->TextOutW(0, 0, test);*/
	CString test;
	CPen cPen;
	CBrush cBrush(RGB(255, 255, 255));
	CPen* pOldPen;
	CBrush* pOldBrush;

	cPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	pOldPen = pDC->SelectObject(&cPen);
	pOldBrush = pDC->SelectObject(&cBrush);
	//CClientDC dc(this);
	CRect rect(60, 318, 515, 320);
	CRect rect2(105, 314, 107, 320); //刻度
	CRect rect3(150, 314, 152, 320); //|
	CRect rect4(195, 314, 197, 320);
	CRect rect5(240, 314, 242, 320);
	CRect rect6(285, 314, 287, 320);
	CRect rect7(330, 314, 332, 320);
	CRect rect8(375, 314, 377, 320);
	CRect rect9(420, 314, 422, 320); //|
	CRect rect10(465, 314, 467, 320); //刻度

	CRect rect11(60, 50, 65, 51);
	CRect rect12(60, 50, 62, 320); //最左邊線
	CRect rect13(513, 50, 515, 320);//最右邊線
	pDC->Rectangle(rect);
	pDC->Rectangle(rect2);
	pDC->Rectangle(rect3);
	pDC->Rectangle(rect4);
	pDC->Rectangle(rect5);
	pDC->Rectangle(rect6);
	pDC->Rectangle(rect7);
	pDC->Rectangle(rect8);
	pDC->Rectangle(rect9);
	pDC->Rectangle(rect10);
	pDC->Rectangle(rect11);
	pDC->Rectangle(rect12);
	pDC->Rectangle(rect13);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	
	cPen.DeleteObject();
	cBrush.DeleteObject();
	pDC->TextOutW(25, 0, _T("人數"));
	pDC->TextOutW(40, 40, _T("30"));
	pDC->TextOutW(40, 85, _T("25"));
	pDC->TextOutW(40, 130, _T("20"));
	pDC->TextOutW(40, 175, _T("15"));
	pDC->TextOutW(40, 220, _T("10"));
	pDC->TextOutW(40, 265, _T("  5"));
	pDC->TextOutW(40, 310, _T("  0"));
	pDC->TextOutW(40, 330, _T("        0        10       20       30       40       50        60        70       80       90        分數"));
	
	CBrush cBrush2(RGB(108, 108, 108));
	cPen.CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&cPen);
	pOldBrush = pDC->SelectObject(&cBrush2);
	CRect rect14(60, 275, 515, 276);
	CRect rect15(60, 230, 515, 231);
	CRect rect16(60, 185, 515, 186);
	CRect rect17(60, 140, 515, 141);
	CRect rect18(60, 95, 515, 96);
	CRect rect19(60, 50, 515, 51);
	pDC->Rectangle(rect14);
	pDC->Rectangle(rect15);
	pDC->Rectangle(rect16);
	pDC->Rectangle(rect17);
	pDC->Rectangle(rect18);
	pDC->Rectangle(rect19);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	cPen.DeleteObject();
	cBrush.DeleteObject();

	if (pDoc->select_paint == 1 || pDoc->select_paint == 2)//印出分區人數
	{
		test.Format(_T("%d"), pDoc->data_number[0]);
		pDC->TextOutW(76, 300 - (pDoc->data_number[0] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[1]);
		pDC->TextOutW(120, 300 - (pDoc->data_number[1] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[2]);
		pDC->TextOutW(165, 300 - (pDoc->data_number[2] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[3]);
		pDC->TextOutW(209, 300 - (pDoc->data_number[3] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[4]);
		pDC->TextOutW(255, 300 - (pDoc->data_number[4] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[5]);
		pDC->TextOutW(300, 300 - (pDoc->data_number[5] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[6]);
		pDC->TextOutW(345, 300 - (pDoc->data_number[6] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[7]);
		pDC->TextOutW(390, 300 - (pDoc->data_number[7] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[8]);
		pDC->TextOutW(435, 300 - (pDoc->data_number[8] * 9), test);
		test.Format(_T("%d"), pDoc->data_number[9]);
		pDC->TextOutW(480, 300 - (pDoc->data_number[9] * 9), test);
	}


	if (pDoc->select_paint == 1)
	{
		cPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		//CBrush cBrush3(RGB(0, 0, 255));
		CBrush cBrush3(RGB(pDoc->color[0], pDoc->color[1], pDoc->color[2]));
		pOldPen = pDC->SelectObject(&cPen);
		pOldBrush = pDC->SelectObject(&cBrush3);
		CRect rec(72.5, 320 - (pDoc->data_number[0] * 9), 92.5, 321);
		CRect rec1(117.5, 320 - (pDoc->data_number[1] * 9), 137.5, 321);
		CRect rec2(162.5, 320 - (pDoc->data_number[2] * 9), 182.5, 321);
		CRect rec3(207.5, 320 - (pDoc->data_number[3] * 9), 227.5, 321);
		CRect rec4(252.5, 320 - (pDoc->data_number[4] * 9), 272.5, 321);
		CRect rec5(297.5, 320 - (pDoc->data_number[5] * 9), 317.5, 321);
		CRect rec6(342.5, 320 - (pDoc->data_number[6] * 9), 362.5, 321);
		CRect rec7(387.5, 320 - (pDoc->data_number[7] * 9), 407.5, 321);
		CRect rec8(432.5, 320 - (pDoc->data_number[8] * 9), 452.5, 321);
		CRect rec9(477.5, 320 - (pDoc->data_number[9] * 9), 497.5, 321);
		pDC->Rectangle(rec);
		pDC->Rectangle(rec1);
		pDC->Rectangle(rec2);
		pDC->Rectangle(rec3);
		pDC->Rectangle(rec4);
		pDC->Rectangle(rec5);
		pDC->Rectangle(rec6);
		pDC->Rectangle(rec7);
		pDC->Rectangle(rec8);
		pDC->Rectangle(rec9);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	
	}
	else if(pDoc->select_paint == 2)
	{
		//cPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		//CBrush cBrush4(RGB(0, 0, 255));
		cPen.CreatePen(PS_SOLID, 2, RGB(pDoc->color[0], pDoc->color[1], pDoc->color[2]));
		CBrush cBrush4(RGB(pDoc->color[0], pDoc->color[1], pDoc->color[2]));
		pOldPen = pDC->SelectObject(&cPen);
		pOldBrush = pDC->SelectObject(&cBrush4);

		pDC->MoveTo(82.5, 320 - (pDoc->data_number[0] * 9));
		pDC->LineTo(127.5, 320 - (pDoc->data_number[1] * 9));
		pDC->LineTo(172.5, 320 - (pDoc->data_number[2] * 9));
		pDC->LineTo(217.5, 320 - (pDoc->data_number[3] * 9));
		pDC->LineTo(262.5, 320 - (pDoc->data_number[4] * 9));
		pDC->LineTo(307.5, 320 - (pDoc->data_number[5] * 9));
		pDC->LineTo(352.5, 320 - (pDoc->data_number[6] * 9));
		pDC->LineTo(397.5, 320 - (pDoc->data_number[7] * 9));
		pDC->LineTo(442.5, 320 - (pDoc->data_number[8] * 9));
		pDC->LineTo(487.5, 320 - (pDoc->data_number[9] * 9));

	}
	else if (pDoc->select_paint == 3)
	{
		cPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		CBrush cBrush5(RGB(pDoc->color[0], pDoc->color[1], pDoc->color[2]));
		pOldPen = pDC->SelectObject(&cPen);
		pOldBrush = pDC->SelectObject(&cBrush5);

		
		for (int i = 0; i <= 100; i++)
		{
			if (pDoc->score[i]!=0)
			{
			CRect re(59 + i*4.5, 320 - (pDoc->score[i] * 9) + 2 , 63 + i*4.5, 320 - (pDoc->score[i] * 9) - 2);
			pDC->Rectangle(re);
			/*test.Format(_T("%d"), pDoc->score[i]);
			pDC->TextOutW(60+i*4.5, 300 - (pDoc->score[i] * 9), test);*/
			}
		}
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	}
	cPen.DeleteObject();
	cBrush.DeleteObject();
	
}


// CS0054027_hw2View 列印

BOOL CS0054027_hw2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CS0054027_hw2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印前額外的初始設定
}

void CS0054027_hw2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  加入列印後的清除程式碼
}


// CS0054027_hw2View 診斷

#ifdef _DEBUG
void CS0054027_hw2View::AssertValid() const
{
	CView::AssertValid();
}

void CS0054027_hw2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CS0054027_hw2Doc* CS0054027_hw2View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CS0054027_hw2Doc)));
	return (CS0054027_hw2Doc*)m_pDocument;
}
#endif //_DEBUG


// CS0054027_hw2View 訊息處理常式


void CS0054027_hw2View::On32775()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CModelessDlg modalDlg;
	if (modalDlg.DoModal() == IDOK)
	{
		
	}
}


void CS0054027_hw2View::OnNewModelessdialog()
{
	// TODO:  在此加入您的命令處理常式程式碼
	if (m_modelessDlg.GetSafeHwnd())
		m_modelessDlg.ShowWindow(SW_SHOW);
	else 
	{
		m_modelessDlg.Create(IDD_DIALOG1, NULL);
		m_modelessDlg.CenterWindow(AfxGetMainWnd());
		m_modelessDlg.ShowWindow(SW_SHOW);
	}


	//(m_modelessDlg.GetDlgItem(IDOK))->EnableWindow(false);
	//(m_modelessDlg.GetDlgItem(IDCANCEL))->ShowWindow(SW_HIDE);
}


void CS0054027_hw2View::OnColorB()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->color[0] = 0; //讀檔後預設為紅色
	pDoc->color[1] = 0;
	pDoc->color[2] = 255;
	(pChildFrm->GetActiveView())->Invalidate();
}


void CS0054027_hw2View::OnColorG()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->color[0] = 0; //讀檔後預設為綠色
	pDoc->color[1] = 255;
	pDoc->color[2] = 0;
	(pChildFrm->GetActiveView())->Invalidate();
}


void CS0054027_hw2View::OnColorR()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->color[0] = 255; //讀檔後預設為藍色
	pDoc->color[1] = 0;
	pDoc->color[2] = 0;
	
	(pChildFrm->GetActiveView())->Invalidate();
}


void CS0054027_hw2View::OnType1()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->select_paint = 2;
	(pChildFrm->GetActiveView())->Invalidate();
}


void CS0054027_hw2View::OnType2()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->select_paint =1;
	(pChildFrm->GetActiveView())->Invalidate();
}


void CS0054027_hw2View::OnType3()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();
	pDoc->select_paint = 3;
	(pChildFrm->GetActiveView())->Invalidate();
}
