// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tchar.h>
#include "pch.h"

// Global variables
HWND hWnd;
HINSTANCE hInstance;

// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Парсер новостей с mail.ru");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 0);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// Store instance handle in our global variable
	hInst = hInstance;

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		550, 320,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("");
	static HWND hBtn, hBtn2, hBtn3; // дескриптор кнопки
	static HWND hEdt1, hEdt2; // дескрипторы полей редактирования
	static HWND hStat; // дескриптор статического текста
	TCHAR StrA[20];

	switch (message)
	{
	case WM_CREATE: // сообщение создания окна
	// Создаем и показываем первое поле редактирования
	hEdt1 = CreateWindow(L"edit", L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 100, 500, 30,
		hWnd, 0, hInst, NULL);
	ShowWindow(hEdt1, SW_SHOWNORMAL);
	// Создаем и показываем второе поле редактирования
	hEdt2 = CreateWindow(L"edit", L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 180, 450, 30,
		hWnd, 0, hInst, NULL);
	ShowWindow(hEdt1, SW_SHOWNORMAL);
	// Создаем и показываем кнопку
	hBtn = CreateWindow(L"button", L"Скачать",
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		120, 230, 120, 30, hWnd, 0, hInst, NULL);
	ShowWindow(hBtn, SW_SHOWNORMAL);

	hBtn2 = CreateWindow(L"button", L"Выход",
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		350, 230, 120, 30, hWnd, 0, hInst, NULL);
	ShowWindow(hBtn, SW_SHOWNORMAL);

	hBtn3 = CreateWindow(L"button", L"...",
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		480, 180, 30, 30, hWnd, 0, hInst, NULL);
	ShowWindow(hBtn, SW_SHOWNORMAL);
		break;
/////////////////
	case WM_COMMAND:  // сообщение о команде
		if (lParam == (LPARAM)hBtn)    // если нажали на кнопку
		{
			GetWindowText(hEdt1, StrA, 20);
		}
		break;
////////////////////
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 20, 20, L"Aдрес в формате", 16); // вывод текстовых сообщений
		TextOut(hdc, 20, 60, L"(https://news.mail.ru/economics/41618594/?frommail=1)", 54); // вывод текстовых сообщений
		TextOut(hdc, 20, 140, L"Куда записать", 14);
		// Here your application is laid out.
		// For this introduction, we just print out "Hello, Windows desktop!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));


		// End application-specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}