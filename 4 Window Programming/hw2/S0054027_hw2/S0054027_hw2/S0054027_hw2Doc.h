
// S0054027_hw2Doc.h : CS0054027_hw2Doc ���O������
//


#pragma once


class CS0054027_hw2Doc : public CDocument
{
protected: // �ȱq�ǦC�ƫإ�
	CS0054027_hw2Doc();
	DECLARE_DYNCREATE(CS0054027_hw2Doc)

// �ݩ�
public:
	CString m_Data;
	int select_paint; //��u�� ������ ���G��
	int data_number[10] = { }; //0~10 11~20 �@���X�H
	int color[3] = {};  //�C��
	int score[101]; //�Ӥ��Ʀ��X�H
// �@�~
public:

// �мg
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �{���X��@
public:
	virtual ~CS0054027_hw2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ���j�M�B�z�`���]�w�j�M���e�� Helper �禡
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
