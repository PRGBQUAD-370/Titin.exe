#include <windows.h>
#include <stdio.h>
#include <cmath>
#pragma comment(lib, "winmm.lib")
#define M_PI   3.14159265358979323846264338327950288
DWORD WINAPI FastInvert(LPVOID lpParam)
{
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN);
		int h = GetSystemMetrics(SM_CYSCREEN);

		RECT rect = { 0, 0, w, h };

		InvertRect(hdc, &rect);
		InvertRect(hdc, &rect);

		ReleaseDC(NULL, hdc);
	}
}
DWORD WINAPI train(LPVOID lpParam) {
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (1) {
		HDC hdc = GetDC(0);
		BitBlt(hdc, -30, 0, w, h, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, w - 30, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
		ReleaseDC(0, hdc);
		Sleep(10);
	}
}
DWORD WINAPI sines(LPVOID lpParam) {
	HDC desk = GetDC(0); HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	double angle = 0;
	while (1) {
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 0.99f) {
			int a = sin(angle) * 10;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, NOTSRCCOPY);
			angle += M_PI / 80;
			DeleteObject(&i); DeleteObject(&a);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
	}
}
bool running = true;

COLORREF HSV(int h) {
	h %= 360;
	int x = (255 * (60 - abs((h % 120) - 60))) / 60;
	switch (h / 60) {
	case 0:  return RGB(255, x, 0);
	case 1:  return RGB(x, 255, 0);
	case 2:  return RGB(0, 255, x);
	case 3:  return RGB(0, x, 255);
	case 4:  return RGB(x, 0, 255);
	default: return RGB(255, 0, x);
	}
}

DWORD WINAPI squares(LPVOID lpParam) {
	int screenW = GetSystemMetrics(SM_CXSCREEN);
	int screenH = GetSystemMetrics(SM_CYSCREEN);

	int x = 100, y = 100;
	int dx = 14, dy = 12;
	const int size = 110;

	while (running) {
		HDC hdc = GetDC(0);

		HBRUSH brush = CreateSolidBrush(HSV(200));
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 255, 255));

		SelectObject(hdc, brush);
		SelectObject(hdc, pen);

		Rectangle(hdc, x, y, x + size, y + size);

		DeleteObject(brush);
		DeleteObject(pen);
		ReleaseDC(0, hdc);

		x += dx;
		y += dy;
		if (x <= 0 || x + size >= screenW) dx = -dx;
		if (y <= 0 || y + size >= screenH) dy = -dy;

		Sleep(8);
	}
	return 0;
}
DWORD WINAPI MoveScreenInvert(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 0, -30, w, h, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, 0, h - 30, w, h, hdc, 0, 0, NOTSRCCOPY);
		BitBlt(hdc, -30, 0, w, h, hdc, 0, 0, SRCCOPY);
		BitBlt(hdc, w - 30, 0, w, h, hdc, 0, 0, NOTSRCCOPY);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
	}
}
VOID WINAPI sound1() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[8000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(9 * t & t >> 4 | 5 * t & t >> 7 | 3 * t & t >> 10);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound2() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 16500, 16500, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[16500 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t >> 6 ^ t & t >> 9 ^ t >> 12 | ((t >> 6 | t << 1) + (t >> 5 | t << 3 | t >> 3) | t >> 2 | t << 1));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound3() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t >> (t % 32 ? 4 : 3) | (t % 128 ? t >> 3 : t >> 3 | t >> 9));

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound4() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11025 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(2 * t & t >> 8 | 5 * t & t >> 7 | 9 * t & t >> 4 | 15 * t & t >> 4);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
VOID WINAPI sound5() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 16000, 16000, 1, 8, 0 };
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[16000 * 30] = {};
	for (DWORD t = 0; t < sizeof(buffer); ++t)
		buffer[t] = static_cast<char>(t * (t & 16384 ? 7 : 5) * (3 - (3 & t >> 9) + (3 & t >> 8)) >> (3 & -t >> (t % 65536 < 59392 ? t & 4096 ? 2 : 16 : 2)) | t >> 3);

	WAVEHDR header = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	if (MessageBoxW(NULL, L"TitinV1.exe, Run GDI?", L"TitinV1.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
		ExitProcess(0);
	}
	else
		if (MessageBoxW(NULL, L"Are you sure? last chance to stop it", L"TitinV1.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
		{
			ExitProcess(0);
		}
		else
		{

			Sleep(1000);
			HANDLE P1 = CreateThread(NULL, 0, FastInvert, NULL, 0, NULL);
			sound1();
			Sleep(30000);
			TerminateThread(P1, 0);
			CloseHandle(P1);
			Sleep(100);
			HANDLE P2 = CreateThread(NULL, 0, sines, NULL, 0, NULL);
			sound2();
			Sleep(30000);
			TerminateThread(P2, 0);
			CloseHandle(P2);
			Sleep(100);
			HANDLE P3 = CreateThread(NULL, 0, train, NULL, 0, NULL);
			sound3();
			Sleep(30000);
			TerminateThread(P3, 0);
			CloseHandle(P3);
			Sleep(100);
			HANDLE P4 = CreateThread(NULL, 0, squares, NULL, 0, NULL);
			sound4();
			Sleep(30000);
			TerminateThread(P4, 0);
			CloseHandle(P4);
			Sleep(100);
			HANDLE P5 = CreateThread(NULL, 0, MoveScreenInvert, NULL, 0, NULL);
			sound5();
			Sleep(30000);

		}
}