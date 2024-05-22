#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int ss) {
    WNDCLASS wc;
    wc.style = 0;
    wc.lpfnWndProc = MainWinProc;
    wc.cbClsExtra = wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = NULL;
    wc.hCursor = NULL;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 100);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "MainWndClass";
    if (!RegisterClass(&wc)) return FALSE;

    HWND hMainWnd = CreateWindow("MainWndClass", "ПР 17", WS_OVERLAPPEDWINDOW,
                                 CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
    if (!hMainWnd) return FALSE;

    ShowWindow(hMainWnd, ss);
    UpdateWindow(hMainWnd);

    MSG msg; 
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

DWORD WINAPI MessageBoxThread(LPVOID lpParam) {
    char *message = (char *)lpParam;
    MessageBox(NULL, message, "MessageBox", MB_OK | MB_ICONINFORMATION);
    return 0;
}

LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("button", "Открыть модальное окно", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         5, 5, 200, 20, hw, (HMENU)1, NULL, NULL);
            CreateWindow("button", "Открыть не модальное окно", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         210, 5, 200, 20, hw, (HMENU)2, NULL, NULL);
            CreateWindow("button", "Открыть несколько окон", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
                         420, 5, 200, 20, hw, (HMENU)3, NULL, NULL);
            return 0;
        case WM_COMMAND:
            if ((HIWORD(wp) == 0) && (LOWORD(wp) == 1))
                MessageBox(hw, "Вы видите модальное окно!", "MessageBox", MB_OK | MB_ICONINFORMATION);
            else if ((HIWORD(wp) == 0) && (LOWORD(wp) == 2))
                MessageBox(NULL, "Вы видите не модальное окно!", "MessageBox", MB_OK | MB_ICONINFORMATION);
            else if ((HIWORD(wp) == 0) && (LOWORD(wp) == 3)) {
                HANDLE threads[5];
                char message[100];
                for (int i = 0; i < 5; i++) {
                    sprintf(message, "ВНИМАНИЕ: Открыто одно из 5 окон!");
                    threads[i] = CreateThread(NULL, 0, MessageBoxThread, (LPVOID)message, 0, NULL);
                    if (threads[i] == NULL) {
                        MessageBox(NULL, "Failed to create thread", "Error", MB_OK | MB_ICONERROR);
                        return 1;
                    }
                }
                WaitForMultipleObjects(5, threads, TRUE, INFINITE);
                for (int i = 0; i < 5; ++i) {
                    CloseHandle(threads[i]);
                }
            }
            return 0;
        case WM_CLOSE:
            DestroyWindow(hw);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hw, msg, wp, lp);
}
