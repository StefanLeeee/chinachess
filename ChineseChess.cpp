#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//Ԥ����
#include"resource.h"


//main  �ڴ��� ����̨���� 
//WinMain  ����

//���ڴ�����
LRESULT CALLBACK WindowProc(
	HWND hWnd,                //���ھ��
	UINT uMsg,					//��Ϣ���
	WPARAM wParam,				//������Ϣ
	LPARAM lParam				//���Ӳ���

	);
//��������
void DrawChessboard(HDC hDC);


//����������˿�

int WINAPI WinMain(
				HINSTANCE hInstance,   //Ӧ�ó���ʵ�����
				HINSTANCE hPrevInstance, //ǰһ��ʵ�����
				LPSTR lcCmdLine,			//�����в���
				int nCmdShow         //���ڵ���ʾ��ʽ

	)
{	//����һ����ʾ���
	PlaySound(TEXT("./res/xq.wav"), NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);


	TCHAR szAPPClassName[] = TEXT("RitchieCheneseChess");

	//���һ��������
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;  //��������չ�ռ��С
	wndClass.cbWndExtra = 0;	//���ڶ���ռ��С
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);  //���ذ�ɫ������ˢ
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);                //���ع��
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LOGO));   //����ͼ��
	wndClass.hInstance = hInstance;    //ʵ�����
	wndClass.lpfnWndProc = WindowProc;         //���ڴ�����
	wndClass.lpszClassName = szAPPClassName;	//����������
	wndClass.lpszMenuName = NULL;									//�˵���
	wndClass.style = CS_HREDRAW | CS_HREDRAW;					//������ķ��


	//2.ע�ᴰ����
	RegisterClass(&wndClass);

	//3.��������
	HWND hWnd = CreateWindow(
		szAPPClassName,										//����������
		TEXT("�˹������й�������Ϸ-��������"),				//���ڵı���
		WS_SYSMENU | WS_MINIMIZEBOX,							//���ڵķ��
		400,												//�������Ͻǵĺ�����
		200,												//�������Ͻǵĺ�����
		475, 											//���ڵĿ��
		426,												//���ڵĸ߶�
		NULL,
		NULL,
		hInstance,
		NULL
	);

	//4.��ʾ����
	ShowWindow(hWnd, SW_SHOW);

	//5.���´���

	UpdateWindow(hWnd);

	//6��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;


}



//���ڴ�����
LRESULT CALLBACK WindowProc(
	HWND hWnd,                //���ھ��
	UINT uMsg,					//��Ϣ���
	WPARAM wParam,				//������Ϣ
	LPARAM lParam				//���Ӳ���

)
{
	PAINTSTRUCT ps;
	HDC hDC;
	switch (uMsg)
	{

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		//��������
		DrawChessboard(hDC);


		
		EndPaint(hWnd, &ps);
		break;

		//���ڹر���Ϣ
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0); //�˳�����
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
//��������
void DrawChessboard(HDC hDC)
{
	// ���������߿�
	MoveToEx(hDC, 28, 28, NULL);
	LineTo(hDC, 304, 28);
	LineTo(hDC, 304, 338);
	LineTo(hDC, 28, 338);
	LineTo(hDC, 28, 28);
	//���̺���
	for (int i = 0; i < 10; i++)
	{
		MoveToEx(hDC, 30, 30 + i * 34, NULL);
		LineTo(hDC, 302, 30 + i * 34);
	}
	//���
	MoveToEx(hDC, 30, 30, NULL);
	LineTo(hDC, 30, 336);
	//�ұ�
	MoveToEx(hDC, 302, 30,NULL);
	LineTo(hDC, 302, 336);
	//�ϱ�
	for (int i = 0; i < 7; i++)
	{
		MoveToEx(hDC, 30 + (i + 1) * 34, 30, NULL);
		LineTo(hDC, 30 + (i + 1) * 34, 30 + 4 * 34);
	}
	//�±�
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