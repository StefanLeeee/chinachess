#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//预处理
#include"resource.h"


//main  黑窗口 控制台程序 
//WinMain  窗口

//窗口处理函数
LRESULT CALLBACK WindowProc(
	HWND hWnd,                //窗口句柄
	UINT uMsg,					//消息编号
	WPARAM wParam,				//附加消息
	LPARAM lParam				//附加参数

	);
//绘制棋盘
void DrawChessboard(HDC hDC);


//函数程序的人口

int WINAPI WinMain(
				HINSTANCE hInstance,   //应用程序实例句柄
				HINSTANCE hPrevInstance, //前一个实例句柄
				LPSTR lcCmdLine,			//命令行参数
				int nCmdShow         //窗口的显示方式

	)
{	//弹出一个提示语句
	PlaySound(TEXT("./res/xq.wav"), NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);


	TCHAR szAPPClassName[] = TEXT("RitchieCheneseChess");

	//设计一个窗口类
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;  //窗口类扩展空间大小
	wndClass.cbWndExtra = 0;	//窗口额外空间大小
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);  //加载白色背景画刷
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                //加载光标
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOGO));   //加载图标
	wndClass.hInstance = hInstance;    //实例句柄
	wndClass.lpfnWndProc = WindowProc;         //窗口处理函数
	wndClass.lpszClassName = szAPPClassName;	//窗口类型名
	wndClass.lpszMenuName = NULL;									//菜单名
	wndClass.style = CS_HREDRAW | CS_HREDRAW;					//窗口类的风格


	//2.注册窗口类
	RegisterClass(&wndClass);

	//3.创建窗口
	HWND hWnd = CreateWindow(
		szAPPClassName,										//窗口类型名
		TEXT("人工智能中国象棋游戏-阿尔法猪"),				//窗口的标题
		WS_SYSMENU | WS_MINIMIZEBOX,							//窗口的风格
		400,												//窗口左上角的横坐标
		200,												//窗口左上角的横坐标
		475, 											//窗口的宽度
		426,												//窗口的高度
		NULL,
		NULL,
		hInstance,
		NULL
	);

	//4.显示窗口
	ShowWindow(hWnd, SW_SHOW);

	//5.更新窗口

	UpdateWindow(hWnd);

	//6消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;


}



//窗口处理函数
LRESULT CALLBACK WindowProc(
	HWND hWnd,                //窗口句柄
	UINT uMsg,					//消息编号
	WPARAM wParam,				//附加消息
	LPARAM lParam				//附加参数

)
{
	PAINTSTRUCT ps;
	HDC hDC;
	switch (uMsg)
	{

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		//绘制棋盘
		DrawChessboard(hDC);


		
		EndPaint(hWnd, &ps);
		break;

		//窗口关闭消息
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0); //退出进程
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//绘制棋盘
void DrawChessboard(HDC hDC)
{
	// 绘制最外层边框
	MoveToEx(hDC, 28, 28, NULL);
	LineTo(hDC, 304, 28);
	LineTo(hDC, 304, 338);
	LineTo(hDC, 28, 338);
	LineTo(hDC, 28, 28);
	//棋盘横线
	for (int i = 0; i < 10; i++)
	{
		MoveToEx(hDC, 30, 30 + i * 34, NULL);
		LineTo(hDC, 302, 30 + i * 34);
	}
	//左边
	MoveToEx(hDC, 30, 30, NULL);
	LineTo(hDC, 30, 336);
	//右边
	MoveToEx(hDC, 302, 30,NULL);
	LineTo(hDC, 302, 336);
	//上边
	for (int i = 0; i < 7; i++)
	{
		MoveToEx(hDC, 30 + (i + 1) * 34, 30, NULL);
		LineTo(hDC, 30 + (i + 1) * 34, 30 + 4 * 34);
	}
	//下边
	for(int i=0;i<7;i++)
	{
		MoveToEx(hDC, 30 + (i + 1) * 34, 200, NULL);
		LineTo(hDC, 30 + (i + 1) * 34, 200 + 4 * 34);
	}

	MoveToEx(hDC, 60, 90, NULL);
	LineTo(hDC, 60, 94);
	LineTo(hDC, 56, 94);

	MoveToEx(hDC, 68, 90, NULL);
	LineTo(hDC, 68, 94);
	LineTo(hDC, 72, 94);

	MoveToEx(hDC, 72, 102, NULL);
	LineTo(hDC, 68, 102);
	LineTo(hDC, 68, 106);

	MoveToEx(hDC, 72, 102, NULL);
	LineTo(hDC, 68, 102);
	LineTo(hDC, 68, 106);

	MoveToEx(hDC, 56,102, NULL);
	LineTo(hDC, 60, 102);
	LineTo(hDC, 60, 106);
	
}