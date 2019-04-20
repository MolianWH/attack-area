// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#define PI 3.1415926
void attack_area()
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	double rho, theta, x, y;//极坐标和直角坐标
	system("cls");			//清屏
	system("color f0");		//白底黑字
	Rectangle(hdc, 120, 50, 120 + 600, 50 + 500);//画个边框
	MoveToEx(hdc, 300, 300, NULL);				 //坐标原点，屏幕坐标（400，300）
	{
		//画坐标系
		//x轴
		LineTo(hdc, 500, 300);
		//画箭头
		MoveToEx(hdc, 490, 310, NULL);
		LineTo(hdc, 500, 300);
		MoveToEx(hdc, 490, 290, NULL);
		LineTo(hdc, 500, 300);
		//y轴
		MoveToEx(hdc, 400, 200, NULL);
		LineTo(hdc, 400, 400);
		//箭头
		MoveToEx(hdc, 390, 210, NULL);
		LineTo(hdc, 400, 200);
		MoveToEx(hdc, 410, 210, NULL);
		LineTo(hdc, 400, 200);
	}
	for (int i = 0; i < 360; i++)
	{
		theta = i / 180.0 * PI;
		//rho = exp(cos(theta)) - 2 * cos(4 * theta) + pow(sin(theta / 12.0), 5);
		//单位：km/h 
		rho = 17.77105 + 0.005683 * 400.0 * sin(theta - PI) * 3.6 - 0.0066 * 300.0 + 1.410863 * 5000.0 * 0.001;
		x = 400 + 3 * rho * cos(theta);
		y = 300 - 3 * rho * sin(theta);
		//将画笔移到曲线第一笔处
		if (i == 0)
		{
			MoveToEx(hdc, x, y, NULL);
		}
		LineTo(hdc, x, y);
	}
	ReleaseDC(hwnd, hdc);
}
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:   //新的进程要访问DLL
		attack_area();
	case DLL_THREAD_ATTACH:    //新的线程要访问DLL
	case DLL_THREAD_DETACH:    //一个线程不再使用DLL
	case DLL_PROCESS_DETACH:   //一个进程不再使用DLL
		break;
	}
	return TRUE;
}
