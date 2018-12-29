// S0054027_hw1.cpp : 定義應用程式的進入點。
//


#include "stdafx.h"
#include "S0054027_hw1.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_LOADSTRING 100

#define NUMBOOKS 10
// books database
struct booksTag {
	TCHAR color_select[40];
} books[NUMBOOKS] = {
	{ _T(" 紅  色 ") },
	{ _T(" 橙  色 ") },
	{ _T(" 黃  色 ")},
	{ _T(" 綠  色 ") },
	{ _T(" 藍  色 ")},
	{ _T(" 青  色 ") },
	{ _T(" 紫  色 ") },
	{ _T(" 棕  色 ") },
	{ _T(" 粉紅色 ") },
	{ _T(" 天藍色 ") },
};

// 全域變數: 
HINSTANCE hInst;								// 目前執行個體
TCHAR szTitle[MAX_LOADSTRING];					// 標題列文字
TCHAR szWindowClass[MAX_LOADSTRING];			// 主視窗類別名稱

//int number[10] = { 1, 2, 3, 8, 10, 0, 6, 4 ,2 ,4 };
int number[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int type=1;//圖形種類
int color[3] = { 255, 0, 0 };
string str;



#define SIZE 100
char line[SIZE];

// 這個程式碼模組中所包含之函式的向前宣告: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK	score(HWND, UINT, WPARAM, LPARAM);


//
TCHAR text[200] = _T("0        10       20       30       40       50        60        70       80       90        分數");
TCHAR text1[40] = _T("0");
TCHAR text2[40] = _T("5");
TCHAR text3[40] = _T("10");
TCHAR text4[40] = _T("15");
TCHAR text5[40] = _T("20");
TCHAR text6[40] = _T("25");
TCHAR text7[40] = _T("30");
TCHAR text8[40] = _T("人數");

TCHAR sc[40] = _T("");




int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	ifstream fin("1.txt");
	//if (!fin){ return 0; }
	while (getline(fin,str)) //while (fin.getline(line, sizeof(line)))
	{
		int num = atoi(str.c_str()) / 10; //int num = atoi(line) / 10;
		switch (num)
		{
		case 0:
			number[0]++;
			break;
		case 1:
			number[1]++;
			break;
		case 2:
			number[2]++;
			break;
		case 3:
			number[3]++;
			break;
		case 4:
			number[4]++;
			break;
		case 5:
			number[5]++;
			break;
		case 6:
			number[6]++;
			break;
		case 7:
			number[7]++;
			break;
		case 8:
			number[8]++;
			break;
		case 9:
			number[9]++;
			break;
		case 10:
			number[9]++;
			break;
		}
	}
	fin.close();

 	// TODO:  在此置入程式碼。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全域字串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_S0054027_HW1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	
	// 執行應用程式初始設定: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_S0054027_HW1));

	// 主訊息迴圈: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函式:  MyRegisterClass()
//
//  用途:  註冊視窗類別。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_S0054027_HW1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_S0054027_HW1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函式:  InitInstance(HINSTANCE, int)
//
//   用途:  儲存執行個體控制代碼並且建立主視窗
//
//   註解: 
//
//        在這個函式中，我們會將執行個體控制代碼儲存在全域變數中，
//        並且建立和顯示主程式視窗。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 將執行個體控制代碼儲存在全域變數中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
  
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   return TRUE;
}

//
//  函式:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  用途:     處理主視窗的訊息。
//
//  WM_COMMAND	- 處理應用程式功能表
//  WM_PAINT	- 繪製主視窗
//  WM_DESTROY	- 顯示結束訊息然後返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 剖析功能表選取項目: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case ID_select:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC) score);
			InvalidateRect(hWnd, NULL, true);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO:  在此加入任何繪圖程式碼...
		HPEN hPen, hPenOld;
		HBRUSH hBrush, hBrushOld;
		hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	    hBrush = CreateSolidBrush(RGB(255, 255, 255));
		
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

		Rectangle(hdc, 60, 318, 515, 320);
		Rectangle(hdc, 105, 314, 107, 320); //刻度
		Rectangle(hdc, 150, 314, 152, 320); //|
		Rectangle(hdc, 195, 314, 197, 320);
		Rectangle(hdc, 240, 314, 242, 320);
		Rectangle(hdc, 285, 314, 287, 320);
		Rectangle(hdc, 330, 314, 332, 320);
		Rectangle(hdc, 375, 314, 377, 320);
		Rectangle(hdc, 420, 314, 422, 320); //|
		Rectangle(hdc, 465, 314, 467, 320); //刻度
	
		Rectangle(hdc, 60, 50, 65, 51);
		Rectangle(hdc, 60, 50, 62, 320); //最左邊線
		Rectangle(hdc, 513, 50, 515, 320);//最右邊線
		TextOut(hdc, 80, 330, text, _tcslen(text));
		TextOut(hdc, 45, 310, text1, _tcslen(text1));
		TextOut(hdc, 45, 265, text2, _tcslen(text2));
		TextOut(hdc, 40, 220, text3, _tcslen(text3));
		TextOut(hdc, 40, 175, text4, _tcslen(text4));
		TextOut(hdc, 40, 130, text5, _tcslen(text5));
		TextOut(hdc, 40, 85, text6, _tcslen(text6));
		TextOut(hdc, 40, 40, text7, _tcslen(text7)); 
		TextOut(hdc, 25, 0, text8, _tcslen(text8)); //人數
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		SelectObject(hdc, hBrushOld);
		DeleteObject(hBrush);

		hPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
		hBrush = CreateSolidBrush(RGB(108, 108, 108));
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
		/*Rectangle(hdc, 66, 275, 555, 276);
		Rectangle(hdc, 66, 230, 555, 231);
		Rectangle(hdc, 66, 185, 555, 186);
		Rectangle(hdc, 66, 140, 555, 141);
		Rectangle(hdc, 66, 95, 555, 96);
		Rectangle(hdc, 66, 50, 555, 51);*/

		Rectangle(hdc, 60, 275, 515, 276);
		Rectangle(hdc, 60, 230, 515, 231);
		Rectangle(hdc, 60, 185, 515, 186);
		Rectangle(hdc, 60, 140, 515, 141);
		Rectangle(hdc, 60, 95, 515, 96);
		Rectangle(hdc, 60, 50, 515, 51);
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		SelectObject(hdc, hBrushOld);
		DeleteObject(hBrush);

		_stprintf_s(sc, _T("%i"), number[0]);
		TextOut(hdc, 76, 300 - (number[0] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[1]);
		TextOut(hdc, 120, 300 - (number[1] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[2]);
		TextOut(hdc, 165, 300 - (number[2] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[3]);
		TextOut(hdc, 209, 300 - (number[3] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[4]);
		TextOut(hdc, 255, 300 - (number[4] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[5]);
		TextOut(hdc, 300, 300 - (number[5] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[6]);
		TextOut(hdc, 345, 300 - (number[6] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[7]);
		TextOut(hdc, 390, 300 - (number[7] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[8]);
		TextOut(hdc, 435, 300 - (number[8] * 9), sc, _tcslen(sc));
		_stprintf_s(sc, _T("%i"), number[9]);
		TextOut(hdc, 480, 300 - (number[9] * 9), sc, _tcslen(sc));

		if (type == 2)
		{
			hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
			hBrush = CreateSolidBrush(RGB(color[0], color[1], color[2]));
			hPenOld = (HPEN)SelectObject(hdc, hPen);
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);


			
			
			
			Rectangle(hdc,  72.5, 320 - (number[0] * 9), 92.5, 321);
			Rectangle(hdc, 117.5, 320 - (number[1] * 9), 137.5, 321);
			Rectangle(hdc, 162.5, 320 - (number[2] * 9), 182.5, 321);
			Rectangle(hdc, 207.5, 320 - (number[3] * 9), 227.5, 321);
			Rectangle(hdc, 252.5, 320-  (number[4] * 9), 272.5, 321);
			Rectangle(hdc, 297.5, 320 - (number[5] * 9), 317.5, 321);
			Rectangle(hdc, 342.5, 320 - (number[6] * 9), 362.5, 321);
			Rectangle(hdc, 387.5, 320 - (number[7] * 9), 407.5, 321);
			Rectangle(hdc, 432.5, 320 - (number[8] * 9), 452.5, 321);
			Rectangle(hdc, 477.5, 320 - (number[9] * 9), 497.5, 321);
			
		}
		else if (type==1)
		{
			hPen = CreatePen(PS_SOLID, 2, RGB(color[0], color[1], color[2]));
			hBrush = CreateSolidBrush(RGB(color[0], color[1], color[2]));
			hPenOld = (HPEN)SelectObject(hdc, hPen);
			hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);
			MoveToEx(hdc, 82.5, 320 - (number[0] * 9), NULL);
			LineTo(hdc, 127.5, 320 - (number[1] * 9));
			LineTo(hdc, 172.5, 320 - (number[2] * 9));
			LineTo(hdc, 217.5, 320 - (number[3] * 9));
			LineTo(hdc, 262.5, 320 - (number[4] * 9));
			LineTo(hdc, 307.5, 320 - (number[5] * 9));
			LineTo(hdc, 352.5, 320 - (number[6] * 9));
			LineTo(hdc, 397.5, 320 - (number[7] * 9));
			LineTo(hdc, 442.5, 320 - (number[8] * 9));
			LineTo(hdc, 487.5, 320 - (number[9] * 9));
		}

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		SelectObject(hdc, hBrushOld);
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// [關於] 方塊的訊息處理常式。
BOOL CALLBACK score(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int count = 0;
	TCHAR tch[120];
	//UNREFERENCED_PARAMETER(lParam);
	switch (message) 
	{
	case WM_INITDIALOG: // initialize list box
		for (int i = 0; i<NUMBOOKS; i++)
			SendDlgItemMessage(hDlg, IDC_LIST1,
			LB_ADDSTRING, 0, (LPARAM)books[i].color_select);
		// select first item
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_SETCURSEL, 0, 0);
		return 1;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return 1;

		case IDC_BUTTON1://折線圖
			type = 1;
			EndDialog(hDlg, 0);
			return 1;
		case IDC_BUTTON2://直條圖
			type = 2;
			EndDialog(hDlg, 0);
			return 1;

		case IDC_LIST1: // process a list box LBN_DBLCLK
			if (HIWORD(wParam) == LBN_DBLCLK) 
			{
				count = SendDlgItemMessage(hDlg, IDC_LIST1,
					LB_GETCURSEL, 0, 0); // get index
				if (count == 0)
				{
					color[0] = 255;
					color[1] = 0;
					color[2] = 0;
				}
				else if (count == 1)
				{
					color[0] = 255;
					color[1] = 127;
					color[2] = 0;
				}
				else if (count == 2)
				{
					color[0] = 255;
					color[1] = 255;
					color[2] = 0;
				}
				else if (count == 3)
				{
					color[0] = 0;
					color[1] = 255;
					color[2] = 0;
				}
				else if (count == 4)
				{
					color[0] = 0;
					color[1] = 0;
					color[2] = 255;
				}
				else if (count == 5)
				{
					color[0] = 0;
					color[1] = 255;
					color[2] = 255;
				}
				else if (count == 6)
				{
					color[0] = 160;
					color[1] = 32;
					color[2] = 240;
				}
				else if (count == 7)
				{
					color[0] = 165;
					color[1] = 42;
					color[2] = 42;
				}
				else if (count == 8)
				{
					color[0] = 255;
					color[1] = 105;
					color[2] = 180;
				}
				else if (count == 9)
				{
					color[0] = 135;
					color[1] = 206;
					color[2] = 255;
				}
				EndDialog(hDlg, 0);
			}
			return 1;
		/*
		case IDC_BUTTON3: //綠色
			color[0] = 0;
			color[1] = 255;
			color[2] = 0;
			EndDialog(hDlg, 0);
			return 1;
		case IDC_BUTTON4: //黃色
			color[0] = 255;
			color[1] = 255;
			color[2] = 0;
			EndDialog(hDlg, 0);
			return 1;
		case IDC_BUTTON5: //藍色
			color[0] = 0;
			color[1] = 0;
			color[2] = 255;
			EndDialog(hDlg, 0);
			return 1;
		
		case IDC_BUTTON6: // Select Book button has been pressed

			count = SendDlgItemMessage(hDlg, IDC_LIST1,
				LB_GETCURSEL, 0, 0); // get index
			if (count==0)
			{
				color[0] = 255;
				color[1] = 0;
				color[2] = 0;
			}
			else if (count==1)
			{
				color[0] = 255;
				color[1] = 127;
				color[2] = 0;
			}
			else if (count == 2)
			{
				color[0] = 255;
				color[1] = 255;
				color[2] = 0;
			}
			else if (count == 3)
			{
				color[0] = 0;
				color[1] = 255;
				color[2] = 0;
			}
			else if (count == 4)
			{
				color[0] = 0;
				color[1] = 0;
				color[2] = 255;
			}
			else if (count == 5)
			{
				color[0] = 0;
				color[1] = 255;
				color[2] = 255;
			}
			else if (count == 6)
			{
				color[0] = 160;
				color[1] = 32;
				color[2] = 240;
			}

			EndDialog(hDlg, 0);
			return 1;*/
		}
	 

	}
	return 0;
}

// [關於] 方塊的訊息處理常式。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

