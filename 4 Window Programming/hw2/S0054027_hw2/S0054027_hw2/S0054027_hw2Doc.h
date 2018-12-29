
// S0054027_hw2Doc.h : CS0054027_hw2Doc 類別的介面
//


#pragma once


class CS0054027_hw2Doc : public CDocument
{
protected: // 僅從序列化建立
	CS0054027_hw2Doc();
	DECLARE_DYNCREATE(CS0054027_hw2Doc)

// 屬性
public:
	CString m_Data;
	int select_paint; //折線圖 長條圖 散佈圖
	int data_number[10] = { }; //0~10 11~20 共有幾人
	int color[3] = {};  //顏色
	int score[101]; //該分數有幾人
// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 程式碼實作
public:
	virtual ~CS0054027_hw2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 為搜尋處理常式設定搜尋內容的 Helper 函式
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
