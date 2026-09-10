#include "Titin.h"

VOID WINAPI Initialize(VOID) {
    HMODULE hModUser32 = LoadLibraryW(L"user32.dll");
    BOOL(WINAPI * SetProcessDPIAware)(VOID) = (BOOL(WINAPI*)(VOID))GetProcAddress(hModUser32, "SetProcessDPIAware");
    if (SetProcessDPIAware) SetProcessDPIAware();
    FreeLibrary(hModUser32);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    Initialize();

    if (MessageBoxW(NULL, L"This is a Titin.exe,\r\nRun?", L"Titin.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
    {
        ExitProcess(0);
    }
    else
    {
        if (MessageBoxW(NULL, L"Are you sure?", L"Final warning - Titin.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
        {
            ExitProcess(0);
        }
        else

            Sleep(1000);
        HANDLE hThread1 = CreateThread(0, 0, FastInvert, 0, 0, 0);
        sound1();
        Sleep(30000);
        HANDLE hThreadRedraw1 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread1, 0);
        CloseHandle(hThread1);
        Sleep(100);
        TerminateThread(hThreadRedraw1, 0);
        CloseHandle(hThreadRedraw1);
        HANDLE hThread2 = CreateThread(0, 0, profect, 0, 0, 0);
        sound2();
        Sleep(30000);
        HANDLE hThreadRedraw2 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread2, 0);
        CloseHandle(hThread2);
        Sleep(100);
        TerminateThread(hThreadRedraw2, 0);
        CloseHandle(hThreadRedraw2);
        HANDLE hThread3 = CreateThread(0, 0, shader1, 0, 0, 0);
        sound3();
        Sleep(47000);
        HANDLE hThreadRedraw3 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread3, 0);
        CloseHandle(hThread3);
        Sleep(100);
        TerminateThread(hThreadRedraw3, 0);
        CloseHandle(hThreadRedraw3);
        HANDLE hThread4 = CreateThread(0, 0, cubes, 0, 0, 0);
        sound4();
        Sleep(30000);
        HANDLE hThreadRedraw4 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread4, 0);
        CloseHandle(hThread4);
        Sleep(100);
        TerminateThread(hThreadRedraw4, 0);
        CloseHandle(hThreadRedraw4);
        HANDLE hThread5 = CreateThread(0, 0, shader2, 0, 0, 0);
        sound5();
        Sleep(30000);
        HANDLE hThreadRedraw5 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread5, 0);
        CloseHandle(hThread5);
        Sleep(100);
        TerminateThread(hThreadRedraw5, 0);
        CloseHandle(hThreadRedraw5);
        HANDLE hThread6 = CreateThread(0, 0, shader3, 0, 0, 0);
        sound6();
        Sleep(30000);
        HANDLE hThreadRedraw6 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread6, 0);
        CloseHandle(hThread6);
        Sleep(100);
        TerminateThread(hThreadRedraw6, 0);
        CloseHandle(hThreadRedraw6);
        HANDLE hThread7 = CreateThread(0, 0, polybeziers, 0, 0, 0);
        sound7();
        Sleep(30000);
        HANDLE hThreadRedraw7 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread7, 0);
        CloseHandle(hThread7);
        Sleep(100);
        TerminateThread(hThreadRedraw7, 0);
        CloseHandle(hThreadRedraw7);
        HANDLE hThread8 = CreateThread(0, 0, Balls, 0, 0, 0);
        HANDLE hThread8dot1 = CreateThread(0, 0, patblt, 0, 0, 0);
        sound8();
        Sleep(30000);
        HANDLE hThreadRedraw8 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread8, 0);
        CloseHandle(hThread8);
        TerminateThread(hThread8dot1, 0);
        CloseHandle(hThread8dot1);
        Sleep(100);
        TerminateThread(hThreadRedraw8, 0);
        CloseHandle(hThreadRedraw8);
        HANDLE hThread9 = CreateThread(0, 0, rgb, 0, 0, 0);
        sound9();
        Sleep(30000);
        HANDLE hThreadRedraw9 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread9, 0);
        CloseHandle(hThread9);
        Sleep(100);
        TerminateThread(hThreadRedraw9, 0);
        CloseHandle(hThreadRedraw9);
        HANDLE hThread10 = CreateThread(0, 0, prgbtriple, 0, 0, 0);
        sound10();
        Sleep(30000);
        HANDLE hThreadRedraw10 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread10, 0);
        CloseHandle(hThread10);
        Sleep(100);
        TerminateThread(hThreadRedraw10, 0);
        CloseHandle(hThreadRedraw10);
        HANDLE hThread11 = CreateThread(0, 0, BetterRgbQuad, 0, 0, 0);
        sound11();
        Sleep(30000);
        HANDLE hThreadRedraw11 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread11, 0);
        CloseHandle(hThread11);
        Sleep(100);
        TerminateThread(hThreadRedraw11, 0);
        CloseHandle(hThreadRedraw11);
        HANDLE hThread12 = CreateThread(0, 0, RgbTrain, 0, 0, 0);
        sound12();
        Sleep(30000);
        HANDLE hThreadRedraw12 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread12, 0);
        CloseHandle(hThread12);
        Sleep(100);
        TerminateThread(hThreadRedraw12, 0);
        CloseHandle(hThreadRedraw12);
        HANDLE hThread13 = CreateThread(0, 0, train, 0, 0, 0);
        sound13();
        Sleep(30000);
        HANDLE hThreadRedraw13 = CreateThread(0, 0, Redrawer, 0, 0, 0);
        TerminateThread(hThread13, 0);
        CloseHandle(hThread13);
        Sleep(100);
    }
}