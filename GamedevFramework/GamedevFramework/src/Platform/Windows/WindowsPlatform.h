/***************************************************************************************
*	Title: WindowsPlatform.h
*	Author: Brandao, Anderson
*	Date: 2014
*
***************************************************************************************/

#ifndef WINDOWS_PLATFORM_H_
#define WINDOWS_PLATFORM_H_

#define D3D_DEBUG_INFO    // Enable debugging information, so the .NET environment can help you.

#include "../../Framework/Platform/iPlatform.h"
#include "../../Framework/Utilities/Singleton.h"
#include <Windows.h>
#include <d3dx9.h>

using namespace Framework;

class WindowsPlatform : public iPlatform {
    private:
        MSG msg_;

        LPDIRECT3D9             g_pD3D;
        LPDIRECT3DDEVICE9       g_pd3dDevice;

        WNDCLASSEX wc_;
        HWND hWnd_;

        D3DPRESENT_PARAMETERS d3dParams_;	//everything we need to setup D3D

        int lastWindowedWidth_, lastWindowedHeight_;	//remember the window size if we drop back from fullscreen
        int lastWindowedPositionX_, lastWindowedPositionY_;	//remember the window position if we drop back from fullscreen

        HRESULT setupD3D();

        bool isDeviceLost();
        void toggleFullScreen();

    public:
        WindowsPlatform(const unsigned int priority);
        virtual ~WindowsPlatform();

        static LRESULT CALLBACK InitialWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
            if (Msg == WM_NCCREATE) {
                LPCREATESTRUCT create_struct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                void * lpCreateParam = create_struct->lpCreateParams;
				WindowsPlatform * this_window = reinterpret_cast<WindowsPlatform *>(lpCreateParam);
                SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this_window));
                SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WindowsPlatform::StaticWndProc));
                return this_window->MsgProc(hWnd, Msg, wParam, lParam);
            }
            return DefWindowProc(hWnd, Msg, wParam, lParam);
        }

        static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
            LONG_PTR user_data = GetWindowLongPtr(hWnd, GWLP_USERDATA);
            WindowsPlatform * this_window = reinterpret_cast<WindowsPlatform *>(user_data);
            return this_window->MsgProc(hWnd, Msg, wParam, lParam);
        }
        LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

        LPDIRECT3DDEVICE9 getDevice() {
            return g_pd3dDevice;
        };

        int getBufferWidth() const {
            return d3dParams_.BackBufferWidth;
        }
        int getBufferHeight() const {
            return d3dParams_.BackBufferHeight;
        }

        HINSTANCE getHInst() {
            return wc_.hInstance;
        }

        HWND getHWnd() {
            return hWnd_;
        }

        virtual bool	start();
        virtual void 	onSuspend();
        virtual void 	update();
        virtual void 	onResume();
        virtual void 	stop();
};

#endif // WINDOWS_PLATFORM_H_
