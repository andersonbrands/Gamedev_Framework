/***************************************************************************************
*	Title: WindowsPlatform.cpp
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#include "WindowsPlatform.h"

#include "../../Framework/EventManager/EventManager.h"

#define CLASS_NAME "Main"
#define WINDOW_NAME "Frame dev project"


WindowsPlatform::WindowsPlatform(const unsigned int priority)
    :	iPlatform(priority) {
    wc_.cbSize = sizeof(WNDCLASSEX);
    wc_.style = CS_CLASSDC;
    wc_.lpfnWndProc = InitialWndProc;
    wc_.cbClsExtra = 0L;
    wc_.cbWndExtra = 0L;
    wc_.hInstance = GetModuleHandle(NULL);
    wc_.hIcon = NULL;
    wc_.hCursor = NULL;
    wc_.hbrBackground = NULL;
    wc_.lpszMenuName = NULL;
    wc_.lpszClassName = CLASS_NAME;
    wc_.hIconSm = NULL;


    RegisterClassEx(&wc_);

    const int w(480), h(320);
    lastWindowedPositionX_ = 400;
    lastWindowedPositionY_ = 100;

    // Create the application's window
    hWnd_ = CreateWindow( CLASS_NAME, WINDOW_NAME,
                          WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, lastWindowedPositionX_, lastWindowedPositionY_, w, h,
                          GetDesktopWindow(), NULL, wc_.hInstance, this);

    // Initialize Direct3D
    if (SUCCEEDED(setupD3D())) {
        // Show the window
        ShowWindow(hWnd_, SW_SHOWDEFAULT);
        UpdateWindow(hWnd_);
    }

    registerEvent(ev::id::PLATFORM_SUSPEND);
    registerEvent(ev::id::PLATFORM_RESUME);
    registerEvent(ev::id::PLATFORM_STOP);
    registerEvent(ev::id::ON_LOST_DEVICE);
    registerEvent(ev::id::ON_RESET_DEVICE);
    registerEvent(ev::id::CHECK_DEVICE_IS_LOST);
    registerEvent(ev::id::TOGGLE_FULLSCREEN);
    registerEvent(ev::id::PLATFORM_CLOSE);
}

WindowsPlatform::~WindowsPlatform() {
    UnregisterClass(CLASS_NAME, wc_.hInstance);

    if (g_pd3dDevice != NULL) g_pd3dDevice -> Release();
    if (g_pD3D != NULL)          g_pD3D -> Release();
}

LRESULT WINAPI WindowsPlatform::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_ACTIVATE:
            if( LOWORD(wParam) == WA_INACTIVE )
                onSuspend();
            else
                onResume();
            return 0;
        case WM_ENTERSIZEMOVE:
            onSuspend();
            return 0;
        case WM_EXITSIZEMOVE:
            onResume();
            return 0;
        case WM_SIZE:
            switch (wParam) {
                case SIZE_MINIMIZED:
                    onSuspend();
                    break;
                case SIZE_MAXIMIZED:
                    onResume();
                    isDeviceLost();
                    break;
                case SIZE_RESTORED:
                    onResume();
                    break;

                default:
                    break;
            }
            return 0;
        case WM_CLOSE:
            sendEvent(ev::id::PLATFORM_CLOSE);
            DestroyWindow(hWnd_);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_SHOWWINDOW:
            return 0;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }
}

HRESULT WindowsPlatform::setupD3D() {
    // Create the D3D object, return failure if this can't be done.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION))) return E_FAIL;


    // Set up the structure used to create the D3DDevice
    ZeroMemory(&d3dParams_, sizeof(d3dParams_));
    d3dParams_.BackBufferWidth            = 0;
    d3dParams_.BackBufferHeight           = 0;
    d3dParams_.BackBufferFormat           = D3DFMT_UNKNOWN;
    d3dParams_.BackBufferCount            = 1;
    d3dParams_.MultiSampleType            = D3DMULTISAMPLE_NONE;
    d3dParams_.MultiSampleQuality         = 0;
    d3dParams_.SwapEffect                 = D3DSWAPEFFECT_DISCARD;
    d3dParams_.hDeviceWindow              = hWnd_;
    d3dParams_.Windowed                   = true;
    d3dParams_.EnableAutoDepthStencil     = true;
    d3dParams_.AutoDepthStencilFormat     = D3DFMT_D24S8;
    d3dParams_.Flags                      = 0;
    d3dParams_.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
    d3dParams_.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

    // Create the D3DDevice
    if (FAILED(g_pD3D -> CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd_,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dParams_, &g_pd3dDevice))) {
        return E_FAIL;
    }

    // Turn on the Z buffer
    g_pd3dDevice -> SetRenderState(D3DRS_ZENABLE, TRUE);

    return S_OK;
}

bool WindowsPlatform::start() {
    ZeroMemory(&msg_, sizeof(msg_));

    return true;
}

void WindowsPlatform::onSuspend() {
    setSuspended(true);
    sendEvent(ev::id::PLATFORM_SUSPEND);
}

void WindowsPlatform::update() {
    if (msg_.message == WM_QUIT) {
        sendEvent(ev::id::PLATFORM_CLOSE);
        DestroyWindow(hWnd_);
    } else {
        if (PeekMessage(&msg_, NULL, 0U, 0U, PM_REMOVE)) {
            TranslateMessage(&msg_);
            DispatchMessage(&msg_);
        }
        isDeviceLost();
    }
}

void WindowsPlatform::onResume() {
    setSuspended(false);
    sendEvent(ev::id::PLATFORM_RESUME);
}

void WindowsPlatform::stop() {
    sendEvent(ev::id::PLATFORM_STOP);
}

void WindowsPlatform::toggleFullScreen() {
    // Switch to fullscreen mode.
    if( d3dParams_.Windowed ) {
        lastWindowedHeight_ = getBufferHeight();
        lastWindowedWidth_ = getBufferWidth();

        RECT rect = {0, 0, 0, 0};
        GetWindowRect(hWnd_, &rect);

        lastWindowedPositionX_ = rect.left;
        lastWindowedPositionY_ = rect.top;

        int width  = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);

        d3dParams_.BackBufferFormat = D3DFMT_X8R8G8B8;
        d3dParams_.BackBufferWidth  = width;
        d3dParams_.BackBufferHeight = height;
        d3dParams_.Windowed         = false;

        // Change the window style to a more fullscreen friendly style.
        SetWindowLongPtr(hWnd_, GWL_STYLE, WS_POPUP);

        // If we call SetWindowLongPtr, MSDN states that we need to call
        // SetWindowPos for the change to take effect.  In addition, we
        // need to call this function anyway to update the window dimensions.
        SetWindowPos(hWnd_, HWND_TOP, 0, 0, width, height, SWP_NOZORDER | SWP_SHOWWINDOW);
    }
    // Switch to windowed mode.
    else {
        RECT R = { 0, 0, lastWindowedWidth_, lastWindowedHeight_};
        AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, false);

        d3dParams_.BackBufferFormat = D3DFMT_UNKNOWN;
        d3dParams_.BackBufferWidth  = lastWindowedWidth_;
        d3dParams_.BackBufferHeight = lastWindowedHeight_;
        d3dParams_.Windowed         = true;

        // Change the window style to a more windowed friendly style.
        SetWindowLongPtr(hWnd_, GWL_STYLE, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX);

        // If we call SetWindowLongPtr, MSDN states that we need to call
        // SetWindowPos for the change to take effect.  In addition, we
        // need to call this function anyway to update the window dimensions.
        SetWindowPos(hWnd_, HWND_NOTOPMOST, lastWindowedPositionX_, lastWindowedPositionY_, R.right, R.bottom, SWP_SHOWWINDOW);
    }
}

bool WindowsPlatform::isDeviceLost() {
    assert(g_pd3dDevice);
    // Get the state of the graphics device.
    HRESULT hr = g_pd3dDevice->TestCooperativeLevel();

    // If the device is lost and cannot be reset yet then
    // sleep for a bit and we'll try again on the next
    // message loop cycle.
    if( hr == D3DERR_DEVICELOST ) {
        Sleep(20);
        return true;
    }
    // Driver error, exit.
    else if( hr == D3DERR_DRIVERINTERNALERROR ) {
        MessageBox(0, "Internal Driver Error...Exiting", 0, 0);
        PostQuitMessage(0);
        return true;
    }
    // The device is lost but we can reset and restore it.
    else if( hr == D3DERR_DEVICENOTRESET ) {
        sendEvent(ev::id::ON_LOST_DEVICE);
        if (!SUCCEEDED(g_pd3dDevice->Reset(&d3dParams_)))
            MessageBox(NULL, "Failed to reset device", "Error", MB_OK);
        sendEvent(ev::id::ON_RESET_DEVICE);
        return false;
    } else
        return false;
}
