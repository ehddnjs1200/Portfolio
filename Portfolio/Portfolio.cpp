// Portfolio.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

// DirectX
// Direct Access, GPU에 직접 접근 하는 API

#include "framework.h"
#include "Portfolio.h"

#define MAX_LOADSTRING 100

// 전역 변수
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND hWnd;
Vector2 mousepos = {CenterX, CenterY};

void ICreate();
void IDelete();

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PORTFOLIO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PORTFOLIO));

    MSG msg = {};

    ICreate();

    ImGui::CreateContext(); // ImGui객체를 생성
    ImGui::StyleColorsDark(); // light(밝게), 배경색을 검정색
    ImGui_ImplWin32_Init(hWnd); // 32bit로 hWnd를 넘김
    ImGui_ImplDX11_Init(DEVICE.Get(), DEVICE_CONTEXT.Get()); // ImGui와 Device의 정보가 연결된다.

    shared_ptr<Program> program = make_shared<Program>();

    while (msg.message != WM_QUIT)
    {
        // 에러메시지
        if(PeekMessage(&msg,nullptr,0,0,PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 메인
            program->Update();
            program->Render();
            //ImageInfo imageInfo = program->GetImageInfoAtMousePosition();
        }
    }
    IDelete();
    // 연결한걸 제거
    ImGui_ImplWin32_Shutdown(); // win32 연결 해제
    ImGui_ImplDX11_Shutdown();  // DX11 연결 해제
    ImGui::DestroyContext();    // 생성된 ImGui를 제거

    return (int) msg.wParam;
}

void ICreate()
{
    Device::Create(hWnd);
    KeyBoard::Create();
    Timer::Create();
    Camera::Create();
    //DXWrite::Create();

    StateManager::Create();
    TextureManager::Create();
    EffectManager::Create();
}

void IDelete()
{
    KeyBoard::Delete();
    Timer::Delete();
    Camera::Delete();
    //DXWrite::Delete();

    StateManager::Delete();
    TextureManager::Delete();
    EffectManager::Delete();

    Device::Delete();
}

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PORTFOLIO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PORTFOLIO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 1. 메뉴창의 크기도 화면크기에 영향을 준다
   /*hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);*/

   // 2. 창메뉴는 보이되, 화면크기에는 영향을 안준다.
   RECT rc = { WIN_STARTX ,WIN_STARTY ,WIN_WIDTH ,WIN_HEIGHT };

   // 현재 윈도우 크기, 윈도우 모양, 메뉴 여부
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       WIN_STARTX ,WIN_STARTY ,rc.right-rc.left , rc.bottom-rc.top , nullptr, nullptr, hInstance, nullptr);

    // 메뉴창없애기
    SetMenu(hWnd,nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

// ImGui 외부변수
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if(ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
        return true;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_MOUSEMOVE:
        {
            mousepos.x = LOWORD(lParam);
            mousepos.y = WIN_HEIGHT - HIWORD(lParam);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
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
