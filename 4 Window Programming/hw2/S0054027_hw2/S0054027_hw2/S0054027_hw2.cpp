
// S0054027_hw2.cpp : �w�q���ε{�������O�欰�C
//

#include <iostream>
#include <fstream>
#include <string>

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "S0054027_hw2.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "S0054027_hw2Doc.h"
#include "S0054027_hw2View.h"
#include "ModelessDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


int number[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
/*
int type = 1;//�ϧκ���
int color[3] = { 255, 0, 0 };*/


// CS0054027_hw2App

BEGIN_MESSAGE_MAP(CS0054027_hw2App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CS0054027_hw2App::OnAppAbout)
	// �̾ڤ��R�O���з��ɮ�
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// �зǦC�L�]�w�R�O
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_OPENF, &CS0054027_hw2App::OnOpenf)
END_MESSAGE_MAP()


// CS0054027_hw2App �غc

CS0054027_hw2App::CS0054027_hw2App()
{
	// �䴩���s�Ұʺ޲z��
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// �p�G���ε{���O�ϥ� Common Language Runtime �䴩 (/clr) �ظm��: 
	//     1) �n�ϭ��s�Ұʺ޲z���䴩���`�B�@�ݭn�o���B�~�]�w�C
	//     2) �b�M�פ������N�Ѧҥ[�J�� System.Windows.Forms �~��i��ظm�C
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  �H�ߤ@�� ID �r����N�U�������ε{�� ID �r��; ��ĳ��
	// �r��榡�� CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("S0054027_hw2.AppID.NoVersion"));

	// TODO:  �b���[�J�غc�{���X�A
	// �N�Ҧ����n����l�]�w�[�J InitInstance ��
}

// �Ȧ����@�� CS0054027_hw2App ����

CS0054027_hw2App theApp;


// CS0054027_hw2App ��l�]�w

BOOL CS0054027_hw2App::InitInstance()
{
	
	
	// ���p���ε{����T�M����w�ϥ� ComCtl32.dll 6 (�t) �H�᪩���A
	// �ӱҰʵ�ı�Ƽ˦��A�b Windows XP �W�A�h�ݭn InitCommonControls()�C
	// �_�h����������إ߳��N���ѡC
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �]�w�n�]�t�Ҧ��z�Q�n�Ω����ε{������
	// �q�α�����O�C
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��l�� OLE �{���w
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// �ݭn�� AfxInitRichEdit2() �~��ϥ� RichEdit ���	
	// AfxInitRichEdit2();

	// �зǪ�l�]�w
	// �p�G�z���ϥγo�ǥ\��åB�Q���
	// �̫᧹�����i�����ɤj�p�A�z�i�H
	// �q�U�C�{���X�������ݭn����l�Ʊ`���A
	// �ܧ��x�s�]�w�Ȫ��n�����X
	// TODO:  �z���ӾA�׭ק惡�r��
	// (�Ҧp�A���q�W�٩β�´�W��)
	SetRegistryKey(_T("���� AppWizard �Ҳ��ͪ����ε{��"));
	LoadStdProfileSettings(4);  // ���J�з� INI �ɿﶵ (�]�t MRU)


	// �n�����ε{�������d���C���d���t�d�b���B
	// �ج[�����P�˵����i��s��
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_S0054027_hw2TYPE,
		RUNTIME_CLASS(CS0054027_hw2Doc),
		RUNTIME_CLASS(CChildFrame), // �ۭq MDI �l�ج[
		RUNTIME_CLASS(CS0054027_hw2View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// �إߥD MDI �ج[����
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// ��R�з� Shell �R�O�BDDE�B�ɮ׶}�����ɪ��R�O�C
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// �b�R�O�C�����w�������R�O�C�p�G�w�ϥ� 
	// /RegServer�B/Register�B/Unregserver �� /Unregister �Ұ����ε{���A�N�Ǧ^ FALSE�C
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �w�g��l�]�w�D�����A�ҥH��ܨç�s�ӵ���
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CS0054027_hw2App::ExitInstance()
{
	// TODO:  �B�z��L�z�w�g�[�J���귽
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CS0054027_hw2App �T���B�z�`��


// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �����ܤ�������ε{���R�O
void CS0054027_hw2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CS0054027_hw2App �T���B�z�`��





void CS0054027_hw2App::OnOpenf()
{
	// TODO:  �b���[�J�z���R�O�B�z�`���{���X
	CString szFilter = _T("*��r���(*.txt)|*.txt|�Ҧ��ɮ�(*.*)|*.*||");
	//CString szFilter = (LPCWSTR)L"*��r���(*.txt)|*.txt|�Ҧ��ɮ�(*.*)|*.*||";
	//CFileDialog fd(true);
	//CFileDialog fd(true, (LPCWSTR)L"*", (LPCWSTR)L"*.txt", OFN_HIDEREADONLY, szFilter, this);//(true�}false�s)(OFN_HIDEREADONLY�}OFN_OVERWRITEPROMPT�s)
	CFileDialog fd(true, L"txt", L"*.txt", OFN_HIDEREADONLY, szFilter,NULL);

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();


	if (fd.DoModal() == IDOK)
	{
		CString szFileName = fd.GetPathName();//���o�}���ɮץ��W(�]�t���|) 
		CString strTemp/*,test*/;
		for (int i = 0; i <= 9;i++)
			pDoc->data_number[i]=0;
		for (int j = 0; j <= 100; j++)
			pDoc->score[j] = 0;

		int num;
		CStdioFile fr(szFileName, CFile::modeRead);
		while (fr.ReadString(strTemp))
		{
			
			num = _ttoi(strTemp); //Cstring to int
			pDoc->score[num] = pDoc->score[num] + 1;

			//test.Format(_T("%d"), num); //int to Cstring
			switch (num / 10)
			{
			case 0:
				number[0]++;
				pDoc->data_number[0]++;
				break;
			case 1:
				number[1]++;
				pDoc->data_number[1]++;
				break;
			case 2:
				number[2]++;
				pDoc->data_number[2]++;
				break;
			case 3:
				number[3]++;
				pDoc->data_number[3]++;
				break;
			case 4:
				number[4]++;
				pDoc->data_number[4]++;
				break;
			case 5:
				number[5]++;
				pDoc->data_number[5]++;
				break;
			case 6:
				number[6]++;
				pDoc->data_number[6]++;
				break;
			case 7:
				number[7]++;
				pDoc->data_number[7]++;
				break;
			case 8:
				number[8]++;
				pDoc->data_number[8]++;
				break;
			case 9:
				number[9]++;
				pDoc->data_number[9]++;
				break;
			case 10:
				number[9]++;
				pDoc->data_number[9]++;
				break;
			}
		}
		fr.Close();

		/*CString test; //���լO�_�������\
		for (int i = 0; i <= 9;i++)
		{
			test.Format(_T("%d"), pDoc->data_number[i]);
			AfxMessageBox(test);
		}*/
		pDoc->select_paint=1;//Ū�ɫ�w�]��1(������)
		pDoc->color[0]=0; //Ū�ɫ�w�]���Ŧ�
		pDoc->color[1]=0;
		pDoc->color[2]=255;
		(pChildFrm->GetActiveView())->Invalidate(); //��s

	}
}
