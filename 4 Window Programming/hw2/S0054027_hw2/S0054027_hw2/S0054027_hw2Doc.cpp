
// S0054027_hw2Doc.cpp : CS0054027_hw2Doc ���O����@
//

#include "stdafx.h"
// SHARED_HANDLERS �i�H�w�q�b��@�w���B�Y�ϩM�j�M�z�����B�z�`����
// ATL �M�פ��A�ä��\�P�ӱM�צ@�Τ��{���X�C
#ifndef SHARED_HANDLERS
#include "S0054027_hw2.h"
#endif

#include "S0054027_hw2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CS0054027_hw2Doc

IMPLEMENT_DYNCREATE(CS0054027_hw2Doc, CDocument)

BEGIN_MESSAGE_MAP(CS0054027_hw2Doc, CDocument)
END_MESSAGE_MAP()


// CS0054027_hw2Doc �غc/�Ѻc

CS0054027_hw2Doc::CS0054027_hw2Doc()
{
	// TODO:  �b���[�J�@���غc�{���X

}

CS0054027_hw2Doc::~CS0054027_hw2Doc()
{
}

BOOL CS0054027_hw2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �b���[�J���s��l�Ƶ{���X
	// (SDI ���|���Φ����)

	return TRUE;
}




// CS0054027_hw2Doc �ǦC��

void CS0054027_hw2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �b���[�J�x�s�{���X
	}
	else
	{
		// TODO:  �b���[�J���J�{���X
	}
}

#ifdef SHARED_HANDLERS

// �Y�Ϫ��䴩
void CS0054027_hw2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �ק�o�q�{���X�Hø�s��󪺸��
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �j�M�B�z�`�����䴩
void CS0054027_hw2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// �]�w�Ӧۤ���ƪ��j�M���e�C
	// ���e�������ӥH ";" �j�}

	// �d��:     strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CS0054027_hw2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CS0054027_hw2Doc �E�_

#ifdef _DEBUG
void CS0054027_hw2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CS0054027_hw2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CS0054027_hw2Doc �R�O
