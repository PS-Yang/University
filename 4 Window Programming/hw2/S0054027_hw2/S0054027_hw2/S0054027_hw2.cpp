
// S0054027_hw2.cpp : 定義應用程式的類別行為。
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
int type = 1;//圖形種類
int color[3] = { 255, 0, 0 };*/


// CS0054027_hw2App

BEGIN_MESSAGE_MAP(CS0054027_hw2App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CS0054027_hw2App::OnAppAbout)
	// 依據文件命令的標準檔案
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 標準列印設定命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_OPENF, &CS0054027_hw2App::OnOpenf)
END_MESSAGE_MAP()


// CS0054027_hw2App 建構

CS0054027_hw2App::CS0054027_hw2App()
{
	// 支援重新啟動管理員
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果應用程式是使用 Common Language Runtime 支援 (/clr) 建置的: 
	//     1) 要使重新啟動管理員支援正常運作需要這個額外設定。
	//     2) 在專案中必須將參考加入至 System.Windows.Forms 才能進行建置。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  以唯一的 ID 字串取代下面的應用程式 ID 字串; 建議的
	// 字串格式為 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("S0054027_hw2.AppID.NoVersion"));

	// TODO:  在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}

// 僅有的一個 CS0054027_hw2App 物件

CS0054027_hw2App theApp;


// CS0054027_hw2App 初始設定

BOOL CS0054027_hw2App::InitInstance()
{
	
	
	// 假如應用程式資訊清單指定使用 ComCtl32.dll 6 (含) 以後版本，
	// 來啟動視覺化樣式，在 Windows XP 上，則需要 InitCommonControls()。
	// 否則任何視窗的建立都將失敗。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 設定要包含所有您想要用於應用程式中的
	// 通用控制項類別。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 初始化 OLE 程式庫
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 需要有 AfxInitRichEdit2() 才能使用 RichEdit 控制項	
	// AfxInitRichEdit2();

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO:  您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));
	LoadStdProfileSettings(4);  // 載入標準 INI 檔選項 (包含 MRU)


	// 登錄應用程式的文件範本。文件範本負責在文件、
	// 框架視窗與檢視間進行連接
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_S0054027_hw2TYPE,
		RUNTIME_CLASS(CS0054027_hw2Doc),
		RUNTIME_CLASS(CChildFrame), // 自訂 MDI 子框架
		RUNTIME_CLASS(CS0054027_hw2View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// 建立主 MDI 框架視窗
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// 剖析標準 Shell 命令、DDE、檔案開啟舊檔的命令列
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 在命令列中指定的分派命令。如果已使用 
	// /RegServer、/Register、/Unregserver 或 /Unregister 啟動應用程式，將傳回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 已經初始設定主視窗，所以顯示並更新該視窗
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CS0054027_hw2App::ExitInstance()
{
	// TODO:  處理其他您已經加入的資源
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CS0054027_hw2App 訊息處理常式


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
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

// 執行對話方塊的應用程式命令
void CS0054027_hw2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CS0054027_hw2App 訊息處理常式





void CS0054027_hw2App::OnOpenf()
{
	// TODO:  在此加入您的命令處理常式程式碼
	CString szFilter = _T("*文字文件(*.txt)|*.txt|所有檔案(*.*)|*.*||");
	//CString szFilter = (LPCWSTR)L"*文字文件(*.txt)|*.txt|所有檔案(*.*)|*.*||";
	//CFileDialog fd(true);
	//CFileDialog fd(true, (LPCWSTR)L"*", (LPCWSTR)L"*.txt", OFN_HIDEREADONLY, szFilter, this);//(true開false存)(OFN_HIDEREADONLY開OFN_OVERWRITEPROMPT存)
	CFileDialog fd(true, L"txt", L"*.txt", OFN_HIDEREADONLY, szFilter,NULL);

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildFrame *pChildFrm = (CChildFrame*)pFrame->GetActiveFrame();
	CS0054027_hw2Doc *pDoc = (CS0054027_hw2Doc*)pChildFrm->GetActiveDocument();


	if (fd.DoModal() == IDOK)
	{
		CString szFileName = fd.GetPathName();//取得開啟檔案全名(包含路徑) 
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

		/*CString test; //測試是否分類成功
		for (int i = 0; i <= 9;i++)
		{
			test.Format(_T("%d"), pDoc->data_number[i]);
			AfxMessageBox(test);
		}*/
		pDoc->select_paint=1;//讀檔後預設為1(長條圖)
		pDoc->color[0]=0; //讀檔後預設為藍色
		pDoc->color[1]=0;
		pDoc->color[2]=255;
		(pChildFrm->GetActiveView())->Invalidate(); //更新

	}
}
