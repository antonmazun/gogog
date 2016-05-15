#include <windows.h>
#include <CommCtrl.h>
#define size 500
const char g_szClassName[] = "myWindowClass";

enum {
    STATIC_ID = 1,
    EDIT_ID
};

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInst = hInstance;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Dezewka",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 330, 330,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
     static HWND Book, Genre, Author, Year,
                 lblBook,lblGenre, lblAuthor, lblYear,
                 stBook,stGenre, stAuthor, stYear;
    static char buf[size];

    switch(msg)
    {
        case WM_CREATE:

/*LineEdit*/
    Book = CreateWindowEx(5,WC_EDIT," ",WS_CHILD | WS_VISIBLE | WS_BORDER,50, 50, 100, 20,hwnd,(HMENU)1, hInst,NULL);

    Genre = CreateWindowEx(5, WC_EDIT, " ", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 100, 100, 23, hwnd,(HMENU)2, hInst,NULL);

    Author = CreateWindowEx(5, WC_EDIT, " ", WS_CHILD | WS_VISIBLE | WS_BORDER,50, 150, 100, 23, hwnd,(HMENU)3, hInst,NULL);

    Year = CreateWindowEx(5, WC_EDIT, " ", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 200, 100, 23, hwnd,(HMENU)4, hInst,NULL);

/* Label:*/
    lblBook = CreateWindowEx(0,"STATIC","Book:", WS_CHILD | WS_VISIBLE, 5, 50, 50, 20, hwnd, (HMENU)EDIT_ID, hInst, NULL);

    lblGenre = CreateWindowEx(0,"STATIC","Genre", WS_CHILD | WS_VISIBLE, 5, 100, 50, 20, hwnd, (HMENU)EDIT_ID, hInst, NULL);

    lblAuthor = CreateWindowEx(0,"STATIC","Author", WS_CHILD | WS_VISIBLE, 5, 150, 50, 20, hwnd, (HMENU)EDIT_ID, hInst, NULL);

    lblYear = CreateWindowEx(0,"STATIC","Year:", WS_CHILD | WS_VISIBLE, 5, 200, 50, 20, hwnd, (HMENU)EDIT_ID, hInst, NULL);

/*Static*/
    stBook = CreateWindowEx(0, WC_STATIC," ", WS_CHILD | WS_VISIBLE,160, 50, 130, 20,hwnd,(HMENU)STATIC_ID,  hInst,NULL);

    stGenre = CreateWindowEx(0, WC_STATIC," ", WS_CHILD | WS_VISIBLE,160, 100, 130, 23,hwnd,(HMENU)STATIC_ID,  hInst,NULL);

    stAuthor = CreateWindowEx(0, WC_STATIC," ", WS_CHILD | WS_VISIBLE,160, 150, 130, 23,hwnd,(HMENU)STATIC_ID,  hInst,NULL);

    stYear = CreateWindowEx(0, WC_STATIC," ", WS_CHILD | WS_VISIBLE,160, 200, 130, 23,hwnd,(HMENU)STATIC_ID, hInst,NULL);

            break;
        case WM_COMMAND:
           if((HIWORD(wParam) == EN_CHANGE) && (LOWORD(wParam) == 1)) {
                GetWindowText(Book, buf, sizeof(buf));
                SetWindowText( stBook, TEXT(buf));
            }

            if((HIWORD(wParam) == EN_CHANGE) && (LOWORD(wParam) == 2)) {
                GetWindowText(Genre, buf, sizeof(buf));
                SetWindowText( stGenre, TEXT(buf));
            }

             if((HIWORD(wParam) == EN_CHANGE) && (LOWORD(wParam) == 3)) {
                GetWindowText(Author, buf, sizeof(buf));
                SetWindowText(  stAuthor, TEXT(buf));
            }

             if((HIWORD(wParam) == EN_CHANGE) && (LOWORD(wParam) == 4)) {
                GetWindowText(Year, buf, sizeof(buf));
                SetWindowText( stYear, TEXT(buf));
            }

            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

